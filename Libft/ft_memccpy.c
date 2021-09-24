/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:11:39 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/11 17:59:55 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Description: copies bytes from string src to string dst.
 * If the character c (as converted to an unsigned char) occurs 
 * in the string src, the copy stops and a pointer to the byte 
 * after the copy of c in the string dst is returned.
 * Otherwise, n bytes are copied, and a NULL pointer is returned
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	const char		*s;

	d = dst;
	s = src;
	while (n--)
	{
		*d = *s;
		if (*d == (unsigned char)c)
			return (++d);
		d++;
		s++;
	}
	return (NULL);
}
