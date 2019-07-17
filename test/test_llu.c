/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_llu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:10:25 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: llu] _lld %lld

#include "tests.h"

void test_llu(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_llu_0 ok [%#0 -+10.4llu]",
		"test_llu_1 ok [%0 -+10.4llu]",
		"test_llu_2 ok [% -+10.4llu]",
		"test_llu_3 ok [%-+10.4llu]",
		"test_llu_4 ok [%+10.4llu]",
		"test_llu_5 ok [%10.4llu]",
		"test_llu_6 ok [%.4llu]",
		"test_llu_7 ok [%10llu]",
		"test_llu_8 ok [%+.4llu]",
		"test_llu_9 ok [%+llu]",
		"test_llu_10 ok [%+10llu]",
		"test_llu_11 ok [%-10.4llu]",
		"test_llu_12 ok [%-.4llu]",
		"test_llu_13 ok [%-llu]",
		"test_llu_14 ok [%-10llu]",
		"test_llu_15 ok [%-+.4llu]",
		"test_llu_16 ok [%-+llu]",
		"test_llu_17 ok [%-+10llu]",
		"test_llu_18 ok [% +10.4llu]",
		"test_llu_19 ok [% 10.4llu]",
		"test_llu_20 ok [% .4llu]",
		"test_llu_21 ok [% llu]",
		"test_llu_22 ok [% 10llu]",
		"test_llu_23 ok [% +.4llu]",
		"test_llu_24 ok [% +llu]",
		"test_llu_25 ok [% +10llu]",
		"test_llu_26 ok [% -10.4llu]",
		"test_llu_27 ok [% -.4llu]",
		"test_llu_28 ok [% -llu]",
		"test_llu_29 ok [% -10llu]",
		"test_llu_30 ok [% -+.4llu]",
		"test_llu_31 ok [% -+llu]",
		"test_llu_32 ok [% -+10llu]",
		"test_llu_33 ok [%0-+10.4llu]",
		"test_llu_34 ok [%0+10.4llu]",
		"test_llu_35 ok [%010.4llu]",
		"test_llu_36 ok [%0.4llu]",
		"test_llu_37 ok [%0llu]",
		"test_llu_38 ok [%010llu]",
		"test_llu_39 ok [%0+.4llu]",
		"test_llu_40 ok [%0+llu]",
		"test_llu_41 ok [%0+10llu]",
		"test_llu_42 ok [%0-10.4llu]",
		"test_llu_43 ok [%0-.4llu]",
		"test_llu_44 ok [%0-llu]",
		"test_llu_45 ok [%0-10llu]",
		"test_llu_46 ok [%0-+.4llu]",
		"test_llu_47 ok [%0-+llu]",
		"test_llu_48 ok [%0-+10llu]",
		"test_llu_49 ok [%0 +10.4llu]",
		"test_llu_50 ok [%0 10.4llu]",
		"test_llu_51 ok [%0 .4llu]",
		"test_llu_52 ok [%0 llu]",
		"test_llu_53 ok [%0 10llu]",
		"test_llu_54 ok [%0 +.4llu]",
		"test_llu_55 ok [%0 +llu]",
		"test_llu_56 ok [%0 +10llu]",
		"test_llu_57 ok [%0 -10.4llu]",
		"test_llu_58 ok [%0 -.4llu]",
		"test_llu_59 ok [%0 -llu]",
		"test_llu_60 ok [%0 -10llu]",
		"test_llu_61 ok [%0 -+.4llu]",
		"test_llu_62 ok [%0 -+llu]",
		"test_llu_63 ok [%0 -+10llu]",
		"test_llu_64 ok [%# -+10.4llu]",
		"test_llu_65 ok [%#-+10.4llu]",
		"test_llu_66 ok [%#+10.4llu]",
		"test_llu_67 ok [%#10.4llu]",
		"test_llu_68 ok [%#.4llu]",
		"test_llu_69 ok [%#llu]",
		"test_llu_70 ok [%#10llu]",
		"test_llu_71 ok [%#+.4llu]",
		"test_llu_72 ok [%#+llu]",
		"test_llu_73 ok [%#+10llu]",
		"test_llu_74 ok [%#-10.4llu]",
		"test_llu_75 ok [%#-.4llu]",
		"test_llu_76 ok [%#-llu]",
		"test_llu_77 ok [%#-10llu]",
		"test_llu_78 ok [%#-+.4llu]",
		"test_llu_79 ok [%#-+llu]",
		"test_llu_80 ok [%#-+10llu]",
		"test_llu_81 ok [%# +10.4llu]",
		"test_llu_82 ok [%# 10.4llu]",
		"test_llu_83 ok [%# .4llu]",
		"test_llu_84 ok [%# llu]",
		"test_llu_85 ok [%# 10llu]",
		"test_llu_86 ok [%# +.4llu]",
		"test_llu_87 ok [%# +llu]",
		"test_llu_88 ok [%# +10llu]",
		"test_llu_89 ok [%# -10.4llu]",
		"test_llu_90 ok [%# -.4llu]",
		"test_llu_91 ok [%# -llu]",
		"test_llu_92 ok [%# -10llu]",
		"test_llu_93 ok [%# -+.4llu]",
		"test_llu_94 ok [%# -+llu]",
		"test_llu_95 ok [%# -+10llu]",
		"test_llu_96 ok [%#0-+10.4llu]",
		"test_llu_97 ok [%#0+10.4llu]",
		"test_llu_98 ok [%#010.4llu]",
		"test_llu_99 ok [%#0.4llu]",
		"test_llu_100 ok [%#0llu]",
		"test_llu_101 ok [%#010llu]",
		"test_llu_102 ok [%#0+.4llu]",
		"test_llu_103 ok [%#0+llu]",
		"test_llu_104 ok [%#0+10llu]",
		"test_llu_105 ok [%#0-10.4llu]",
		"test_llu_106 ok [%#0-.4llu]",
		"test_llu_107 ok [%#0-llu]",
		"test_llu_108 ok [%#0-10llu]",
		"test_llu_109 ok [%#0-+.4llu]",
		"test_llu_110 ok [%#0-+llu]",
		"test_llu_111 ok [%#0-+10llu]",
		"test_llu_112 ok [%#0 +10.4llu]",
		"test_llu_113 ok [%#0 10.4llu]",
		"test_llu_114 ok [%#0 .4llu]",
		"test_llu_115 ok [%#0 llu]",
		"test_llu_116 ok [%#0 10llu]",
		"test_llu_117 ok [%#0 +.4llu]",
		"test_llu_118 ok [%#0 +llu]",
		"test_llu_119 ok [%#0 +10llu]",
		"test_llu_120 ok [%#0 -10.4llu]",
		"test_llu_121 ok [%#0 -.4llu]",
		"test_llu_122 ok [%#0 -llu]",
		"test_llu_123 ok [%#0 -10llu]",
		"test_llu_124 ok [%#0 -+.4llu]",
		"test_llu_125 ok [%#0 -+llu]",
		"test_llu_126 ok [%#0 -+10llu]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %llu); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
