/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 15:26:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void test_p(int (*fun)(const char *format, ...))
{
	char *str;
	char *test;
	char *nul;
	int a;

	test = "abc";
	str = "test_p_0 [%p] ok\n";
	fun(str, test);

	test = "bc";
	str = "test_p_1 [%p] ok\n";
	fun(str, test);

	a = 20;
	str = "test_p_2 [%p] ok\n";
	fun(str, a);

	nul = NULL;
	str = "test_p_3 [%p] ok\n";
	fun(str, nul);

	test = "abc";
	str = "test_p_4 ok [%20.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_5 ok [%-20.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_6 ok [%020.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_7 ok [%0-20p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_8 ok [%.3p] T_T 123\n";
	fun(str, test);

	test = "abc";
	str = "test_p_8 ok [%.3p] T_T 123\n";
	fun(str, NULL);

	a = 20;
	test = "test_p_9 len = %d\n";
	str = "[%p]";
	fun(test, fun(str, a));


	a = 20;
	test = "test_p_10 len = %d\n";
	str = "[%20p]";
	fun(test, fun(str, a));

	int idx;
	int idxn;
	char *stra[] = {
		"test_p_0 ok [%#0 -+10.4p]",
		"test_p_1 ok [%0 -+10.4p]",
		"test_p_2 ok [% -+10.4p]",
		"test_p_3 ok [%-+10.4p]",
		"test_p_4 ok [%+10.4p]",
		"test_p_5 ok [%10.4p]",
		"test_p_6 ok [%.4p]",
		"test_p_7 ok [%10p]",
		"test_p_8 ok [%+.4p]",
		"test_p_9 ok [%+p]",
		"test_p_10 ok [%+10p]",
		"test_p_11 ok [%-10.4p]",
		"test_p_12 ok [%-.4p]",
		"test_p_13 ok [%-p]",
		"test_p_14 ok [%-10p]",
		"test_p_15 ok [%-+.4p]",
		"test_p_16 ok [%-+p]",
		"test_p_17 ok [%-+10p]",
		"test_p_18 ok [% +10.4p]",
		"test_p_19 ok [% 10.4p]",
		"test_p_20 ok [% .4p]",
		"test_p_21 ok [% p]",
		"test_p_22 ok [% 10p]",
		"test_p_23 ok [% +.4p]",
		"test_p_24 ok [% +p]",
		"test_p_25 ok [% +10p]",
		"test_p_26 ok [% -10.4p]",
		"test_p_27 ok [% -.4p]",
		"test_p_28 ok [% -p]",
		"test_p_29 ok [% -10p]",
		"test_p_30 ok [% -+.4p]",
		"test_p_31 ok [% -+p]",
		"test_p_32 ok [% -+10p]",
		"test_p_33 ok [%0-+10.4p]",
		"test_p_34 ok [%0+10.4p]",
		"test_p_35 ok [%010.4p]",
		"test_p_36 ok [%0.4p]",
		"test_p_37 ok [%0p]",
		"test_p_38 ok [%010p]",
		"test_p_39 ok [%0+.4p]",
		"test_p_40 ok [%0+p]",
		"test_p_41 ok [%0+10p]",
		"test_p_42 ok [%0-10.4p]",
		"test_p_43 ok [%0-.4p]",
		"test_p_44 ok [%0-p]",
		"test_p_45 ok [%0-10p]",
		"test_p_46 ok [%0-+.4p]",
		"test_p_47 ok [%0-+p]",
		"test_p_48 ok [%0-+10p]",
		"test_p_49 ok [%0 +10.4p]",
		"test_p_50 ok [%0 10.4p]",
		"test_p_51 ok [%0 .4p]",
		"test_p_52 ok [%0 p]",
		"test_p_53 ok [%0 10p]",
		"test_p_54 ok [%0 +.4p]",
		"test_p_55 ok [%0 +p]",
		"test_p_56 ok [%0 +10p]",
		"test_p_57 ok [%0 -10.4p]",
		"test_p_58 ok [%0 -.4p]",
		"test_p_59 ok [%0 -p]",
		"test_p_60 ok [%0 -10p]",
		"test_p_61 ok [%0 -+.4p]",
		"test_p_62 ok [%0 -+p]",
		"test_p_63 ok [%0 -+10p]",
		"test_p_64 ok [%# -+10.4p]",
		"test_p_65 ok [%#-+10.4p]",
		"test_p_66 ok [%#+10.4p]",
		"test_p_67 ok [%#10.4p]",
		"test_p_68 ok [%#.4p]",
		"test_p_69 ok [%#p]",
		"test_p_70 ok [%#10p]",
		"test_p_71 ok [%#+.4p]",
		"test_p_72 ok [%#+p]",
		"test_p_73 ok [%#+10p]",
		"test_p_74 ok [%#-10.4p]",
		"test_p_75 ok [%#-.4p]",
		"test_p_76 ok [%#-p]",
		"test_p_77 ok [%#-10p]",
		"test_p_78 ok [%#-+.4p]",
		"test_p_79 ok [%#-+p]",
		"test_p_80 ok [%#-+10p]",
		"test_p_81 ok [%# +10.4p]",
		"test_p_82 ok [%# 10.4p]",
		"test_p_83 ok [%# .4p]",
		"test_p_84 ok [%# p]",
		"test_p_85 ok [%# 10p]",
		"test_p_86 ok [%# +.4p]",
		"test_p_87 ok [%# +p]",
		"test_p_88 ok [%# +10p]",
		"test_p_89 ok [%# -10.4p]",
		"test_p_90 ok [%# -.4p]",
		"test_p_91 ok [%# -p]",
		"test_p_92 ok [%# -10p]",
		"test_p_93 ok [%# -+.4p]",
		"test_p_94 ok [%# -+p]",
		"test_p_95 ok [%# -+10p]",
		"test_p_96 ok [%#0-+10.4p]",
		"test_p_97 ok [%#0+10.4p]",
		"test_p_98 ok [%#010.4p]",
		"test_p_99 ok [%#0.4p]",
		"test_p_100 ok [%#0p]",
		"test_p_101 ok [%#010p]",
		"test_p_102 ok [%#0+.4p]",
		"test_p_103 ok [%#0+p]",
		"test_p_104 ok [%#0+10p]",
		"test_p_105 ok [%#0-10.4p]",
		"test_p_106 ok [%#0-.4p]",
		"test_p_107 ok [%#0-p]",
		"test_p_108 ok [%#0-10p]",
		"test_p_109 ok [%#0-+.4p]",
		"test_p_110 ok [%#0-+p]",
		"test_p_111 ok [%#0-+10p]",
		"test_p_112 ok [%#0 +10.4p]",
		"test_p_113 ok [%#0 10.4p]",
		"test_p_114 ok [%#0 .4p]",
		"test_p_115 ok [%#0 p]",
		"test_p_116 ok [%#0 10p]",
		"test_p_117 ok [%#0 +.4p]",
		"test_p_118 ok [%#0 +p]",
		"test_p_119 ok [%#0 +10p]",
		"test_p_120 ok [%#0 -10.4p]",
		"test_p_121 ok [%#0 -.4p]",
		"test_p_122 ok [%#0 -p]",
		"test_p_123 ok [%#0 -10p]",
		"test_p_124 ok [%#0 -+.4p]",
		"test_p_125 ok [%#0 -+p]",
		"test_p_126 ok [%#0 -+10p]",
		"test_p_127 %#.0p",
		"test_p_128 %#.p",
		"test_p_129 %#p",
		"test_p_130 %.0p",
		"test_p_131 %.p",
		"test_p_132 %p",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-1,
		0,
		1,
		stop_num
	};

	idx = -1;
	while (stra[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(stra[idx], num[idxn]);
			//fun("\t\t\t\t//\tprintf(\"%s\", %o); // RUN THIS CODE FOR DEBUG", str[idx], num[idxn]);
			fun("\n");
		}
	}
}
