/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:11:08 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/22 11:03:03 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	error_message(int x)
{
	write(2, "Error\n", 6);
	exit(x);
}

int	ft_atoi(const char *str)
{
	long			n;
	int				sign;

	sign = 1;
	n = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		str++;
	}
	while (str[0])
	{
		if (!ft_isdigit(str[0]))
			error_message(1);
		n *= 10;
		n += (str[0] - '0');
		str++;
	}
	if (n * sign > 2147483647 || n * sign < -2147483648)
		error_message(1);
	return ((int)n * sign);
}
