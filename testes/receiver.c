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
	int tmp;
    // signal(SIGTERM, handler); // Catch SIGTERM
	if(signal(SIGUSR1, handler))
	{
		tmp = 1;
	}
	else
	{
		tmp = 0;
	}
	

	printf("the pid is %d \n", getpid());
	// printf("the sig is %d\n", tmp);
	while(1) {
        pause();
    }
}
