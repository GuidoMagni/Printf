/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:49:58 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/04 13:04:27 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_phexa_long(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_phexa_long(nb / 16);
		count += ft_phexa_long(nb % 16);
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

int	ft_pptr(void *ptr)
{
	int				count;
	unsigned long	addr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	addr = (unsigned long)ptr;
	count = write(1, "0x", 2);
	count += ft_phexa_long(addr);
	return (count);
}
