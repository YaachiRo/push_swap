/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:58:59 by idelfag           #+#    #+#             */
/*   Updated: 2022/12/09 01:51:11 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_hexa_low(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		i += ft_putchar("0123456789abcdef"[n]);
	}
	if (n >= 16)
	{
		i += ft_put_hexa_low(n / 16);
		i += ft_put_hexa_low(n % 16);
	}
	return (i);
}

int	ft_put_hexa_up(unsigned long n)
{
	int	i;

	i = 0;
	if (n < 16)
	{
		i += ft_putchar("0123456789ABCDEF"[n]);
	}
	if (n >= 16)
	{
		i += ft_put_hexa_up(n / 16);
		i += ft_put_hexa_up(n % 16);
	}
	return (i);
}

int	ft_put_adress(unsigned long n)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	i += ft_put_hexa_low(n);
	return (i);
}
