#include <signal.h>
#include <stdio.h>


int main()
{
	int pid = 38570;
	char num = 'a';

	// kill(pid, num);
	kill(pid, SIGUSR1);
	
	
}
