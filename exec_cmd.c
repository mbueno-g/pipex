/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 12:14:06 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/24 13:34:25 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	*get_cmd(t_list *l)
{
	return ((t_cmd *)l->content);
}

void	child_process(int fd[2])
{
	close(fd[READ_END]);
	dup2(fd[WRITE_END], STDOUT); //checkear errores
	close(fd[WRITE_END]);
}

void	parent_process(t_data *d, int fd[2], t_list *current)
{
	close(fd[WRITE_END]);
	if (d->data == ft_lstlast(d->data)) //primer cmd
		dup2(d->fd_in, STDIN);
	else
		dup2(fd[READ_END], STDIN);
	if (current == d->data)
		dup2(d->fd_out, STDOUT);
	close(fd[READ_END]);
}

void	pipex(t_data *d, t_list *current, char **envp)
{
	int fd[2];
	pid_t pid;
	t_list	*prev_cmd;

	pipe(fd);
	prev_cmd = current->next;
	pid = 1;
	if (prev_cmd != NULL)
	{
		pid = fork();
	}
	if (pid < 0)
		error(d, "Fork error\n");
	else if (pid == 0) //hijo
	{
		child_process(fd);
		pipex(d, prev_cmd, envp); //eliminar todo despues de cada proceso??
	}
	else if (pid > 0) //padre
	{
		waitpid(pid, NULL, 0);
		parent_process(d, fd, current);
		execve(get_cmd(current)->path, get_cmd(current)->cmd_arg, envp);
	}
	//limpiar
}
