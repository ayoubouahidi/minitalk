#include "minitalk.h"
#include <signal.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)info;    // Unused parameter
    (void)context; // Unused parameter
	static char charact;
	static int bit;

	if (sig == SIGUSR1)
		charact |= (1 << bit);
	bit++;
	if (bit == 8)
	{ 	
		write(1, &charact, 1);
		bit = 0;
		charact = 0;
	}
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	printf("the pid is : %d\n", getpid());
	// signal(SIGUSR1,handle_signal);
	// signal(SIGUSR2,handle_signal);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);	
}
