#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


typedef struct page_table_entry {
    int pageID;
    unsigned int counter;
} const page_table_entry_default = {-1, 0};


int main() {
    int n;
    printf("Enter the number of pages\n");
    scanf("%d", &n);

    char fpath[] = "myInput.txt";
    FILE *file = fopen(fpath, "r");

    struct page_table_entry pages[n];
  
    for (int i = 0; i < n; i++)
        pages[i] = page_table_entry_default;

    int pageID;
    unsigned int hitCounter = 0;
    unsigned int missCounter = 0;

    while (fscanf(file, "%d", &pageID) == 1) {
        int pageFound = 0;

        for (int i = 0; i < n; i++) {
            if (pages[i].pageID == pageID) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            int freeSpace = 0;
            for (int i = 0; i < n; i++) {
                if (pages[i].pageID == -1) {
                    page_table_entry page;
                    page.pageID = pageID;
                    page.counter = 0;
                    pages[i] = page;
                    freeSpace = 1;
                    break;
                }
            }

            if (freeSpace)
                continue;

            unsigned int minCounter = INT_MAX;
            unsigned int index = -1;
            for (int i = 0; i < n; i++) {
                if (minCounter > pages[i].counter) {
                    minCounter = pages[i].counter;
                    index = i;
                }
            }

            page_table_entry page;
            page.pageID = pageID;
            page.counter = 0;
            pages[index] = page;
        }

        for (int i = 0; i < n; i++) {
            pages[i].counter >>= 1;

            if (pageFound && pageID == pages[i].pageID)
                pages[i].counter |= 1 << 31;
        }
      
        if (pageFound)
            hitCounter++;
        else
            missCounter++;
    }
  
    printf("Hit: %f; Miss: %f; Ratio: %f\n", hit_counter, miss_counter, (float) hit_counter / (float) miss_counter);
  
    fclose(file);

    return 0;
}
