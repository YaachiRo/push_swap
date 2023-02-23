/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 06:48:34 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/23 15:27:49 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../push_swap.h"
# include "gnl42/get_next_line.h"

typedef struct s_lol
{
	int		*tab;
	int		size;
	char	*instruction;
	t_list	*stack_a;
	t_list	*stack_b;

}	t_lol;

#endif