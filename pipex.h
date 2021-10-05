/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:59:31 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/10/05 15:54:00 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define READ_END 0
# define WRITE_END 1
# define STDOUT 1
# define STDIN 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_cmd
{
	char	*path;
	char	**cmd_arg;
}			t_cmd;

typedef struct s_data
{
	int		fd_in;
	int		fd_out;
	int		argc;
	t_list	*data;
}			t_data;

void	error(t_data *d, char *message);
void	ft_exec_cmd(t_data *d, t_list *current, char **envp);
void	pipex(t_data *d, t_list *current, char **envp);
void	ft_free_matrix(char ***matrix);
t_list	*ft_lstnew_cmd(char *path, char **cmd_arg);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_lstsize(t_list *lst);

#endif
