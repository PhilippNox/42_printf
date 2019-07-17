/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 14:48:33 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_d_small(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_d_my_1 ok [% d]",
		"test_d_my_2 ok [%+ d]",
		"test_d_my_3 ok [%20 d]",
		"test_d_my_4 ok [%20 0 -+d]",
		"test_d_my_5 ok [%20 0 -d]",
		"test_d_my_6 ok [%20 d]",
		"test_d_my_7 ok [%20 +d]",
		"test_d_my_8 ok [%20 0+d]",
		"test_d_my_9 ok [%.5 0+d]",
		"test_d_my_10 ok [%.5 8d]",
		"test_d_my_11 ok [%20 0d]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-123,
		-1,
		0,
		1,
		123,
		111778123,
		2147483647,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %d); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
