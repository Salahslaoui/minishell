# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 17:54:19 by sslaoui           #+#    #+#              #
#    Updated: 2024/07/05 04:36:40 by sslaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = pipex

SRC = pipex.c fetch_path.c ft_split.c ft_strjoin.c execute.c var_options.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $@

%.o : %.c pipex.h
	$(CC) $(FLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
