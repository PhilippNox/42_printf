/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 02:06:05 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: o] _o_ %o

#include "tests.h"

void test_o(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_o_0 ok [%#0 -+10.4o]",
		"test_o_1 ok [%0 -+10.4o]",
		"test_o_2 ok [% -+10.4o]",
		"test_o_3 ok [%-+10.4o]",
		"test_o_4 ok [%+10.4o]",
		"test_o_5 ok [%10.4o]",
		"test_o_6 ok [%.4o]",
		"test_o_7 ok [%10o]",
		"test_o_8 ok [%+.4o]",
		"test_o_9 ok [%+o]",
		"test_o_10 ok [%+10o]",
		"test_o_11 ok [%-10.4o]",
		"test_o_12 ok [%-.4o]",
		"test_o_13 ok [%-o]",
		"test_o_14 ok [%-10o]",
		"test_o_15 ok [%-+.4o]",
		"test_o_16 ok [%-+o]",
		"test_o_17 ok [%-+10o]",
		"test_o_18 ok [% +10.4o]",
		"test_o_19 ok [% 10.4o]",
		"test_o_20 ok [% .4o]",
		"test_o_21 ok [% o]",
		"test_o_22 ok [% 10o]",
		"test_o_23 ok [% +.4o]",
		"test_o_24 ok [% +o]",
		"test_o_25 ok [% +10o]",
		"test_o_26 ok [% -10.4o]",
		"test_o_27 ok [% -.4o]",
		"test_o_28 ok [% -o]",
		"test_o_29 ok [% -10o]",
		"test_o_30 ok [% -+.4o]",
		"test_o_31 ok [% -+o]",
		"test_o_32 ok [% -+10o]",
		"test_o_33 ok [%0-+10.4o]",
		"test_o_34 ok [%0+10.4o]",
		"test_o_35 ok [%010.4o]",
		"test_o_36 ok [%0.4o]",
		"test_o_37 ok [%0o]",
		"test_o_38 ok [%010o]",
		"test_o_39 ok [%0+.4o]",
		"test_o_40 ok [%0+o]",
		"test_o_41 ok [%0+10o]",
		"test_o_42 ok [%0-10.4o]",
		"test_o_43 ok [%0-.4o]",
		"test_o_44 ok [%0-o]",
		"test_o_45 ok [%0-10o]",
		"test_o_46 ok [%0-+.4o]",
		"test_o_47 ok [%0-+o]",
		"test_o_48 ok [%0-+10o]",
		"test_o_49 ok [%0 +10.4o]",
		"test_o_50 ok [%0 10.4o]",
		"test_o_51 ok [%0 .4o]",
		"test_o_52 ok [%0 o]",
		"test_o_53 ok [%0 10o]",
		"test_o_54 ok [%0 +.4o]",
		"test_o_55 ok [%0 +o]",
		"test_o_56 ok [%0 +10o]",
		"test_o_57 ok [%0 -10.4o]",
		"test_o_58 ok [%0 -.4o]",
		"test_o_59 ok [%0 -o]",
		"test_o_60 ok [%0 -10o]",
		"test_o_61 ok [%0 -+.4o]",
		"test_o_62 ok [%0 -+o]",
		"test_o_63 ok [%0 -+10o]",
		"test_o_64 ok [%# -+10.4o]",
		"test_o_65 ok [%#-+10.4o]",
		"test_o_66 ok [%#+10.4o]",
		"test_o_67 ok [%#10.4o]",
		"test_o_68 ok [%#.4o]",
		"test_o_69 ok [%#o]",
		"test_o_70 ok [%#10o]",
		"test_o_71 ok [%#+.4o]",
		"test_o_72 ok [%#+o]",
		"test_o_73 ok [%#+10o]",
		"test_o_74 ok [%#-10.4o]",
		"test_o_75 ok [%#-.4o]",
		"test_o_76 ok [%#-o]",
		"test_o_77 ok [%#-10o]",
		"test_o_78 ok [%#-+.4o]",
		"test_o_79 ok [%#-+o]",
		"test_o_80 ok [%#-+10o]",
		"test_o_81 ok [%# +10.4o]",
		"test_o_82 ok [%# 10.4o]",
		"test_o_83 ok [%# .4o]",
		"test_o_84 ok [%# o]",
		"test_o_85 ok [%# 10o]",
		"test_o_86 ok [%# +.4o]",
		"test_o_87 ok [%# +o]",
		"test_o_88 ok [%# +10o]",
		"test_o_89 ok [%# -10.4o]",
		"test_o_90 ok [%# -.4o]",
		"test_o_91 ok [%# -o]",
		"test_o_92 ok [%# -10o]",
		"test_o_93 ok [%# -+.4o]",
		"test_o_94 ok [%# -+o]",
		"test_o_95 ok [%# -+10o]",
		"test_o_96 ok [%#0-+10.4o]",
		"test_o_97 ok [%#0+10.4o]",
		"test_o_98 ok [%#010.4o]",
		"test_o_99 ok [%#0.4o]",
		"test_o_100 ok [%#0o]",
		"test_o_101 ok [%#010o]",
		"test_o_102 ok [%#0+.4o]",
		"test_o_103 ok [%#0+o]",
		"test_o_104 ok [%#0+10o]",
		"test_o_105 ok [%#0-10.4o]",
		"test_o_106 ok [%#0-.4o]",
		"test_o_107 ok [%#0-o]",
		"test_o_108 ok [%#0-10o]",
		"test_o_109 ok [%#0-+.4o]",
		"test_o_110 ok [%#0-+o]",
		"test_o_111 ok [%#0-+10o]",
		"test_o_112 ok [%#0 +10.4o]",
		"test_o_113 ok [%#0 10.4o]",
		"test_o_114 ok [%#0 .4o]",
		"test_o_115 ok [%#0 o]",
		"test_o_116 ok [%#0 10o]",
		"test_o_117 ok [%#0 +.4o]",
		"test_o_118 ok [%#0 +o]",
		"test_o_119 ok [%#0 +10o]",
		"test_o_120 ok [%#0 -10.4o]",
		"test_o_121 ok [%#0 -.4o]",
		"test_o_122 ok [%#0 -o]",
		"test_o_123 ok [%#0 -10o]",
		"test_o_124 ok [%#0 -+.4o]",
		"test_o_125 ok [%#0 -+o]",
		"test_o_126 ok [%#0 -+10o]",
		"test_x_127 %#.0o",
		"test_x_128 %#.o",
		"test_x_129 %#o",
		"test_x_130 %.0o",
		"test_x_131 %.o",
		"test_x_132 %o",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %o); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
