/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 03:21:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/07/20 13:28:41 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>

// make -C ./ft_printf && gcc -Wall -Wextra test.c -I./ft_printf -L./ft_printf -lftprintf && ./a.out

void test(int (*fun)(const char *format, ...))
{
	//printf("\nout=%d\n", fun("%.1150f", 0x1p-1074));
	fun("{%.*s}", -5, "42");
	//fun("%s", 3);
}

int main (void)
{
	setlocale(LC_ALL, "");
	test(&ft_printf);
	//printf("\n\n");
	test(&printf);
	ft_putstr("\n"); write_boost(" ", 1);
	printf("\n");
}
