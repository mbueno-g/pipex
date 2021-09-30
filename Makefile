# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 19:10:56 by mbueno-g          #+#    #+#              #
#    Updated: 2021/09/24 19:35:32 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc 
FLAGS = #-Wall -Werror -Wextra  
RM = rm -f
LIBFT = Libft/libft.a

SRC_M = main.c utils.c pipex.c

OBJ_M = $(SRC_M:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ_M) Libft
		$(CC) $(FLAGS) $(OBJ_M) $(LIBFT) -o $@

$(OBJ_M): $(SRC_M)
		$(CC) $(FLAGS) -c $^

Libft:
	 @make all -C Libft/

clean: 
		make clean -C Libft/
		$(RM) $(OBJ_M) 

fclean: clean
		$(RM) $(LIBFT)
		$(RM) $(NAME)

re: fclean all

.PHONY: all Libft clean fclean re
