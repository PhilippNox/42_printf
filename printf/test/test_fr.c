/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/07 22:16:09 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _fr_ %f

#include "tests.h"
	#include "ft_printf.h"

typedef	struct s_roundnig
{
	double	d;
	int			pr;
	char *why;
	char *check;
} t_roundnig;

void test_fr(int (*fun)(const char *format, ...))
{
	int idx;
	int idxtop;
	t_str_f target;
	t_roundnig tab[100];

	idxtop = 0;
	tab[idxtop].d = 3.03125;
	tab[idxtop].pr = 10;
	tab[idxtop].why = "precision more then digits";
	tab[idxtop++].check = "3.0312500000";

	tab[idxtop].d = 3.0001;
	tab[idxtop].pr = 1;
	tab[idxtop].why = "in zero bridge";
	tab[idxtop++].check = "3.0";

	tab[idxtop].d = 3.0001;
	tab[idxtop].pr = 2;
	tab[idxtop].why = "in zero bridge";
	tab[idxtop++].check = "3.00";

	tab[idxtop].d = 3.0001;
	tab[idxtop].pr = 3;
	tab[idxtop].why = "less then 5";
	tab[idxtop++].check = "3.000";

	tab[idxtop].d = 3.0005;
	tab[idxtop].pr = 3;
	tab[idxtop].why = "up cause more then 5:";
	tab[idxtop++].check = "3.001";

	tab[idxtop].d = 3.03125;
	tab[idxtop].pr = 5;
	tab[idxtop].why = "precision more then digits ";
	tab[idxtop++].check = "3.03125";

	tab[idxtop].d = 3.03125;
	tab[idxtop].pr = 4;
	tab[idxtop].why = "equial to 5 and !%2:";
	tab[idxtop++].check = "3.0312";

	tab[idxtop].d = 3.09375;
	tab[idxtop].pr = 4;
	tab[idxtop].why = "equial to 5 and !%2:";
	tab[idxtop++].check = "3.0938";

	tab[idxtop].d = 3.99999;
	tab[idxtop].pr = 4;
	tab[idxtop].why = "up cause more then 5:";
	tab[idxtop++].check = "4.0000";

	tab[idxtop].d = 3.09999;
	tab[idxtop].pr = 4;
	tab[idxtop].why = "up cause more then 5:";
	tab[idxtop++].check = "3.1000";

	tab[idxtop].d = 3;
	tab[idxtop].pr = 4;
	tab[idxtop].why = "precision more then digits";
	tab[idxtop++].check = "3.0000";

	idx = -1;
	while (++idx < idxtop)
	{
		get_precision_d(&target, tab[idx].d);
		print_t_str_f_human(&target);
		//print_t_str_f(&target);
		t_str_f_round(&target, tab[idx].pr);
		if (DEBUG_ROUNDING)
			print_t_str_f_human(&target);
		//print_t_str_f(&target);
		ft_putstr("CHECK:\n[\n\t");
		t_str_f_print_full_simple(&target, tab[idx].pr);
		ft_putstr("\n\t");
		ft_putstr(tab[idx].check);
		ft_putstr("\n]\n");
		ft_putstr("\n\n");
	}






return ;
//int idx;
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
		2.0625,
		3.03125,
		4.09375,
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
		//print_t_str_f_human(&target);
		print_t_str_f(&target);
		//t_str_f_round(&target, 3);
		//t_str_f_round(&target, 4);
		//t_str_f_round(&target, 1);
		//t_str_f_round(&target, 0);
		//print_t_str_f(&target);
		//t_str_f_round(&target, 2);
		//print_t_str_f(&target);
		//print_t_str_f_human(&target);
		ft_putstr("\n\n");
	}
	idx = -1;
	while (num[++idx] != stop_num)
	{
		idxn = -1;
		while (str[++idxn])
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %f); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
