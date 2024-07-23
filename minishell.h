/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:15:43 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/23 00:35:04 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

typedef struct s_exct
{
	char	*cmd;
	char	**arg;
	char	**opt;
	int		pip;
	struct s_exct	*next;
}	t_exct;

typedef struct s_exp
{
	char	*content;
	char	*type;
	struct s_exp *next;
}	t_exp;

typedef struct s_detail
{
	pid_t	last_cmd;
	int		i;
	int		j;
	int		id;
	int		fd;
	int		save;
	int		ext_status;
}	t_detail;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*file;
	int		fd;
	int		type;
	struct s_cmd *next; 
}	t_cmd;


int	ft_strcmp(const char *s1, const char *s2);
void	ft_var_init(t_detail *var);
void	ft_pipe_cmd(char **av, int *pip, char **env, t_detail *var);
void	ft_redirection_cmd(char **av, int *pip, int i, t_detail *var);

//				EXECUTE CMD
void	ft_cmd_to_cmd(char **hadik, char **array);
void	ft_cmd_loop(char **hadik, char **env);
void	ft_execute_last_one(char *av, int *pip, char **env);
void	ft_execute_one_cmd(char **av, int *pip, char **env, t_detail *var);
void	ft_first_one(char **av, int *pip, char **env, t_detail *var);
void	ft_cmd_execute(char **av, int *pip, char **env, t_detail *var);
void	ft_execute_cmd1(char **av, int *pip, char **env);
void	ft_execute_cmd2(char **av, int *pip, char **env);
char	*ft_search_path(char *av, char **env, int *pip);
char	*ft_search_cmd(char *first_path, char *av, int *pip);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_exit1(char *av, int *pip);
void	ft_exit(int *pip);
void	ft_close(int *pip);
//

//				ENVIRONEMENT SETTING
void	create_var(t_list *av, char *arg);
void	ft_modify_val(t_list *av, char *val, char *arg);
t_list	*ft_search_val(t_list *av, char *val);
// void	ft_add_val(char *val, t_list *av, char *var);
char	**list_t_array(t_list *av);
//

//				BUILT_INS
void	echo(char **arg, char **opt);
void	cd(char **arg, t_exct *a, t_list *av);



#endif

