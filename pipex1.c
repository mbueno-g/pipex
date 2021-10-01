/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:41:04 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/01 11:33:19 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_cmd *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid < 0)
	{
		printf("Error\n");
		exit(0);
	}
	else if (pid == 0)
	{
		close(fd[READ_END]);
		dup2(fd[WRITE_END], STDOUT);
		execve(cmd->path, cmd->cmd_arg, envp);
	}
	else
	{
		close(fd[WRITE_END]);
		dup2(fd[READ_END], STDIN);
		waitpid(pid, NULL, 0);
	}
}

void	pipex(t_data *d, t_list *current, char **envp)
{
	int		i;
	t_cmd	*aux;

	i = 2;
	dup2(d->fd_in, STDIN);
	while (i <= d->argc - 2)
	{
		aux = (t_cmd *)current->content;
		/*if (i == d->argc - 2)
		{
			dup2(d->fd_out, STDOUT);
			execve(aux->path, aux->cmd_arg, envp);
		}
		else*/
			child_process(aux, envp);
		current = current->next;
		i++;
	}
	error(d, NULL);
}
