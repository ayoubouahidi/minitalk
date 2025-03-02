#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void	handler(int n)
{
	// write(1, "STOP\n", 5);
	printf("the num is %d \n",n);
}

int	main()
{
    // signal(SIGTERM, handler); // Catch SIGTERM
	signal(SIGKILL, handler);

	printf("the pid is %d \n", getpid());

	while(1) {
        pause();
    }
}