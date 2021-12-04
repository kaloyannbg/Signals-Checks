#include "includes.h"

void sleep(int);

void ctrlz_handler(int sig_num)
{
    printf("Cannot execute Ctrl+Z\n");
    exit(EXIT_FAILURE);
}


int main()
{

   

    return 0;
}
