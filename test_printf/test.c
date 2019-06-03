/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 20:09:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/03 15:43:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


// cd /Users/wgorold/d04_printf_gitlab/test_printf
// clear && gcc -Wall -Wextra test.c && ./a.out

// https://ru.wikipedia.org/wiki/Printf

// https://en.wikipedia.org/wiki/Printf_format_string

void simple_hh()
{
	int test;

	test = 65800; // 2**16 + 2**8 + 8

	printf("%%d= %d\n", test);
	printf("%%hhd= %hhd\n", test);
	printf("%%hd= %hd\n", test);
}

void simple_f()
{
	float test;

	test = 10.009;
	printf("test = 10.009\n");
	printf("%%f   = %f\n", test);
	printf("%%.1f = %.1f\n", test);
	printf("%%.f  = %.f\n", test);
	printf("%%.20f= %.20f\n", test);
	printf("%%.31f= %.31f\n", test);

	test = 0.004158;
	printf("\n\ntest = 0.004158\n");
	printf("%%f   = %f\n", test);
	printf("%%.1f = %.1f\n", test);
	printf("%%.f  = %.f\n", test);
	printf("%%.20f= %.20f\n", test);
	printf("%%.31f= %.31f\n", test);

	test = 1.4148941E36;
	printf("\n\ntest = 1.4148941E36\n");
	printf("%%f   = %f\n", test);
	printf("%%.1f = %.1f\n", test);
	printf("%%.f  = %.f\n", test);
	printf("%%.20f= %.20f\n", test);
	printf("%%.31f= %.31f\n", test);
}

void simple_e()
{
	float test;

	test = 10.009;
	printf("test = 10.009\n");
	printf("%%e   = %e\n", test);
	printf("%%.1e = %.1e\n", test);
	printf("%%.e  = %.e\n", test);
	printf("%%.20e= %.20e\n", test);
	printf("%%.31e= %.31e\n", test);

	test = 0.004158;
	printf("\n\ntest = 0.004158\n");
	printf("%%e   = %e\n", test);
	printf("%%.1e = %.1e\n", test);
	printf("%%.e  = %.e\n", test);
	printf("%%.20e= %.20e\n", test);
	printf("%%.31e= %.31e\n", test);

	test = 1.4148941E36;
	printf("\n\ntest = 1.4148941E36\n");
	printf("%%e   = %e\n", test);
	printf("%%.1e = %.1e\n", test);
	printf("%%.e  = %.e\n", test);
	printf("%%.20e= %.20e\n", test);
	printf("%%.31e= %.31e\n", test);
}

int	main(void)
{
	// simple_hh();
	// simple_f();
	simple_e();
}
