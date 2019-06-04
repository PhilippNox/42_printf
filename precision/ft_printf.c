/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/04 21:13:05 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "longd.h"

// cd /Users/wgorold/d04_printf_gitlab/precision && clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c && ./a.out

// cd /Users/wgorold/d04_printf_gitlab/precision
// clear && gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c ft_make_c.c ft_make_d.c ft_printf_helper.c ft_printf_task.c ft_make_s.c ft_make_p.c  && ./a.out
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
	t_task *last;

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
		last = &task;
	}
	va_end(ap);
	//print_task(last);
	return (total);
}

void test_s(char with_ft)
{
	char *str;
	char *test;

	str = "test_s_00 ok [%s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_01 ok [%s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_02 ok [%.-5s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_03 ok [%.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_04 ok [%6.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_05 ok [%-6.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_06 ok [%06.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_07 ok [%-06.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_08 ok [%#06.3s] T_T 123\n";
	test = "abcdef";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	str = "test_s_09 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	printf(str, 3, 4, test);
	if (with_ft)
		ft_printf(str, 3, 4, test);

	str = "test_s_010 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	printf(str, 4, 3, test);
	if (with_ft)
		ft_printf(str, 4, 3, test);

	str = "test_s_011 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	printf(str, -4, 3, test);
	if (with_ft)
		ft_printf(str, -4, 3, test);

	str = "test_s_012 ok [%*.*s] T_T 123\n";
	test = "abcdef";
	printf(str, 4, -3, test);
	if (with_ft)
		ft_printf(str, 4, -3, test);

	str = "test_s_012.1 ok [%*.-3s] T_T 123\n";
	test = "abcdef";
	printf(str, 4, test);
	if (with_ft)
		ft_printf(str, 4, test);

	str = "test_s_013 ok [%*.+s] T_T 123\n";
	test = "abcdef";
	printf(str, 4, test);
	if (with_ft)
		ft_printf(str, 4, test);

	str = "test_s_014 ok [%+#- 0*.Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 10, test);
	if (with_ft)
		ft_printf(str, 10, test);

	str = "test_s_015 ok [%+#- 0*.78Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 10, test);
	if (with_ft)
		ft_printf(str, 10, test);

	str = "test_s_016 ok [%+# 0*.78Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 10, test);
	if (with_ft)
		ft_printf(str, 10, test);

	str = "test_s_017 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 10, test);
	if (with_ft)
		ft_printf(str, 10, test);

	str = "test_s_018 ok [%+# *.78Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 0, test);
	if (with_ft)
		ft_printf(str, 0, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_s_019 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	printf(str, -10, test);
	if (with_ft)
		ft_printf(str, -10, test);

	str = "test_s_020 ok [%+# *.7Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 2, test);
	if (with_ft)
		ft_printf(str, 2, test);

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_s_021 ok [%+# *.-7Ls] T_T 123\n";
	test = "abcdef";
	printf(str, 2, test);
	if (with_ft)
		ft_printf(str, 2, test);
	ft_putstr("ok_end");
}

void test_s2()
{
	char *str;
	char *test;

	str = "test_s_0 ok [%#0 -+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_1 ok [%0 -+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_2 ok [% -+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_3 ok [%-+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_4 ok [%+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_5 ok [%10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_6 ok [%.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_7 ok [%10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_8 ok [%+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_9 ok [%+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_10 ok [%+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_11 ok [%-10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_12 ok [%-.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_13 ok [%-s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_14 ok [%-10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_15 ok [%-+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_16 ok [%-+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_17 ok [%-+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_18 ok [% +10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_19 ok [% 10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_20 ok [% .4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_21 ok [% s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_22 ok [% 10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_23 ok [% +.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_24 ok [% +s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_25 ok [% +10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_26 ok [% -10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_27 ok [% -.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_28 ok [% -s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_29 ok [% -10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_30 ok [% -+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_31 ok [% -+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_32 ok [% -+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_33 ok [%0-+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_34 ok [%0+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_35 ok [%010.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_36 ok [%0.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_37 ok [%0s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_38 ok [%010s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_39 ok [%0+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_40 ok [%0+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_41 ok [%0+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_42 ok [%0-10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_43 ok [%0-.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_44 ok [%0-s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_45 ok [%0-10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_46 ok [%0-+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_47 ok [%0-+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_48 ok [%0-+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_49 ok [%0 +10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_50 ok [%0 10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_51 ok [%0 .4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_52 ok [%0 s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_53 ok [%0 10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_54 ok [%0 +.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_55 ok [%0 +s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_56 ok [%0 +10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_57 ok [%0 -10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_58 ok [%0 -.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_59 ok [%0 -s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_60 ok [%0 -10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_61 ok [%0 -+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_62 ok [%0 -+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_63 ok [%0 -+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_64 ok [%# -+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_65 ok [%#-+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_66 ok [%#+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_67 ok [%#10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_68 ok [%#.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_69 ok [%#s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_70 ok [%#10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_71 ok [%#+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_72 ok [%#+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_73 ok [%#+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_74 ok [%#-10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_75 ok [%#-.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_76 ok [%#-s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_77 ok [%#-10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_78 ok [%#-+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_79 ok [%#-+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_80 ok [%#-+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_81 ok [%# +10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_82 ok [%# 10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_83 ok [%# .4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_84 ok [%# s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_85 ok [%# 10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_86 ok [%# +.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_87 ok [%# +s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_88 ok [%# +10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_89 ok [%# -10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_90 ok [%# -.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_91 ok [%# -s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_92 ok [%# -10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_93 ok [%# -+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_94 ok [%# -+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_95 ok [%# -+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_96 ok [%#0-+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_97 ok [%#0+10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_98 ok [%#010.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_99 ok [%#0.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_100 ok [%#0s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_101 ok [%#010s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_102 ok [%#0+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_103 ok [%#0+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_104 ok [%#0+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_105 ok [%#0-10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_106 ok [%#0-.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_107 ok [%#0-s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_108 ok [%#0-10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_109 ok [%#0-+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_110 ok [%#0-+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_111 ok [%#0-+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_112 ok [%#0 +10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_113 ok [%#0 10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_114 ok [%#0 .4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_115 ok [%#0 s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_116 ok [%#0 10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_117 ok [%#0 +.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_118 ok [%#0 +s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_119 ok [%#0 +10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_120 ok [%#0 -10.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_121 ok [%#0 -.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_122 ok [%#0 -s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_123 ok [%#0 -10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_124 ok [%#0 -+.4s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_125 ok [%#0 -+s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	str = "test_s_126 ok [%#0 -+10s] T>T 123\n";
	test = "abcdef";
	ft_printf(str, test);

	ft_putstr("ok_end");

	str = "test_s_0 ok [%#0 -+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_1 ok [%0 -+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_2 ok [% -+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_3 ok [%-+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_4 ok [%+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_5 ok [%10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_6 ok [%.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_7 ok [%10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_8 ok [%+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_9 ok [%+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_10 ok [%+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_11 ok [%-10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_12 ok [%-.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_13 ok [%-s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_14 ok [%-10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_15 ok [%-+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_16 ok [%-+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_17 ok [%-+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_18 ok [% +10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_19 ok [% 10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_20 ok [% .4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_21 ok [% s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_22 ok [% 10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_23 ok [% +.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_24 ok [% +s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_25 ok [% +10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_26 ok [% -10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_27 ok [% -.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_28 ok [% -s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_29 ok [% -10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_30 ok [% -+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_31 ok [% -+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_32 ok [% -+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_33 ok [%0-+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_34 ok [%0+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_35 ok [%010.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_36 ok [%0.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_37 ok [%0s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_38 ok [%010s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_39 ok [%0+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_40 ok [%0+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_41 ok [%0+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_42 ok [%0-10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_43 ok [%0-.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_44 ok [%0-s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_45 ok [%0-10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_46 ok [%0-+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_47 ok [%0-+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_48 ok [%0-+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_49 ok [%0 +10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_50 ok [%0 10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_51 ok [%0 .4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_52 ok [%0 s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_53 ok [%0 10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_54 ok [%0 +.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_55 ok [%0 +s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_56 ok [%0 +10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_57 ok [%0 -10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_58 ok [%0 -.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_59 ok [%0 -s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_60 ok [%0 -10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_61 ok [%0 -+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_62 ok [%0 -+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_63 ok [%0 -+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_64 ok [%# -+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_65 ok [%#-+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_66 ok [%#+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_67 ok [%#10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_68 ok [%#.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_69 ok [%#s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_70 ok [%#10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_71 ok [%#+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_72 ok [%#+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_73 ok [%#+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_74 ok [%#-10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_75 ok [%#-.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_76 ok [%#-s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_77 ok [%#-10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_78 ok [%#-+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_79 ok [%#-+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_80 ok [%#-+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_81 ok [%# +10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_82 ok [%# 10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_83 ok [%# .4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_84 ok [%# s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_85 ok [%# 10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_86 ok [%# +.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_87 ok [%# +s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_88 ok [%# +10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_89 ok [%# -10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_90 ok [%# -.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_91 ok [%# -s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_92 ok [%# -10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_93 ok [%# -+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_94 ok [%# -+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_95 ok [%# -+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_96 ok [%#0-+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_97 ok [%#0+10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_98 ok [%#010.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_99 ok [%#0.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_100 ok [%#0s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_101 ok [%#010s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_102 ok [%#0+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_103 ok [%#0+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_104 ok [%#0+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_105 ok [%#0-10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_106 ok [%#0-.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_107 ok [%#0-s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_108 ok [%#0-10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_109 ok [%#0-+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_110 ok [%#0-+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_111 ok [%#0-+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_112 ok [%#0 +10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_113 ok [%#0 10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_114 ok [%#0 .4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_115 ok [%#0 s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_116 ok [%#0 10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_117 ok [%#0 +.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_118 ok [%#0 +s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_119 ok [%#0 +10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_120 ok [%#0 -10.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_121 ok [%#0 -.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_122 ok [%#0 -s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_123 ok [%#0 -10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_124 ok [%#0 -+.4s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_125 ok [%#0 -+s] T>T 123\n";
	test = "abcdef";
	printf(str, test);

	str = "test_s_126 ok [%#0 -+10s] T>T 123\n";
	test = "abcdef";
	printf(str, test);
}

void test_p(char with_ft)
{
	char *str;
	char *test;
	char *nul;
	int a;

	test = "abc";
	str = "test_p_0 [%p] ok\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	test = "bc";
	str = "test_p_1 [%p] ok\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	a = 20;
	str = "test_p_2 [%p] ok\n";
	printf(str, a);
	if (with_ft)
		ft_printf(str, a);

	nul = NULL;
	str = "test_p_3 [%p] ok\n";
	printf(str, nul);
	if (with_ft)
		ft_printf(str, nul);

	test = "abc";
	str = "test_p_4 ok [%20.3p] T_T 123\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	test = "abc";
	str = "test_p_5 ok [%-20.3p] T_T 123\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	test = "abc";
	str = "test_p_6 ok [%020.3p] T_T 123\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	test = "abc";
	str = "test_p_7 ok [%0-20p] T_T 123\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	test = "abc";
	str = "test_p_8 ok [%.3p] T_T 123\n";
	printf(str, test);
	if (with_ft)
		ft_printf(str, test);

	ft_putstr("ok_end");
	return ;
	a = 20;
	test = "test_p_9 len = %d\n";
	str = "[%p]";
	printf(test, printf(str, a));
	if (with_ft)
		printf(test, ft_printf(str, a));

	a = 20;
	test = "test_p_10 len = %d\n";
	str = "[%20p]";
	printf(test, printf(str, a));
	if (with_ft)
		printf(test, ft_printf(str, a));

	ft_putstr("ok_end");
	return ;
}

void test_d(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_d_0 ok [%#0 -+10.4d]",
		"test_d_1 ok [%0 -+10.4d]",
		"test_d_2 ok [% -+10.4d]",
		"test_d_3 ok [%-+10.4d]",
		"test_d_4 ok [%+10.4d]",
		"test_d_5 ok [%10.4d]",
		"test_d_6 ok [%.4d]",
		"test_d_7 ok [%10d]",
		"test_d_8 ok [%+.4d]",
		"test_d_9 ok [%+d]",
		"test_d_10 ok [%+10d]",
		"test_d_11 ok [%-10.4d]",
		"test_d_12 ok [%-.4d]",
		"test_d_13 ok [%-d]",
		"test_d_14 ok [%-10d]",
		"test_d_15 ok [%-+.4d]",
		"test_d_16 ok [%-+d]",
		"test_d_17 ok [%-+10d]",
		"test_d_18 ok [% +10.4d]",
		"test_d_19 ok [% 10.4d]",
		"test_d_20 ok [% .4d]",
		"test_d_21 ok [% d]",
		"test_d_22 ok [% 10d]",
		"test_d_23 ok [% +.4d]",
		"test_d_24 ok [% +d]",
		"test_d_25 ok [% +10d]",
		"test_d_26 ok [% -10.4d]",
		"test_d_27 ok [% -.4d]",
		"test_d_28 ok [% -d]",
		"test_d_29 ok [% -10d]",
		"test_d_30 ok [% -+.4d]",
		"test_d_31 ok [% -+d]",
		"test_d_32 ok [% -+10d]",
		"test_d_33 ok [%0-+10.4d]",
		"test_d_34 ok [%0+10.4d]",
		"test_d_35 ok [%010.4d]",
		"test_d_36 ok [%0.4d]",
		"test_d_37 ok [%0d]",
		"test_d_38 ok [%010d]",
		"test_d_39 ok [%0+.4d]",
		"test_d_40 ok [%0+d]",
		"test_d_41 ok [%0+10d]",
		"test_d_42 ok [%0-10.4d]",
		"test_d_43 ok [%0-.4d]",
		"test_d_44 ok [%0-d]",
		"test_d_45 ok [%0-10d]",
		"test_d_46 ok [%0-+.4d]",
		"test_d_47 ok [%0-+d]",
		"test_d_48 ok [%0-+10d]",
		"test_d_49 ok [%0 +10.4d]",
		"test_d_50 ok [%0 10.4d]",
		"test_d_51 ok [%0 .4d]",
		"test_d_52 ok [%0 d]",
		"test_d_53 ok [%0 10d]",
		"test_d_54 ok [%0 +.4d]",
		"test_d_55 ok [%0 +d]",
		"test_d_56 ok [%0 +10d]",
		"test_d_57 ok [%0 -10.4d]",
		"test_d_58 ok [%0 -.4d]",
		"test_d_59 ok [%0 -d]",
		"test_d_60 ok [%0 -10d]",
		"test_d_61 ok [%0 -+.4d]",
		"test_d_62 ok [%0 -+d]",
		"test_d_63 ok [%0 -+10d]",
		"test_d_64 ok [%# -+10.4d]",
		"test_d_65 ok [%#-+10.4d]",
		"test_d_66 ok [%#+10.4d]",
		"test_d_67 ok [%#10.4d]",
		"test_d_68 ok [%#.4d]",
		"test_d_69 ok [%#d]",
		"test_d_70 ok [%#10d]",
		"test_d_71 ok [%#+.4d]",
		"test_d_72 ok [%#+d]",
		"test_d_73 ok [%#+10d]",
		"test_d_74 ok [%#-10.4d]",
		"test_d_75 ok [%#-.4d]",
		"test_d_76 ok [%#-d]",
		"test_d_77 ok [%#-10d]",
		"test_d_78 ok [%#-+.4d]",
		"test_d_79 ok [%#-+d]",
		"test_d_80 ok [%#-+10d]",
		"test_d_81 ok [%# +10.4d]",
		"test_d_82 ok [%# 10.4d]",
		"test_d_83 ok [%# .4d]",
		"test_d_84 ok [%# d]",
		"test_d_85 ok [%# 10d]",
		"test_d_86 ok [%# +.4d]",
		"test_d_87 ok [%# +d]",
		"test_d_88 ok [%# +10d]",
		"test_d_89 ok [%# -10.4d]",
		"test_d_90 ok [%# -.4d]",
		"test_d_91 ok [%# -d]",
		"test_d_92 ok [%# -10d]",
		"test_d_93 ok [%# -+.4d]",
		"test_d_94 ok [%# -+d]",
		"test_d_95 ok [%# -+10d]",
		"test_d_96 ok [%#0-+10.4d]",
		"test_d_97 ok [%#0+10.4d]",
		"test_d_98 ok [%#010.4d]",
		"test_d_99 ok [%#0.4d]",
		"test_d_100 ok [%#0d]",
		"test_d_101 ok [%#010d]",
		"test_d_102 ok [%#0+.4d]",
		"test_d_103 ok [%#0+d]",
		"test_d_104 ok [%#0+10d]",
		"test_d_105 ok [%#0-10.4d]",
		"test_d_106 ok [%#0-.4d]",
		"test_d_107 ok [%#0-d]",
		"test_d_108 ok [%#0-10d]",
		"test_d_109 ok [%#0-+.4d]",
		"test_d_110 ok [%#0-+d]",
		"test_d_111 ok [%#0-+10d]",
		"test_d_112 ok [%#0 +10.4d]",
		"test_d_113 ok [%#0 10.4d]",
		"test_d_114 ok [%#0 .4d]",
		"test_d_115 ok [%#0 d]",
		"test_d_116 ok [%#0 10d]",
		"test_d_117 ok [%#0 +.4d]",
		"test_d_118 ok [%#0 +d]",
		"test_d_119 ok [%#0 +10d]",
		"test_d_120 ok [%#0 -10.4d]",
		"test_d_121 ok [%#0 -.4d]",
		"test_d_122 ok [%#0 -d]",
		"test_d_123 ok [%#0 -10d]",
		"test_d_124 ok [%#0 -+.4d]",
		"test_d_125 ok [%#0 -+d]",
		"test_d_126 ok [%#0 -+10d]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-123,
		-1,
		0,
		1,
		123,
		111778123,
		2147483647,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %d); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}

void test_d_my(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_d_my_1 ok [% d]",
		"test_d_my_2 ok [%+ d]",
		"test_d_my_3 ok [%20 d]",
		"test_d_my_4 ok [%20 0 -+d]",
		"test_d_my_5 ok [%20 0 -d]",
		"test_d_my_6 ok [%20 d]",
		"test_d_my_7 ok [%20 +d]",
		"test_d_my_8 ok [%20 0+d]",
		"test_d_my_9 ok [%.5 0+d]",
		"test_d_my_10 ok [%.5 8d]",
		"test_d_my_11 ok [%20 0d]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		123,
		2147483647,
		1,
		0,
		-1,
		-321,
		-2147483647,
		-2147483648,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %d); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}


void test_c(int (*fun)(const char *format, ...))
{
	char *str;

	str = "test_c_0 🦑 [%+#- 0*.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_1 🦑 [%+# 0*.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_2 🦑 [%+# *.78Lc]ok👈\n";
	fun(str, 10, 'A');

	str = "test_c_3 🦑 [%+# *.78Lc]ok👈\n";
	fun(str, 0, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag !
	str = "test_c_4 🦑 [%+# *.7Lc]ok👈\n";
	fun(str, -10, 'A');

	str = "test_c_5 🦑 [%+# *.7Lc]ok👈\n";
	fun(str, 2, 'A');

	// ⚠️⚠️⚠️⚠️ minus is a flag and so precision is a width
	str = "test_c_6 🦑 [%+# *.-7Lc]ok👈\n";
	fun(str, 2, 'A');
}

int main ()
{
	//test_s(1);
	//test_s2();
	//test_p(1);


	void (*tab[100]) (int (*fun)(const char *format, ...)) = {
		&test_c,
		&test_d_my,
		&test_d,
		NULL
	};

	int idx = -1;
	while (tab[++idx])
		tab[idx](&ft_printf);

	ft_putstr("ok_end\n");

	idx = -1;
	while (tab[++idx])
		tab[idx](&printf);
}
