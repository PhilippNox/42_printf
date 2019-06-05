/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 14:56:47 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_p(int (*fun)(const char *format, ...))
{
	char *str;
	char *test;
	char *nul;
	int a;

	test = "abc";
	str = "test_p_0 [%p] ok\n";
	fun(str, test);

	test = "bc";
	str = "test_p_1 [%p] ok\n";
	fun(str, test);

	a = 20;
	str = "test_p_2 [%p] ok\n";
	fun(str, a);

	nul = NULL;
	str = "test_p_3 [%p] ok\n";
	fun(str, nul);

	test = "abc";
	str = "test_p_4 ok [%20.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_5 ok [%-20.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_6 ok [%020.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_7 ok [%0-20p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_8 ok [%.3p] T_T 123\n";
	fun(str, test);

	a = 20;
	test = "test_p_9 len = %d\n";
	str = "[%p]";
	printf(test, fun(str, a));


	a = 20;
	test = "test_p_10 len = %d\n";
	str = "[%20p]";
	printf(test, fun(str, a));
}
