/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 19:26:42 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _fr_ %f

#include "tests.h"
	#include "longd.h"

void test_fr(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_fr_1 ok [%f]",
		"test_fr_2 ok [%.5f]",
		"test_fr_3 ok [%.4f]",
		"test_fr_4 ok [%.3f]",
		"test_fr_5 ok [%.2f]",
		"test_fr_6 ok [%.1f]",
		"test_fr_7 ok [%.0f]",
		NULL
	};

	float stop_num = -42;
	float num[] = {
		//2.0625,
		//3.03125,
		//4.09375,
		//4.4,
		//4.6,
		//5.4,
		//5.6,
		//4.99999,
		4.00001,

		stop_num,
		2.4,	//2
		2.49,	//2
		2.5,	//2
		2.51,	//3
		2.6,	//3
		3.4,	//3
		3.49,	//3
		3.5,	//4
		3.51,	//4
		3.6,	//4
		stop_num
	};


	idx = -1;
	while (num[++idx] != stop_num)
	{
		t_str_f target;
		get_precision_d(&target, (double)num[idx]);
		//print_t_str_f(&target);
		//t_str_f_round(&target, 3);
		//t_str_f_round(&target, 4);
		//t_str_f_round(&target, 1);
		//t_str_f_round(&target, 0);
		print_t_str_f(&target);
		t_str_f_round(&target, 2);
		//print_t_str_f(&target);
		print_t_str_f_human(&target);
		ft_putstr("\n\n");
	}
	return ;

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
