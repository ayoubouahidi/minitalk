#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	handler(int n)
{
	write(1, "STOP\n", 5);
}

int main()
{
		signal(SIGINT, handler);
		while (1)
		{
			printf("hey im here ! %d",getpid());
			// usleep(7000);
			sleep(1);
			
		}
}
