/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 13:54:22 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/17 16:34:42 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Description: locates the first occurrence of c 
 * (converted to a char) in the string pointed to 
 * by s. The terminating null character is considered 
 * to be part of the string; therefore if c is `\0', 
 * the functions locate the terminating `\0'.
 * Return: pointer to the located character or
 * NULL if it doesn't appear in the string
*/

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		s = s + ft_strlen((char *)s);
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
