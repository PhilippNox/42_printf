/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:10:24 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hu] _hd %hd

#include "tests.h"

void test_hu(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hu_0 ok [%#0 -+10.4hu]",
		"test_hu_1 ok [%0 -+10.4hu]",
		"test_hu_2 ok [% -+10.4hu]",
		"test_hu_3 ok [%-+10.4hu]",
		"test_hu_4 ok [%+10.4hu]",
		"test_hu_5 ok [%10.4hu]",
		"test_hu_6 ok [%.4hu]",
		"test_hu_7 ok [%10hu]",
		"test_hu_8 ok [%+.4hu]",
		"test_hu_9 ok [%+hu]",
		"test_hu_10 ok [%+10hu]",
		"test_hu_11 ok [%-10.4hu]",
		"test_hu_12 ok [%-.4hu]",
		"test_hu_13 ok [%-hu]",
		"test_hu_14 ok [%-10hu]",
		"test_hu_15 ok [%-+.4hu]",
		"test_hu_16 ok [%-+hu]",
		"test_hu_17 ok [%-+10hu]",
		"test_hu_18 ok [% +10.4hu]",
		"test_hu_19 ok [% 10.4hu]",
		"test_hu_20 ok [% .4hu]",
		"test_hu_21 ok [% hu]",
		"test_hu_22 ok [% 10hu]",
		"test_hu_23 ok [% +.4hu]",
		"test_hu_24 ok [% +hu]",
		"test_hu_25 ok [% +10hu]",
		"test_hu_26 ok [% -10.4hu]",
		"test_hu_27 ok [% -.4hu]",
		"test_hu_28 ok [% -hu]",
		"test_hu_29 ok [% -10hu]",
		"test_hu_30 ok [% -+.4hu]",
		"test_hu_31 ok [% -+hu]",
		"test_hu_32 ok [% -+10hu]",
		"test_hu_33 ok [%0-+10.4hu]",
		"test_hu_34 ok [%0+10.4hu]",
		"test_hu_35 ok [%010.4hu]",
		"test_hu_36 ok [%0.4hu]",
		"test_hu_37 ok [%0hu]",
		"test_hu_38 ok [%010hu]",
		"test_hu_39 ok [%0+.4hu]",
		"test_hu_40 ok [%0+hu]",
		"test_hu_41 ok [%0+10hu]",
		"test_hu_42 ok [%0-10.4hu]",
		"test_hu_43 ok [%0-.4hu]",
		"test_hu_44 ok [%0-hu]",
		"test_hu_45 ok [%0-10hu]",
		"test_hu_46 ok [%0-+.4hu]",
		"test_hu_47 ok [%0-+hu]",
		"test_hu_48 ok [%0-+10hu]",
		"test_hu_49 ok [%0 +10.4hu]",
		"test_hu_50 ok [%0 10.4hu]",
		"test_hu_51 ok [%0 .4hu]",
		"test_hu_52 ok [%0 hu]",
		"test_hu_53 ok [%0 10hu]",
		"test_hu_54 ok [%0 +.4hu]",
		"test_hu_55 ok [%0 +hu]",
		"test_hu_56 ok [%0 +10hu]",
		"test_hu_57 ok [%0 -10.4hu]",
		"test_hu_58 ok [%0 -.4hu]",
		"test_hu_59 ok [%0 -hu]",
		"test_hu_60 ok [%0 -10hu]",
		"test_hu_61 ok [%0 -+.4hu]",
		"test_hu_62 ok [%0 -+hu]",
		"test_hu_63 ok [%0 -+10hu]",
		"test_hu_64 ok [%# -+10.4hu]",
		"test_hu_65 ok [%#-+10.4hu]",
		"test_hu_66 ok [%#+10.4hu]",
		"test_hu_67 ok [%#10.4hu]",
		"test_hu_68 ok [%#.4hu]",
		"test_hu_69 ok [%#hu]",
		"test_hu_70 ok [%#10hu]",
		"test_hu_71 ok [%#+.4hu]",
		"test_hu_72 ok [%#+hu]",
		"test_hu_73 ok [%#+10hu]",
		"test_hu_74 ok [%#-10.4hu]",
		"test_hu_75 ok [%#-.4hu]",
		"test_hu_76 ok [%#-hu]",
		"test_hu_77 ok [%#-10hu]",
		"test_hu_78 ok [%#-+.4hu]",
		"test_hu_79 ok [%#-+hu]",
		"test_hu_80 ok [%#-+10hu]",
		"test_hu_81 ok [%# +10.4hu]",
		"test_hu_82 ok [%# 10.4hu]",
		"test_hu_83 ok [%# .4hu]",
		"test_hu_84 ok [%# hu]",
		"test_hu_85 ok [%# 10hu]",
		"test_hu_86 ok [%# +.4hu]",
		"test_hu_87 ok [%# +hu]",
		"test_hu_88 ok [%# +10hu]",
		"test_hu_89 ok [%# -10.4hu]",
		"test_hu_90 ok [%# -.4hu]",
		"test_hu_91 ok [%# -hu]",
		"test_hu_92 ok [%# -10hu]",
		"test_hu_93 ok [%# -+.4hu]",
		"test_hu_94 ok [%# -+hu]",
		"test_hu_95 ok [%# -+10hu]",
		"test_hu_96 ok [%#0-+10.4hu]",
		"test_hu_97 ok [%#0+10.4hu]",
		"test_hu_98 ok [%#010.4hu]",
		"test_hu_99 ok [%#0.4hu]",
		"test_hu_100 ok [%#0hu]",
		"test_hu_101 ok [%#010hu]",
		"test_hu_102 ok [%#0+.4hu]",
		"test_hu_103 ok [%#0+hu]",
		"test_hu_104 ok [%#0+10hu]",
		"test_hu_105 ok [%#0-10.4hu]",
		"test_hu_106 ok [%#0-.4hu]",
		"test_hu_107 ok [%#0-hu]",
		"test_hu_108 ok [%#0-10hu]",
		"test_hu_109 ok [%#0-+.4hu]",
		"test_hu_110 ok [%#0-+hu]",
		"test_hu_111 ok [%#0-+10hu]",
		"test_hu_112 ok [%#0 +10.4hu]",
		"test_hu_113 ok [%#0 10.4hu]",
		"test_hu_114 ok [%#0 .4hu]",
		"test_hu_115 ok [%#0 hu]",
		"test_hu_116 ok [%#0 10hu]",
		"test_hu_117 ok [%#0 +.4hu]",
		"test_hu_118 ok [%#0 +hu]",
		"test_hu_119 ok [%#0 +10hu]",
		"test_hu_120 ok [%#0 -10.4hu]",
		"test_hu_121 ok [%#0 -.4hu]",
		"test_hu_122 ok [%#0 -hu]",
		"test_hu_123 ok [%#0 -10hu]",
		"test_hu_124 ok [%#0 -+.4hu]",
		"test_hu_125 ok [%#0 -+hu]",
		"test_hu_126 ok [%#0 -+10hu]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hu); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
