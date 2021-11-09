#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    struct input_event events[10000];

    while (1)
    {
        int val = read(open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY), events, sizeof(events));

        for (int i = 0; i < (int) (val / sizeof(struct input_event)); i++)
        {

            if (events[i].type == EV_KEY)
            {
              if (events[i].value == 1)
              {
                  printf("PRESS 0x%x (%d)\n", events[i].code, events[i].code);
              }
              else if (events[i].value == 0)
              {
                  printf("RELEASE 0x%x (%d)\n", events[i].code, events[i].code);
              }
            }
        }
    }
    return 0;
}
