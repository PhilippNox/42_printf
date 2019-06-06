/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 23:18:52 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _fs_ %f

#include "tests.h"

void test_fs(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_fs_0 ok [%.150f]",
		"test_fs_0.1 ok [%.100f]",
		"test_fs_0.2 ok [%.10f]",
		"test_fs_0.3 ok [%.14f]",
		"test_fs_1 ok [%f]",
		"test_fs_2 ok [%.1f]",
		"test_fs_3 ok [%.0f]",
		NULL
	};

	float stop_num = -42;
	float num[] = {
		FLT_MIN,
		FLT_MAX,
		FLT_EPSILON,
		0,
		1,
		-1,
		2,
		-2,
		0.2,
		-0.2,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %f); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
