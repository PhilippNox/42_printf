/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c_utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 14:52:10 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_c_utf8(int (*fun)(const char *format, ...))
{
	char *str;

	str = "test_c_0 🦑 [%+#- 0*.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_1 🦑 [%+# 0*.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_2 🦑 [%+# *.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_3 🦑 [%+# *.78Lc]ok👈\n";
	fun(str, 0, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_c_4 🦑 [%+# *.7Lc]ok👈\n";
	fun(str, -10, 'A');

	str = "test_c_5 🦑 [%+# *.7Lc]ok👈\n";
	fun(str, 2, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_c_6 🦑 [%+# *.-7Lc]ok👈\n";
	fun(str, 2, 'A');
}
