/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:41:29 by idelfag           #+#    #+#             */
/*   Updated: 2022/12/08 04:45:25 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	format(va_list lt, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(lt, int));
	else if (c == 'd' || c == 'i')
		i = ft_putnbr(va_arg(lt, int));
	else if (c == 's')
		i = ft_putstr(va_arg(lt, const char *));
	else if (c == 'u')
		i = ft_put_unsigned(va_arg(lt, unsigned int));
	else if (c == 'x')
		i = ft_put_hexa_low(va_arg(lt, unsigned int));
	else if (c == 'X')
		i = ft_put_hexa_up(va_arg(lt, unsigned int));
	else if (c == 'p')
		i = ft_put_adress(va_arg(lt, unsigned long));
	else if (c == '%')
		i = ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	lp;
	int		i;

	i = 0;
	va_start(lp, s);
	while (s && *s)
	{
		if (*s == '%')
		{
			s++;
			i += format(lp, *s);
		}
		else
			i += ft_putchar(*s);
		s++;
	}
	va_end(lp);
	return (i);
}
