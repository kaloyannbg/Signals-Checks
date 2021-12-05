#include "includes.h"

void isFileExist(string fileName)
{
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        // perror(" -- ERR ");
        printf("\n -- ERR: %d: %s -- ", errno, strerror(errno));
        fclose(fp);
        return;
    }

    fclose(fp);
}

void printDivision(int num1, int divisor)
{
    if (divisor == 0)
    {
        printf("\n -- %d: %s -- ", errno, strerror(errno));
        // perror("\n -- ERR: ");
        return;
    }

    printf("%d", num1 / divisor);
}

void sleep(int);

void ctrlc_handler(int iUnused)
{
    printf("\n You handle Ctrl + C\n");
    exit(EXIT_FAILURE);
}

void ctrl_c_handler()
{
    signal(SIGINT, ctrlc_handler);

    while (!0)
    {
        sleep(1);
    }
}

int isFileExistIntReturn(string fileName)
{
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        // perror(" -- ERR ");
        printf("\n -- ERR: %d: %s -- ", errno, strerror(errno));
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

void createFileIfNotExist(string fileName)
{
    if (!isFileExistIntReturn(fileName))
    {
        fp = fopen(fileName, "w");
        fclose(fp);
        return;
    }
}

int countRows(string fileName)
{
    createFileIfNotExist(fileName);

    fp = fopen(fileName, "r");
    char buffer[MAX_BUFF_SIZE];

    string fileGets = fgets(buffer, MAX_BUFF_SIZE, fp);
    int cnt = 0;
    while (fileGets != NULL)
    {
        ++cnt;
        fileGets = fgets(buffer, MAX_BUFF_SIZE, fp);
    }

    return cnt;
}

int returnMaxN(int n1, int n2)
{
    if (n1 > n2)
    {
        return n1;
    }
    else if (n1 < n2)
    {
        return n2;
    }

    return n1;
}

int checkNewLine(string arr)
{
    int max = strlen(arr);
    if (arr[max - 1] == '\n')
    {
        return 1;
    }
    return 0;
}

void printFirstNotEqualRowInTwoFiles(string file1, string file2) // EX-5
{

    createFileIfNotExist(file1);
    createFileIfNotExist(file2);

    int file1Rows = countRows(file1);
    int file2Rows = countRows(file2);

    char buffer[MAX_BUFF_SIZE];
    char buffer2[MAX_BUFF_SIZE];

    fp = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    int cnt = 0;
    int i = 0;
    while (i < returnMaxN(file1Rows, file2Rows))
    {
        ++cnt;
        i++;
        string fileGets = fgets(buffer, MAX_BUFF_SIZE, fp);
        string fileGets2 = fgets(buffer2, MAX_BUFF_SIZE, fp2);

        if (fileGets != NULL || fileGets2 != NULL)
        {
            if (checkNewLine(buffer) == 1)
            {
                buffer[strlen(buffer) - 1] = '\0';
            }
            if (checkNewLine(buffer2) == 1)
            {
                buffer2[strlen(buffer2) - 1] = '\0';
            }

            if (fileGets == NULL)
            {
                printf("Line: %d -- ", cnt);
                printf("%s: %s != %s: (EMPTY LINE)\n", file2, buffer2, file1);
                return;
            }
            else if (fileGets2 == NULL)
            {
                printf("Line: %d -- ", cnt);
                printf("%s: %s != %s: (EMPTY LINE)\n", file1, buffer, file2);
                return;
            }
            else if (strcmp(buffer, buffer2) != 0)
            {
                printf("Line: %d -- ", cnt);
                printf("%s: %s != %s: %s  ", file1, buffer, file2, buffer2);
                return;
            }
        }
    }

    printf("MAX ROWS IN FILE : %d", cnt);
}

// void sig_handler(int signum)
// {
//     printf("Inside handler function\n");
// }

// void timeLoop()
// {

//     time_t currTime = time(NULL);
//     while (currTime)
//     {
//         system("cls");
//         printf("%d", time(NULL));
//         signal(SIGALRM, sig_handler); // Register signal handler

//         sleep(1);
//     }
// }
