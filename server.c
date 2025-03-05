#include "minitalk.h"
#include <signal.h>

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	// (void)info;    // Unused parameter
  //   (void)context; // Unused parameter

	// static unsigned char ch;
	// static int count;

	// ch = ch << 1;
	// if (sig == SIGUSR1)
	// 	ch |= 1;
	// count++;
	// if(count == 8)
	// {
	// 	printf("%c",ch);
	// 	ch = 0;
	// 	count = 0;
	// }
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	printf("the pid is : %d\n", getpid());
	// signal(SIGUSR1,handle_signal);
	// signal(SIGUSR2,handle_signal);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }
	while (1)
		pause();
	return (0);	
}
