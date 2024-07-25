# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 09:26:32 by sslaoui           #+#    #+#              #
#    Updated: 2024/07/25 01:24:36 by sslaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

FLAGS2 =  -fsanitize=address -lreadline

NAME = minishell

SRC =	set_things.c libft/ft_lstnew_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_strdup.c libft/ft_strlen.c \
		libft/ft_strncmp.c env_config.c libft/ft_strjoin.c libft/ft_split.c ft_strcmp.c  \
		builts_in/cd.c utils/execute.c utils/fetch_path.c utils/var_options.c utils/pipex.c

OBJ =	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $@

%.o : %.c minishell.h
	$(CC) $(FLAGS) -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
