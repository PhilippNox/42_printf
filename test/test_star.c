/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_star.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 02:57:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: d] _d_ %d

#include "tests.h"

void test_star(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	int idxs;
	char *str[] = {
		"test_star_0 ok [%05.*d]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-32768,
		-123,
		-1,
		0,
		1,
		123,
		32767,
		111778123,
		2147483647,
		stop_num
	};

	int stars[] = {
		-15,
		-1,
		0,
		1,
		15,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			idxs = -1;
			while (stars[++idxs] != stop_num)
			{
				fun(str[idx], stars[idxs], num[idxn]);
				//fun("\t\t\t\t//\tprintf(\"%s\", %d); // RUN THIS CODE FOR DEBUG", str[idx], num[idxn]);
				fun("\n");
			}
		}
	}
}
