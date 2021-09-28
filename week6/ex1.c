#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int  arrival[n], burst[n];
  
    for (int i = 0; i < n; i++) {
        scanf("%d %d", arrival[i], burst[i]);
    }

    int done = 0;
    int allTime = 0;
    
    int averageTurnaround = 0;
    int averageWaiting = 0;
    
    while (done != n) 
    {
        int minArrival = INT_MAX;
        int minId = -1;
      
        for (int i = 0; i < n; i++) 
        {
            if (arrival[i] > allTime)
                continue;
            if (arrival[i] < minArrival) 
            {
                minArrival = arrival[i];
                minId = i;
            }
        }
        if (minId == -1) 
        {
            printf("T = %d  -  No processes to execute...\n", allTime);
            allTime++;
            continue;
        }

        int waitingTime = allTime - arrival[minId];

        printf("T = %d  -  Executing process %d...\n", allTime, minId);
        allTime += burst[minId];
        printf("T = %d  -  Process %d has been executed.\n", allTime, minId);
        burst[minId] = arrival[minId] = -1;
        done++;

        int turnaround = allTime - arrival[minId];
        printf("Process %d: turnaround time is %d, waiting time is %d", minId, turnaround, waitingTime);
        averageTurnaround += turnaround;
        averageWaiting += waitingTime;
    }
    printf("Completion time: %d\n", t);
    printf("Average turnaround time: %f\n", 1.0 * averageT / n);
    printf("Average waiting time: %f\n", 1.0 * averageWaiting / n);
    return 0;
}
