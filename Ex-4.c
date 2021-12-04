// C program that does not suspend when
// Ctrl+Z is pressed
#include <stdio.h>
#include <signal.h>

// Signal Handler for SIGTSTP
void sighandler(int sig_num)
{
    printf("Cannot execute Ctrl+Z\n");
}

void ctrl_z_handler()
{
    signal(SIGTSTP, sighandler);
}
void ctrlc_handler(int iUnused)
{
    printf("\n You handle Ctrl + C\n");
}

void ctrl_c_handler()
{
    signal(SIGINT, ctrlc_handler);
}

int main()
{
    ctrl_z_handler();
    ctrl_c_handler();
    int a = 0;
    scanf("%d", &a);

    return 0;
}