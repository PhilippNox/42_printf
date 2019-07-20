/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_test_wchar_t.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:26:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 20:28:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "ft_printf.h"
#include <limits.h>

void test(int (*fun)(const char *format, ...))
{
	//fun("@moulitest: %#.1x", 2, 0);
	//fun("@moulitest: %#.1x", 1, 0);
	//fun("@moulitest: %#.1x", 0, 0);
	//fun("@moulitest: %#.0x", 0, 0);
	//fun("@moulitest: %#x", 0, 0);
	//fun("@moulitest: %#.0x", 1, 0);

	//fun("%s %s", NULL, "string");
	//fun("%.2s %s", NULL, "string");
	//fun("ooo %.o %.0o", 0, 0);
	//fun("test_x_127 %#.0o", 0);
	//fun("test_x_130 %.0o", 0);
	//fun("@moulitest: %.d %.0d", 0, 0);
	//fun("%.u, %.0u", 0, 0);

	//fun("{%05.*d}", 15, 42);
	//fun("{%05.*d}", -15, 42);

	//fun("%o", LONG_MIN);
	//fun("%O", LONG_MIN);
	//fun("%lo", LONG_MIN);

	//fun("%c", 130);
	//fun("%c", 200);

	//fun("%.p", 0);
	//fun("%.0p", 0);
	//fun("%.0p, %.p", 0, 0);

	//ft_putnbr(fun("%"));
	//fun("%");

	fun("%S", "米");
	fun("%S", (char *)L"米");

}

#include <wchar.h>
/*
typedef union u_wchar {
	wchar_t	tmp;
	char bit[4];
} t_wchar;

t_wchar tt;
tt.tmp = tmp[0];
tt.bit[0] ? ft_putchar(tt.bit[0]) : ft_putchar('0');
tt.bit[1] ? ft_putchar(tt.bit[1]) : ft_putchar('0');
tt.bit[2] ? ft_putchar(tt.bit[2]) : ft_putchar('0');
tt.bit[3] ? ft_putchar(tt.bit[3]) : ft_putchar('0');
return 0;
*/

// 248 	       0x11111000  0x11111000
// 			0x110_00011 0x10_111000

// https://www.fileformat.info/info/unicode/utf8.htm
// https://unicodelookup.com/#latin/2
// http://www.binaryconvert.com/

int unicode2utf8(unsigned int tmp)
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

int main (void)
{
	int out;
	//wchar_t tmp[] = L"a";
	//wchar_t tmp[] = L"ø";
	//wchar_t tmp[] = L"米";
	wchar_t tmp[] = L"𝛀";

	//ft_putnbr(tmp[0]); ft_putstr("\n");

	out = unicode2utf8(tmp[0]);
	ft_putstr("\n");
	ft_putnbr(out);


	return 0;
	test(&ft_printf);
	ft_putstr("\n");
	test(&printf);
}
