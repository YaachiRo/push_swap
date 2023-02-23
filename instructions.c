/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:53:27 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:53:27 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_list **stack, char *str)
{
	t_list	*node;

	node = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		ft_swap(&node->content, &node->next->content);
		if (str)
			ft_printf("%s\n", str);
	}
}

void	ss(t_list **stack_a, t_list **stack_b, int order)
{
	swap_stack(stack_a, NULL);
	swap_stack(stack_b, NULL);
	if (order)
		ft_printf("ss\n");
}

void	pa(t_list **stack_a, t_list **stack_b, int order)
{
	t_list	*node;

	if (ft_lstsize(*stack_b) < 1)
		return ;
	node = *stack_b;
	*stack_b = node->next;
	ft_lstadd_front(stack_a, node);
	if (order)
		ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b, int order)
{
	t_list	*node;

	if (ft_lstsize(*stack_a) < 1)
		return ;
	node = *stack_a;
	*stack_a = node->next;
	ft_lstadd_front(stack_b, node);
	if (order)
		ft_printf("pb\n");
}
