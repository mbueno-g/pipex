/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:24:08 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/09 16:47:10 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Description: compare no more than n characters
 * characters that appear after a `\0' character are not compared
 * Return: integer greater than, equal to, or less than 0
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const char	*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	while (n-- && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
			return ((unsigned char) *str1 - (unsigned char) *str2);
		str1++;
		str2++;
	}
	return (0);
}
