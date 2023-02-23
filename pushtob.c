/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 00:08:55 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/21 06:08:04 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update(t_supp *supp)
{
	supp->start -= supp->csize;
	supp->end += supp->csize;
	if (supp->start < 0)
		supp->start = 0;
	if (supp->end > (supp->array_size - 1))
		supp->end = (supp->array_size - 1);
}

void	ra_or_rra(t_list **stack_a, int *tab, t_supp *supp)
{
	t_list	*node;

	node = *stack_a;
	while (node && !(node->content >= tab[supp->start]
			&& node->content <= tab[supp->end]))
		node = node->next;
	if (!node)
		update(supp);
	else
	{
		if (check_content(stack_a, node->content) <= ft_lstsize(*stack_a) / 2)
			rotate(stack_a, "ra");
		else
			reverse_rotate(stack_a, "rra");
	}
}

void	pushtob(t_list **stack_a, t_list **stack_b, t_supp *supp, int *tab)
{
	while (*stack_a)
	{
		if ((*stack_a)->content >= tab[supp->start]
			&& (*stack_a)->content <= tab[supp->end])
		{
			pb(stack_a, stack_b, 1);
			if ((*stack_b)->content <= tab[supp->mid])
				rotate(stack_b, "rb");
		}
		else
			ra_or_rra(stack_a, tab, supp);
	}
}
