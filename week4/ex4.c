#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "unistd.h"

#define buffer 128

int main()
{
        printf("This is a shell for run commands\nFor close it write \"closeShell\"\n");

        char command[buffer] = "";

        while(strcmp(command, "closeShell") != 0)
        {
            printf("$ ");
            scanf("%s", command);

            char *argv[] = {};
            int index = 0;

            do
            {
                char *arg = strtok((index == 0 ? command : NULL), " \n");
                if (arg)
                    strcpy(argv[index], arg);
                else
                    argv[index] = 0;
                index++;
            }
            while(argv[index-1]);

            if(strcmp(command, "closeShell") != 0)
            {
                fork();
                execvp(argv[0], argv);
            }
        }
        return 0;
}
