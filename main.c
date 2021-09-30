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
		error(NULL, "Not enough arguments\n");
	else if (access(argv[1], F_OK & R_OK) == -1)
		error(NULL, "The file doesn't exist or there's not read permissions");
}

char	**ft_get_path(t_data *d, char **envp)
{
	char	**path;

	while (!ft_strnstr(*envp, "PATH", ft_strlen(*envp)))
		envp++;
	*envp = ft_strchr(*envp, '/');
	if (!(*envp))
		error(d, "Couldn't find /");
	path = ft_split(*envp, ':');
	if (!path)
	{
		free(path);
		error(d, "Split failed\n");
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
	{
		free(new);
		return (NULL);
	}
	c->path = path;
	c->cmd_arg = cmd_arg;
	new->content = (struct s_cmd *)c;
	new->next = NULL;
	return (new);
}

void	init_t_data(t_data *d, int argc, char **argv, char **path)
{
	int		i;
	int		j;
	char	*path_cmd;
	char	*path_aux;
	char	**cmd_arg;

	d->data = NULL;
	i = 1;
	while (++i <= argc - 2)
	{
		j = -1;
		cmd_arg = ft_split(argv[i], ' ');
		if (!cmd_arg)
			error(d, "Split failed\n");
		while (path[++j])
		{
			path_aux = ft_strjoin(path[j], "/");
			path_cmd = ft_strjoin(path_aux, *cmd_arg);
			if (!path_cmd)
			{
				free(cmd_arg);
				error(d, "Strjoin failed\n");
			}
			if (access(path_cmd, F_OK) != -1)
			{
				ft_lstadd_front(&d->data, ft_lstnew_cmd(path_cmd, cmd_arg));
				break ;
			}
			free(path_aux);
			free(path_cmd);
		}
		if (!path[j])
			error(d, "Couldn't access any path\n");
	}
}
	
void	leak(void)
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;
	char		**path;

	//atexit(leak);
	ft_check_file(argc, argv);
	d.argc = argc;
	d.fd_in = open(argv[1], O_WRONLY); //cerrar //derechos del archivo cuando lo creamos??
	d.fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666); //¿Cuales son estos derechos?
	if (d.fd_out == -1)
		error(&d, "Error opening outfile");
	path = ft_get_path(&d, envp);
	init_t_data(&d, argc, argv, path);
	pipex(&d, d.data , envp);
	//limpiar
	return (0);
}
