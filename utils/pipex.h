/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 09:28:07 by sslaoui           #+#    #+#             */
/*   Updated: 2024/07/25 01:19:53 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// void	ft_cmd_to_cmd(char **hadik, char **array);
// void	ft_cmd_loop(char **hadik, char **env);
// void	ft_execute_last_one(char **av, int *pip, char **env, t_detail *var);
// void	ft_execute_one_cmd(char *av, int *pip, char **env);
// void	ft_first_one(char *av, int *pip, char **env);
// void	ft_cmd_execute(char **av, int *pip, char **env);
void	ft_execute_cmd1(char **av, int *pip, char **env);
void	ft_execute_cmd2(char **av, int *pip, char **env);
char	*ft_search_path(char *av, char **env, int *pip);
char	*ft_search_cmd(char *first_path, char *av, int *pip);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_exit1(char *av, int *pip);
void	ft_exit(int *pip);
void	ft_close(int *pip);

#endif