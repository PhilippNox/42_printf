/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:26:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 21:39:09 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "longd.h"
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

	//wchar_t tmp[] = L"a";
	//wchar_t tmp[] = L"ø";
	//wchar_t tmp[] = L"米";
	//wchar_t tmp[] = L"𝛀";
	//fun("%S", L"米212𝛀");

	fun("%S", L"Α α");

}

int main (void)
{
	int out;
	//wchar_t tmp[] = L"米212𝛀";
	//wchar_t tmp[] = L"米";
	wchar_t tmp[] = L"Α α";

	ft_putnbr(length_unicode(tmp)); ft_putstr("\n");

	out = ft_putunicode(tmp, 20); ft_putstr("\t");
	ft_putnbr(out);ft_putstr("\n");

	return 0;
	test(&ft_printf);
	ft_putstr("\n");
	test(&printf);
	ft_putstr("\n");
}
