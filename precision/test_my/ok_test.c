/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 00:26:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 01:44:16 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "longd.h"

void test(int (*fun)(const char *format, ...))
{
	//fun("@moulitest: %#.1x", 2, 0);
	//fun("@moulitest: %#.1x", 1, 0);
	//fun("@moulitest: %#.1x", 0, 0);
	//fun("@moulitest: %#.0x", 0, 0);
	//fun("@moulitest: %#x", 0, 0);
	//fun("@moulitest: %#.0x", 1, 0);

	fun("%s %s", NULL, "string");
	fun("%.2s %s", NULL, "string");
}


int main (void)
{
	test(&ft_printf);
	ft_putstr("\n");
	test(&printf);
}
