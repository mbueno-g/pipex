/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:14:40 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/19 16:39:17 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* locates the first occurrence of the null-terminated string 
 * needle in the string haystack, where not more than len 
 * characters are searched. Characters that appear after a `\0' 
 * character are not searched
 * Return: If needle is an empty string, haystack is returned; 
 * if needle occurs nowhere in haystack, NULL is returned; 
 * otherwise a pointer to the first character of the first 
 * occurrence of needle is returned.
*/

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[x] != '\0' && len && x < len)
	{
		y = 0;
		while (to_find[y] == str[x + y] && (x + y) < len && str[x + y] != '\0')
		{
			if (to_find[y + 1] == '\0')
				return ((char *) str + x);
			y++;
		}
		x++;
	}
	return (NULL);
}
