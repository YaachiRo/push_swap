/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelfag <idelfag@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 00:32:12 by idelfag           #+#    #+#             */
/*   Updated: 2023/02/21 05:35:01 by idelfag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

void				error_message(int x);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				**ft_split(char const *s, char c);
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(int));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
int					ft_putnbr(int n);
int					ft_put_unsigned(unsigned int n);
int					ft_put_hexa_low(unsigned long n);
int					ft_put_hexa_up(unsigned long n);
int					ft_put_adress(unsigned long n);
int					ft_printf(const char *s, ...);

#endif