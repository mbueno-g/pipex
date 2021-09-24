/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 15:30:02 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/17 16:36:49 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Description: locates the last occurrence of c
 * (converted to a char) in the string pointed to
 * by s. The terminating null character is considered
 * to be part of the string; therefore if c is `\0',
 * the functions locate the terminating `\0'.
 * Return: pointer to the located character or
 * NULL if it doesn't appear in the string
*/

char	*ft_strrchr(const char *s, int c)
{
	int	n;

	n = ft_strlen((char *)s);
	s = s + n;
	if (c == '\0')
		return ((char *)s);
	while (n-- >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
