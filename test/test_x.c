/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 02:01:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: x] _x %x

#include "tests.h"

void test_x(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_x_0 ok [%#0 -+10.4x]",
		"test_x_1 ok [%0 -+10.4x]",
		"test_x_2 ok [% -+10.4x]",
		"test_x_3 ok [%-+10.4x]",
		"test_x_4 ok [%+10.4x]",
		"test_x_5 ok [%10.4x]",
		"test_x_6 ok [%.4x]",
		"test_x_7 ok [%10x]",
		"test_x_8 ok [%+.4x]",
		"test_x_9 ok [%+x]",
		"test_x_10 ok [%+10x]",
		"test_x_11 ok [%-10.4x]",
		"test_x_12 ok [%-.4x]",
		"test_x_13 ok [%-x]",
		"test_x_14 ok [%-10x]",
		"test_x_15 ok [%-+.4x]",
		"test_x_16 ok [%-+x]",
		"test_x_17 ok [%-+10x]",
		"test_x_18 ok [% +10.4x]",
		"test_x_19 ok [% 10.4x]",
		"test_x_20 ok [% .4x]",
		"test_x_21 ok [% x]",
		"test_x_22 ok [% 10x]",
		"test_x_23 ok [% +.4x]",
		"test_x_24 ok [% +x]",
		"test_x_25 ok [% +10x]",
		"test_x_26 ok [% -10.4x]",
		"test_x_27 ok [% -.4x]",
		"test_x_28 ok [% -x]",
		"test_x_29 ok [% -10x]",
		"test_x_30 ok [% -+.4x]",
		"test_x_31 ok [% -+x]",
		"test_x_32 ok [% -+10x]",
		"test_x_33 ok [%0-+10.4x]",
		"test_x_34 ok [%0+10.4x]",
		"test_x_35 ok [%010.4x]",
		"test_x_36 ok [%0.4x]",
		"test_x_37 ok [%0x]",
		"test_x_38 ok [%010x]",
		"test_x_39 ok [%0+.4x]",
		"test_x_40 ok [%0+x]",
		"test_x_41 ok [%0+10x]",
		"test_x_42 ok [%0-10.4x]",
		"test_x_43 ok [%0-.4x]",
		"test_x_44 ok [%0-x]",
		"test_x_45 ok [%0-10x]",
		"test_x_46 ok [%0-+.4x]",
		"test_x_47 ok [%0-+x]",
		"test_x_48 ok [%0-+10x]",
		"test_x_49 ok [%0 +10.4x]",
		"test_x_50 ok [%0 10.4x]",
		"test_x_51 ok [%0 .4x]",
		"test_x_52 ok [%0 x]",
		"test_x_53 ok [%0 10x]",
		"test_x_54 ok [%0 +.4x]",
		"test_x_55 ok [%0 +x]",
		"test_x_56 ok [%0 +10x]",
		"test_x_57 ok [%0 -10.4x]",
		"test_x_58 ok [%0 -.4x]",
		"test_x_59 ok [%0 -x]",
		"test_x_60 ok [%0 -10x]",
		"test_x_61 ok [%0 -+.4x]",
		"test_x_62 ok [%0 -+x]",
		"test_x_63 ok [%0 -+10x]",
		"test_x_64 ok [%# -+10.4x]",
		"test_x_65 ok [%#-+10.4x]",
		"test_x_66 ok [%#+10.4x]",
		"test_x_67 ok [%#10.4x]",
		"test_x_68 ok [%#.4x]",
		"test_x_69 ok [%#x]",
		"test_x_70 ok [%#10x]",
		"test_x_71 ok [%#+.4x]",
		"test_x_72 ok [%#+x]",
		"test_x_73 ok [%#+10x]",
		"test_x_74 ok [%#-10.4x]",
		"test_x_75 ok [%#-.4x]",
		"test_x_76 ok [%#-x]",
		"test_x_77 ok [%#-10x]",
		"test_x_78 ok [%#-+.4x]",
		"test_x_79 ok [%#-+x]",
		"test_x_80 ok [%#-+10x]",
		"test_x_81 ok [%# +10.4x]",
		"test_x_82 ok [%# 10.4x]",
		"test_x_83 ok [%# .4x]",
		"test_x_84 ok [%# x]",
		"test_x_85 ok [%# 10x]",
		"test_x_86 ok [%# +.4x]",
		"test_x_87 ok [%# +x]",
		"test_x_88 ok [%# +10x]",
		"test_x_89 ok [%# -10.4x]",
		"test_x_90 ok [%# -.4x]",
		"test_x_91 ok [%# -x]",
		"test_x_92 ok [%# -10x]",
		"test_x_93 ok [%# -+.4x]",
		"test_x_94 ok [%# -+x]",
		"test_x_95 ok [%# -+10x]",
		"test_x_96 ok [%#0-+10.4x]",
		"test_x_97 ok [%#0+10.4x]",
		"test_x_98 ok [%#010.4x]",
		"test_x_99 ok [%#0.4x]",
		"test_x_100 ok [%#0x]",
		"test_x_101 ok [%#010x]",
		"test_x_102 ok [%#0+.4x]",
		"test_x_103 ok [%#0+x]",
		"test_x_104 ok [%#0+10x]",
		"test_x_105 ok [%#0-10.4x]",
		"test_x_106 ok [%#0-.4x]",
		"test_x_107 ok [%#0-x]",
		"test_x_108 ok [%#0-10x]",
		"test_x_109 ok [%#0-+.4x]",
		"test_x_110 ok [%#0-+x]",
		"test_x_111 ok [%#0-+10x]",
		"test_x_112 ok [%#0 +10.4x]",
		"test_x_113 ok [%#0 10.4x]",
		"test_x_114 ok [%#0 .4x]",
		"test_x_115 ok [%#0 x]",
		"test_x_116 ok [%#0 10x]",
		"test_x_117 ok [%#0 +.4x]",
		"test_x_118 ok [%#0 +x]",
		"test_x_119 ok [%#0 +10x]",
		"test_x_120 ok [%#0 -10.4x]",
		"test_x_121 ok [%#0 -.4x]",
		"test_x_122 ok [%#0 -x]",
		"test_x_123 ok [%#0 -10x]",
		"test_x_124 ok [%#0 -+.4x]",
		"test_x_125 ok [%#0 -+x]",
		"test_x_126 ok [%#0 -+10x]",
		"test_x_127 %#.0x",
		"test_x_128 %#.x",
		"test_x_129 %#x",
		"test_x_130 %.0x",
		"test_x_131 %.x",
		"test_x_132 %x",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-1234,
		-123,
		-1,
		0,
		1,
		123,
		1234,
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
			fun("\t\t\t\t//\tprintf(\"%s\", %x); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
