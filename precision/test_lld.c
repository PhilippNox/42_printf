/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 20:38:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lld] _lld %lld

#include "tests.h"

void test_lld(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_lld_0 ok [%#0 -+10.4lld]",
		"test_lld_1 ok [%0 -+10.4lld]",
		"test_lld_2 ok [% -+10.4lld]",
		"test_lld_3 ok [%-+10.4lld]",
		"test_lld_4 ok [%+10.4lld]",
		"test_lld_5 ok [%10.4lld]",
		"test_lld_6 ok [%.4lld]",
		"test_lld_7 ok [%10lld]",
		"test_lld_8 ok [%+.4lld]",
		"test_lld_9 ok [%+lld]",
		"test_lld_10 ok [%+10lld]",
		"test_lld_11 ok [%-10.4lld]",
		"test_lld_12 ok [%-.4lld]",
		"test_lld_13 ok [%-lld]",
		"test_lld_14 ok [%-10lld]",
		"test_lld_15 ok [%-+.4lld]",
		"test_lld_16 ok [%-+lld]",
		"test_lld_17 ok [%-+10lld]",
		"test_lld_18 ok [% +10.4lld]",
		"test_lld_19 ok [% 10.4lld]",
		"test_lld_20 ok [% .4lld]",
		"test_lld_21 ok [% lld]",
		"test_lld_22 ok [% 10lld]",
		"test_lld_23 ok [% +.4lld]",
		"test_lld_24 ok [% +lld]",
		"test_lld_25 ok [% +10lld]",
		"test_lld_26 ok [% -10.4lld]",
		"test_lld_27 ok [% -.4lld]",
		"test_lld_28 ok [% -lld]",
		"test_lld_29 ok [% -10lld]",
		"test_lld_30 ok [% -+.4lld]",
		"test_lld_31 ok [% -+lld]",
		"test_lld_32 ok [% -+10lld]",
		"test_lld_33 ok [%0-+10.4lld]",
		"test_lld_34 ok [%0+10.4lld]",
		"test_lld_35 ok [%010.4lld]",
		"test_lld_36 ok [%0.4lld]",
		"test_lld_37 ok [%0lld]",
		"test_lld_38 ok [%010lld]",
		"test_lld_39 ok [%0+.4lld]",
		"test_lld_40 ok [%0+lld]",
		"test_lld_41 ok [%0+10lld]",
		"test_lld_42 ok [%0-10.4lld]",
		"test_lld_43 ok [%0-.4lld]",
		"test_lld_44 ok [%0-lld]",
		"test_lld_45 ok [%0-10lld]",
		"test_lld_46 ok [%0-+.4lld]",
		"test_lld_47 ok [%0-+lld]",
		"test_lld_48 ok [%0-+10lld]",
		"test_lld_49 ok [%0 +10.4lld]",
		"test_lld_50 ok [%0 10.4lld]",
		"test_lld_51 ok [%0 .4lld]",
		"test_lld_52 ok [%0 lld]",
		"test_lld_53 ok [%0 10lld]",
		"test_lld_54 ok [%0 +.4lld]",
		"test_lld_55 ok [%0 +lld]",
		"test_lld_56 ok [%0 +10lld]",
		"test_lld_57 ok [%0 -10.4lld]",
		"test_lld_58 ok [%0 -.4lld]",
		"test_lld_59 ok [%0 -lld]",
		"test_lld_60 ok [%0 -10lld]",
		"test_lld_61 ok [%0 -+.4lld]",
		"test_lld_62 ok [%0 -+lld]",
		"test_lld_63 ok [%0 -+10lld]",
		"test_lld_64 ok [%# -+10.4lld]",
		"test_lld_65 ok [%#-+10.4lld]",
		"test_lld_66 ok [%#+10.4lld]",
		"test_lld_67 ok [%#10.4lld]",
		"test_lld_68 ok [%#.4lld]",
		"test_lld_69 ok [%#lld]",
		"test_lld_70 ok [%#10lld]",
		"test_lld_71 ok [%#+.4lld]",
		"test_lld_72 ok [%#+lld]",
		"test_lld_73 ok [%#+10lld]",
		"test_lld_74 ok [%#-10.4lld]",
		"test_lld_75 ok [%#-.4lld]",
		"test_lld_76 ok [%#-lld]",
		"test_lld_77 ok [%#-10lld]",
		"test_lld_78 ok [%#-+.4lld]",
		"test_lld_79 ok [%#-+lld]",
		"test_lld_80 ok [%#-+10lld]",
		"test_lld_81 ok [%# +10.4lld]",
		"test_lld_82 ok [%# 10.4lld]",
		"test_lld_83 ok [%# .4lld]",
		"test_lld_84 ok [%# lld]",
		"test_lld_85 ok [%# 10lld]",
		"test_lld_86 ok [%# +.4lld]",
		"test_lld_87 ok [%# +lld]",
		"test_lld_88 ok [%# +10lld]",
		"test_lld_89 ok [%# -10.4lld]",
		"test_lld_90 ok [%# -.4lld]",
		"test_lld_91 ok [%# -lld]",
		"test_lld_92 ok [%# -10lld]",
		"test_lld_93 ok [%# -+.4lld]",
		"test_lld_94 ok [%# -+lld]",
		"test_lld_95 ok [%# -+10lld]",
		"test_lld_96 ok [%#0-+10.4lld]",
		"test_lld_97 ok [%#0+10.4lld]",
		"test_lld_98 ok [%#010.4lld]",
		"test_lld_99 ok [%#0.4lld]",
		"test_lld_100 ok [%#0lld]",
		"test_lld_101 ok [%#010lld]",
		"test_lld_102 ok [%#0+.4lld]",
		"test_lld_103 ok [%#0+lld]",
		"test_lld_104 ok [%#0+10lld]",
		"test_lld_105 ok [%#0-10.4lld]",
		"test_lld_106 ok [%#0-.4lld]",
		"test_lld_107 ok [%#0-lld]",
		"test_lld_108 ok [%#0-10lld]",
		"test_lld_109 ok [%#0-+.4lld]",
		"test_lld_110 ok [%#0-+lld]",
		"test_lld_111 ok [%#0-+10lld]",
		"test_lld_112 ok [%#0 +10.4lld]",
		"test_lld_113 ok [%#0 10.4lld]",
		"test_lld_114 ok [%#0 .4lld]",
		"test_lld_115 ok [%#0 lld]",
		"test_lld_116 ok [%#0 10lld]",
		"test_lld_117 ok [%#0 +.4lld]",
		"test_lld_118 ok [%#0 +lld]",
		"test_lld_119 ok [%#0 +10lld]",
		"test_lld_120 ok [%#0 -10.4lld]",
		"test_lld_121 ok [%#0 -.4lld]",
		"test_lld_122 ok [%#0 -lld]",
		"test_lld_123 ok [%#0 -10lld]",
		"test_lld_124 ok [%#0 -+.4lld]",
		"test_lld_125 ok [%#0 -+lld]",
		"test_lld_126 ok [%#0 -+10lld]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %lld); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
