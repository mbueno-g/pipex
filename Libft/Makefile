# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 15:57:21 by mbueno-g          #+#    #+#              #
#    Updated: 2021/09/21 18:23:06 by mbueno-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

FLAGS = -Wall -Werror -Wextra 

AR = ar rc

SRCS =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memchr.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

SRCSB = ft_lstnew.c \
		ft_lstadd_front.c \
        ft_lstsize.c \
		ft_lstlast.c \
        ft_lstadd_back.c \
        ft_lstdelone.c \
 		ft_lstclear.c \
 		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew_struct.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

$(NAME): $(SRCS) $(SRCSB)
	gcc $(FLAGS) -c $(SRCS) $(SRCSB) 
	$(AR) $(NAME) $(OBJS) $(OBJSB)

all: $(NAME)

bonus: all
	gcc $(FLAGS) -c $(SRCSB)
	$(AR) $(NAME) $(OBJSB)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re
