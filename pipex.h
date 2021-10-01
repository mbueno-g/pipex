/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:40:43 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/01 19:05:30 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <unistd.h> //access
#include <fcntl.h> // open
#include <sys/wait.h> //waitpid

#define READ_END 0
#define WRITE_END 1
#define STDOUT 1
#define STDIN 0

typedef struct s_cmd
{
	char	*path;
	char	**cmd_arg;
}			t_cmd;

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	int		argc;
	t_list	*data;
}			t_data;

void	error(t_data *d, char *message);
void	ft_exec_cmd(t_data *d, t_list *current, char **envp);
void	pipex(t_data *d, t_list *current, char **envp);
void	ft_free_matrix(char ***matrix);
t_list	*ft_lstnew_cmd(char *path, char **cmd_arg);
