#include "minitalk.h"

void	handle_signal(int sig)
{
	static unsigned char	buff;
	static int				i;

	buff |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		printf("%c", buff);
		i = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int main()
{
	printf("the pid is : %d\n", getpid());
	signal(SIGUSR1,handle_signal);
	signal(SIGUSR2,handle_signal);
	while (1)
		pause();
	return (0);	
}
