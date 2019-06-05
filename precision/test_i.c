/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 14:45:37 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: i] _i_ %i

#include "tests.h"

void test_i(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_i_0 ok [%#0 -+10.4i]",
		"test_i_1 ok [%0 -+10.4i]",
		"test_i_2 ok [% -+10.4i]",
		"test_i_3 ok [%-+10.4i]",
		"test_i_4 ok [%+10.4i]",
		"test_i_5 ok [%10.4i]",
		"test_i_6 ok [%.4i]",
		"test_i_7 ok [%10i]",
		"test_i_8 ok [%+.4i]",
		"test_i_9 ok [%+i]",
		"test_i_10 ok [%+10i]",
		"test_i_11 ok [%-10.4i]",
		"test_i_12 ok [%-.4i]",
		"test_i_13 ok [%-i]",
		"test_i_14 ok [%-10i]",
		"test_i_15 ok [%-+.4i]",
		"test_i_16 ok [%-+i]",
		"test_i_17 ok [%-+10i]",
		"test_i_18 ok [% +10.4i]",
		"test_i_19 ok [% 10.4i]",
		"test_i_20 ok [% .4i]",
		"test_i_21 ok [% i]",
		"test_i_22 ok [% 10i]",
		"test_i_23 ok [% +.4i]",
		"test_i_24 ok [% +i]",
		"test_i_25 ok [% +10i]",
		"test_i_26 ok [% -10.4i]",
		"test_i_27 ok [% -.4i]",
		"test_i_28 ok [% -i]",
		"test_i_29 ok [% -10i]",
		"test_i_30 ok [% -+.4i]",
		"test_i_31 ok [% -+i]",
		"test_i_32 ok [% -+10i]",
		"test_i_33 ok [%0-+10.4i]",
		"test_i_34 ok [%0+10.4i]",
		"test_i_35 ok [%010.4i]",
		"test_i_36 ok [%0.4i]",
		"test_i_37 ok [%0i]",
		"test_i_38 ok [%010i]",
		"test_i_39 ok [%0+.4i]",
		"test_i_40 ok [%0+i]",
		"test_i_41 ok [%0+10i]",
		"test_i_42 ok [%0-10.4i]",
		"test_i_43 ok [%0-.4i]",
		"test_i_44 ok [%0-i]",
		"test_i_45 ok [%0-10i]",
		"test_i_46 ok [%0-+.4i]",
		"test_i_47 ok [%0-+i]",
		"test_i_48 ok [%0-+10i]",
		"test_i_49 ok [%0 +10.4i]",
		"test_i_50 ok [%0 10.4i]",
		"test_i_51 ok [%0 .4i]",
		"test_i_52 ok [%0 i]",
		"test_i_53 ok [%0 10i]",
		"test_i_54 ok [%0 +.4i]",
		"test_i_55 ok [%0 +i]",
		"test_i_56 ok [%0 +10i]",
		"test_i_57 ok [%0 -10.4i]",
		"test_i_58 ok [%0 -.4i]",
		"test_i_59 ok [%0 -i]",
		"test_i_60 ok [%0 -10i]",
		"test_i_61 ok [%0 -+.4i]",
		"test_i_62 ok [%0 -+i]",
		"test_i_63 ok [%0 -+10i]",
		"test_i_64 ok [%# -+10.4i]",
		"test_i_65 ok [%#-+10.4i]",
		"test_i_66 ok [%#+10.4i]",
		"test_i_67 ok [%#10.4i]",
		"test_i_68 ok [%#.4i]",
		"test_i_69 ok [%#i]",
		"test_i_70 ok [%#10i]",
		"test_i_71 ok [%#+.4i]",
		"test_i_72 ok [%#+i]",
		"test_i_73 ok [%#+10i]",
		"test_i_74 ok [%#-10.4i]",
		"test_i_75 ok [%#-.4i]",
		"test_i_76 ok [%#-i]",
		"test_i_77 ok [%#-10i]",
		"test_i_78 ok [%#-+.4i]",
		"test_i_79 ok [%#-+i]",
		"test_i_80 ok [%#-+10i]",
		"test_i_81 ok [%# +10.4i]",
		"test_i_82 ok [%# 10.4i]",
		"test_i_83 ok [%# .4i]",
		"test_i_84 ok [%# i]",
		"test_i_85 ok [%# 10i]",
		"test_i_86 ok [%# +.4i]",
		"test_i_87 ok [%# +i]",
		"test_i_88 ok [%# +10i]",
		"test_i_89 ok [%# -10.4i]",
		"test_i_90 ok [%# -.4i]",
		"test_i_91 ok [%# -i]",
		"test_i_92 ok [%# -10i]",
		"test_i_93 ok [%# -+.4i]",
		"test_i_94 ok [%# -+i]",
		"test_i_95 ok [%# -+10i]",
		"test_i_96 ok [%#0-+10.4i]",
		"test_i_97 ok [%#0+10.4i]",
		"test_i_98 ok [%#010.4i]",
		"test_i_99 ok [%#0.4i]",
		"test_i_100 ok [%#0i]",
		"test_i_101 ok [%#010i]",
		"test_i_102 ok [%#0+.4i]",
		"test_i_103 ok [%#0+i]",
		"test_i_104 ok [%#0+10i]",
		"test_i_105 ok [%#0-10.4i]",
		"test_i_106 ok [%#0-.4i]",
		"test_i_107 ok [%#0-i]",
		"test_i_108 ok [%#0-10i]",
		"test_i_109 ok [%#0-+.4i]",
		"test_i_110 ok [%#0-+i]",
		"test_i_111 ok [%#0-+10i]",
		"test_i_112 ok [%#0 +10.4i]",
		"test_i_113 ok [%#0 10.4i]",
		"test_i_114 ok [%#0 .4i]",
		"test_i_115 ok [%#0 i]",
		"test_i_116 ok [%#0 10i]",
		"test_i_117 ok [%#0 +.4i]",
		"test_i_118 ok [%#0 +i]",
		"test_i_119 ok [%#0 +10i]",
		"test_i_120 ok [%#0 -10.4i]",
		"test_i_121 ok [%#0 -.4i]",
		"test_i_122 ok [%#0 -i]",
		"test_i_123 ok [%#0 -10i]",
		"test_i_124 ok [%#0 -+.4i]",
		"test_i_125 ok [%#0 -+i]",
		"test_i_126 ok [%#0 -+10i]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %i); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
