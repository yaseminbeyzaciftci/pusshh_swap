# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaciftci <yaciftci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 12:18:37 by yaciftci          #+#    #+#              #
#    Updated: 2025/01/09 07:49:31 by yaciftci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC =ft_split.c\
function1.c\
function2.c\
function3.c\
function4.c\
push_swap.c\
quick_sort.c\
sort.c\
utils.c
OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re