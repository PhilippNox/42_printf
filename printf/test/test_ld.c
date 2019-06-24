/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 20:39:05 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: ld] _ld %ld

#include "tests.h"

void test_ld(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_ld_0 ok [%#0 -+10.4ld]",
		"test_ld_1 ok [%0 -+10.4ld]",
		"test_ld_2 ok [% -+10.4ld]",
		"test_ld_3 ok [%-+10.4ld]",
		"test_ld_4 ok [%+10.4ld]",
		"test_ld_5 ok [%10.4ld]",
		"test_ld_6 ok [%.4ld]",
		"test_ld_7 ok [%10ld]",
		"test_ld_8 ok [%+.4ld]",
		"test_ld_9 ok [%+ld]",
		"test_ld_10 ok [%+10ld]",
		"test_ld_11 ok [%-10.4ld]",
		"test_ld_12 ok [%-.4ld]",
		"test_ld_13 ok [%-ld]",
		"test_ld_14 ok [%-10ld]",
		"test_ld_15 ok [%-+.4ld]",
		"test_ld_16 ok [%-+ld]",
		"test_ld_17 ok [%-+10ld]",
		"test_ld_18 ok [% +10.4ld]",
		"test_ld_19 ok [% 10.4ld]",
		"test_ld_20 ok [% .4ld]",
		"test_ld_21 ok [% ld]",
		"test_ld_22 ok [% 10ld]",
		"test_ld_23 ok [% +.4ld]",
		"test_ld_24 ok [% +ld]",
		"test_ld_25 ok [% +10ld]",
		"test_ld_26 ok [% -10.4ld]",
		"test_ld_27 ok [% -.4ld]",
		"test_ld_28 ok [% -ld]",
		"test_ld_29 ok [% -10ld]",
		"test_ld_30 ok [% -+.4ld]",
		"test_ld_31 ok [% -+ld]",
		"test_ld_32 ok [% -+10ld]",
		"test_ld_33 ok [%0-+10.4ld]",
		"test_ld_34 ok [%0+10.4ld]",
		"test_ld_35 ok [%010.4ld]",
		"test_ld_36 ok [%0.4ld]",
		"test_ld_37 ok [%0ld]",
		"test_ld_38 ok [%010ld]",
		"test_ld_39 ok [%0+.4ld]",
		"test_ld_40 ok [%0+ld]",
		"test_ld_41 ok [%0+10ld]",
		"test_ld_42 ok [%0-10.4ld]",
		"test_ld_43 ok [%0-.4ld]",
		"test_ld_44 ok [%0-ld]",
		"test_ld_45 ok [%0-10ld]",
		"test_ld_46 ok [%0-+.4ld]",
		"test_ld_47 ok [%0-+ld]",
		"test_ld_48 ok [%0-+10ld]",
		"test_ld_49 ok [%0 +10.4ld]",
		"test_ld_50 ok [%0 10.4ld]",
		"test_ld_51 ok [%0 .4ld]",
		"test_ld_52 ok [%0 ld]",
		"test_ld_53 ok [%0 10ld]",
		"test_ld_54 ok [%0 +.4ld]",
		"test_ld_55 ok [%0 +ld]",
		"test_ld_56 ok [%0 +10ld]",
		"test_ld_57 ok [%0 -10.4ld]",
		"test_ld_58 ok [%0 -.4ld]",
		"test_ld_59 ok [%0 -ld]",
		"test_ld_60 ok [%0 -10ld]",
		"test_ld_61 ok [%0 -+.4ld]",
		"test_ld_62 ok [%0 -+ld]",
		"test_ld_63 ok [%0 -+10ld]",
		"test_ld_64 ok [%# -+10.4ld]",
		"test_ld_65 ok [%#-+10.4ld]",
		"test_ld_66 ok [%#+10.4ld]",
		"test_ld_67 ok [%#10.4ld]",
		"test_ld_68 ok [%#.4ld]",
		"test_ld_69 ok [%#ld]",
		"test_ld_70 ok [%#10ld]",
		"test_ld_71 ok [%#+.4ld]",
		"test_ld_72 ok [%#+ld]",
		"test_ld_73 ok [%#+10ld]",
		"test_ld_74 ok [%#-10.4ld]",
		"test_ld_75 ok [%#-.4ld]",
		"test_ld_76 ok [%#-ld]",
		"test_ld_77 ok [%#-10ld]",
		"test_ld_78 ok [%#-+.4ld]",
		"test_ld_79 ok [%#-+ld]",
		"test_ld_80 ok [%#-+10ld]",
		"test_ld_81 ok [%# +10.4ld]",
		"test_ld_82 ok [%# 10.4ld]",
		"test_ld_83 ok [%# .4ld]",
		"test_ld_84 ok [%# ld]",
		"test_ld_85 ok [%# 10ld]",
		"test_ld_86 ok [%# +.4ld]",
		"test_ld_87 ok [%# +ld]",
		"test_ld_88 ok [%# +10ld]",
		"test_ld_89 ok [%# -10.4ld]",
		"test_ld_90 ok [%# -.4ld]",
		"test_ld_91 ok [%# -ld]",
		"test_ld_92 ok [%# -10ld]",
		"test_ld_93 ok [%# -+.4ld]",
		"test_ld_94 ok [%# -+ld]",
		"test_ld_95 ok [%# -+10ld]",
		"test_ld_96 ok [%#0-+10.4ld]",
		"test_ld_97 ok [%#0+10.4ld]",
		"test_ld_98 ok [%#010.4ld]",
		"test_ld_99 ok [%#0.4ld]",
		"test_ld_100 ok [%#0ld]",
		"test_ld_101 ok [%#010ld]",
		"test_ld_102 ok [%#0+.4ld]",
		"test_ld_103 ok [%#0+ld]",
		"test_ld_104 ok [%#0+10ld]",
		"test_ld_105 ok [%#0-10.4ld]",
		"test_ld_106 ok [%#0-.4ld]",
		"test_ld_107 ok [%#0-ld]",
		"test_ld_108 ok [%#0-10ld]",
		"test_ld_109 ok [%#0-+.4ld]",
		"test_ld_110 ok [%#0-+ld]",
		"test_ld_111 ok [%#0-+10ld]",
		"test_ld_112 ok [%#0 +10.4ld]",
		"test_ld_113 ok [%#0 10.4ld]",
		"test_ld_114 ok [%#0 .4ld]",
		"test_ld_115 ok [%#0 ld]",
		"test_ld_116 ok [%#0 10ld]",
		"test_ld_117 ok [%#0 +.4ld]",
		"test_ld_118 ok [%#0 +ld]",
		"test_ld_119 ok [%#0 +10ld]",
		"test_ld_120 ok [%#0 -10.4ld]",
		"test_ld_121 ok [%#0 -.4ld]",
		"test_ld_122 ok [%#0 -ld]",
		"test_ld_123 ok [%#0 -10ld]",
		"test_ld_124 ok [%#0 -+.4ld]",
		"test_ld_125 ok [%#0 -+ld]",
		"test_ld_126 ok [%#0 -+10ld]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %ld); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
