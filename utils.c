/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 11:00:06 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/01 19:53:09 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	ft_free_matrix(char ***matrix)
{
	int	pos;

	pos = 0;
	while (matrix[0][pos])
	{
		free(matrix[0][pos]);
		pos++;
	}
	free(matrix[0]);
}

void	free_pipex(void *content)
{
	t_cmd	*aux;

	aux = (struct s_cmd *)content;
	free(aux->path);
	ft_free_matrix(&aux->cmd_arg);
	free(aux);
}

void	error(t_data *d, char *message)
{
	if (message != NULL)
		ft_putendl_fd(message, 1);
	if (d)
	{
		write(1, "jdf", 3);
		close(d->fd_in);
		close(d->fd_out);
		ft_lstclear(&d->data, free_pipex);
	}
	while (1);	
	exit(0);
}
