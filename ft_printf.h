/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumagni <gumagni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:02:19 by gumagni           #+#    #+#             */
/*   Updated: 2026/01/03 22:43:01 by gumagni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
#include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_pint(int a);
int		ft_pchar(char c);
int		ft_pstring(char *s);
int		ft_pu(unsigned int a);
int		ft_phexa(unsigned int nb);
int		ft_pheXa(unsigned int nb);
int		ft_pptr(void *ptr);

#endif //FT_PRINTF.H