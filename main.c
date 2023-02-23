/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:53:53 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:53:53 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init(t_supp *supp, int size)
{
	if (size <= 10)
		supp->csize = size / 5;
	else if (size <= 150)
		supp->csize = size / 8;
	else if (size > 150)
		supp->csize = size / 18;
	supp->mid = size / 2;
	supp->start = supp->mid - supp->csize;
	supp->end = supp->mid + supp->csize;
	supp->array_size = size;
}

void	sort_long(t_list **a, t_list **b, t_variables *vars, t_supp *supp)
{
	init(supp, vars->size);
	pushtob(a, b, supp, vars->tab);
	vars->size--;
	pushtoa(a, b, vars);
}

int	main(int ac, char **av)
{
	t_variables	vars;
	t_supp		supp;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	vars.size = array_size(ac, av);
	vars.tab = malloc(sizeof(int) * vars.size);
	if (!vars.tab)
		return (1);
	fill_array(ac, av, vars.tab);
	check_dup(vars.tab, vars.size);
	fill_stack(&stack_a, vars.tab, vars.size);
	sort_tab(vars.tab, vars.size);
	if (ft_lstsize(stack_a) == 2)
		swap_stack(&stack_a, "sa");
	else if (ft_lstsize(stack_a) == 3)
		sort_three(&stack_a);
	else if (ft_lstsize(stack_a) <= 5)
		sort_five(&stack_a, &stack_b, vars.tab, vars.size);
	else
		sort_long(&stack_a, &stack_b, &vars, &supp);
	return (0);
}
