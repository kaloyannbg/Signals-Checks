#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

void sig_handler(int signum)
{

	printf("ALARM\n");
}

int main()
{
	alarm(60);
	int iSecC = 0;
	while (1)
	{
		if (iSecC < 60)
		{
			printf("%d\n", ++iSecC);
			sleep(1);
		}
		else
		{
			signal(SIGALRM, SIG_DFL);
			iSecC = 0;
			printf("%d\n", ++iSecC);
			sleep(1);
		}
	}
	return 0;
}
