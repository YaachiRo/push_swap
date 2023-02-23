/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:41:03 by idelfag           #+#    #+#             */
/*   Updated: 2022/12/08 04:18:16 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i] != '\0')
	{
		i += ft_putchar(s[i]);
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else
	{
		if (n < 0)
		{
			i += ft_putchar(('-'));
			n *= -1;
			i += ft_putnbr(n);
		}
		else if (n < 10)
			i += ft_putchar((n + 48));
		else
		{
			i += ft_putnbr((n / 10));
			i += ft_putchar((n % 10 + 48));
		}
	}
	return (i);
}

int	ft_put_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n < 10)
		i += ft_putchar((n + 48));
	else
	{
		i += ft_putnbr((n / 10));
		i += ft_putchar((n % 10 + 48));
	}
	return (i);
}
