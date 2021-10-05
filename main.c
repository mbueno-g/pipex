/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:08:40 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/05 19:06:41 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	ft_check_file(int argc, char **argv)
{
	if (argc < 5)
		error(NULL, "Not enough arguments");
	else if (access(argv[1], F_OK | R_OK) == -1)
		error(NULL, "The file doesn't exist or there's not read permissions");
}

char	**ft_get_env_path(t_data *d, char **envp)
{
	char	**path;

	while (*envp && !ft_strnstr(*envp, "PATH", ft_strlen(*envp)))
		envp++;
	if (!(*envp))
		error(d, "Couldn't find PATH");
	*envp = ft_strchr(*envp, '/');
	if (!(*envp))
		error(d, "Couldn't find /");
	path = ft_split(*envp, ':');
	if (!path)
		error(d, "Split failed");
	return (path);
}

int	get_pathname(t_data *d, t_list **data, char *path, char **cmd_arg)
{
	char	*path_cmd;
	char	*path_aux;

	path_aux = ft_strjoin(path, "/");
	path_cmd = ft_strjoin(path_aux, *cmd_arg);
	if (!path_cmd)
	{
		free(cmd_arg);
		error(d, "Strjoin failed");
	}
	if (access(path_cmd, F_OK) != -1)
	{
		ft_lstadd_back(data, ft_lstnew_cmd(path_cmd, cmd_arg));
		free(path_aux);
		return (1);
	}
	free(path_aux);
	free(path_cmd);
	return (0);
}

void	init_t_data(t_data *d, int argc, char **argv, char **path)
{
	int		i;
	int		j;
	char	**cmd_arg;

	i = 1;
	while (++i <= argc - 2)
	{
		j = -1;
		cmd_arg = ft_split(argv[i], ' ');
		if (!cmd_arg)
			error(d, "Split failed");
		while (path[++j])
		{
			if (get_pathname(d, &d->data, path[j], cmd_arg))
				break ;
		}
		if (!path[j])
		{
			ft_free_matrix(&path);
			ft_free_matrix(&cmd_arg);
			error(d, "Couldn't access any path");
		}
	}
	ft_free_matrix(&path);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	d;
	char	**path;

	ft_check_file(argc, argv);
	d.data = NULL;
	d.argc = argc;
	d.fd_in = open(argv[1], O_RDONLY);
	d.fd_out = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (d.fd_out == -1)
		error(&d, "Error opening outfile");
	path = ft_get_env_path(&d, envp);
	init_t_data(&d, argc, argv, path);
	pipex(&d, d.data, envp);
	return (0);
}
