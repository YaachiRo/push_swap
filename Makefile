NAME 	= push_swap

BONUS 	= checker

SRCS =	instructions.c 			\
		instructions2.c 			\
		algorithm.c 				\
		tools.c 					\
		tools2.c 					\
		pushtoa.c					\
		pushtob.c 				\
		libft/ft_isdigit.c 			\
		libft/ft_atoi.c 			\
		libft/ft_split.c 			\
		libft/ft_printf.c 			\
		libft/ft_put_hexa.c 		\
		libft/ft_put_utils.c 		\
		libft/ft_lstlast.c 			\
		libft/ft_lstadd_back.c 		\
		libft/ft_lstadd_front.c 		\
		libft/ft_lstnew.c 			\
		libft/ft_lstiter.c 			\
		libft/ft_lstsize.c 			\
		libft/ft_strlcpy.c 			\
		libft/ft_strlen.c 			\
		libft/ft_strncmp.c 			\

MANDATORY = main.c

SRCBONUS = 	bonus_part/bonus.c 							\
			bonus_part/gnl42/get_next_line.c 				\
			bonus_part/gnl42/get_next_line_utils.c 			\

OBJS = ${SRCS:.c=.o}

OBJSMANDATORY = main.o

OBJSBONUS =${SRCBONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all : ${NAME}

${NAME}: ${OBJS} ${OBJSMANDATORY}
				${CC}  ${OBJS} ${OBJSMANDATORY} -o  ${NAME}

clean:
		${RM} ${OBJS} ${OBJSBONUS} ${OBJSMANDATORY}

bonus : ${BONUS}

${BONUS}: ${OBJS} ${OBJSBONUS}
				${CC} ${OBJS} ${OBJSBONUS} -o  ${BONUS}

fclean:		clean
			${RM} ${NAME} ${BONUS}

re:			fclean all

.PHONY:		clean fclean all re