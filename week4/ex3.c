#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define buffer 128

int main()
{
        printf("This is a shell for run commands without parameters\nFor close it write \"closeShell\"\n");

        char command[buffer] = "";

        while(strcmp(command, "closeShell") != 0)
        {
            printf("$ ");
            scanf("%s", command);

            if(strcmp(command, "closeShell") != 0)
                system(command);
        }
        return 0;
}
