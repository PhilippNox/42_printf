/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:26:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 15:58:30 by wgorold          ###   ########.fr       */
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
	fun("%.p", 0);
	fun("%.0p", 0);
}


int main (void)
{
	test(&ft_printf);
	ft_putstr("\n");
	test(&printf);
}
