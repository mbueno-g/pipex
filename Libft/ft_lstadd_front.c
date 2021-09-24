/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:03:33 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/04/16 12:05:29 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Añadir el elementos new al principio de la lista
 * dadp la direccion al elemento que hay que poner al principio
 * y la dirección al primer elemento de la lista
*/

/* Linea 24: guardamos el elemento que estaba al principio de 
 * la lista en la posicion siguiente
 * Linea 25: el principio de la lista lo ocupamos con new */

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}
