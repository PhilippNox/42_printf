/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 20:30:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: d] _d_ %d

#include "tests.h"

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
		-32768,
		-123,
		-1,
		0,
		1,
		123,
		32767,
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
