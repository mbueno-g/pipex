/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:46:30 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/01 15:02:31 by mbueno-g         ###   ########.fr       */
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
