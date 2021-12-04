#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int sig)
{
    printf("Signal trapped: %d\n", sig);
    // exit(0);
    // return;
}

int main()
{
    for (int i = -1; i <= 20; i++)
    {
        if(i == 9 || i == 19) { //CONTINUE AT KILL
            continue;
        }
        signal(i, handler);
        raise(i);
    }

    // signal(1, handler);
    // signal(2, handler);
    // signal(3, handler);
    // signal(6, handler);
    // signal(9, handler);
    // signal(13, handler);
    // signal(15, handler);
    // signal(19, handler);

    while (1);
}