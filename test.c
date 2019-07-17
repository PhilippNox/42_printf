/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 03:21:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/07/17 18:30:00 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>

// gcc -Wall -Wextra -Werror test.c -I./ft_printf -L./ft_printf -lftprintf && ./a.out

void test(int (*fun)(const char *format, ...))
{
	//printf("\nout=%d\n", fun("%.1150f|%.1150f|%.1150f|%.1150f", 0x1p-1074, 0x1.ffffffffffffep-1023, 0x1.4e46p-1058, 0x1.59a8b0c3dp-1037));
	//printf("\nout=%d\n", fun("%f|%2147483649f", 1.0, 1.0));
	//printf("\nout=%d\n", fun("%.2147483649f|%2147483649f", 1.0, 1.0));
	//printf("\nout=%d\n", fun("%.1150f", 0x1p-1074));
	//fun("{%.*s}", -5, "42");
	//fun("{%05.*d}", -15, 42);
	printf("\nout=%d\n",fun("%f|%-f|%+f|% f|%#f|%0f", NAN, NAN, NAN, NAN, NAN, NAN));
}

int main (void)
{
	setlocale(LC_ALL, "");
	test(&ft_printf);
	printf("\n\n");
	test(&printf);
	//ft_putstr("\n"); write_boost(" ", 1);
	printf("\n");
}