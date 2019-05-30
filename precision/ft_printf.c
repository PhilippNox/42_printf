/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/30 17:17:23 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

// cd /Users/wgorold/d04_printf_gitlab/precision && clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c && ./a.out

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c ft_make_c.c ft_printf_helper.c ft_printf_task.c ft_make_s.c  && ./a.out
// sh z_check.sh -d


// man 3 stdarg
// va_list ap, ap2;
// https://ru.wikipedia.org/wiki/Printf
// https://en.wikipedia.org/wiki/Printf_format_string

// if (*start > 48 && *start < 58)
	//int val = ft_atoi(start, &add_total); ft_putstr("\nval = "); ft_putnbr(val);ft_putstr("\nadd_total = "); ft_putnbr(add_total);ft_putstr("\n");


// TODO pasring value .a -> 0

int	ft_printf(const char *format, ...)
{
	va_list ap;
	//char *s;
	int idx;
	int total;
	t_task task;

	if (!format)
		return (0);
	va_start(ap, format);
	total = 0;
	idx = 0;
	while (*(format + idx))
	{
		if (*(format + idx) != '%')
		{
			idx += ft_pututf8(format + idx);
			total += 1;
			continue;
		}
		init_task(&task);
		idx += set_task(&task, (char *)format + idx + 1, &ap) + 1;
		//print_task(&task);
		total += make_task(&task, &ap);
	}
	va_end(ap);
	return (total);
}

void test_c()
{
	char *str;

	str = "test_c_0 🦑 [%+#- 0*.78Lc]ok👈\n";
	ft_printf(str, 10, 'A');
	printf(str, 10, 'A');

	str = "test_c_1 🦑 [%+# 0*.78Lc]ok👈\n";
	ft_printf(str, 10, 'A');
	printf(str, 10, 'A');

	str = "test_c_2 🦑 [%+# *.78Lc]ok👈\n";
	ft_printf(str, 10, 'A');
	printf(str, 10, 'A');

	str = "test_c_3 🦑 [%+# *.78Lc]ok👈\n";
	ft_printf(str, 0, 'A');
	printf(str, 0, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_c_4 🦑 [%+# *.7Lc]ok👈\n";
	ft_printf(str, -10, 'A');
	printf(str, -10, 'A');

	str = "test_c_5 🦑 [%+# *.7Lc]ok👈\n";
	ft_printf(str, 2, 'A');
	printf(str, 2, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_c_6 🦑 [%+# *.-7Lc]ok👈\n";
	ft_printf(str, 2, 'A');
	printf(str, 2, 'A');
	ft_putstr("ok_end");
}

void test_s(char with_ft)
{
	char *str;
	char *test;

	str = "test_s_0 ok [%s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_1 ok [%.s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_2 ok [%.-5s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_3 ok [%.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_4 ok [%6.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_5 ok [%-6.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_6 ok [%06.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_7 ok [%-06.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_8 ok [%#06.3s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, test);
	printf(str, test);

	str = "test_s_9 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 3, 4, test);
	printf(str, 3, 4, test);

	str = "test_s_10 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 4, 3, test);
	printf(str, 4, 3, test);

	str = "test_s_11 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, -4, 3, test);
	printf(str, -4, 3, test);

	str = "test_s_12 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 4, -3, test);
	printf(str, 4, -3, test);

	str = "test_s_13 ok [%*.+s] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 4, test);
	printf(str, 4, test);

	return ;
	str = "test_s_14 ok [%+#- 0*.Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 10, test);
	printf(str, 10, test);

	str = "test_s_15 ok [%+#- 0*.78Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 10, test);
	printf(str, 10, test);

	str = "test_s_16 ok [%+# 0*.78Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 10, test);
	printf(str, 10, test);

	str = "test_s_17 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 10, test);
	printf(str, 10, test);

	str = "test_s_18 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 0, test);
	printf(str, 0, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_s_4 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, -10, test);
	printf(str, -10, test);

	str = "test_s_5 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 2, test);
	printf(str, 2, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_s_6 ok [%+# *.-7Ls] T_T 123\n";
	test = "abcdef";
	if (with_ft)
		ft_printf(str, 2, test);
	printf(str, 2, test);
	ft_putstr("ok_end");
}

int main ()
{
	//ft_putnbr(ft_printf("8 🦑 ok👈\n"));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 010d]ok👈\n"));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*d]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78d]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.*d]ok👈\n", 10, 42));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78hhd]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78Lg]ok👈\n", 10));
	//ft_putnbr(ft_printf("11 🦑 [%+#- 0*.78Lc]ok👈\n", 10, 'A'));
	//test_c();
	test_s(1);
	ft_putstr("\n");
}
