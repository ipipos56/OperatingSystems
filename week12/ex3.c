#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>

int lenHK = 3;

int hotkeysNumbers[3][3] = {
        {18, 25, -1},
        {25, 30, 46},
        {18, 30, -1}
};

int pressedHotkeys[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
};


char *messages[3];

int main() {

    messages[0] = "I passed the Exam!";
    messages[1] = "Get some cappuccino!";
    messages[2] = "Some interesting message";

    struct input_event events[10000];

    while (1)
    {

        for (int it = 0; it < lenHK; it++)
            for (int jt = 0; jt < lenHK; jt++)
                pressedHotkeys[it][jt] = 0;

        int val = read(open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY), events, sizeof(events));

        for (int i = 0; i < (int) (val / sizeof(struct input_event)); i++)
        {

            if (events[i].type == EV_KEY)
            {
                if (events[i].value == 1)
                {
                    //printf("PRESS 0x%x (%d)\n", events[i].code, events[i].code);
                    for (int it = 0; it < lenHK; it++)
                    {
                        for (int jt = 0; jt < lenHK; jt++)
                        {
                            if (events[i].code == hotkeysNumbers[it][jt])
                                pressedHotkeys[it][jt] = 1;
                            if (hotkeysNumbers[it][jt] == -1)
                                pressedHotkeys[it][jt] = 1;
                        }

                    }
                    for (int it = 0; it < lenHK; it++)
                    {
                        int sumHot = 0;

                        for (int jt = 0; jt < lenHK; jt++)
                            if (pressedHotkeys[it][jt] == 1)
                                sumHot += 1;

                        if (sumHot >= lenHK)
                            printf("%s\n", messages[it]);

                    }
                }
                else if (events[i].value == 0)
                {
                    //RELEASE
                }
            }
        }
    }
    return 0;
}
