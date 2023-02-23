/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:53:18 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:53:18 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int		i;
	int		j;
	t_list	*node;

	node = *stack;
	i = node->next->content;
	j = node->next->next->content;
	if (node->content > i && i < j && node->content < j)
		swap_stack(stack, "sa");
	else if (node->content > i && i > j && node->content > j)
	{
		swap_stack(stack, "sa");
		reverse_rotate(stack, "rra");
	}
	else if (node->content > i && i < j && node->content > j)
		rotate(stack, "ra");
	else if (node->content < i && i > j && node->content < j)
	{
		swap_stack(stack, "sa");
		rotate(stack, "ra");
	}
	else if (node->content < i && i > j && node->content > j)
		reverse_rotate(stack, "rra");
}

void	helper(t_list **stack, int position)
{
	if (position >= ft_lstsize(*stack) / 2)
	{
		while (position < ft_lstsize(*stack))
		{
			reverse_rotate(stack, "rra");
			position++;
		}
	}
	else
		while (position--)
			rotate(stack, "ra");
}

void	sort_five(t_list **stack_a, t_list **stack_b, int *tab, int size)
{
	int	position;

	position = get_position(stack_a, tab, 0);
	helper(stack_a, position);
	pb(stack_a, stack_b, 1);
	if (size == 5)
	{
		position = get_position(stack_a, tab, 1);
		helper(stack_a, position);
		pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
