/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_llxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:35:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: llX] _lld %lld

#include "tests.h"

void test_llxx(int (*fun)(const char *format, ...))
{
	int idX;
	int idXn;
	char *str[] = {
		"test_llX_0 ok [%#0 -+10.4llX]",
		"test_llX_1 ok [%0 -+10.4llX]",
		"test_llX_2 ok [% -+10.4llX]",
		"test_llX_3 ok [%-+10.4llX]",
		"test_llX_4 ok [%+10.4llX]",
		"test_llX_5 ok [%10.4llX]",
		"test_llX_6 ok [%.4llX]",
		"test_llX_7 ok [%10llX]",
		"test_llX_8 ok [%+.4llX]",
		"test_llX_9 ok [%+llX]",
		"test_llX_10 ok [%+10llX]",
		"test_llX_11 ok [%-10.4llX]",
		"test_llX_12 ok [%-.4llX]",
		"test_llX_13 ok [%-llX]",
		"test_llX_14 ok [%-10llX]",
		"test_llX_15 ok [%-+.4llX]",
		"test_llX_16 ok [%-+llX]",
		"test_llX_17 ok [%-+10llX]",
		"test_llX_18 ok [% +10.4llX]",
		"test_llX_19 ok [% 10.4llX]",
		"test_llX_20 ok [% .4llX]",
		"test_llX_21 ok [% llX]",
		"test_llX_22 ok [% 10llX]",
		"test_llX_23 ok [% +.4llX]",
		"test_llX_24 ok [% +llX]",
		"test_llX_25 ok [% +10llX]",
		"test_llX_26 ok [% -10.4llX]",
		"test_llX_27 ok [% -.4llX]",
		"test_llX_28 ok [% -llX]",
		"test_llX_29 ok [% -10llX]",
		"test_llX_30 ok [% -+.4llX]",
		"test_llX_31 ok [% -+llX]",
		"test_llX_32 ok [% -+10llX]",
		"test_llX_33 ok [%0-+10.4llX]",
		"test_llX_34 ok [%0+10.4llX]",
		"test_llX_35 ok [%010.4llX]",
		"test_llX_36 ok [%0.4llX]",
		"test_llX_37 ok [%0llX]",
		"test_llX_38 ok [%010llX]",
		"test_llX_39 ok [%0+.4llX]",
		"test_llX_40 ok [%0+llX]",
		"test_llX_41 ok [%0+10llX]",
		"test_llX_42 ok [%0-10.4llX]",
		"test_llX_43 ok [%0-.4llX]",
		"test_llX_44 ok [%0-llX]",
		"test_llX_45 ok [%0-10llX]",
		"test_llX_46 ok [%0-+.4llX]",
		"test_llX_47 ok [%0-+llX]",
		"test_llX_48 ok [%0-+10llX]",
		"test_llX_49 ok [%0 +10.4llX]",
		"test_llX_50 ok [%0 10.4llX]",
		"test_llX_51 ok [%0 .4llX]",
		"test_llX_52 ok [%0 llX]",
		"test_llX_53 ok [%0 10llX]",
		"test_llX_54 ok [%0 +.4llX]",
		"test_llX_55 ok [%0 +llX]",
		"test_llX_56 ok [%0 +10llX]",
		"test_llX_57 ok [%0 -10.4llX]",
		"test_llX_58 ok [%0 -.4llX]",
		"test_llX_59 ok [%0 -llX]",
		"test_llX_60 ok [%0 -10llX]",
		"test_llX_61 ok [%0 -+.4llX]",
		"test_llX_62 ok [%0 -+llX]",
		"test_llX_63 ok [%0 -+10llX]",
		"test_llX_64 ok [%# -+10.4llX]",
		"test_llX_65 ok [%#-+10.4llX]",
		"test_llX_66 ok [%#+10.4llX]",
		"test_llX_67 ok [%#10.4llX]",
		"test_llX_68 ok [%#.4llX]",
		"test_llX_69 ok [%#llX]",
		"test_llX_70 ok [%#10llX]",
		"test_llX_71 ok [%#+.4llX]",
		"test_llX_72 ok [%#+llX]",
		"test_llX_73 ok [%#+10llX]",
		"test_llX_74 ok [%#-10.4llX]",
		"test_llX_75 ok [%#-.4llX]",
		"test_llX_76 ok [%#-llX]",
		"test_llX_77 ok [%#-10llX]",
		"test_llX_78 ok [%#-+.4llX]",
		"test_llX_79 ok [%#-+llX]",
		"test_llX_80 ok [%#-+10llX]",
		"test_llX_81 ok [%# +10.4llX]",
		"test_llX_82 ok [%# 10.4llX]",
		"test_llX_83 ok [%# .4llX]",
		"test_llX_84 ok [%# llX]",
		"test_llX_85 ok [%# 10llX]",
		"test_llX_86 ok [%# +.4llX]",
		"test_llX_87 ok [%# +llX]",
		"test_llX_88 ok [%# +10llX]",
		"test_llX_89 ok [%# -10.4llX]",
		"test_llX_90 ok [%# -.4llX]",
		"test_llX_91 ok [%# -llX]",
		"test_llX_92 ok [%# -10llX]",
		"test_llX_93 ok [%# -+.4llX]",
		"test_llX_94 ok [%# -+llX]",
		"test_llX_95 ok [%# -+10llX]",
		"test_llX_96 ok [%#0-+10.4llX]",
		"test_llX_97 ok [%#0+10.4llX]",
		"test_llX_98 ok [%#010.4llX]",
		"test_llX_99 ok [%#0.4llX]",
		"test_llX_100 ok [%#0llX]",
		"test_llX_101 ok [%#010llX]",
		"test_llX_102 ok [%#0+.4llX]",
		"test_llX_103 ok [%#0+llX]",
		"test_llX_104 ok [%#0+10llX]",
		"test_llX_105 ok [%#0-10.4llX]",
		"test_llX_106 ok [%#0-.4llX]",
		"test_llX_107 ok [%#0-llX]",
		"test_llX_108 ok [%#0-10llX]",
		"test_llX_109 ok [%#0-+.4llX]",
		"test_llX_110 ok [%#0-+llX]",
		"test_llX_111 ok [%#0-+10llX]",
		"test_llX_112 ok [%#0 +10.4llX]",
		"test_llX_113 ok [%#0 10.4llX]",
		"test_llX_114 ok [%#0 .4llX]",
		"test_llX_115 ok [%#0 llX]",
		"test_llX_116 ok [%#0 10llX]",
		"test_llX_117 ok [%#0 +.4llX]",
		"test_llX_118 ok [%#0 +llX]",
		"test_llX_119 ok [%#0 +10llX]",
		"test_llX_120 ok [%#0 -10.4llX]",
		"test_llX_121 ok [%#0 -.4llX]",
		"test_llX_122 ok [%#0 -llX]",
		"test_llX_123 ok [%#0 -10llX]",
		"test_llX_124 ok [%#0 -+.4llX]",
		"test_llX_125 ok [%#0 -+llX]",
		"test_llX_126 ok [%#0 -+10llX]",
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

	idX = -1;
	while (str[++idX])
	{
		idXn = -1;
		while (num[++idXn] != stop_num)
		{
			fun(str[idX], num[idXn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %llX); // RUN THIS CODE FOR DEBUG\n", str[idX], num[idXn]);
		}
	}
}
