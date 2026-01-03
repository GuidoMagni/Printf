/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:00:51 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/03 19:24:15 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	unsigned int	num;

	num = (unsigned int)n;
	len = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int	ft_pu(unsigned int a)
{
	int		i;
	char	*s;
	int	count;

	count = 0;
	i = 0;
	s = ft_itoa(a);
	while (s[i])
	{
		write(1, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}