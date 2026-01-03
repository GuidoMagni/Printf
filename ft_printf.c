/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:51:16 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/03 23:13:19 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_symbol(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count = ft_pint(va_arg(args, int ));
	else if (c == 'c')
		count = ft_pchar(va_arg(args, int ));
	else if (c == 's')
		count = ft_pstring(va_arg(args, char *));
	else if (c == 'u')
		count = ft_pu(va_arg(args, unsigned int ));
	else if (c == 'x')
		count = ft_phexa(va_arg(args, unsigned int ));
	else if (c == 'X')
		count = ft_pheXa(va_arg(args, unsigned int ));
	//else if (c == 'p')
	//	count = ft_pptr(va_arg(args, int ));
	else if (c == '%')
		count = ft_pchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count += ft_symbol(s[i + 1], args);
			i += 2;
		}
		else
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	//char	*p = "stringa di prova";
	//char	c = 'a';
	//unsigned int	a = 9658739;
	unsigned int	b = 309866;
	int	c = 0;
	//void	*ptr = &b;

	c = ft_printf("%X\n", b);
	ft_printf("%d\n", c);
	b = printf("%X\n", b);
	printf("%d\n", b);
	return(0);
}

/*esadecimali devono controllare i valori negativi?*/