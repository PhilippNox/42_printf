/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/10 23:59:21 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: f] _f_ %f

#include "tests.h"

void test_f(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_f_0 ok [%#0 -+10.4f]",
		"test_f_1 ok [%0 -+10.4f]",
		"test_f_2 ok [% -+10.4f]",
		"test_f_3 ok [%-+10.4f]",
		"test_f_4 ok [%+10.4f]",
		"test_f_5 ok [%10.4f]",
		"test_f_6 ok [%.4f]",
		"test_f_7 ok [%10f]",
		"test_f_8 ok [%+.4f]",
		"test_f_9 ok [%+f]",
		"test_f_10 ok [%+10f]",
		"test_f_11 ok [%-10.4f]",
		"test_f_12 ok [%-.4f]",
		"test_f_13 ok [%-f]",
		"test_f_14 ok [%-10f]",
		"test_f_15 ok [%-+.4f]",
		"test_f_16 ok [%-+f]",
		"test_f_17 ok [%-+10f]",
		"test_f_18 ok [% +10.4f]",
		"test_f_19 ok [% 10.4f]",
		"test_f_20 ok [% .4f]",
		"test_f_21 ok [% f]",
		"test_f_22 ok [% 10f]",
		"test_f_23 ok [% +.4f]",
		"test_f_24 ok [% +f]",
		"test_f_25 ok [% +10f]",
		"test_f_26 ok [% -10.4f]",
		"test_f_27 ok [% -.4f]",
		"test_f_28 ok [% -f]",
		"test_f_29 ok [% -10f]",
		"test_f_30 ok [% -+.4f]",
		"test_f_31 ok [% -+f]",
		"test_f_32 ok [% -+10f]",
		"test_f_33 ok [%0-+10.4f]",
		"test_f_34 ok [%0+10.4f]",
		"test_f_35 ok [%010.4f]",
		"test_f_36 ok [%0.4f]",
		"test_f_37 ok [%0f]",
		"test_f_38 ok [%010f]",
		"test_f_39 ok [%0+.4f]",
		"test_f_40 ok [%0+f]",
		"test_f_41 ok [%0+10f]",
		"test_f_42 ok [%0-10.4f]",
		"test_f_43 ok [%0-.4f]",
		"test_f_44 ok [%0-f]",
		"test_f_45 ok [%0-10f]",
		"test_f_46 ok [%0-+.4f]",
		"test_f_47 ok [%0-+f]",
		"test_f_48 ok [%0-+10f]",
		"test_f_49 ok [%0 +10.4f]",
		"test_f_50 ok [%0 10.4f]",
		"test_f_51 ok [%0 .4f]",
		"test_f_52 ok [%0 f]",
		"test_f_53 ok [%0 10f]",
		"test_f_54 ok [%0 +.4f]",
		"test_f_55 ok [%0 +f]",
		"test_f_56 ok [%0 +10f]",
		"test_f_57 ok [%0 -10.4f]",
		"test_f_58 ok [%0 -.4f]",
		"test_f_59 ok [%0 -f]",
		"test_f_60 ok [%0 -10f]",
		"test_f_61 ok [%0 -+.4f]",
		"test_f_62 ok [%0 -+f]",
		"test_f_63 ok [%0 -+10f]",
		"test_f_64 ok [%# -+10.4f]",
		"test_f_65 ok [%#-+10.4f]",
		"test_f_66 ok [%#+10.4f]",
		"test_f_67 ok [%#10.4f]",
		"test_f_68 ok [%#.4f]",
		"test_f_69 ok [%#f]",
		"test_f_70 ok [%#10f]",
		"test_f_71 ok [%#+.4f]",
		"test_f_72 ok [%#+f]",
		"test_f_73 ok [%#+10f]",
		"test_f_74 ok [%#-10.4f]",
		"test_f_75 ok [%#-.4f]",
		"test_f_76 ok [%#-f]",
		"test_f_77 ok [%#-10f]",
		"test_f_78 ok [%#-+.4f]",
		"test_f_79 ok [%#-+f]",
		"test_f_80 ok [%#-+10f]",
		"test_f_81 ok [%# +10.4f]",
		"test_f_82 ok [%# 10.4f]",
		"test_f_83 ok [%# .4f]",
		"test_f_84 ok [%# f]",
		"test_f_85 ok [%# 10f]",
		"test_f_86 ok [%# +.4f]",
		"test_f_87 ok [%# +f]",
		"test_f_88 ok [%# +10f]",
		"test_f_89 ok [%# -10.4f]",
		"test_f_90 ok [%# -.4f]",
		"test_f_91 ok [%# -f]",
		"test_f_92 ok [%# -10f]",
		"test_f_93 ok [%# -+.4f]",
		"test_f_94 ok [%# -+f]",
		"test_f_95 ok [%# -+10f]",
		"test_f_96 ok [%#0-+10.4f]",
		"test_f_97 ok [%#0+10.4f]",
		"test_f_98 ok [%#010.4f]",
		"test_f_99 ok [%#0.4f]",
		"test_f_100 ok [%#0f]",
		"test_f_101 ok [%#010f]",
		"test_f_102 ok [%#0+.4f]",
		"test_f_103 ok [%#0+f]",
		"test_f_104 ok [%#0+10f]",
		"test_f_105 ok [%#0-10.4f]",
		"test_f_106 ok [%#0-.4f]",
		"test_f_107 ok [%#0-f]",
		"test_f_108 ok [%#0-10f]",
		"test_f_109 ok [%#0-+.4f]",
		"test_f_110 ok [%#0-+f]",
		"test_f_111 ok [%#0-+10f]",
		"test_f_112 ok [%#0 +10.4f]",
		"test_f_113 ok [%#0 10.4f]",
		"test_f_114 ok [%#0 .4f]",
		"test_f_115 ok [%#0 f]",
		"test_f_116 ok [%#0 10f]",
		"test_f_117 ok [%#0 +.4f]",
		"test_f_118 ok [%#0 +f]",
		"test_f_119 ok [%#0 +10f]",
		"test_f_120 ok [%#0 -10.4f]",
		"test_f_121 ok [%#0 -.4f]",
		"test_f_122 ok [%#0 -f]",
		"test_f_123 ok [%#0 -10f]",
		"test_f_124 ok [%#0 -+.4f]",
		"test_f_125 ok [%#0 -+f]",
		"test_f_126 ok [%#0 -+10f]",
		"test_fr_1 ok [%f]",
		"test_fr_2 ok [%.5f]",
		"test_fr_3 ok [%.4f]",
		"test_fr_4 ok [%.3f]",
		"test_fr_5 ok [%.2f]",
		"test_fr_6 ok [%.1f]",
		"test_fr_7 ok [%.0f]",
		"test_fr_8 ok [%.150f]",
		NULL
	};

	double stop_num = -42;
	double num[] = {
		FLT_MIN,
		FLT_MAX,
		FLT_EPSILON,
		0,
		-0,
		1,
		-1,
		2,
		-2,
		0.2,
		-0.2,
		2.0625,
		3.03125,
		4.09375,
		4.00001,
		1.0 / 0.0,
		-1.0 / 0.0,
		0.0 / 0.0,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %f); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
