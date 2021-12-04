// C program that does not suspend when
// Ctrl+Z is pressed
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Signal Handler for SIGTSTP
void sighandler(int sig_num)
{
    printf("You handle Ctrl + Z\n");
}

void ctrl_z_handler()
{
    signal(SIGTSTP, sighandler);
}
void ctrlc_handler(int iUnused)
{
    printf("You handle Ctrl + C\n");
}

void ctrl_c_handler()
{
    signal(SIGINT, ctrlc_handler);
}

void ctrl_d_handler() {
    printf("^DYou handle ctrl + D\n");
    exit(0);
}

int main()
{
    ctrl_z_handler();
    ctrl_c_handler();
    int a = 0;
    char c = 0;
    while(1) {

        c = getchar();

        if(c == EOF) {
            ctrl_d_handler();
        }

    }

    scanf("%d", &a);

    return 0;
}