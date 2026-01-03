/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:49:23 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/03 23:05:13 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phexa(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_phexa(nb / 16);
		count += ft_phexa(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			count += ft_pchar(nb + '0');
		}
		else
		{
			count += ft_pchar(nb + 'W');
		}
	}
	return (count);
}
