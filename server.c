#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

char	*g_buffer;

#include <stdio.h>
void	ft_sigs_to_bin(int signum)
{
	static int	ibit = 0;
	static char	cur_byte;

	if (signum == SIGUSR2)
		cur_byte |= (0x80 >> ibit);
	++ibit;
	//printf("%c", (signum == SIGUSR1)? '0' : '1');
	if (ibit == 8)
	{
		//printf("\n");
		ibit = 0;
		*(g_buffer++) = cur_byte;
		cur_byte = 0x00;
	}
}

void	ft_nreceive(void *buff, size_t n)
{
	ft_bzero(buff, n);
	g_buffer = buff;
	((char *) buff)[n] = 0xff;
	while (((char *) buff)[n] != '\0')
		usleep(500);
}

int	main()
{
	pid_t	pid;
	size_t	sz_buff[2];
	char	*str;

	pid = getpid();
	ft_printf("server pid: %d\n", pid);
	signal(SIGUSR1, ft_sigs_to_bin);
	signal(SIGUSR2, ft_sigs_to_bin);
	while(1)
	{
		ft_nreceive(sz_buff, sizeof(size_t));
		str = malloc(sz_buff[0] + 1);
		if (!str)
		{
			write(2, "malloc error\n", 13);
			exit(-1);
		}
		ft_nreceive(str, sz_buff[0]);
		write(1, str, sz_buff[0]);
		write(1, "\n", 1);
		free(str);
	}
}
