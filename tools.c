/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:54:36 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:54:36 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	x;
	int	j;

	j = 0;
	i = 0;
	x = 0;
	while (i < size - 1)
	{
		x = 0;
		while (x < size - i - 1)
		{
			if (tab[x] > tab[x + 1])
			{
				ft_swap(&tab[x], &tab[x + 1]);
				j++;
			}
			x++;
		}
		i++;
	}
	if (j == 0)
		exit(0);
}

void	check_dup(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j])
				error_message(1);
			j++;
		}
		i++;
	}
}

void	fill_array(int ac, char **av, int *tab)
{
	int		i;
	int		j;
	int		x;
	char	**tmp;

	tmp = NULL;
	x = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
		{
			tab[x] = ft_atoi(tmp[j]);
			free(tmp[j]);
			x++;
			j++;
		}
		free(tmp);
		i++;
	}
}

int	array_size(int ac, char **av)
{
	int		i;
	int		j;
	int		size;
	char	**tmp;

	tmp = NULL;
	size = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		size += j;
		free(tmp);
		i++;
	}
	return (size);
}
