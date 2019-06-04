/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 17:40:03 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_put.c  && ./a.out

#include "longd.h"

int	ft_utf8step(char const *s)
{
	int idx;

	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;
	return (idx);
}

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

int	ft_putstrn(char const *s, int len)
{
	int idx;
	int printed;

	if (!s)
		return (0);

	printed = 0;
	idx = 0;
	while (*(s + idx) && printed < len)
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

void	ft_baseitoa(char *out, unsigned long target, unsigned char base)
{
	char *code;
	char rev_out[21];
	unsigned long rest;
	unsigned long idx;

	if (base < 10)
	{
		out[0] = '0';
		out[1] = '\0';
		return ;
	}
	code = "0123456789abcdef";
	idx = 0;
	while ((rest = target / base) != 0)
	{
		rev_out[idx++] = code[target % base];
		target = rest;
	}
	rev_out[idx++] = code[target % base];
	rest = idx;
	while (idx > 0)
	{
		out[rest - idx] = rev_out[idx - 1];
		idx--;
	}
	out[rest] = '\0';
}

void	ft_baseitoasign(char *out, long target, unsigned char base)
{
	char *code;
	char rev_out[22];
	long rest;
	long idx;

	if (base < 10)
	{
		out[0] = '0';
		out[1] = '\0';
		return ;
	}
	code = "0123456789abcdef";
	idx = 0;
	while ((rest = target / base) != 0)
	{
		rev_out[idx++] = (target < 0) ? code[-(target % base)] : code[target % base];
		target = rest;
	}
	rev_out[idx++] = (target < 0) ? code[-(target % base)] : code[target % base];
	if (target < 0)
		rev_out[idx++] = '-';
	rest = idx;
	while (idx > 0)
	{
		out[rest - idx] = rev_out[idx - 1];
		idx--;
	}
	out[rest] = '\0';
}

/*
int main()
{
	char str[20];
	ft_baseitoa(str, 1000, 16);
	printf("%s\n", str);
	return (1);
}
*/
