/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_longd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:09:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/24 20:41:10 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"
#include <stdio.h>
#include <float.h>
// clear && gcc -Wall -Wextra -Werror ft_put.c t_longd.c mat_precision.c test_longd.c && ./a.out

void test_power2form_pos()
{
	t_str_f tmp;

	power2form(&tmp, 0, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 1, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 2, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 22, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 16, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 22, 16);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 16383, 22);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");
}

void test_power2form_neg()
{
	t_str_f tmp;

	power2form(&tmp, -1, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, -2, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, -8, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, -9, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	return ;
	init_t_str_f(&tmp);
	power2form(&tmp, -10, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, -4, 0);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, -10, -4);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, -16383, -10);
	print_t_str_f(&tmp);
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");
}

void test_max_float_longdouble()
{
	//	1.18×104932
	//	3.65×10−4951
	t_longd tmp;

	tmp.ld = LDBL_MAX;
	printf("FLT_MAX = %.99f\n", FLT_MAX);
	printf("\nLDBL_MAX = %.999999Lg\n", LDBL_MAX);
}

void test_longdouble(long double input)
{
	t_longd tmp;
	short	power_tab[FRAC_FLOAT];
	t_str_f ent;
	t_str_f frc;

	init_t_str_f(&ent);
	init_t_str_f(&frc);
	tmp.ld = input;

	show_float(tmp);

	set_power_tab(power_tab, tmp.t_parts.frac, (short)tmp.t_parts.exp - 16383);

	get_fractionnaire(&frc, power_tab);
	get_entiere(&ent, power_tab);
	get_final(&ent, &frc, tmp.t_parts.sign);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&ent);
	printf("\ninput = %.999999Lg\n", input);
}

int	main()
{

	//test_power2form_pos();
	//test_power2form_neg();
	//test_max_float_longdouble();
	//test_my_max_longdouble();
	//test_longdouble(LDBL_MAX);
	//test_longdouble(LDBL_MIN);
	test_longdouble(2.235);
}
