/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvander- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:33:48 by jvander-          #+#    #+#             */
/*   Updated: 2021/07/20 12:12:23 by jvander-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_longmax(int negative)
{
	if (negative == -1)
		return (0);
	return (-1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\v' || c == '\r' || c == '\f'
		|| c == '\n' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	unsigned long long	res;
	int					i;
	int					negative;
	unsigned long long	tmp;

	i = 0;
	negative = 1;
	res = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			negative *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		tmp = res;
		res *= 10;
		res += s[i++] - 48;
		if (res > LLONG_MAX || res < tmp)
			return (ft_check_longmax(negative));
	}
	return (res * negative);
}
