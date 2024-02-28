#include "./include/minitalk.h"
#include "./include/ft_printf.h"

void sig_handler(int sig)
{
	static int sigg;
	static int i = 0;

	if (sig == SIGUSR1)
		sigg |= (1 << i);
	i++;
	if (i == 8)
	{
		write(1, &sigg, 1);
		i = 0;
		sigg = 0;
	}
}
int main(void)
{
	char *tag;

	tag = malloc(366 * sizeof(char));
	tag = 
"███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n"
"████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n"
"██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n"
"██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n"
"██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n"
"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n";

	printf("%s \n PID : %d\n", tag ,getpid());

	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}

}