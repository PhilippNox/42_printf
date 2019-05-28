/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 01:56:13 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

int	ft_pututf8(char const *s)
{
	int idx;

	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;

	write(1, s, idx);
	return (idx);
}

int	ft_putchar(int c)
{
	return (ft_pututf8((char *)&c));
}

int	ft_putstr(char const *s)
{
	int idx;
	int printed;

	if (!s)
		return (0);

	printed = 0;
	idx = 0;
	while (*(s + idx))
	{
		idx += ft_pututf8(s + idx);
		printed++;
	}
	return (printed);
}

static void	ft_putnbr_rec(int n, char is_neg)
{
	if (n == 0)
	{
		if (is_neg)
			ft_putchar('-');
		return ;
	}
	ft_putnbr_rec(n / 10, is_neg);
	if (is_neg)
		ft_putchar(-(n % 10) + 48);
	else
		ft_putchar(n % 10 + 48);
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
	ft_putchar(n % 10 + 48);
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
