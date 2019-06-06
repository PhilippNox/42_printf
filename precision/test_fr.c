/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 00:30:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _fr_ %f

#include "tests.h"

void test_fr(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_fr_3 ok [%.0f]",
		NULL
	};

	float stop_num = -42;
	float num[] = {
		//2.4,	//2
		//2.49,	//2
		//2.5,	//2
		2.51,	//3
stop_num,
		2.6,	//3
		3.4,	//3
		3.49,	//3
		3.5,	//4
		3.51,	//4
		3.6,	//4
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
