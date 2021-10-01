/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 10:41:04 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/01 19:53:11 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data *d, t_cmd *cmd, char **envp, int i)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error(d, "Pipe failed");
	pid = fork();
	printf("pid %d\n", pid);
	if (pid < 0)
	{
		close(STDIN);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		error(d, "Fork failed");
	}
	else if (pid == 0)
	{
		close(fd[READ_END]);
		if (dup2(fd[WRITE_END], STDOUT) == -1)
			error(d, "Dup2 failed");
		close(fd[WRITE_END]);
		if (i != d->argc - 2)
		{
			if (execve(cmd->path, cmd->cmd_arg, envp) == -1)
				error(d, "Execve failed");
		}
		else
		{
			if (dup2(d->fd_out, STDOUT) == -1)
				error(d, "Dup2 failed");
			close(d->fd_out);
			if (execve(cmd->path, cmd->cmd_arg, envp) == -1) //gestionar salida error
				error(d, "Execve failed");
		}
	}
	else
	{
		close(fd[WRITE_END]);
		if (dup2(fd[READ_END], STDIN) == -1)
			error(d, "Dup2 failed");
		close(fd[READ_END]);
		if (waitpid(pid, NULL, 0) == -1)
			error(d, "Waitpid failed");
	}
}

void	pipex(t_data *d, t_list *current, char **envp)
{
	int		i;
	t_cmd	*aux;

	i = 2;
	if (dup2(d->fd_in, STDIN) == -1)
		error(d, "Dup2 failed");
	while (i <= d->argc - 2)
	{
		aux = (t_cmd *)current->content;
		child_process(d, aux, envp, i);
		current = current->next;
		i++;
	}
	//close(STDIN);
	//close(d->fd_in);
	error(d, NULL);
}
