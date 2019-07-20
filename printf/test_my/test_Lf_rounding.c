/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Lf_rounding.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/08 01:29:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _fr_ %f

#include "tests.h"
#include "ft_printf.h"
#include <float.h>

typedef	struct s_roundnig
{
	long double	d;
	int			pr;
	char *why;
	char *check;
} t_roundnig;

void test_Lf_rounding(int (*fun)(const char *format, ...))
{
	int idx;
	int idxtop;
	t_str_f target;
	t_roundnig tab[100];

	idxtop = 0;
	tab[idxtop].d = LDBL_MIN;
	tab[idxtop].pr = 10;
	tab[idxtop].why = "precision more then digits";
	tab[idxtop++].check = "3.0312500000";

	tab[idxtop].d = 0;
	tab[idxtop].pr = 10;
	tab[idxtop].why = "precision more then digits";
	tab[idxtop++].check = "3.0312500000";

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
	while (++idx < 2)
	// while (++idx < idxtop)
	{
		get_precision_longd(&target, tab[idx].d);
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
}

int main (void)
{
		test_Lf_rounding(&ft_printf);
		//test_f_rounding(&printf);
}
