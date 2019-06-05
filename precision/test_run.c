/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 16:31:21 by wgorold          ###   ########.fr       */
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

	void (*tests2run[100]) (int (*fun)(const char *format, ...)) =
	{
		//&test_c_utf8,
		//&test_s_small,
		//&test_s,
		//&test_p,
		//&test_d_small,
		//&test_d,
		&test_i,
		NULL
	};

	int idx = -1;
	while (tests2run[++idx])
		tests2run[idx](&ft_printf);

	ft_putstr("next_origin_printf\n");

	idx = -1;
	while (tests2run[++idx])
		tests2run[idx](&printf);
}
