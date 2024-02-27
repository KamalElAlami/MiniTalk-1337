/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:46:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/02/27 01:14:08 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"
#include "./include/ft_printf.h"

void send_sig(pid_t pid, char *str)
{
    int i;
    
    while (*str)
    {        
        i = 0;
        while (i <= 7)
        {
            if ((*str >> i) & 1)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            i++;
            usleep(500);
        }
        str++;
    }
}

int main(int ac, char **av)
{
    pid_t pidd;

    pidd = ft_atoi(av[1]);
    if (ac == 3)
    {
        send_sig(pidd, av[2]);
    }
    else
        ft_printf("Opps, Something went wrong\n");
}