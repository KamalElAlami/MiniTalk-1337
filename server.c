/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:54:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/03 20:25:53 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk_bonus.h"
#include "./include/ft_printf.h"

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static int	sigg;
	static int	i;
	static int	c_pid;

	(void)context;
	if (c_pid == 0 || c_pid != info->si_pid)
	{
		c_pid = info->si_pid;
		sigg = 0;
		i = 0;
	}
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

int	main(void)
{
	struct sigaction	act;
	char				*tag;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_handler;
	tag = "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗\n"
		"████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝\n"
		"██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝\n"
		"██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗\n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝\n";
	ft_printf("%s \n PID : %d\n", tag, getpid());
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
}
