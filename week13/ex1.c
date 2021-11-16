#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 3
#define N 5
#define sampleNumLength 1000

int E[M];
int A[M];

int C[N][M];
int R[N][M];

int passedProcesses[N];

FILE *fp;

void charNuller(char* inputChar, int lengthOfChar)
{
    for(int j = 0;j<lengthOfChar;j++)
        inputChar[j] = ' ';
}

void splitLine(char* inputLine, int* inputWithSpaces)
{
    int spaceCounter = 0;
    int curIndexer = 0;
    char* curNumber[sampleNumLength];
    charNuller(curNumber,sampleNumLength);
    for(int i = 0;i<strlen(inputLine);i++)
    {
        if(inputLine[i] == ' ')
        {
            inputWithSpaces[spaceCounter] = atoi(curNumber);
            spaceCounter++;
            charNuller(curNumber,sampleNumLength);
            curIndexer = 0;
        }
        else
        {
            curNumber[curIndexer] = inputLine[i];
            curIndexer++;
        }
    }
    inputWithSpaces[spaceCounter] = atoi(curNumber);
}

/*
void printArray(int* arrayPointer, int lengthOfArray)
{
    for(int i = 0;i<lengthOfArray; i++)
        printf("%d ", arrayPointer[i]);
    printf("\n");
}
*/

void inputSetter(int* toArray)
{
    char* inputString = NULL;
    int splittedInput[M];
    size_t len = 0;
    ssize_t read;
    int trueH = 1;
    while(trueH == 1)
    {
        read = getline(&inputString, &len, fp);
        if (strlen(inputString) > 1) {
            splitLine(inputString, splittedInput);
            for (int i = 0; i < M; i++)
                toArray[i] = splittedInput[i];
            break;
        }
    }
}

int main(){
    fp = fopen("input.txt", "r");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    for(int i = 0;i<N; i++)
        passedProcesses[i] = 0;
    inputSetter(E);
    inputSetter(A);
    for(int j = 0;j<N;j++)
        inputSetter(C[j]);
    for(int j = 0;j<N;j++)
        inputSetter(R[j]);


    int numberOfPassedProcesses = 0;
    int oldNumberOfPassedProcesses = -1;
    while(oldNumberOfPassedProcesses != numberOfPassedProcesses) {
        oldNumberOfPassedProcesses = numberOfPassedProcesses;
        for (int j = 0; j < N; j++) {
            if (passedProcesses[j] == 0) {
                int curResTypesCheck = 0;

                for (int z = 0; z < M; z++)
                    if (A[z] >= R[j][z])
                        curResTypesCheck++;

                if (curResTypesCheck >= M) {
                    for (int z = 0; z < M; z++) {
                        if (A[z] >= R[j][z]) {
                            A[z] += C[j][z];
                            C[j][z] = 0;
                        }
                    }
                    numberOfPassedProcesses++;
                    passedProcesses[j] = 1;
                }
            }
        }
    }

    if(numberOfPassedProcesses >= N)
        printf("No deadlocks detected, everything is fine)\n");
    else
    {
        printf("Deadlock.\nIndexes of the deadlocked processes:\n");
        for(int i=0;i<N;i++){
            if(passedProcesses[i] == 0){
                printf("%d ", i);
            }
        }
    }


    printf("\n");
    fclose(fp);
    return 0;
}

