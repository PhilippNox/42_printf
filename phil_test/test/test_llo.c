/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_llo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:04:28 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: llo] _lld %lld

#include "tests.h"

void test_llo(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_llo_0 ok [%#0 -+10.4llo]",
		"test_llo_1 ok [%0 -+10.4llo]",
		"test_llo_2 ok [% -+10.4llo]",
		"test_llo_3 ok [%-+10.4llo]",
		"test_llo_4 ok [%+10.4llo]",
		"test_llo_5 ok [%10.4llo]",
		"test_llo_6 ok [%.4llo]",
		"test_llo_7 ok [%10llo]",
		"test_llo_8 ok [%+.4llo]",
		"test_llo_9 ok [%+llo]",
		"test_llo_10 ok [%+10llo]",
		"test_llo_11 ok [%-10.4llo]",
		"test_llo_12 ok [%-.4llo]",
		"test_llo_13 ok [%-llo]",
		"test_llo_14 ok [%-10llo]",
		"test_llo_15 ok [%-+.4llo]",
		"test_llo_16 ok [%-+llo]",
		"test_llo_17 ok [%-+10llo]",
		"test_llo_18 ok [% +10.4llo]",
		"test_llo_19 ok [% 10.4llo]",
		"test_llo_20 ok [% .4llo]",
		"test_llo_21 ok [% llo]",
		"test_llo_22 ok [% 10llo]",
		"test_llo_23 ok [% +.4llo]",
		"test_llo_24 ok [% +llo]",
		"test_llo_25 ok [% +10llo]",
		"test_llo_26 ok [% -10.4llo]",
		"test_llo_27 ok [% -.4llo]",
		"test_llo_28 ok [% -llo]",
		"test_llo_29 ok [% -10llo]",
		"test_llo_30 ok [% -+.4llo]",
		"test_llo_31 ok [% -+llo]",
		"test_llo_32 ok [% -+10llo]",
		"test_llo_33 ok [%0-+10.4llo]",
		"test_llo_34 ok [%0+10.4llo]",
		"test_llo_35 ok [%010.4llo]",
		"test_llo_36 ok [%0.4llo]",
		"test_llo_37 ok [%0llo]",
		"test_llo_38 ok [%010llo]",
		"test_llo_39 ok [%0+.4llo]",
		"test_llo_40 ok [%0+llo]",
		"test_llo_41 ok [%0+10llo]",
		"test_llo_42 ok [%0-10.4llo]",
		"test_llo_43 ok [%0-.4llo]",
		"test_llo_44 ok [%0-llo]",
		"test_llo_45 ok [%0-10llo]",
		"test_llo_46 ok [%0-+.4llo]",
		"test_llo_47 ok [%0-+llo]",
		"test_llo_48 ok [%0-+10llo]",
		"test_llo_49 ok [%0 +10.4llo]",
		"test_llo_50 ok [%0 10.4llo]",
		"test_llo_51 ok [%0 .4llo]",
		"test_llo_52 ok [%0 llo]",
		"test_llo_53 ok [%0 10llo]",
		"test_llo_54 ok [%0 +.4llo]",
		"test_llo_55 ok [%0 +llo]",
		"test_llo_56 ok [%0 +10llo]",
		"test_llo_57 ok [%0 -10.4llo]",
		"test_llo_58 ok [%0 -.4llo]",
		"test_llo_59 ok [%0 -llo]",
		"test_llo_60 ok [%0 -10llo]",
		"test_llo_61 ok [%0 -+.4llo]",
		"test_llo_62 ok [%0 -+llo]",
		"test_llo_63 ok [%0 -+10llo]",
		"test_llo_64 ok [%# -+10.4llo]",
		"test_llo_65 ok [%#-+10.4llo]",
		"test_llo_66 ok [%#+10.4llo]",
		"test_llo_67 ok [%#10.4llo]",
		"test_llo_68 ok [%#.4llo]",
		"test_llo_69 ok [%#llo]",
		"test_llo_70 ok [%#10llo]",
		"test_llo_71 ok [%#+.4llo]",
		"test_llo_72 ok [%#+llo]",
		"test_llo_73 ok [%#+10llo]",
		"test_llo_74 ok [%#-10.4llo]",
		"test_llo_75 ok [%#-.4llo]",
		"test_llo_76 ok [%#-llo]",
		"test_llo_77 ok [%#-10llo]",
		"test_llo_78 ok [%#-+.4llo]",
		"test_llo_79 ok [%#-+llo]",
		"test_llo_80 ok [%#-+10llo]",
		"test_llo_81 ok [%# +10.4llo]",
		"test_llo_82 ok [%# 10.4llo]",
		"test_llo_83 ok [%# .4llo]",
		"test_llo_84 ok [%# llo]",
		"test_llo_85 ok [%# 10llo]",
		"test_llo_86 ok [%# +.4llo]",
		"test_llo_87 ok [%# +llo]",
		"test_llo_88 ok [%# +10llo]",
		"test_llo_89 ok [%# -10.4llo]",
		"test_llo_90 ok [%# -.4llo]",
		"test_llo_91 ok [%# -llo]",
		"test_llo_92 ok [%# -10llo]",
		"test_llo_93 ok [%# -+.4llo]",
		"test_llo_94 ok [%# -+llo]",
		"test_llo_95 ok [%# -+10llo]",
		"test_llo_96 ok [%#0-+10.4llo]",
		"test_llo_97 ok [%#0+10.4llo]",
		"test_llo_98 ok [%#010.4llo]",
		"test_llo_99 ok [%#0.4llo]",
		"test_llo_100 ok [%#0llo]",
		"test_llo_101 ok [%#010llo]",
		"test_llo_102 ok [%#0+.4llo]",
		"test_llo_103 ok [%#0+llo]",
		"test_llo_104 ok [%#0+10llo]",
		"test_llo_105 ok [%#0-10.4llo]",
		"test_llo_106 ok [%#0-.4llo]",
		"test_llo_107 ok [%#0-llo]",
		"test_llo_108 ok [%#0-10llo]",
		"test_llo_109 ok [%#0-+.4llo]",
		"test_llo_110 ok [%#0-+llo]",
		"test_llo_111 ok [%#0-+10llo]",
		"test_llo_112 ok [%#0 +10.4llo]",
		"test_llo_113 ok [%#0 10.4llo]",
		"test_llo_114 ok [%#0 .4llo]",
		"test_llo_115 ok [%#0 llo]",
		"test_llo_116 ok [%#0 10llo]",
		"test_llo_117 ok [%#0 +.4llo]",
		"test_llo_118 ok [%#0 +llo]",
		"test_llo_119 ok [%#0 +10llo]",
		"test_llo_120 ok [%#0 -10.4llo]",
		"test_llo_121 ok [%#0 -.4llo]",
		"test_llo_122 ok [%#0 -llo]",
		"test_llo_123 ok [%#0 -10llo]",
		"test_llo_124 ok [%#0 -+.4llo]",
		"test_llo_125 ok [%#0 -+llo]",
		"test_llo_126 ok [%#0 -+10llo]",
		NULL
	};

	long long stop_num = -42;
	long long num[] = {
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
			fun("\t\t\t\t//\tprintf(\"%s\", %llo); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
