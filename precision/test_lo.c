/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:55:47 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lo] _ld %ld

#include "tests.h"

void test_lo(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_lo_0 ok [%#0 -+10.4lo]",
		"test_lo_1 ok [%0 -+10.4lo]",
		"test_lo_2 ok [% -+10.4lo]",
		"test_lo_3 ok [%-+10.4lo]",
		"test_lo_4 ok [%+10.4lo]",
		"test_lo_5 ok [%10.4lo]",
		"test_lo_6 ok [%.4lo]",
		"test_lo_7 ok [%10lo]",
		"test_lo_8 ok [%+.4lo]",
		"test_lo_9 ok [%+lo]",
		"test_lo_10 ok [%+10lo]",
		"test_lo_11 ok [%-10.4lo]",
		"test_lo_12 ok [%-.4lo]",
		"test_lo_13 ok [%-lo]",
		"test_lo_14 ok [%-10lo]",
		"test_lo_15 ok [%-+.4lo]",
		"test_lo_16 ok [%-+lo]",
		"test_lo_17 ok [%-+10lo]",
		"test_lo_18 ok [% +10.4lo]",
		"test_lo_19 ok [% 10.4lo]",
		"test_lo_20 ok [% .4lo]",
		"test_lo_21 ok [% lo]",
		"test_lo_22 ok [% 10lo]",
		"test_lo_23 ok [% +.4lo]",
		"test_lo_24 ok [% +lo]",
		"test_lo_25 ok [% +10lo]",
		"test_lo_26 ok [% -10.4lo]",
		"test_lo_27 ok [% -.4lo]",
		"test_lo_28 ok [% -lo]",
		"test_lo_29 ok [% -10lo]",
		"test_lo_30 ok [% -+.4lo]",
		"test_lo_31 ok [% -+lo]",
		"test_lo_32 ok [% -+10lo]",
		"test_lo_33 ok [%0-+10.4lo]",
		"test_lo_34 ok [%0+10.4lo]",
		"test_lo_35 ok [%010.4lo]",
		"test_lo_36 ok [%0.4lo]",
		"test_lo_37 ok [%0lo]",
		"test_lo_38 ok [%010lo]",
		"test_lo_39 ok [%0+.4lo]",
		"test_lo_40 ok [%0+lo]",
		"test_lo_41 ok [%0+10lo]",
		"test_lo_42 ok [%0-10.4lo]",
		"test_lo_43 ok [%0-.4lo]",
		"test_lo_44 ok [%0-lo]",
		"test_lo_45 ok [%0-10lo]",
		"test_lo_46 ok [%0-+.4lo]",
		"test_lo_47 ok [%0-+lo]",
		"test_lo_48 ok [%0-+10lo]",
		"test_lo_49 ok [%0 +10.4lo]",
		"test_lo_50 ok [%0 10.4lo]",
		"test_lo_51 ok [%0 .4lo]",
		"test_lo_52 ok [%0 lo]",
		"test_lo_53 ok [%0 10lo]",
		"test_lo_54 ok [%0 +.4lo]",
		"test_lo_55 ok [%0 +lo]",
		"test_lo_56 ok [%0 +10lo]",
		"test_lo_57 ok [%0 -10.4lo]",
		"test_lo_58 ok [%0 -.4lo]",
		"test_lo_59 ok [%0 -lo]",
		"test_lo_60 ok [%0 -10lo]",
		"test_lo_61 ok [%0 -+.4lo]",
		"test_lo_62 ok [%0 -+lo]",
		"test_lo_63 ok [%0 -+10lo]",
		"test_lo_64 ok [%# -+10.4lo]",
		"test_lo_65 ok [%#-+10.4lo]",
		"test_lo_66 ok [%#+10.4lo]",
		"test_lo_67 ok [%#10.4lo]",
		"test_lo_68 ok [%#.4lo]",
		"test_lo_69 ok [%#lo]",
		"test_lo_70 ok [%#10lo]",
		"test_lo_71 ok [%#+.4lo]",
		"test_lo_72 ok [%#+lo]",
		"test_lo_73 ok [%#+10lo]",
		"test_lo_74 ok [%#-10.4lo]",
		"test_lo_75 ok [%#-.4lo]",
		"test_lo_76 ok [%#-lo]",
		"test_lo_77 ok [%#-10lo]",
		"test_lo_78 ok [%#-+.4lo]",
		"test_lo_79 ok [%#-+lo]",
		"test_lo_80 ok [%#-+10lo]",
		"test_lo_81 ok [%# +10.4lo]",
		"test_lo_82 ok [%# 10.4lo]",
		"test_lo_83 ok [%# .4lo]",
		"test_lo_84 ok [%# lo]",
		"test_lo_85 ok [%# 10lo]",
		"test_lo_86 ok [%# +.4lo]",
		"test_lo_87 ok [%# +lo]",
		"test_lo_88 ok [%# +10lo]",
		"test_lo_89 ok [%# -10.4lo]",
		"test_lo_90 ok [%# -.4lo]",
		"test_lo_91 ok [%# -lo]",
		"test_lo_92 ok [%# -10lo]",
		"test_lo_93 ok [%# -+.4lo]",
		"test_lo_94 ok [%# -+lo]",
		"test_lo_95 ok [%# -+10lo]",
		"test_lo_96 ok [%#0-+10.4lo]",
		"test_lo_97 ok [%#0+10.4lo]",
		"test_lo_98 ok [%#010.4lo]",
		"test_lo_99 ok [%#0.4lo]",
		"test_lo_100 ok [%#0lo]",
		"test_lo_101 ok [%#010lo]",
		"test_lo_102 ok [%#0+.4lo]",
		"test_lo_103 ok [%#0+lo]",
		"test_lo_104 ok [%#0+10lo]",
		"test_lo_105 ok [%#0-10.4lo]",
		"test_lo_106 ok [%#0-.4lo]",
		"test_lo_107 ok [%#0-lo]",
		"test_lo_108 ok [%#0-10lo]",
		"test_lo_109 ok [%#0-+.4lo]",
		"test_lo_110 ok [%#0-+lo]",
		"test_lo_111 ok [%#0-+10lo]",
		"test_lo_112 ok [%#0 +10.4lo]",
		"test_lo_113 ok [%#0 10.4lo]",
		"test_lo_114 ok [%#0 .4lo]",
		"test_lo_115 ok [%#0 lo]",
		"test_lo_116 ok [%#0 10lo]",
		"test_lo_117 ok [%#0 +.4lo]",
		"test_lo_118 ok [%#0 +lo]",
		"test_lo_119 ok [%#0 +10lo]",
		"test_lo_120 ok [%#0 -10.4lo]",
		"test_lo_121 ok [%#0 -.4lo]",
		"test_lo_122 ok [%#0 -lo]",
		"test_lo_123 ok [%#0 -10lo]",
		"test_lo_124 ok [%#0 -+.4lo]",
		"test_lo_125 ok [%#0 -+lo]",
		"test_lo_126 ok [%#0 -+10lo]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %lo); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
