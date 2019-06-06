/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:52:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: c] _c_ %c

#include "tests.h"

void test_c(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_c_0 ok [%#0 -+10.4c]",
		"test_c_1 ok [%0 -+10.4c]",
		"test_c_2 ok [% -+10.4c]",
		"test_c_3 ok [%-+10.4c]",
		"test_c_4 ok [%+10.4c]",
		"test_c_5 ok [%10.4c]",
		"test_c_6 ok [%.4c]",
		"test_c_7 ok [%10c]",
		"test_c_8 ok [%+.4c]",
		"test_c_9 ok [%+c]",
		"test_c_10 ok [%+10c]",
		"test_c_11 ok [%-10.4c]",
		"test_c_12 ok [%-.4c]",
		"test_c_13 ok [%-c]",
		"test_c_14 ok [%-10c]",
		"test_c_15 ok [%-+.4c]",
		"test_c_16 ok [%-+c]",
		"test_c_17 ok [%-+10c]",
		"test_c_18 ok [% +10.4c]",
		"test_c_19 ok [% 10.4c]",
		"test_c_20 ok [% .4c]",
		"test_c_21 ok [% c]",
		"test_c_22 ok [% 10c]",
		"test_c_23 ok [% +.4c]",
		"test_c_24 ok [% +c]",
		"test_c_25 ok [% +10c]",
		"test_c_26 ok [% -10.4c]",
		"test_c_27 ok [% -.4c]",
		"test_c_28 ok [% -c]",
		"test_c_29 ok [% -10c]",
		"test_c_30 ok [% -+.4c]",
		"test_c_31 ok [% -+c]",
		"test_c_32 ok [% -+10c]",
		"test_c_33 ok [%0-+10.4c]",
		"test_c_34 ok [%0+10.4c]",
		"test_c_35 ok [%010.4c]",
		"test_c_36 ok [%0.4c]",
		"test_c_37 ok [%0c]",
		"test_c_38 ok [%010c]",
		"test_c_39 ok [%0+.4c]",
		"test_c_40 ok [%0+c]",
		"test_c_41 ok [%0+10c]",
		"test_c_42 ok [%0-10.4c]",
		"test_c_43 ok [%0-.4c]",
		"test_c_44 ok [%0-c]",
		"test_c_45 ok [%0-10c]",
		"test_c_46 ok [%0-+.4c]",
		"test_c_47 ok [%0-+c]",
		"test_c_48 ok [%0-+10c]",
		"test_c_49 ok [%0 +10.4c]",
		"test_c_50 ok [%0 10.4c]",
		"test_c_51 ok [%0 .4c]",
		"test_c_52 ok [%0 c]",
		"test_c_53 ok [%0 10c]",
		"test_c_54 ok [%0 +.4c]",
		"test_c_55 ok [%0 +c]",
		"test_c_56 ok [%0 +10c]",
		"test_c_57 ok [%0 -10.4c]",
		"test_c_58 ok [%0 -.4c]",
		"test_c_59 ok [%0 -c]",
		"test_c_60 ok [%0 -10c]",
		"test_c_61 ok [%0 -+.4c]",
		"test_c_62 ok [%0 -+c]",
		"test_c_63 ok [%0 -+10c]",
		"test_c_64 ok [%# -+10.4c]",
		"test_c_65 ok [%#-+10.4c]",
		"test_c_66 ok [%#+10.4c]",
		"test_c_67 ok [%#10.4c]",
		"test_c_68 ok [%#.4c]",
		"test_c_69 ok [%#c]",
		"test_c_70 ok [%#10c]",
		"test_c_71 ok [%#+.4c]",
		"test_c_72 ok [%#+c]",
		"test_c_73 ok [%#+10c]",
		"test_c_74 ok [%#-10.4c]",
		"test_c_75 ok [%#-.4c]",
		"test_c_76 ok [%#-c]",
		"test_c_77 ok [%#-10c]",
		"test_c_78 ok [%#-+.4c]",
		"test_c_79 ok [%#-+c]",
		"test_c_80 ok [%#-+10c]",
		"test_c_81 ok [%# +10.4c]",
		"test_c_82 ok [%# 10.4c]",
		"test_c_83 ok [%# .4c]",
		"test_c_84 ok [%# c]",
		"test_c_85 ok [%# 10c]",
		"test_c_86 ok [%# +.4c]",
		"test_c_87 ok [%# +c]",
		"test_c_88 ok [%# +10c]",
		"test_c_89 ok [%# -10.4c]",
		"test_c_90 ok [%# -.4c]",
		"test_c_91 ok [%# -c]",
		"test_c_92 ok [%# -10c]",
		"test_c_93 ok [%# -+.4c]",
		"test_c_94 ok [%# -+c]",
		"test_c_95 ok [%# -+10c]",
		"test_c_96 ok [%#0-+10.4c]",
		"test_c_97 ok [%#0+10.4c]",
		"test_c_98 ok [%#010.4c]",
		"test_c_99 ok [%#0.4c]",
		"test_c_100 ok [%#0c]",
		"test_c_101 ok [%#010c]",
		"test_c_102 ok [%#0+.4c]",
		"test_c_103 ok [%#0+c]",
		"test_c_104 ok [%#0+10c]",
		"test_c_105 ok [%#0-10.4c]",
		"test_c_106 ok [%#0-.4c]",
		"test_c_107 ok [%#0-c]",
		"test_c_108 ok [%#0-10c]",
		"test_c_109 ok [%#0-+.4c]",
		"test_c_110 ok [%#0-+c]",
		"test_c_111 ok [%#0-+10c]",
		"test_c_112 ok [%#0 +10.4c]",
		"test_c_113 ok [%#0 10.4c]",
		"test_c_114 ok [%#0 .4c]",
		"test_c_115 ok [%#0 c]",
		"test_c_116 ok [%#0 10c]",
		"test_c_117 ok [%#0 +.4c]",
		"test_c_118 ok [%#0 +c]",
		"test_c_119 ok [%#0 +10c]",
		"test_c_120 ok [%#0 -10.4c]",
		"test_c_121 ok [%#0 -.4c]",
		"test_c_122 ok [%#0 -c]",
		"test_c_123 ok [%#0 -10c]",
		"test_c_124 ok [%#0 -+.4c]",
		"test_c_125 ok [%#0 -+c]",
		"test_c_126 ok [%#0 -+10c]",
		NULL
	};

	char stop_num = 0;
	char num[] = {
		'a',
		'B',
		'7',
		'@',
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %c); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
