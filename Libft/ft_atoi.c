/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:28:17 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/16 09:36:41 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Converts the initial portion of the string pointed to by str
 * to int representation.  
*/

/* 	Probar a declarar num como long*/

int	ft_atoi(const char *str)
{
	int	i;
	int	cont;
	int	num;

	i = 0;
	cont = 1;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			cont = -cont;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * cont > 214748364 && str[i] - '0' > 7)
			return (-1);
		if (num * cont < -214748364 && str[i] - '0' >= 8)
			return (0);
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * cont);
}
