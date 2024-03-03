/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:46:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/03 19:47:40 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"
#include "./include/ft_printf.h"

void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		ft_printf("Failed to send signal to %d\n", pid);
		exit(EXIT_FAILURE);
	}
}

void	send_sig(pid_t pid, char *str)
{
	int	i;

	while (*str)
	{
		i = 0;
		while (i <= 7)
		{
			if ((*str >> i) & 1)
				ft_kill(pid, SIGUSR1);
			else
				ft_kill(pid, SIGUSR2);
			i++;
			usleep(900);
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pidd;

	if (ac == 3)
	{
		pidd = ft_atoi(av[1]);
		send_sig(pidd, av[2]);
	}
	else
	{
		ft_printf("Opps, Something went wrong\n");
		exit(EXIT_FAILURE);
	}
}
