/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_s_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 16:02:24 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: s] _s_ %s

#include "tests.h"

void test_s_small(int (*fun)(const char *format, ...))
{
	char *str;
	char *test;

	str = "test_s_00 ok [%s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_01 ok [%s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_02 ok [%.-5s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_03 ok [%.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_04 ok [%6.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_05 ok [%-6.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_06 ok [%06.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_07 ok [%-06.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_08 ok [%#06.3s] T_T 123\n";
	test = "abcdef";
	fun(str, test);

	str = "test_s_09 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	fun(str, 3, 4, test);

	str = "test_s_010 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	fun(str, 4, 3, test);

	str = "test_s_011 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	fun(str, -4, 3, test);

	str = "test_s_012 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	fun(str, 4, -3, test);

	str = "test_s_012.1 ok [%*.-3s] T_T 123\n";
	test = "abcdef";
	fun(str, 4, test);

	str = "test_s_013 ok [%*.+s] T_T 123\n";
	test = "abcdef";
	fun(str, 4, test);

	str = "test_s_014 ok [%+#- 0*.Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 10, test);

	str = "test_s_015 ok [%+#- 0*.78Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 10, test);

	str = "test_s_016 ok [%+# 0*.78Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 10, test);

	str = "test_s_017 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 10, test);

	str = "test_s_018 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 0, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_s_019 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	fun(str, -10, test);

	str = "test_s_020 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 2, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_s_021 ok [%+# *.-7Ls] T_T 123\n";
	test = "abcdef";
	fun(str, 2, test);
}
