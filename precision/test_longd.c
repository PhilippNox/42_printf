/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_longd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:09:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/29 02:00:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"
#include <stdio.h>
#include <float.h>

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra -Werror ft_put.c 1_mat_precision_1.c 2_mat_precision_2.c test_longd.c && time ./a.out
// test_precision(); ./a.out  1.38s user 0.01s system 98% cpu 1.424 total

void test_power2form_pos()
{
	t_str_f tmp;

	power2form(&tmp, 0, 0);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 1, 0);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 2, 0);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 22, 0);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	init_t_str_f(&tmp);
	power2form(&tmp, 16, 0);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 22, 16);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
	print_t_str_f_human(&tmp);
	ft_putstr("\n\n");

	power2form(&tmp, 16383, 22);
	print_t_str_f(&tmp);
	ft_putstr("====\n");
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

void test_longdouble_old(long double input)
{
	t_longd tmp;
	short	power_tab[FRAC_FLOAT];
	t_str_f out;

	init_t_str_f(&out);
	tmp.ld = input;

	show_float(tmp);

	set_power_tab(power_tab, tmp.t_parts_ld.frac, (short)tmp.t_parts_ld.exp - 16383, 0x4000000000000000);

	get_fractionnaire(&out, power_tab);
	get_entiere(&out, power_tab);
	set_sign(&out, tmp.t_parts_ld.sign);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&out);
	printf("\ninput = %.15000Lg\n", input);
}

void test_longdouble(long double input)
{
	t_str_f output;

	get_precision_longd(&output, input);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f(&output);
	print_t_str_f_human(&output);
	printf("\ninput = %.999999Lg\n", input);
}

void test_longdouble_f(long double input)
{
	t_str_f output;

	get_precision_longd(&output, input);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f(&output);
	print_t_str_f_human(&output);
	printf("\ninput = %.16500Lf\n", input);
}

void test_precision_max()
{
	t_str_f output;

	get_precision_longd(&output, LDBL_MAX);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.9999Lg\n", LDBL_MAX);

	get_precision_d(&output, DBL_MAX);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.310f\n", DBL_MAX);

	get_precision_f(&output, FLT_MAX);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.50f\n", FLT_MAX);
}

void test_precision_min()
{
	t_str_f output;

	get_precision_longd(&output, LDBL_MIN);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.99999Lg\n", LDBL_MIN);

	get_precision_d(&output, DBL_MIN);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.99999g\n", DBL_MIN);

	get_precision_f(&output, FLT_MIN);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.99999g\n", FLT_MIN);
}

void test_precision()
{
	t_str_f output;
	long double ld;
	double d;
	float f;

	ld = LDBL_MIN;
	d = 2.2134;
	f = 2.2134;

	get_precision_longd(&output, ld);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.16500Lf\n", ld);

	get_precision_d(&output, d);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.310f\n", d);

	get_precision_f(&output, f);
	ft_putstr("\n\nfinal_= ");
	print_t_str_f_human(&output);
	printf("\ninput = %.100f\n", f);
}

int	main()
{

	//test_power2form_pos();
	//test_power2form_neg();
	//test_max_float_longdouble();
	//test_my_max_longdouble();
	//test_precision_max();
	//test_longdouble(LDBL_MAX);
	//test_longdouble(LDBL_MIN);
	//test_longdouble_f(LDBL_MIN);
	//test_longdouble_f(LDBL_MIN);
	test_precision_min();
	//test_longdouble(0.05);
	//test_longdouble(0.0029296875L);
	//test_longdouble(2.253);
	//test_precision();
}
