#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define MAX_BUFF_SIZE 256

FILE *fp;
FILE *fp2;

typedef char *string;

void isFileExist(string fileName);
void printDivision(int num1, int divisor);
void ctrl_c_handler();
void ctrl_z_handler();
void printFirstNotEqualRowInTwoFiles(string file1, string file2);
void timeLoop();