/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pheXa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:17:33 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/04 13:12:49 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phexa_upper(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_phexa_upper(nb / 16);
		count += ft_phexa_upper(nb % 16);
	}
	else
	{
		if (nb <= 9)
		{
			count += ft_pchar(nb + '0');
		}
		else
		{
			count += ft_pchar(nb + '7');
		}
	}
	return (count);
}
