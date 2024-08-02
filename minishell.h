/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:15:43 by sslaoui           #+#    #+#             */
/*   Updated: 2024/08/02 14:48:15 by sslaoui          ###   ########.fr       */
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
# include "libft2/libft.h"

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

// typedef struct s_cmd
// {
// 	char	*cmd;
// 	char	**args;
// 	char	*file;
// 	int		fd;
// 	int		type;
// 	struct s_cmd *next; 
// }	t_cmd;

typedef struct s_exct
{
	char	**args;
	char	**red;
	char	*cmd;
	int		pip;
	int		file_in;
	int		file_out;
	struct s_exct	*next;
}	t_exct;

//				UTILS<><>
void	ft_pipe_cmd(t_exct *av, int *pip, char **env, t_detail *var);
void	ft_redirection_cmd(t_exct *av, int *pip, t_detail *var);
void	ft_modify_val_cd(t_list *av, char *val, char *arg);
void	ft_lstadd_back_exct(t_exct **lst, t_exct *new);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_var_init(t_detail *var);

//				REDIRECT && HERE_DOC
char    *ft_here_doc(t_exct *av, int i, int *pip);

//				EXECUTE CMD
void	ft_execute_last_one(char **av, int *pip, char **env, t_detail *var);
void	ft_execute_one_cmd(t_exct *av, int *pip, char **env, t_detail *var);
void	ft_cmd_execute(char **av, int *pip, char **env, t_detail *var);
void	ft_first_one(char **av, int *pip, char **env, t_detail *var);
char	*ft_search_cmd(char *first_path, char *av, int *pip);
void	ft_execute_cmd1(char **av, int *pip, char **env);
void	ft_execute_cmd2(char **av, int *pip, char **env);
char	*ft_search_path(char *av, char **env, int *pip);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_cmd_to_cmd(t_exct *hadik, char **array);
void	ft_execution(t_exct *hadik, char **array);
void	ft_cmd_loop(t_exct *hadik, char **env);
char	**ft_split(char const *s, char c);
void	ft_exit1(char *av, int *pip);
void	ft_close(int *pip);
void	ft_exit(int *pip);
//

//				ENVIRONEMENT SETTING
void	ft_modify_val(t_list *av, char *val, char *arg);
void	ft_name_env(t_list *n, char *env, int *a);
void	ft_delete_val(char	*val, t_list **av);
t_list	*ft_search_val(t_list *av, char *val);
void	create_var(t_list *av, char *arg);
void	ft_val_name(t_list *n, char *env);
char	**list_t_array(t_list *av);
// void	ft_add_val(char *val, t_list *av, char *var);
//

//				BUILT_INS
void	ft_builts_in(char *arr, t_exct *ex, t_list **av);
void	cd(char **arg, t_exct *a, t_list *av);
void	export(t_list *av, t_exct *lst);
void	unset(t_list **av, t_exct *lst);
void	echo(char **arg, char **opt);
void	env(t_list *av);


////////////				PARSING					\\\\\\\\\\\\

int check_syntax(char **line);
void	switch_content(char **s);
// int syntax_error(char *line);
// int	ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_strchr(const char *s, int c);
char	*ft_strtrim2(char *s1, char *set);
char *add_space(char *line);
// size_t	ft_strlen(char *s);
// char	**ft_split(const char *s, char c);

typedef struct s_type
{
	char *content;
	int numb;
	int len;
	struct s_type *next;
}	t_type;


// typedef struct s_cmd
// {
// 	char *cmdline;
// 	char *cmd;
// 	char **redirection;
// 	char **arg;
// 	char **option;
// 	struct s_cmd *next;
// } t_cmd;

typedef struct s_cmd
{
	char *cmdline;
	char **redirection;
	char **args;
	struct s_cmd *next;
} t_cmd;

typedef struct s_var
{
	int i;
	int newlen;
	int checker;
	int checker2;
	int checker3;
	t_list *envlist;
	t_list *var;
	char *hold;
} t_var;


t_type	*ft_typenew(char *content);
void	ft_typeadd_back(t_type **lst, t_type *new);
void fill_type(char *line, t_type **type);
void	ft_free(char **str);
// char	*ft_strdup(char *s1);
int red_check(t_type *type);
int check_error(t_type *type);
void	ft_typeclear(t_type **lst);
t_cmd *lexing(char **line, char **elements);
t_cmd *ft_newcmd(char *cmd);
t_cmd	*ft_lastcmd(t_cmd *cmd);
void ft_add_cmd_back(t_cmd **cmd, t_cmd *new);
size_t	countwords(const char *s, char c);
t_var *setup_to_expand(char **line, char **env);
void ft_expand(char **line, t_var *v);
char *get_variable(char *line, int *checker3);
t_list	*ft_set_env(char **env);
void	ft_val_name(t_list *n, char *env);
// void	ft_name_env(t_list *n, char *env);
t_list    *ft_search_var(t_list *av, char *target);
void hide_content(char **line, int c);
void hide_delimiter(char **line, int index, int x);
void edit_dollars(char **line, int i, int x, int count);
char *update_line(char *line, int i,char *hold);
char *add_var(char *line, t_list *var, char *hold, int i);
#endif



