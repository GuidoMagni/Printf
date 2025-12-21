/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:51:16 by gumagni           #+#    #+#             */
/*   Updated: 2025/12/21 17:27:57 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, int a)
{
	int	i;

	i = 0;
	if (!s[i] || !a)
		return (0);
	while (s[i]) //invece di fare sto casino potresti usare putnbr fd da libft...
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'd')
			{
				ft_printint(a);
				i++;
			}
		}
		write(1, &s[i], 1);
		i++;
	}
	return (1);
}

int	main(void)
{
	//char	ar[] = "stringa di prova";
	//char	c = 'a';
	int		a = -143;

	ft_printf("%d\n", a);
	printf("%d\n", a);
	return(0);
}