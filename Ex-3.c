#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>


void sig_handler(int signum)
{
    printf("ALARM\n");
    exit(EXIT_SUCCESS);
}

int main()
{
    signal(SIGALRM, sig_handler);
    alarm(60);
    time_t currTime = time(NULL);
    int a = 0;
    while (1)
    {
        printf("%d", time(NULL) - currTime);
        printf("\n");
        sleep(1);
    }
    return 0;
}