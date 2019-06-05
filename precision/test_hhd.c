/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 19:32:20 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hhd] _hhd %hhd

#include "tests.h"

void test_hhd(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hhd_0 ok [%#0 -+10.4hhd]",
		"test_hhd_1 ok [%0 -+10.4hhd]",
		"test_hhd_2 ok [% -+10.4hhd]",
		"test_hhd_3 ok [%-+10.4hhd]",
		"test_hhd_4 ok [%+10.4hhd]",
		"test_hhd_5 ok [%10.4hhd]",
		"test_hhd_6 ok [%.4hhd]",
		"test_hhd_7 ok [%10hhd]",
		"test_hhd_8 ok [%+.4hhd]",
		"test_hhd_9 ok [%+hhd]",
		"test_hhd_10 ok [%+10hhd]",
		"test_hhd_11 ok [%-10.4hhd]",
		"test_hhd_12 ok [%-.4hhd]",
		"test_hhd_13 ok [%-hhd]",
		"test_hhd_14 ok [%-10hhd]",
		"test_hhd_15 ok [%-+.4hhd]",
		"test_hhd_16 ok [%-+hhd]",
		"test_hhd_17 ok [%-+10hhd]",
		"test_hhd_18 ok [% +10.4hhd]",
		"test_hhd_19 ok [% 10.4hhd]",
		"test_hhd_20 ok [% .4hhd]",
		"test_hhd_21 ok [% hhd]",
		"test_hhd_22 ok [% 10hhd]",
		"test_hhd_23 ok [% +.4hhd]",
		"test_hhd_24 ok [% +hhd]",
		"test_hhd_25 ok [% +10hhd]",
		"test_hhd_26 ok [% -10.4hhd]",
		"test_hhd_27 ok [% -.4hhd]",
		"test_hhd_28 ok [% -hhd]",
		"test_hhd_29 ok [% -10hhd]",
		"test_hhd_30 ok [% -+.4hhd]",
		"test_hhd_31 ok [% -+hhd]",
		"test_hhd_32 ok [% -+10hhd]",
		"test_hhd_33 ok [%0-+10.4hhd]",
		"test_hhd_34 ok [%0+10.4hhd]",
		"test_hhd_35 ok [%010.4hhd]",
		"test_hhd_36 ok [%0.4hhd]",
		"test_hhd_37 ok [%0hhd]",
		"test_hhd_38 ok [%010hhd]",
		"test_hhd_39 ok [%0+.4hhd]",
		"test_hhd_40 ok [%0+hhd]",
		"test_hhd_41 ok [%0+10hhd]",
		"test_hhd_42 ok [%0-10.4hhd]",
		"test_hhd_43 ok [%0-.4hhd]",
		"test_hhd_44 ok [%0-hhd]",
		"test_hhd_45 ok [%0-10hhd]",
		"test_hhd_46 ok [%0-+.4hhd]",
		"test_hhd_47 ok [%0-+hhd]",
		"test_hhd_48 ok [%0-+10hhd]",
		"test_hhd_49 ok [%0 +10.4hhd]",
		"test_hhd_50 ok [%0 10.4hhd]",
		"test_hhd_51 ok [%0 .4hhd]",
		"test_hhd_52 ok [%0 hhd]",
		"test_hhd_53 ok [%0 10hhd]",
		"test_hhd_54 ok [%0 +.4hhd]",
		"test_hhd_55 ok [%0 +hhd]",
		"test_hhd_56 ok [%0 +10hhd]",
		"test_hhd_57 ok [%0 -10.4hhd]",
		"test_hhd_58 ok [%0 -.4hhd]",
		"test_hhd_59 ok [%0 -hhd]",
		"test_hhd_60 ok [%0 -10hhd]",
		"test_hhd_61 ok [%0 -+.4hhd]",
		"test_hhd_62 ok [%0 -+hhd]",
		"test_hhd_63 ok [%0 -+10hhd]",
		"test_hhd_64 ok [%# -+10.4hhd]",
		"test_hhd_65 ok [%#-+10.4hhd]",
		"test_hhd_66 ok [%#+10.4hhd]",
		"test_hhd_67 ok [%#10.4hhd]",
		"test_hhd_68 ok [%#.4hhd]",
		"test_hhd_69 ok [%#hhd]",
		"test_hhd_70 ok [%#10hhd]",
		"test_hhd_71 ok [%#+.4hhd]",
		"test_hhd_72 ok [%#+hhd]",
		"test_hhd_73 ok [%#+10hhd]",
		"test_hhd_74 ok [%#-10.4hhd]",
		"test_hhd_75 ok [%#-.4hhd]",
		"test_hhd_76 ok [%#-hhd]",
		"test_hhd_77 ok [%#-10hhd]",
		"test_hhd_78 ok [%#-+.4hhd]",
		"test_hhd_79 ok [%#-+hhd]",
		"test_hhd_80 ok [%#-+10hhd]",
		"test_hhd_81 ok [%# +10.4hhd]",
		"test_hhd_82 ok [%# 10.4hhd]",
		"test_hhd_83 ok [%# .4hhd]",
		"test_hhd_84 ok [%# hhd]",
		"test_hhd_85 ok [%# 10hhd]",
		"test_hhd_86 ok [%# +.4hhd]",
		"test_hhd_87 ok [%# +hhd]",
		"test_hhd_88 ok [%# +10hhd]",
		"test_hhd_89 ok [%# -10.4hhd]",
		"test_hhd_90 ok [%# -.4hhd]",
		"test_hhd_91 ok [%# -hhd]",
		"test_hhd_92 ok [%# -10hhd]",
		"test_hhd_93 ok [%# -+.4hhd]",
		"test_hhd_94 ok [%# -+hhd]",
		"test_hhd_95 ok [%# -+10hhd]",
		"test_hhd_96 ok [%#0-+10.4hhd]",
		"test_hhd_97 ok [%#0+10.4hhd]",
		"test_hhd_98 ok [%#010.4hhd]",
		"test_hhd_99 ok [%#0.4hhd]",
		"test_hhd_100 ok [%#0hhd]",
		"test_hhd_101 ok [%#010hhd]",
		"test_hhd_102 ok [%#0+.4hhd]",
		"test_hhd_103 ok [%#0+hhd]",
		"test_hhd_104 ok [%#0+10hhd]",
		"test_hhd_105 ok [%#0-10.4hhd]",
		"test_hhd_106 ok [%#0-.4hhd]",
		"test_hhd_107 ok [%#0-hhd]",
		"test_hhd_108 ok [%#0-10hhd]",
		"test_hhd_109 ok [%#0-+.4hhd]",
		"test_hhd_110 ok [%#0-+hhd]",
		"test_hhd_111 ok [%#0-+10hhd]",
		"test_hhd_112 ok [%#0 +10.4hhd]",
		"test_hhd_113 ok [%#0 10.4hhd]",
		"test_hhd_114 ok [%#0 .4hhd]",
		"test_hhd_115 ok [%#0 hhd]",
		"test_hhd_116 ok [%#0 10hhd]",
		"test_hhd_117 ok [%#0 +.4hhd]",
		"test_hhd_118 ok [%#0 +hhd]",
		"test_hhd_119 ok [%#0 +10hhd]",
		"test_hhd_120 ok [%#0 -10.4hhd]",
		"test_hhd_121 ok [%#0 -.4hhd]",
		"test_hhd_122 ok [%#0 -hhd]",
		"test_hhd_123 ok [%#0 -10hhd]",
		"test_hhd_124 ok [%#0 -+.4hhd]",
		"test_hhd_125 ok [%#0 -+hhd]",
		"test_hhd_126 ok [%#0 -+10hhd]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hhd); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
