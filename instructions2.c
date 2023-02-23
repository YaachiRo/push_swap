/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:53:43 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:53:43 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;

	tmp = *stack;
	if (ft_lstsize(*stack) <= 1)
		return ;
	ft_lstlast(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	if (str)
		ft_printf("%s\n", str);
}

void	rr(t_list **stack_a, t_list **stack_b, int order)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	if (order)
		ft_printf("rr\n");
}

void	reverse_rotate(t_list **stack, char *str)
{
	t_list	*head;
	t_list	*blast;
	t_list	*last;

	head = *stack;
	blast = *stack;
	last = ft_lstlast(*stack);
	if (ft_lstsize(*stack) <= 1)
		return ;
	while (blast->next->next)
		blast = blast->next;
	blast->next = NULL;
	last->next = head;
	*stack = last;
	if (str)
		ft_printf("%s\n", str);
}

void	rrr(t_list **stack_a, t_list **stack_b, int order)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	if (order)
		ft_printf("rrr\n");
}
