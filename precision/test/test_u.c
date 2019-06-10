/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/11 02:28:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: u] _u_ %u

#include "tests.h"

void test_u(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_u_0 ok [%#0 -+10.4u]",
		"test_u_1 ok [%0 -+10.4u]",
		"test_u_2 ok [% -+10.4u]",
		"test_u_3 ok [%-+10.4u]",
		"test_u_4 ok [%+10.4u]",
		"test_u_5 ok [%10.4u]",
		"test_u_6 ok [%.4u]",
		"test_u_7 ok [%10u]",
		"test_u_8 ok [%+.4u]",
		"test_u_9 ok [%+u]",
		"test_u_10 ok [%+10u]",
		"test_u_11 ok [%-10.4u]",
		"test_u_12 ok [%-.4u]",
		"test_u_13 ok [%-u]",
		"test_u_14 ok [%-10u]",
		"test_u_15 ok [%-+.4u]",
		"test_u_16 ok [%-+u]",
		"test_u_17 ok [%-+10u]",
		"test_u_18 ok [% +10.4u]",
		"test_u_19 ok [% 10.4u]",
		"test_u_20 ok [% .4u]",
		"test_u_21 ok [% u]",
		"test_u_22 ok [% 10u]",
		"test_u_23 ok [% +.4u]",
		"test_u_24 ok [% +u]",
		"test_u_25 ok [% +10u]",
		"test_u_26 ok [% -10.4u]",
		"test_u_27 ok [% -.4u]",
		"test_u_28 ok [% -u]",
		"test_u_29 ok [% -10u]",
		"test_u_30 ok [% -+.4u]",
		"test_u_31 ok [% -+u]",
		"test_u_32 ok [% -+10u]",
		"test_u_33 ok [%0-+10.4u]",
		"test_u_34 ok [%0+10.4u]",
		"test_u_35 ok [%010.4u]",
		"test_u_36 ok [%0.4u]",
		"test_u_37 ok [%0u]",
		"test_u_38 ok [%010u]",
		"test_u_39 ok [%0+.4u]",
		"test_u_40 ok [%0+u]",
		"test_u_41 ok [%0+10u]",
		"test_u_42 ok [%0-10.4u]",
		"test_u_43 ok [%0-.4u]",
		"test_u_44 ok [%0-u]",
		"test_u_45 ok [%0-10u]",
		"test_u_46 ok [%0-+.4u]",
		"test_u_47 ok [%0-+u]",
		"test_u_48 ok [%0-+10u]",
		"test_u_49 ok [%0 +10.4u]",
		"test_u_50 ok [%0 10.4u]",
		"test_u_51 ok [%0 .4u]",
		"test_u_52 ok [%0 u]",
		"test_u_53 ok [%0 10u]",
		"test_u_54 ok [%0 +.4u]",
		"test_u_55 ok [%0 +u]",
		"test_u_56 ok [%0 +10u]",
		"test_u_57 ok [%0 -10.4u]",
		"test_u_58 ok [%0 -.4u]",
		"test_u_59 ok [%0 -u]",
		"test_u_60 ok [%0 -10u]",
		"test_u_61 ok [%0 -+.4u]",
		"test_u_62 ok [%0 -+u]",
		"test_u_63 ok [%0 -+10u]",
		"test_u_64 ok [%# -+10.4u]",
		"test_u_65 ok [%#-+10.4u]",
		"test_u_66 ok [%#+10.4u]",
		"test_u_67 ok [%#10.4u]",
		"test_u_68 ok [%#.4u]",
		"test_u_69 ok [%#u]",
		"test_u_70 ok [%#10u]",
		"test_u_71 ok [%#+.4u]",
		"test_u_72 ok [%#+u]",
		"test_u_73 ok [%#+10u]",
		"test_u_74 ok [%#-10.4u]",
		"test_u_75 ok [%#-.4u]",
		"test_u_76 ok [%#-u]",
		"test_u_77 ok [%#-10u]",
		"test_u_78 ok [%#-+.4u]",
		"test_u_79 ok [%#-+u]",
		"test_u_80 ok [%#-+10u]",
		"test_u_81 ok [%# +10.4u]",
		"test_u_82 ok [%# 10.4u]",
		"test_u_83 ok [%# .4u]",
		"test_u_84 ok [%# u]",
		"test_u_85 ok [%# 10u]",
		"test_u_86 ok [%# +.4u]",
		"test_u_87 ok [%# +u]",
		"test_u_88 ok [%# +10u]",
		"test_u_89 ok [%# -10.4u]",
		"test_u_90 ok [%# -.4u]",
		"test_u_91 ok [%# -u]",
		"test_u_92 ok [%# -10u]",
		"test_u_93 ok [%# -+.4u]",
		"test_u_94 ok [%# -+u]",
		"test_u_95 ok [%# -+10u]",
		"test_u_96 ok [%#0-+10.4u]",
		"test_u_97 ok [%#0+10.4u]",
		"test_u_98 ok [%#010.4u]",
		"test_u_99 ok [%#0.4u]",
		"test_u_100 ok [%#0u]",
		"test_u_101 ok [%#010u]",
		"test_u_102 ok [%#0+.4u]",
		"test_u_103 ok [%#0+u]",
		"test_u_104 ok [%#0+10u]",
		"test_u_105 ok [%#0-10.4u]",
		"test_u_106 ok [%#0-.4u]",
		"test_u_107 ok [%#0-u]",
		"test_u_108 ok [%#0-10u]",
		"test_u_109 ok [%#0-+.4u]",
		"test_u_110 ok [%#0-+u]",
		"test_u_111 ok [%#0-+10u]",
		"test_u_112 ok [%#0 +10.4u]",
		"test_u_113 ok [%#0 10.4u]",
		"test_u_114 ok [%#0 .4u]",
		"test_u_115 ok [%#0 u]",
		"test_u_116 ok [%#0 10u]",
		"test_u_117 ok [%#0 +.4u]",
		"test_u_118 ok [%#0 +u]",
		"test_u_119 ok [%#0 +10u]",
		"test_u_120 ok [%#0 -10.4u]",
		"test_u_121 ok [%#0 -.4u]",
		"test_u_122 ok [%#0 -u]",
		"test_u_123 ok [%#0 -10u]",
		"test_u_124 ok [%#0 -+.4u]",
		"test_u_125 ok [%#0 -+u]",
		"test_u_126 ok [%#0 -+10u]",
		"test_x_127 %#.0u",
		"test_x_128 %#.u",
		"test_x_129 %#u",
		"test_x_130 %.0u",
		"test_x_131 %.u",
		"test_x_132 %u",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %u); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
