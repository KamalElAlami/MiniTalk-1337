/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dedsec <dedsec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:47 by kael-ala          #+#    #+#             */
/*   Updated: 2024/02/27 00:39:39 by dedsec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

static int	_skipper(char *str, int *i, int sign)
{
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = sign * -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	number;

	i = 0;
	sign = 1;
	sign = _skipper((char *)str, &i, sign);
	number = 0;
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		if (number > LONG_MAX && sign == 1)
			return (-1);
		if (number > LONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return (number * sign);
}