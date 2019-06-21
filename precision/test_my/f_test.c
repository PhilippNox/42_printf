/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:26:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/21 16:40:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
15360

14336

12288

8192

4096

after make tst
sh ./z_check.sh  3.35s user 0.08s system 97% cpu 3.516 total
*/


#include "tests.h"
#include "longd.h"
#include <limits.h>

#include <locale.h>
int main (void)
{
	t_str_f tmp;
	t_longd val;
	short	power_tab[FRAC_FLOAT];

	//get_precision_longd(&tmp, 16383);

	set_power_tab(power_tab, 0, 0, 0x4000000000000000);
	mat_for_precision(&tmp, power_tab, 0);


	print_t_str_f(&tmp);
	write_boost("\n", 0);
	print_t_str_f_human(&tmp);
	write_boost(NULL, 1);






}
