/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 10:43:26 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/18 11:37:24 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Cuenta el numero de palabras en funcion de c*/
int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c)
			len++;
		if (!s[i] && s[i - 1] != c)
			return (len + 1);
	}
	return (len);
}

/*Calcula el len de la palabra y la guarda en str*/

char	*ft_word(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(i + 1);
	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* Libera toda la tabla si no hay espacio para alguna de las palabras*/
char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	 char	**tab;
	 int	j;

	j = 0;
	if (!s)
		return (NULL);
	tab = malloc (sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[j] = ft_word(s, c);
			if (!tab[j])
				return (ft_free(tab));
			while (*s && *s != c)
				s++;
			j++;
		}	
	}
	tab[j] = NULL;
	return (tab);
}
