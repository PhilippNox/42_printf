/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:10:26 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: lu] _ld %ld

#include "tests.h"

void test_lu(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_lu_0 ok [%#0 -+10.4lu]",
		"test_lu_1 ok [%0 -+10.4lu]",
		"test_lu_2 ok [% -+10.4lu]",
		"test_lu_3 ok [%-+10.4lu]",
		"test_lu_4 ok [%+10.4lu]",
		"test_lu_5 ok [%10.4lu]",
		"test_lu_6 ok [%.4lu]",
		"test_lu_7 ok [%10lu]",
		"test_lu_8 ok [%+.4lu]",
		"test_lu_9 ok [%+lu]",
		"test_lu_10 ok [%+10lu]",
		"test_lu_11 ok [%-10.4lu]",
		"test_lu_12 ok [%-.4lu]",
		"test_lu_13 ok [%-lu]",
		"test_lu_14 ok [%-10lu]",
		"test_lu_15 ok [%-+.4lu]",
		"test_lu_16 ok [%-+lu]",
		"test_lu_17 ok [%-+10lu]",
		"test_lu_18 ok [% +10.4lu]",
		"test_lu_19 ok [% 10.4lu]",
		"test_lu_20 ok [% .4lu]",
		"test_lu_21 ok [% lu]",
		"test_lu_22 ok [% 10lu]",
		"test_lu_23 ok [% +.4lu]",
		"test_lu_24 ok [% +lu]",
		"test_lu_25 ok [% +10lu]",
		"test_lu_26 ok [% -10.4lu]",
		"test_lu_27 ok [% -.4lu]",
		"test_lu_28 ok [% -lu]",
		"test_lu_29 ok [% -10lu]",
		"test_lu_30 ok [% -+.4lu]",
		"test_lu_31 ok [% -+lu]",
		"test_lu_32 ok [% -+10lu]",
		"test_lu_33 ok [%0-+10.4lu]",
		"test_lu_34 ok [%0+10.4lu]",
		"test_lu_35 ok [%010.4lu]",
		"test_lu_36 ok [%0.4lu]",
		"test_lu_37 ok [%0lu]",
		"test_lu_38 ok [%010lu]",
		"test_lu_39 ok [%0+.4lu]",
		"test_lu_40 ok [%0+lu]",
		"test_lu_41 ok [%0+10lu]",
		"test_lu_42 ok [%0-10.4lu]",
		"test_lu_43 ok [%0-.4lu]",
		"test_lu_44 ok [%0-lu]",
		"test_lu_45 ok [%0-10lu]",
		"test_lu_46 ok [%0-+.4lu]",
		"test_lu_47 ok [%0-+lu]",
		"test_lu_48 ok [%0-+10lu]",
		"test_lu_49 ok [%0 +10.4lu]",
		"test_lu_50 ok [%0 10.4lu]",
		"test_lu_51 ok [%0 .4lu]",
		"test_lu_52 ok [%0 lu]",
		"test_lu_53 ok [%0 10lu]",
		"test_lu_54 ok [%0 +.4lu]",
		"test_lu_55 ok [%0 +lu]",
		"test_lu_56 ok [%0 +10lu]",
		"test_lu_57 ok [%0 -10.4lu]",
		"test_lu_58 ok [%0 -.4lu]",
		"test_lu_59 ok [%0 -lu]",
		"test_lu_60 ok [%0 -10lu]",
		"test_lu_61 ok [%0 -+.4lu]",
		"test_lu_62 ok [%0 -+lu]",
		"test_lu_63 ok [%0 -+10lu]",
		"test_lu_64 ok [%# -+10.4lu]",
		"test_lu_65 ok [%#-+10.4lu]",
		"test_lu_66 ok [%#+10.4lu]",
		"test_lu_67 ok [%#10.4lu]",
		"test_lu_68 ok [%#.4lu]",
		"test_lu_69 ok [%#lu]",
		"test_lu_70 ok [%#10lu]",
		"test_lu_71 ok [%#+.4lu]",
		"test_lu_72 ok [%#+lu]",
		"test_lu_73 ok [%#+10lu]",
		"test_lu_74 ok [%#-10.4lu]",
		"test_lu_75 ok [%#-.4lu]",
		"test_lu_76 ok [%#-lu]",
		"test_lu_77 ok [%#-10lu]",
		"test_lu_78 ok [%#-+.4lu]",
		"test_lu_79 ok [%#-+lu]",
		"test_lu_80 ok [%#-+10lu]",
		"test_lu_81 ok [%# +10.4lu]",
		"test_lu_82 ok [%# 10.4lu]",
		"test_lu_83 ok [%# .4lu]",
		"test_lu_84 ok [%# lu]",
		"test_lu_85 ok [%# 10lu]",
		"test_lu_86 ok [%# +.4lu]",
		"test_lu_87 ok [%# +lu]",
		"test_lu_88 ok [%# +10lu]",
		"test_lu_89 ok [%# -10.4lu]",
		"test_lu_90 ok [%# -.4lu]",
		"test_lu_91 ok [%# -lu]",
		"test_lu_92 ok [%# -10lu]",
		"test_lu_93 ok [%# -+.4lu]",
		"test_lu_94 ok [%# -+lu]",
		"test_lu_95 ok [%# -+10lu]",
		"test_lu_96 ok [%#0-+10.4lu]",
		"test_lu_97 ok [%#0+10.4lu]",
		"test_lu_98 ok [%#010.4lu]",
		"test_lu_99 ok [%#0.4lu]",
		"test_lu_100 ok [%#0lu]",
		"test_lu_101 ok [%#010lu]",
		"test_lu_102 ok [%#0+.4lu]",
		"test_lu_103 ok [%#0+lu]",
		"test_lu_104 ok [%#0+10lu]",
		"test_lu_105 ok [%#0-10.4lu]",
		"test_lu_106 ok [%#0-.4lu]",
		"test_lu_107 ok [%#0-lu]",
		"test_lu_108 ok [%#0-10lu]",
		"test_lu_109 ok [%#0-+.4lu]",
		"test_lu_110 ok [%#0-+lu]",
		"test_lu_111 ok [%#0-+10lu]",
		"test_lu_112 ok [%#0 +10.4lu]",
		"test_lu_113 ok [%#0 10.4lu]",
		"test_lu_114 ok [%#0 .4lu]",
		"test_lu_115 ok [%#0 lu]",
		"test_lu_116 ok [%#0 10lu]",
		"test_lu_117 ok [%#0 +.4lu]",
		"test_lu_118 ok [%#0 +lu]",
		"test_lu_119 ok [%#0 +10lu]",
		"test_lu_120 ok [%#0 -10.4lu]",
		"test_lu_121 ok [%#0 -.4lu]",
		"test_lu_122 ok [%#0 -lu]",
		"test_lu_123 ok [%#0 -10lu]",
		"test_lu_124 ok [%#0 -+.4lu]",
		"test_lu_125 ok [%#0 -+lu]",
		"test_lu_126 ok [%#0 -+10lu]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %lu); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
