/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:34:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lX] _ld %ld

#include "tests.h"

void test_lxx(int (*fun)(const char *format, ...))
{
	int idX;
	int idXn;
	char *str[] = {
		"test_lX_0 ok [%#0 -+10.4lX]",
		"test_lX_1 ok [%0 -+10.4lX]",
		"test_lX_2 ok [% -+10.4lX]",
		"test_lX_3 ok [%-+10.4lX]",
		"test_lX_4 ok [%+10.4lX]",
		"test_lX_5 ok [%10.4lX]",
		"test_lX_6 ok [%.4lX]",
		"test_lX_7 ok [%10lX]",
		"test_lX_8 ok [%+.4lX]",
		"test_lX_9 ok [%+lX]",
		"test_lX_10 ok [%+10lX]",
		"test_lX_11 ok [%-10.4lX]",
		"test_lX_12 ok [%-.4lX]",
		"test_lX_13 ok [%-lX]",
		"test_lX_14 ok [%-10lX]",
		"test_lX_15 ok [%-+.4lX]",
		"test_lX_16 ok [%-+lX]",
		"test_lX_17 ok [%-+10lX]",
		"test_lX_18 ok [% +10.4lX]",
		"test_lX_19 ok [% 10.4lX]",
		"test_lX_20 ok [% .4lX]",
		"test_lX_21 ok [% lX]",
		"test_lX_22 ok [% 10lX]",
		"test_lX_23 ok [% +.4lX]",
		"test_lX_24 ok [% +lX]",
		"test_lX_25 ok [% +10lX]",
		"test_lX_26 ok [% -10.4lX]",
		"test_lX_27 ok [% -.4lX]",
		"test_lX_28 ok [% -lX]",
		"test_lX_29 ok [% -10lX]",
		"test_lX_30 ok [% -+.4lX]",
		"test_lX_31 ok [% -+lX]",
		"test_lX_32 ok [% -+10lX]",
		"test_lX_33 ok [%0-+10.4lX]",
		"test_lX_34 ok [%0+10.4lX]",
		"test_lX_35 ok [%010.4lX]",
		"test_lX_36 ok [%0.4lX]",
		"test_lX_37 ok [%0lX]",
		"test_lX_38 ok [%010lX]",
		"test_lX_39 ok [%0+.4lX]",
		"test_lX_40 ok [%0+lX]",
		"test_lX_41 ok [%0+10lX]",
		"test_lX_42 ok [%0-10.4lX]",
		"test_lX_43 ok [%0-.4lX]",
		"test_lX_44 ok [%0-lX]",
		"test_lX_45 ok [%0-10lX]",
		"test_lX_46 ok [%0-+.4lX]",
		"test_lX_47 ok [%0-+lX]",
		"test_lX_48 ok [%0-+10lX]",
		"test_lX_49 ok [%0 +10.4lX]",
		"test_lX_50 ok [%0 10.4lX]",
		"test_lX_51 ok [%0 .4lX]",
		"test_lX_52 ok [%0 lX]",
		"test_lX_53 ok [%0 10lX]",
		"test_lX_54 ok [%0 +.4lX]",
		"test_lX_55 ok [%0 +lX]",
		"test_lX_56 ok [%0 +10lX]",
		"test_lX_57 ok [%0 -10.4lX]",
		"test_lX_58 ok [%0 -.4lX]",
		"test_lX_59 ok [%0 -lX]",
		"test_lX_60 ok [%0 -10lX]",
		"test_lX_61 ok [%0 -+.4lX]",
		"test_lX_62 ok [%0 -+lX]",
		"test_lX_63 ok [%0 -+10lX]",
		"test_lX_64 ok [%# -+10.4lX]",
		"test_lX_65 ok [%#-+10.4lX]",
		"test_lX_66 ok [%#+10.4lX]",
		"test_lX_67 ok [%#10.4lX]",
		"test_lX_68 ok [%#.4lX]",
		"test_lX_69 ok [%#lX]",
		"test_lX_70 ok [%#10lX]",
		"test_lX_71 ok [%#+.4lX]",
		"test_lX_72 ok [%#+lX]",
		"test_lX_73 ok [%#+10lX]",
		"test_lX_74 ok [%#-10.4lX]",
		"test_lX_75 ok [%#-.4lX]",
		"test_lX_76 ok [%#-lX]",
		"test_lX_77 ok [%#-10lX]",
		"test_lX_78 ok [%#-+.4lX]",
		"test_lX_79 ok [%#-+lX]",
		"test_lX_80 ok [%#-+10lX]",
		"test_lX_81 ok [%# +10.4lX]",
		"test_lX_82 ok [%# 10.4lX]",
		"test_lX_83 ok [%# .4lX]",
		"test_lX_84 ok [%# lX]",
		"test_lX_85 ok [%# 10lX]",
		"test_lX_86 ok [%# +.4lX]",
		"test_lX_87 ok [%# +lX]",
		"test_lX_88 ok [%# +10lX]",
		"test_lX_89 ok [%# -10.4lX]",
		"test_lX_90 ok [%# -.4lX]",
		"test_lX_91 ok [%# -lX]",
		"test_lX_92 ok [%# -10lX]",
		"test_lX_93 ok [%# -+.4lX]",
		"test_lX_94 ok [%# -+lX]",
		"test_lX_95 ok [%# -+10lX]",
		"test_lX_96 ok [%#0-+10.4lX]",
		"test_lX_97 ok [%#0+10.4lX]",
		"test_lX_98 ok [%#010.4lX]",
		"test_lX_99 ok [%#0.4lX]",
		"test_lX_100 ok [%#0lX]",
		"test_lX_101 ok [%#010lX]",
		"test_lX_102 ok [%#0+.4lX]",
		"test_lX_103 ok [%#0+lX]",
		"test_lX_104 ok [%#0+10lX]",
		"test_lX_105 ok [%#0-10.4lX]",
		"test_lX_106 ok [%#0-.4lX]",
		"test_lX_107 ok [%#0-lX]",
		"test_lX_108 ok [%#0-10lX]",
		"test_lX_109 ok [%#0-+.4lX]",
		"test_lX_110 ok [%#0-+lX]",
		"test_lX_111 ok [%#0-+10lX]",
		"test_lX_112 ok [%#0 +10.4lX]",
		"test_lX_113 ok [%#0 10.4lX]",
		"test_lX_114 ok [%#0 .4lX]",
		"test_lX_115 ok [%#0 lX]",
		"test_lX_116 ok [%#0 10lX]",
		"test_lX_117 ok [%#0 +.4lX]",
		"test_lX_118 ok [%#0 +lX]",
		"test_lX_119 ok [%#0 +10lX]",
		"test_lX_120 ok [%#0 -10.4lX]",
		"test_lX_121 ok [%#0 -.4lX]",
		"test_lX_122 ok [%#0 -lX]",
		"test_lX_123 ok [%#0 -10lX]",
		"test_lX_124 ok [%#0 -+.4lX]",
		"test_lX_125 ok [%#0 -+lX]",
		"test_lX_126 ok [%#0 -+10lX]",
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

	idX = -1;
	while (str[++idX])
	{
		idXn = -1;
		while (num[++idXn] != stop_num)
		{
			fun(str[idX], num[idXn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %lX); // RUN THIS CODE FOR DEBUG\n", str[idX], num[idXn]);
		}
	}
}
