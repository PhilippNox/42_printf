/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_llx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:28:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: llx] _lld %lld

#include "tests.h"

void test_llx(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_llx_0 ok [%#0 -+10.4llx]",
		"test_llx_1 ok [%0 -+10.4llx]",
		"test_llx_2 ok [% -+10.4llx]",
		"test_llx_3 ok [%-+10.4llx]",
		"test_llx_4 ok [%+10.4llx]",
		"test_llx_5 ok [%10.4llx]",
		"test_llx_6 ok [%.4llx]",
		"test_llx_7 ok [%10llx]",
		"test_llx_8 ok [%+.4llx]",
		"test_llx_9 ok [%+llx]",
		"test_llx_10 ok [%+10llx]",
		"test_llx_11 ok [%-10.4llx]",
		"test_llx_12 ok [%-.4llx]",
		"test_llx_13 ok [%-llx]",
		"test_llx_14 ok [%-10llx]",
		"test_llx_15 ok [%-+.4llx]",
		"test_llx_16 ok [%-+llx]",
		"test_llx_17 ok [%-+10llx]",
		"test_llx_18 ok [% +10.4llx]",
		"test_llx_19 ok [% 10.4llx]",
		"test_llx_20 ok [% .4llx]",
		"test_llx_21 ok [% llx]",
		"test_llx_22 ok [% 10llx]",
		"test_llx_23 ok [% +.4llx]",
		"test_llx_24 ok [% +llx]",
		"test_llx_25 ok [% +10llx]",
		"test_llx_26 ok [% -10.4llx]",
		"test_llx_27 ok [% -.4llx]",
		"test_llx_28 ok [% -llx]",
		"test_llx_29 ok [% -10llx]",
		"test_llx_30 ok [% -+.4llx]",
		"test_llx_31 ok [% -+llx]",
		"test_llx_32 ok [% -+10llx]",
		"test_llx_33 ok [%0-+10.4llx]",
		"test_llx_34 ok [%0+10.4llx]",
		"test_llx_35 ok [%010.4llx]",
		"test_llx_36 ok [%0.4llx]",
		"test_llx_37 ok [%0llx]",
		"test_llx_38 ok [%010llx]",
		"test_llx_39 ok [%0+.4llx]",
		"test_llx_40 ok [%0+llx]",
		"test_llx_41 ok [%0+10llx]",
		"test_llx_42 ok [%0-10.4llx]",
		"test_llx_43 ok [%0-.4llx]",
		"test_llx_44 ok [%0-llx]",
		"test_llx_45 ok [%0-10llx]",
		"test_llx_46 ok [%0-+.4llx]",
		"test_llx_47 ok [%0-+llx]",
		"test_llx_48 ok [%0-+10llx]",
		"test_llx_49 ok [%0 +10.4llx]",
		"test_llx_50 ok [%0 10.4llx]",
		"test_llx_51 ok [%0 .4llx]",
		"test_llx_52 ok [%0 llx]",
		"test_llx_53 ok [%0 10llx]",
		"test_llx_54 ok [%0 +.4llx]",
		"test_llx_55 ok [%0 +llx]",
		"test_llx_56 ok [%0 +10llx]",
		"test_llx_57 ok [%0 -10.4llx]",
		"test_llx_58 ok [%0 -.4llx]",
		"test_llx_59 ok [%0 -llx]",
		"test_llx_60 ok [%0 -10llx]",
		"test_llx_61 ok [%0 -+.4llx]",
		"test_llx_62 ok [%0 -+llx]",
		"test_llx_63 ok [%0 -+10llx]",
		"test_llx_64 ok [%# -+10.4llx]",
		"test_llx_65 ok [%#-+10.4llx]",
		"test_llx_66 ok [%#+10.4llx]",
		"test_llx_67 ok [%#10.4llx]",
		"test_llx_68 ok [%#.4llx]",
		"test_llx_69 ok [%#llx]",
		"test_llx_70 ok [%#10llx]",
		"test_llx_71 ok [%#+.4llx]",
		"test_llx_72 ok [%#+llx]",
		"test_llx_73 ok [%#+10llx]",
		"test_llx_74 ok [%#-10.4llx]",
		"test_llx_75 ok [%#-.4llx]",
		"test_llx_76 ok [%#-llx]",
		"test_llx_77 ok [%#-10llx]",
		"test_llx_78 ok [%#-+.4llx]",
		"test_llx_79 ok [%#-+llx]",
		"test_llx_80 ok [%#-+10llx]",
		"test_llx_81 ok [%# +10.4llx]",
		"test_llx_82 ok [%# 10.4llx]",
		"test_llx_83 ok [%# .4llx]",
		"test_llx_84 ok [%# llx]",
		"test_llx_85 ok [%# 10llx]",
		"test_llx_86 ok [%# +.4llx]",
		"test_llx_87 ok [%# +llx]",
		"test_llx_88 ok [%# +10llx]",
		"test_llx_89 ok [%# -10.4llx]",
		"test_llx_90 ok [%# -.4llx]",
		"test_llx_91 ok [%# -llx]",
		"test_llx_92 ok [%# -10llx]",
		"test_llx_93 ok [%# -+.4llx]",
		"test_llx_94 ok [%# -+llx]",
		"test_llx_95 ok [%# -+10llx]",
		"test_llx_96 ok [%#0-+10.4llx]",
		"test_llx_97 ok [%#0+10.4llx]",
		"test_llx_98 ok [%#010.4llx]",
		"test_llx_99 ok [%#0.4llx]",
		"test_llx_100 ok [%#0llx]",
		"test_llx_101 ok [%#010llx]",
		"test_llx_102 ok [%#0+.4llx]",
		"test_llx_103 ok [%#0+llx]",
		"test_llx_104 ok [%#0+10llx]",
		"test_llx_105 ok [%#0-10.4llx]",
		"test_llx_106 ok [%#0-.4llx]",
		"test_llx_107 ok [%#0-llx]",
		"test_llx_108 ok [%#0-10llx]",
		"test_llx_109 ok [%#0-+.4llx]",
		"test_llx_110 ok [%#0-+llx]",
		"test_llx_111 ok [%#0-+10llx]",
		"test_llx_112 ok [%#0 +10.4llx]",
		"test_llx_113 ok [%#0 10.4llx]",
		"test_llx_114 ok [%#0 .4llx]",
		"test_llx_115 ok [%#0 llx]",
		"test_llx_116 ok [%#0 10llx]",
		"test_llx_117 ok [%#0 +.4llx]",
		"test_llx_118 ok [%#0 +llx]",
		"test_llx_119 ok [%#0 +10llx]",
		"test_llx_120 ok [%#0 -10.4llx]",
		"test_llx_121 ok [%#0 -.4llx]",
		"test_llx_122 ok [%#0 -llx]",
		"test_llx_123 ok [%#0 -10llx]",
		"test_llx_124 ok [%#0 -+.4llx]",
		"test_llx_125 ok [%#0 -+llx]",
		"test_llx_126 ok [%#0 -+10llx]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %llx); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
