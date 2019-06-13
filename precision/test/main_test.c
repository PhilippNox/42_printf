/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/13 16:11:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"
#include "tests.h"

// cd /Users/wgorold/d04_printf_gitlab/precision && clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c && ./a.out

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_atoi.c ft_put.c test_run.c ft_make_c.c ft_make_d.c ft_printf_helper.c ft_printf_task.c ft_make_s.c ft_make_p.c test_s_small.c test_s.c test_c_utf8.c test_d_small.c test_d.c test_p.c test_i.c && ./a.out
// sh z_check.sh -d


// man 3 stdarg
// va_list ap, ap2;
// https://ru.wikipedia.org/wiki/Printf
// https://en.wikipedia.org/wiki/Printf_format_string

// if (*start > 48 && *start < 58)
	//int val = ft_atoi(start, &add_total); ft_putstr("\nval = "); ft_putnbr(val);ft_putstr("\nadd_total = "); ft_putnbr(add_total);ft_putstr("\n");


// TODO pasring value .a -> 0

int main ()
{
	int idx;
	void (*tests2run[100]) (int (*fun)(const char *format, ...)) =
	{
		//&test_c, &test_cp,
		//&test_c_utf8, &test_s_small, &test_s, &test_p, &test_d_small, &test_d, &test_i,
		//&test_p,
		//&test_s,
		//&test_o,
		//&test_u,
		//&test_d,
		&test__, //weird
		//&test_x, &test_X,
		//&test_hhd, &test_hd, &test_ld, &test_lld,
		//&test_hhi, &test_hi, &test_li, &test_lli,
		//&test_hho, &test_ho, &test_lo, &test_llo,
		//&test_hhu, &test_hu, &test_lu, &test_llu,
		//&test_hhx, &test_hx, &test_lx, &test_llx,
		//&test_hhxx, &test_hxx, &test_lxx, &test_llxx,
		//&test_f,
		//&test_fs,
		//&test_f, &test_Lf,
		//&test_ff, &test_Lff,
		//&test_f,
		//&test_star,
		NULL
	};

	idx = -1;
	while (tests2run[++idx])
		tests2run[idx](&ft_printf);
	if (idx == 0)
		puts("no_tests");
	puts("next_origin_printf");

	idx = -1;
	while (tests2run[++idx])
		tests2run[idx](&printf);
	if (idx == 0)
		puts("no_tests");
}
