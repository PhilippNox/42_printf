/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 03:21:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/07/17 12:03:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"
#include <stdio.h>
#include <locale.h>

// gcc -Wall -Wextra -Werror test.c -L. -lftprintf && ./a.out

void test(int (*fun)(const char *format, ...))
{
	printf("\nout=%d\n", fun("%.f|%.f|%.f|%.f|%.f", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52));
	//printf("%d\n", fun("%.f|%.f|%.f|%.f|%.f", 44.5, 44.4, 44.6, 44.50001, 44.5 + 1e-52));
	//printf("%d\n", fun("%15.f|%15.1f|%15.2f|%15.5f|%15.12f", 999.99999, 999.99999, 999.99999, 999.99999, 999.99999));
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
