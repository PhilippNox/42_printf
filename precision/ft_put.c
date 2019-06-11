/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 21:40:21 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_put.c  && ./a.out

#include "longd.h"

int unicodestep(wchar_t tmp)
{
	int out;

	if (tmp < 128)
		out = 1;
	else if (tmp < 2048)
		out = 2;
	else if (tmp < 65536)
		out = 3;
	else
		out = 4;
	return (out);
}

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
	return (UTF8COUNT) ? (printed) : idx;
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
		if (!UTF8COUNT)
			printed = idx;
	}
	return (printed);
}

int unicode2utf8(wchar_t tmp)
{
	int idx;
	char toPrint[5];

	idx = -1;
	while (++idx < 5)
		toPrint[idx] = 0;

	if (tmp < 128)
		toPrint[0] = tmp & 0x7F;
	else if (tmp < 2048)
	{
		toPrint[1] = 0x80 | (tmp & 0x3F);
		toPrint[0] = 0xC0 | ((tmp >> 6) & 0x1F);
	}
	else if (tmp < 65536)
	{
		toPrint[2] = 0x80 | (tmp & 0x3F);
		toPrint[1] = 0x80 | ((tmp >> 6) & 0x3F);
		toPrint[0] = 0xE0 | ((tmp >> 12) & 0xF);
	}
	else
	{
		toPrint[3] = 0x80 | (tmp & 0x3F);
		toPrint[2] = 0x80 | ((tmp >> 6) & 0x3F);
		toPrint[1] = 0x80 | ((tmp >> 12) & 0x3F);
		toPrint[0] = 0xF0 | ((tmp >> 18) & 0x7);
	}
	return (ft_putstr(toPrint));
}

int	ft_putunicode(wchar_t *s, int len)
{
	int idx;
	int printed;

	if (!s)
		return (0);

	printed = 0;
	idx = 0;
	while (*(s + idx) && printed < len)
	{
		printed += unicode2utf8(*(s + idx));
		++idx;
	}
	return (!UTF8COUNT) ? (printed) : idx;
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

void	ft_baseitoa(char *out, unsigned long long target, unsigned char base, char big)
{
	char *code;
	char rev_out[65];
	unsigned long long rest;
	unsigned long long idx;

	if (base < 2)
	{
		out[0] = '0';
		out[1] = '\0';
		return ;
	}
	code = "0123456789abcdef";
	if (big)
		code = "0123456789ABCDEF";
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

void	ft_baseitoasign(char *out, long long target, unsigned char base)
{
	char *code;
	char rev_out[65];
	long long rest;
	unsigned long long idx;

	if (base < 2)
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
	ft_baseitoa(str, 1000, 16, 0);
	printf("%s\n", str);
	return (1);
}
*/
