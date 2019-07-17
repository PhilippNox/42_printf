/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_li.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:40:18 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: li] _ld %ld

#include "tests.h"

void test_li(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_li_0 ok [%#0 -+10.4li]",
		"test_li_1 ok [%0 -+10.4li]",
		"test_li_2 ok [% -+10.4li]",
		"test_li_3 ok [%-+10.4li]",
		"test_li_4 ok [%+10.4li]",
		"test_li_5 ok [%10.4li]",
		"test_li_6 ok [%.4li]",
		"test_li_7 ok [%10li]",
		"test_li_8 ok [%+.4li]",
		"test_li_9 ok [%+li]",
		"test_li_10 ok [%+10li]",
		"test_li_11 ok [%-10.4li]",
		"test_li_12 ok [%-.4li]",
		"test_li_13 ok [%-li]",
		"test_li_14 ok [%-10li]",
		"test_li_15 ok [%-+.4li]",
		"test_li_16 ok [%-+li]",
		"test_li_17 ok [%-+10li]",
		"test_li_18 ok [% +10.4li]",
		"test_li_19 ok [% 10.4li]",
		"test_li_20 ok [% .4li]",
		"test_li_21 ok [% li]",
		"test_li_22 ok [% 10li]",
		"test_li_23 ok [% +.4li]",
		"test_li_24 ok [% +li]",
		"test_li_25 ok [% +10li]",
		"test_li_26 ok [% -10.4li]",
		"test_li_27 ok [% -.4li]",
		"test_li_28 ok [% -li]",
		"test_li_29 ok [% -10li]",
		"test_li_30 ok [% -+.4li]",
		"test_li_31 ok [% -+li]",
		"test_li_32 ok [% -+10li]",
		"test_li_33 ok [%0-+10.4li]",
		"test_li_34 ok [%0+10.4li]",
		"test_li_35 ok [%010.4li]",
		"test_li_36 ok [%0.4li]",
		"test_li_37 ok [%0li]",
		"test_li_38 ok [%010li]",
		"test_li_39 ok [%0+.4li]",
		"test_li_40 ok [%0+li]",
		"test_li_41 ok [%0+10li]",
		"test_li_42 ok [%0-10.4li]",
		"test_li_43 ok [%0-.4li]",
		"test_li_44 ok [%0-li]",
		"test_li_45 ok [%0-10li]",
		"test_li_46 ok [%0-+.4li]",
		"test_li_47 ok [%0-+li]",
		"test_li_48 ok [%0-+10li]",
		"test_li_49 ok [%0 +10.4li]",
		"test_li_50 ok [%0 10.4li]",
		"test_li_51 ok [%0 .4li]",
		"test_li_52 ok [%0 li]",
		"test_li_53 ok [%0 10li]",
		"test_li_54 ok [%0 +.4li]",
		"test_li_55 ok [%0 +li]",
		"test_li_56 ok [%0 +10li]",
		"test_li_57 ok [%0 -10.4li]",
		"test_li_58 ok [%0 -.4li]",
		"test_li_59 ok [%0 -li]",
		"test_li_60 ok [%0 -10li]",
		"test_li_61 ok [%0 -+.4li]",
		"test_li_62 ok [%0 -+li]",
		"test_li_63 ok [%0 -+10li]",
		"test_li_64 ok [%# -+10.4li]",
		"test_li_65 ok [%#-+10.4li]",
		"test_li_66 ok [%#+10.4li]",
		"test_li_67 ok [%#10.4li]",
		"test_li_68 ok [%#.4li]",
		"test_li_69 ok [%#li]",
		"test_li_70 ok [%#10li]",
		"test_li_71 ok [%#+.4li]",
		"test_li_72 ok [%#+li]",
		"test_li_73 ok [%#+10li]",
		"test_li_74 ok [%#-10.4li]",
		"test_li_75 ok [%#-.4li]",
		"test_li_76 ok [%#-li]",
		"test_li_77 ok [%#-10li]",
		"test_li_78 ok [%#-+.4li]",
		"test_li_79 ok [%#-+li]",
		"test_li_80 ok [%#-+10li]",
		"test_li_81 ok [%# +10.4li]",
		"test_li_82 ok [%# 10.4li]",
		"test_li_83 ok [%# .4li]",
		"test_li_84 ok [%# li]",
		"test_li_85 ok [%# 10li]",
		"test_li_86 ok [%# +.4li]",
		"test_li_87 ok [%# +li]",
		"test_li_88 ok [%# +10li]",
		"test_li_89 ok [%# -10.4li]",
		"test_li_90 ok [%# -.4li]",
		"test_li_91 ok [%# -li]",
		"test_li_92 ok [%# -10li]",
		"test_li_93 ok [%# -+.4li]",
		"test_li_94 ok [%# -+li]",
		"test_li_95 ok [%# -+10li]",
		"test_li_96 ok [%#0-+10.4li]",
		"test_li_97 ok [%#0+10.4li]",
		"test_li_98 ok [%#010.4li]",
		"test_li_99 ok [%#0.4li]",
		"test_li_100 ok [%#0li]",
		"test_li_101 ok [%#010li]",
		"test_li_102 ok [%#0+.4li]",
		"test_li_103 ok [%#0+li]",
		"test_li_104 ok [%#0+10li]",
		"test_li_105 ok [%#0-10.4li]",
		"test_li_106 ok [%#0-.4li]",
		"test_li_107 ok [%#0-li]",
		"test_li_108 ok [%#0-10li]",
		"test_li_109 ok [%#0-+.4li]",
		"test_li_110 ok [%#0-+li]",
		"test_li_111 ok [%#0-+10li]",
		"test_li_112 ok [%#0 +10.4li]",
		"test_li_113 ok [%#0 10.4li]",
		"test_li_114 ok [%#0 .4li]",
		"test_li_115 ok [%#0 li]",
		"test_li_116 ok [%#0 10li]",
		"test_li_117 ok [%#0 +.4li]",
		"test_li_118 ok [%#0 +li]",
		"test_li_119 ok [%#0 +10li]",
		"test_li_120 ok [%#0 -10.4li]",
		"test_li_121 ok [%#0 -.4li]",
		"test_li_122 ok [%#0 -li]",
		"test_li_123 ok [%#0 -10li]",
		"test_li_124 ok [%#0 -+.4li]",
		"test_li_125 ok [%#0 -+li]",
		"test_li_126 ok [%#0 -+10li]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %li); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
