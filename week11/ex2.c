#include <dirent.h>
#include <stdio.h>

int main(void)
{
    DIR *directory;
    struct dirent *tempDirent;
    directory = opendir(".");

    while ((tempDirent = readdir(directory)) != NULL)
        if(tempDirent->d_name != "")
            printf("%s\n", tempDirent->d_name);
    closedir(directory);

    return 0;
}
