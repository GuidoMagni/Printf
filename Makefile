# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/21 16:25:51 by gumagni           #+#    #+#              #
#    Updated: 2026/01/03 23:17:43 by gumagni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_printf.c ft_pint.c ft_pchar.c ft_pstring.c ft_pu.c ft_phexa.c ft_pheXa.c ft_pptr.c
OBJS	= $(SRCS:.c=.o)

AR		= ar rcs
RM		= rm -f

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re