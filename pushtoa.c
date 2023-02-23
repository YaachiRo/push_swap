/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:17:54 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/21 06:07:53 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_list **stack_b, int *tab, int size)
{
	t_list	*node;

	node = *stack_b;
	while (node)
	{
		if (node->content == tab[size])
			return (1);
		node = node->next;
	}
	return (0);
}

void	pushtoa_tool(t_list **sa, t_list **sb, int *down, t_variables *vars)
{
	if ((*sb)->content == vars->tab[vars->size])
	{
		pa(sa, sb, 1);
		vars->size--;
	}
	else
	{
		if (!*down || (*sb)->content > ft_lstlast((*sa))->content)
		{
			pa(sa, sb, 1);
			rotate(sa, "ra");
			++*down;
		}
		else
		{
			if (get_position(sb, vars->tab, vars->size) <= ft_lstsize(*sb) / 2)
				rotate(sb, "rb");
			else
				reverse_rotate(sb, "rrb");
		}
	}
}

void	pushtoa(t_list **stack_a, t_list **stack_b, t_variables *vars)
{
	int	down;

	down = 0;
	while (*stack_b)
	{
		if (max(stack_b, vars->tab, vars->size))
			pushtoa_tool(stack_a, stack_b, &down, vars);
		else
		{
			reverse_rotate(stack_a, "rra");
			down--;
			vars->size--;
		}
	}
	while (down)
	{
		reverse_rotate(stack_a, "rra");
		down--;
	}
}
