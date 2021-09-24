/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:08:40 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/24 19:35:28 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_file(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", 1);
		exit(0);
	}
	else if (access(argv[1], F_OK & R_OK) == -1)
	{
		ft_putstr_fd("The file doesn't exist or there's not read permission", 1);
		exit(0);
	}
}

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

char	**ft_get_path(char **envp)
{
	char	**path;

	while (!ft_strnstr(*envp, "PATH", ft_strlen(*envp)))
		envp++;
	printf("%s\n", *envp);
	*envp = ft_strchr(*envp, '/'); // me muevo hasta que encuentro el salto de línea
	/*if (!(*envp))//si falla strchr
	{
		ft_putstr_fd("Couldn't find /", 1);
		exit(0);
	}*/
	path = ft_split(*envp, ':');
	if (!path)// si falla split
	{
		ft_putstr_fd("Split failed\n", 1);
		exit(0);
	}
	return (path);
}

t_list	*ft_lstnew_cmd(char *path, char **cmd_arg)
{
	t_list	*new;
	t_cmd	*c;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	c = malloc(sizeof(t_cmd));
	if (!c)
		return (NULL);
	c->path = path;
	c->cmd_arg = cmd_arg;
	new->content = (struct s_cmd *) c;
	new->next = NULL;
	return (new);
}


void	init_t_data(t_data *d, int argc, char **argv, char **envp)
{
	int		i;
	int		j;
	char	**path; //leaksss
	char	*path_cmd;
	char	*path_aux;
	char	**cmd_arg;
	t_list	*l;

	d->fd_in = open(argv[1], O_WRONLY); //cerrar
	//derechos del archivo cuando lo creamos??
	d->fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, S_IWUSR);
	if (d->fd_out == -1)
	{
		ft_putstr_fd("Error opening outfile\n",1);
		exit(0);
	}
	d->data = NULL;
	path = ft_get_path(envp);
	i = 2;
	while (i >= 2 && i <= argc - 2)
	{
		j = 0;
		cmd_arg = ft_split(argv[i], ' ');
		while (path[j])
		{
			path_aux = ft_strjoin(path[j], "/");
			path_cmd = ft_strjoin(path_aux, cmd_arg[0]);
			printf("ss %s\n", path_cmd);
			if (access(path_cmd, F_OK) != -1)
			{
				printf("gola\n");
				ft_lstadd_back(&l, ft_lstnew_cmd(path_cmd, cmd_arg));
				break ;
			}
			j++;
			free(path_cmd);
			free(path_aux);
		}
		if (!path[j])
		{
			ft_putstr_fd("Couldn't access any path\n", 1);
			free(path);
			exit(0);
		}
		free(cmd_arg);
		i++;
	}

}

//char **newa = ft_split("whereis ls -la", ' ');
	//int r = execve("/usr/bin/whereis", newa, envp);
	//printf("r %d\n", r);
	//printf("%s,  %s,  %s,  %s, %s\n", envp[10], envp[11], envp[12], envp[13], envp[14]);
	
void	leak(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;

	//atexit(leak);
	//printf("%s,  %s,  %s,  %s, %s\n", envp[10], envp[11], envp[12], envp[13], envp[14]);
	ft_check_file(argc, argv);
	init_t_data(&d, argc, argv, envp);
	//ft_exec_cmd();
	return (0);
}
