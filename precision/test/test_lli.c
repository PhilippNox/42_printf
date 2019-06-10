/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:40:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lli] _lld %lld

#include "tests.h"

void test_lli(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_lli_0 ok [%#0 -+10.4lli]",
		"test_lli_1 ok [%0 -+10.4lli]",
		"test_lli_2 ok [% -+10.4lli]",
		"test_lli_3 ok [%-+10.4lli]",
		"test_lli_4 ok [%+10.4lli]",
		"test_lli_5 ok [%10.4lli]",
		"test_lli_6 ok [%.4lli]",
		"test_lli_7 ok [%10lli]",
		"test_lli_8 ok [%+.4lli]",
		"test_lli_9 ok [%+lli]",
		"test_lli_10 ok [%+10lli]",
		"test_lli_11 ok [%-10.4lli]",
		"test_lli_12 ok [%-.4lli]",
		"test_lli_13 ok [%-lli]",
		"test_lli_14 ok [%-10lli]",
		"test_lli_15 ok [%-+.4lli]",
		"test_lli_16 ok [%-+lli]",
		"test_lli_17 ok [%-+10lli]",
		"test_lli_18 ok [% +10.4lli]",
		"test_lli_19 ok [% 10.4lli]",
		"test_lli_20 ok [% .4lli]",
		"test_lli_21 ok [% lli]",
		"test_lli_22 ok [% 10lli]",
		"test_lli_23 ok [% +.4lli]",
		"test_lli_24 ok [% +lli]",
		"test_lli_25 ok [% +10lli]",
		"test_lli_26 ok [% -10.4lli]",
		"test_lli_27 ok [% -.4lli]",
		"test_lli_28 ok [% -lli]",
		"test_lli_29 ok [% -10lli]",
		"test_lli_30 ok [% -+.4lli]",
		"test_lli_31 ok [% -+lli]",
		"test_lli_32 ok [% -+10lli]",
		"test_lli_33 ok [%0-+10.4lli]",
		"test_lli_34 ok [%0+10.4lli]",
		"test_lli_35 ok [%010.4lli]",
		"test_lli_36 ok [%0.4lli]",
		"test_lli_37 ok [%0lli]",
		"test_lli_38 ok [%010lli]",
		"test_lli_39 ok [%0+.4lli]",
		"test_lli_40 ok [%0+lli]",
		"test_lli_41 ok [%0+10lli]",
		"test_lli_42 ok [%0-10.4lli]",
		"test_lli_43 ok [%0-.4lli]",
		"test_lli_44 ok [%0-lli]",
		"test_lli_45 ok [%0-10lli]",
		"test_lli_46 ok [%0-+.4lli]",
		"test_lli_47 ok [%0-+lli]",
		"test_lli_48 ok [%0-+10lli]",
		"test_lli_49 ok [%0 +10.4lli]",
		"test_lli_50 ok [%0 10.4lli]",
		"test_lli_51 ok [%0 .4lli]",
		"test_lli_52 ok [%0 lli]",
		"test_lli_53 ok [%0 10lli]",
		"test_lli_54 ok [%0 +.4lli]",
		"test_lli_55 ok [%0 +lli]",
		"test_lli_56 ok [%0 +10lli]",
		"test_lli_57 ok [%0 -10.4lli]",
		"test_lli_58 ok [%0 -.4lli]",
		"test_lli_59 ok [%0 -lli]",
		"test_lli_60 ok [%0 -10lli]",
		"test_lli_61 ok [%0 -+.4lli]",
		"test_lli_62 ok [%0 -+lli]",
		"test_lli_63 ok [%0 -+10lli]",
		"test_lli_64 ok [%# -+10.4lli]",
		"test_lli_65 ok [%#-+10.4lli]",
		"test_lli_66 ok [%#+10.4lli]",
		"test_lli_67 ok [%#10.4lli]",
		"test_lli_68 ok [%#.4lli]",
		"test_lli_69 ok [%#lli]",
		"test_lli_70 ok [%#10lli]",
		"test_lli_71 ok [%#+.4lli]",
		"test_lli_72 ok [%#+lli]",
		"test_lli_73 ok [%#+10lli]",
		"test_lli_74 ok [%#-10.4lli]",
		"test_lli_75 ok [%#-.4lli]",
		"test_lli_76 ok [%#-lli]",
		"test_lli_77 ok [%#-10lli]",
		"test_lli_78 ok [%#-+.4lli]",
		"test_lli_79 ok [%#-+lli]",
		"test_lli_80 ok [%#-+10lli]",
		"test_lli_81 ok [%# +10.4lli]",
		"test_lli_82 ok [%# 10.4lli]",
		"test_lli_83 ok [%# .4lli]",
		"test_lli_84 ok [%# lli]",
		"test_lli_85 ok [%# 10lli]",
		"test_lli_86 ok [%# +.4lli]",
		"test_lli_87 ok [%# +lli]",
		"test_lli_88 ok [%# +10lli]",
		"test_lli_89 ok [%# -10.4lli]",
		"test_lli_90 ok [%# -.4lli]",
		"test_lli_91 ok [%# -lli]",
		"test_lli_92 ok [%# -10lli]",
		"test_lli_93 ok [%# -+.4lli]",
		"test_lli_94 ok [%# -+lli]",
		"test_lli_95 ok [%# -+10lli]",
		"test_lli_96 ok [%#0-+10.4lli]",
		"test_lli_97 ok [%#0+10.4lli]",
		"test_lli_98 ok [%#010.4lli]",
		"test_lli_99 ok [%#0.4lli]",
		"test_lli_100 ok [%#0lli]",
		"test_lli_101 ok [%#010lli]",
		"test_lli_102 ok [%#0+.4lli]",
		"test_lli_103 ok [%#0+lli]",
		"test_lli_104 ok [%#0+10lli]",
		"test_lli_105 ok [%#0-10.4lli]",
		"test_lli_106 ok [%#0-.4lli]",
		"test_lli_107 ok [%#0-lli]",
		"test_lli_108 ok [%#0-10lli]",
		"test_lli_109 ok [%#0-+.4lli]",
		"test_lli_110 ok [%#0-+lli]",
		"test_lli_111 ok [%#0-+10lli]",
		"test_lli_112 ok [%#0 +10.4lli]",
		"test_lli_113 ok [%#0 10.4lli]",
		"test_lli_114 ok [%#0 .4lli]",
		"test_lli_115 ok [%#0 lli]",
		"test_lli_116 ok [%#0 10lli]",
		"test_lli_117 ok [%#0 +.4lli]",
		"test_lli_118 ok [%#0 +lli]",
		"test_lli_119 ok [%#0 +10lli]",
		"test_lli_120 ok [%#0 -10.4lli]",
		"test_lli_121 ok [%#0 -.4lli]",
		"test_lli_122 ok [%#0 -lli]",
		"test_lli_123 ok [%#0 -10lli]",
		"test_lli_124 ok [%#0 -+.4lli]",
		"test_lli_125 ok [%#0 -+lli]",
		"test_lli_126 ok [%#0 -+10lli]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %lli); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
