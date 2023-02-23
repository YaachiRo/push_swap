/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 02:54:05 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/19 02:54:05 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_supp
{
	int	mid;
	int	start;
	int	end;
	int	csize;
	int	array_size;

}	t_supp;

typedef struct s_variables
{
	int	size;
	int	*tab;
}	t_variables;

void	swap_stack(t_list **stack, char *str);
void	pa(t_list **stack_a, t_list **stack_b, int order);
void	ss(t_list **stack_a, t_list **stack_b, int order);
void	pa(t_list **stack_b, t_list **stack_a, int order);
void	pb(t_list **stack_b, t_list **stack_a, int order);
void	rotate(t_list **stack, char *str);
void	rr(t_list **stack_a, t_list **stack_b, int order);
void	reverse_rotate(t_list **stack, char *str);
void	rrr(t_list **stack_a, t_list **stack_b, int order);
void	ft_swap(int *a, int *b);
void	sort_tab(int *tab, int size);
void	check_dup(int *tab, int size);
int		array_size(int ac, char **av);
void	fill_array(int ac, char **av, int *tab);
void	sort_three(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b, int *tab, int size);
int		get_position(t_list **stack, int *tab, int index);
int		check_content(t_list **stack, int content);
void	fill_stack(t_list **stack, int *tab, int size);
void	pushtob(t_list **stack_a, t_list **stack_b, t_supp *supp, int *tab);
void	pushtoa(t_list **stack_a, t_list **stack_b, t_variables *vars);

#endif