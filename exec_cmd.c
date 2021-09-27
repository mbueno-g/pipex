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

/*void	ft_get_path_cmd(t_data *d, int argc, char **argv, char **envp)
{
	int	i;
	char *str;
	int	fd1[2];
	int pid;
	char **new;
	char lectura[50];
	int	status;
	int	len;


	i = 2;
	d->fd_in=0;
	while (i >= 2 && i <= argc - 2)
	{
		pipe(fd1);
		pid = fork();
		if (pid < 0) //error
			ft_putstr_fd("Fork error \n", 1);
		else if (pid == 0) //hijo1
		{
			close(fd1[0]); //cerrar lectura
			dup2(fd1[1], 1); //STDOUT
			close(fd1[1]);
			str = ft_strjoin("whereis ", argv[i]);
			new = ft_split(str, ' ');
			//d->data->cmd = ft_split(str, ' ');
			execve("/usr/bin/whereis", new, envp);
			//d->data->path = malloc(sizeof(char)* 50);
		}
		else //padre
		{
			waitpid(pid, &status, 0);
			read(fd1[0], lectura , 50);
			printf("path %s", lectura);
		}
		i++;
	}
}*/

t_cmd	*get_cont(t_list *l)
{
	return ((t_cmd *)l->content);
}


void	child_process(t_data *d, int i)
{
	if (i == 2)
	{
		close(pipe_fd[READ_END]);
		dup2(d->fd_in, STDIN);
		close(d->fd_n);
	}
}

void	ft_exec_cmd(t_data *d, char **envp)
{
	int i;
	int	pipe_fd[2];
	int	pid;
	int	status;
	char	lectura[1000];
	//t_list	*current;
	//char	*str;
	//char	**new;
	//t_cmd	*aux;

	//aux = (t_cmd *)d->data->content;
	//printf("aa %s\n", aux->path);
	//printf("aa %s\n", aux->cmd_arg[0]);
	i = 2;
	while(++i <= d->argc - 2)
	{
		//current = d->data;
		pipe(fd1);
		pid = fork();
		printf("pid %d\n", pid);
		if (pid < 0)
			error(d, "Fork failed\n");
		else if (pid == 0) //hijo1
		{
			if (i == 2)
				child_process(READ_END,);
			else if (i == argc - 2)
				child_process();
			else
				child_process();
			//printf("entra\n");
			//close(fd1[READ_END]);
			//dup2(d->fd_in, STDIN);
			//close(d->fd_in);
			//str = ft_strjoin("whereis ", "ls");
			//new = ft_split(str, ' ');
			//execve("/usr/bin/whereis", new, envp);
			//ft_putstr_fd(get_cont(d->data)->path, 1);
			//execve(get_cont(d->data)->path, get_cont(d->data)->cmd_arg, envp);
		}
		else //padre
		{
			//waitpid(pid, &status, 0);
			//close(fd1[WRITE_END]);
			//read(fd1[READ_END], lectura , 1000);
			//printf("helloo %s\n", lectura);
		}
	}
}
