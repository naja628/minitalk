#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
	(void) ac;
	printf("my pid is %d\n", getpid());
	kill(atoi(av[1]), SIGUSR1);
	return (0);
}
