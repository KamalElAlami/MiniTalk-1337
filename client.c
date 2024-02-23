/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:46:46 by kael-ala          #+#    #+#             */
/*   Updated: 2024/02/23 18:08:16 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void send_sig(pid_t pid, char c)
{
    int i;
    
    i = 7;
    while (i >= 0)
    {
        if ((c >> i) & 1)
            // printf("1");
            kill(pid, SIGUSR1);
        else
            // printf("0");
            kill(pid, SIGUSR2);
        i--;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 3)
    {
        while (av[2][i])
        {
            send_sig(atoi(av[1]), av[2][i]);
            i++;
        }
    }
}