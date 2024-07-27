# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 09:26:32 by sslaoui           #+#    #+#              #
#    Updated: 2024/07/25 20:10:15 by sslaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -fsanitize=address -lreadline

FLAGS2 =   -lreadline

NAME = minishell

SRC =	set_things.c libft2/ft_lstnew_bonus.c libft2/ft_lstadd_back_bonus.c libft2/ft_strdup.c libft2/ft_strlen.c \
		libft2/ft_strncmp.c env_config.c libft2/ft_strjoin.c libft2/ft_split.c ft_strcmp.c utils/here_doc.c \
		builts_in/cd.c utils/execute.c utils/fetch_path.c utils/var_options.c utils/pipex.c

OBJ =	$(SRC:.c=.o)

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
