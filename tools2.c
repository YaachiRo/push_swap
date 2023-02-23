/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:54:46 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:54:46 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list **stack, int *tab, int index)
{
	int		i;
	t_list	*node;

	node = *stack;
	i = 0;
	while (node)
	{
		if (node->content == tab[index])
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

int	check_content(t_list **stack, int content)
{
	t_list	*node;
	int		i;

	node = *stack;
	i = 0;
	while (node)
	{
		if (node->content == content)
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

void	fill_stack(t_list **stack, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(stack, ft_lstnew(tab[i]));
		i++;
	}
}
