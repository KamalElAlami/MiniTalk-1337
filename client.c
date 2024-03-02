/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:46:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/02 18:22:56 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minitalk.h"
#include "./include/ft_printf.h"

void print_message(int sig)
{
    (void)sig;
    ft_printf("Message Sent Successfully\n");
    exit(0);
}

void    ft_kill(pid_t pid, int sig) {
    if (kill(pid, sig) < 0) {
        ft_printf("Failed to send signal to %d or  may the server is down\n", pid);
        exit(0);
    }
}

void send_sig(pid_t pid, char *str)
{
    // (void)pid;
    int i;
    
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
    kill(pid, SIGINT);
}

int main(int ac, char **av)
{
    pid_t pidd;

    pidd = ft_atoi(av[1]);
    signal(SIGUSR1, print_message);
    if (ac == 3)
    {
        send_sig(pidd, av[2]);
        while(1);
    }
    else
        ft_printf("Opps, Something went wrong\n");
    
}