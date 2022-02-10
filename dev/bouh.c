#include <signal.h>
#include <stdio.h>

int g_done = 0;
void showpid(int signum, siginfo_t *info, void *useless)
{
	(void) useless;

	printf("sender's PID was %d\n", info->si_pid);
	g_done = 1;
}

int main()
{
	struct sigaction act;

	act.sa_sigaction = showpid;
	act.sa_flags = SA_SIGINFO;
	// do I need to worry about sa_mask
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	while (!g_done) ;
	return (0);
}
