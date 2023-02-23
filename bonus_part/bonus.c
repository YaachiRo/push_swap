/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:47:48 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/22 11:34:43 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exec(char *instruction, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(instruction, "sa\n", ft_strlen(instruction)))
		swap_stack(stack_a, NULL);
	else if (!ft_strncmp(instruction, "sb\n", ft_strlen(instruction)))
		swap_stack(stack_b, NULL);
	else if (!ft_strncmp(instruction, "ss\n", ft_strlen(instruction)))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pa\n", ft_strlen(instruction)))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "pb\n", ft_strlen(instruction)))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "ra\n", ft_strlen(instruction)))
		rotate(stack_a, NULL);
	else if (!ft_strncmp(instruction, "rb\n", ft_strlen(instruction)))
		rotate(stack_b, NULL);
	else if (!ft_strncmp(instruction, "rr\n", ft_strlen(instruction)))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(instruction, "rra\n", ft_strlen(instruction)))
		reverse_rotate(stack_a, NULL);
	else if (!ft_strncmp(instruction, "rrb\n", ft_strlen(instruction)))
		reverse_rotate(stack_b, NULL);
	else if (!ft_strncmp(instruction, "rrr\n", ft_strlen(instruction)))
		rrr(stack_a, stack_b, 0);
	else
		error_message(1);
}

int	check_if_sorted(t_list **stack_a)
{
	t_list	*head;

	head = *stack_a;
	if (!head)
		return (0);
	while (head->next && head->content < head->next->content)
		head = head->next;
	if (!head->next)
		return (1);
	return (0);
}

void	parcing(int ac, char **av, t_lol *vars)
{
	vars->size = array_size(ac, av);
	vars->tab = malloc(sizeof(int) * vars->size);
	if (!vars->tab)
		exit(1);
	fill_array(ac, av, vars->tab);
	check_dup(vars->tab, vars->size);
	fill_stack(&vars->stack_a, vars->tab, vars->size);
}

int	main(int ac, char **av)
{
	t_lol	vars;

	vars.stack_a = NULL;
	vars.stack_b = NULL;
	if (ac > 1)
	{
		parcing(ac, av, &vars);
		while (1)
		{
			vars.instruction = get_next_line(0);
			if (!vars.instruction)
				break ;
			exec(vars.instruction, &vars.stack_a, &vars.stack_b);
			free(vars.instruction);
		}
		if (check_if_sorted(&vars.stack_a) && !ft_lstsize(vars.stack_b))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
