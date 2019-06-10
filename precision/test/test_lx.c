/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:28:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lx] _ld %ld

#include "tests.h"

void test_lx(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_lx_0 ok [%#0 -+10.4lx]",
		"test_lx_1 ok [%0 -+10.4lx]",
		"test_lx_2 ok [% -+10.4lx]",
		"test_lx_3 ok [%-+10.4lx]",
		"test_lx_4 ok [%+10.4lx]",
		"test_lx_5 ok [%10.4lx]",
		"test_lx_6 ok [%.4lx]",
		"test_lx_7 ok [%10lx]",
		"test_lx_8 ok [%+.4lx]",
		"test_lx_9 ok [%+lx]",
		"test_lx_10 ok [%+10lx]",
		"test_lx_11 ok [%-10.4lx]",
		"test_lx_12 ok [%-.4lx]",
		"test_lx_13 ok [%-lx]",
		"test_lx_14 ok [%-10lx]",
		"test_lx_15 ok [%-+.4lx]",
		"test_lx_16 ok [%-+lx]",
		"test_lx_17 ok [%-+10lx]",
		"test_lx_18 ok [% +10.4lx]",
		"test_lx_19 ok [% 10.4lx]",
		"test_lx_20 ok [% .4lx]",
		"test_lx_21 ok [% lx]",
		"test_lx_22 ok [% 10lx]",
		"test_lx_23 ok [% +.4lx]",
		"test_lx_24 ok [% +lx]",
		"test_lx_25 ok [% +10lx]",
		"test_lx_26 ok [% -10.4lx]",
		"test_lx_27 ok [% -.4lx]",
		"test_lx_28 ok [% -lx]",
		"test_lx_29 ok [% -10lx]",
		"test_lx_30 ok [% -+.4lx]",
		"test_lx_31 ok [% -+lx]",
		"test_lx_32 ok [% -+10lx]",
		"test_lx_33 ok [%0-+10.4lx]",
		"test_lx_34 ok [%0+10.4lx]",
		"test_lx_35 ok [%010.4lx]",
		"test_lx_36 ok [%0.4lx]",
		"test_lx_37 ok [%0lx]",
		"test_lx_38 ok [%010lx]",
		"test_lx_39 ok [%0+.4lx]",
		"test_lx_40 ok [%0+lx]",
		"test_lx_41 ok [%0+10lx]",
		"test_lx_42 ok [%0-10.4lx]",
		"test_lx_43 ok [%0-.4lx]",
		"test_lx_44 ok [%0-lx]",
		"test_lx_45 ok [%0-10lx]",
		"test_lx_46 ok [%0-+.4lx]",
		"test_lx_47 ok [%0-+lx]",
		"test_lx_48 ok [%0-+10lx]",
		"test_lx_49 ok [%0 +10.4lx]",
		"test_lx_50 ok [%0 10.4lx]",
		"test_lx_51 ok [%0 .4lx]",
		"test_lx_52 ok [%0 lx]",
		"test_lx_53 ok [%0 10lx]",
		"test_lx_54 ok [%0 +.4lx]",
		"test_lx_55 ok [%0 +lx]",
		"test_lx_56 ok [%0 +10lx]",
		"test_lx_57 ok [%0 -10.4lx]",
		"test_lx_58 ok [%0 -.4lx]",
		"test_lx_59 ok [%0 -lx]",
		"test_lx_60 ok [%0 -10lx]",
		"test_lx_61 ok [%0 -+.4lx]",
		"test_lx_62 ok [%0 -+lx]",
		"test_lx_63 ok [%0 -+10lx]",
		"test_lx_64 ok [%# -+10.4lx]",
		"test_lx_65 ok [%#-+10.4lx]",
		"test_lx_66 ok [%#+10.4lx]",
		"test_lx_67 ok [%#10.4lx]",
		"test_lx_68 ok [%#.4lx]",
		"test_lx_69 ok [%#lx]",
		"test_lx_70 ok [%#10lx]",
		"test_lx_71 ok [%#+.4lx]",
		"test_lx_72 ok [%#+lx]",
		"test_lx_73 ok [%#+10lx]",
		"test_lx_74 ok [%#-10.4lx]",
		"test_lx_75 ok [%#-.4lx]",
		"test_lx_76 ok [%#-lx]",
		"test_lx_77 ok [%#-10lx]",
		"test_lx_78 ok [%#-+.4lx]",
		"test_lx_79 ok [%#-+lx]",
		"test_lx_80 ok [%#-+10lx]",
		"test_lx_81 ok [%# +10.4lx]",
		"test_lx_82 ok [%# 10.4lx]",
		"test_lx_83 ok [%# .4lx]",
		"test_lx_84 ok [%# lx]",
		"test_lx_85 ok [%# 10lx]",
		"test_lx_86 ok [%# +.4lx]",
		"test_lx_87 ok [%# +lx]",
		"test_lx_88 ok [%# +10lx]",
		"test_lx_89 ok [%# -10.4lx]",
		"test_lx_90 ok [%# -.4lx]",
		"test_lx_91 ok [%# -lx]",
		"test_lx_92 ok [%# -10lx]",
		"test_lx_93 ok [%# -+.4lx]",
		"test_lx_94 ok [%# -+lx]",
		"test_lx_95 ok [%# -+10lx]",
		"test_lx_96 ok [%#0-+10.4lx]",
		"test_lx_97 ok [%#0+10.4lx]",
		"test_lx_98 ok [%#010.4lx]",
		"test_lx_99 ok [%#0.4lx]",
		"test_lx_100 ok [%#0lx]",
		"test_lx_101 ok [%#010lx]",
		"test_lx_102 ok [%#0+.4lx]",
		"test_lx_103 ok [%#0+lx]",
		"test_lx_104 ok [%#0+10lx]",
		"test_lx_105 ok [%#0-10.4lx]",
		"test_lx_106 ok [%#0-.4lx]",
		"test_lx_107 ok [%#0-lx]",
		"test_lx_108 ok [%#0-10lx]",
		"test_lx_109 ok [%#0-+.4lx]",
		"test_lx_110 ok [%#0-+lx]",
		"test_lx_111 ok [%#0-+10lx]",
		"test_lx_112 ok [%#0 +10.4lx]",
		"test_lx_113 ok [%#0 10.4lx]",
		"test_lx_114 ok [%#0 .4lx]",
		"test_lx_115 ok [%#0 lx]",
		"test_lx_116 ok [%#0 10lx]",
		"test_lx_117 ok [%#0 +.4lx]",
		"test_lx_118 ok [%#0 +lx]",
		"test_lx_119 ok [%#0 +10lx]",
		"test_lx_120 ok [%#0 -10.4lx]",
		"test_lx_121 ok [%#0 -.4lx]",
		"test_lx_122 ok [%#0 -lx]",
		"test_lx_123 ok [%#0 -10lx]",
		"test_lx_124 ok [%#0 -+.4lx]",
		"test_lx_125 ok [%#0 -+lx]",
		"test_lx_126 ok [%#0 -+10lx]",
		NULL
	};

	long stop_num = -42;
	long num[] = {
		-9223372036854775807 - 1,
		-4242424242424242,
		-2147483648,
		-111778123,
		-32768,
		-123,
		-1,
		0,
		1,
		123,
		32767,
		111778123,
		2147483647,
		4242424242424242,
		9223372036854775807,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %lx); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
