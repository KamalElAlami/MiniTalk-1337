/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:54:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/03 03:10:20 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"
#include <signal.h>
#include "./include/ft_printf.h"

void sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	static int sigg;
	static int i;
	static int c_pid;

	if (c_pid == 0 || c_pid != info->si_pid) 
	{
		if ((sigg << 8) == 1)
		{
			write(1, "\b", 1);
		}
		c_pid = info->si_pid;
		sigg = 0;
		i = 0;
	}
	if (sig == SIGUSR1)
		sigg |= (1 << i);
	if (sig == SIGINT && c_pid == info->si_pid)
	{
		kill(c_pid, SIGUSR1);
		c_pid = 0;
		sigg = 0;
		i = 0;
	}
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
	struct sigaction act;
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;


	char *tag;
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
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		sigaction(SIGINT, &act, 0);
		// signal(SIGUSR1, sig_handler);
		// signal(SIGUSR2, sig_handler);
		pause();
	}

}