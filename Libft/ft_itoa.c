/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:57:13 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/17 20:36:13 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int n)
{
	int	num;

	num = 1;
	while (n--)
		num = num * 10;
	return (num);
}

char	*ft_number(int len, long num, int i, char *str)
{
	int	n;

	n = len - 1;
	while (len--)
	{
		str[i++] = (num / ft_power(n)) + '0';
		num = num % ft_power(n);
		n--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_malloc(long num, int *len)
{
	char	*str;

	if (num < 0)
		str = malloc(*len + 2);
	else if (*len == 0)
	{
		*len = 1;
		str = malloc (*len + 1);
	}
	else
		str = malloc(*len + 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = 0;
	num = (long)n;
	while (n)
	{
		n = n / 10;
		len++;
	}
	str = ft_malloc(num, &len);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[i++] = '-';
		num = -num;
	}
	return (ft_number(len, num, i, str));
}
