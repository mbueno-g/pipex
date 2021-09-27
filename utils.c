
#include "pipex.h"

void	ft_free_matrix(char ***matrix)
{
	int pos;

	pos = 0;
	while(matrix[0][pos])
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
	close(d->fd_in);
	close(d->fd_out);
	ft_lstclear(&d->data, free_pipex);
	ft_putstr_fd(message, 1);
	exit(0);
}
