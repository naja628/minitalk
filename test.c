#include <signal.h>
#include <unistd.h>

void ft_nothing(int signum, siginfo_t *info, void *c)
{
	write(1, "hello\n", 6);
	(void) signum;
}

int main() 
{
	struct sigaction	act;

	sigemptyset(&(act.sa_mask));
	sigaddset(&(act.sa_mask), SIGUSR1);
	sigaddset(&(act.sa_mask), SIGUSR2);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_nothing;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);

	sleep(60);
	return (0);
}
