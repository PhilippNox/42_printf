/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 01:46:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr_rec(int n, char is_neg)
{
	if (n == 0)
		return (is_neg) ? ft_putchar('-') : 0;
	ft_putnbr_rec(n / 10, is_neg);
	return (is_neg) ? ft_putchar(-(n % 10) + 48) : ft_putchar(n % 10 + 48);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putnbr_rec(n, 't');
	else if (n > 0)
		ft_putnbr_rec(n, '\0');
	else
		ft_putchar('0');
}

void	ft_putunbr(unsigned long n)
{
	if (n == 0)
		return ;
	ft_putunbr(n / 10);
	return ft_putchar(n % 10 + 48);
}

void	ft_putstr(char const *s)
{
	if (!s || !*s)
		return ;
	ft_putchar(*s);
	ft_putstr(s + 1);
}

void	print_arr(short *list, int size)
{
	int idx;

	idx = -1;
	ft_putstr("[ ");
	while (++idx < size)
	{
		ft_putnbr(list[idx]);
		ft_putstr(", ");
	}
	ft_putstr("]");
}
