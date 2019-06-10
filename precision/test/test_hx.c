/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:28:28 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hx] _hd %hd

#include "tests.h"

void test_hx(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hx_0 ok [%#0 -+10.4hx]",
		"test_hx_1 ok [%0 -+10.4hx]",
		"test_hx_2 ok [% -+10.4hx]",
		"test_hx_3 ok [%-+10.4hx]",
		"test_hx_4 ok [%+10.4hx]",
		"test_hx_5 ok [%10.4hx]",
		"test_hx_6 ok [%.4hx]",
		"test_hx_7 ok [%10hx]",
		"test_hx_8 ok [%+.4hx]",
		"test_hx_9 ok [%+hx]",
		"test_hx_10 ok [%+10hx]",
		"test_hx_11 ok [%-10.4hx]",
		"test_hx_12 ok [%-.4hx]",
		"test_hx_13 ok [%-hx]",
		"test_hx_14 ok [%-10hx]",
		"test_hx_15 ok [%-+.4hx]",
		"test_hx_16 ok [%-+hx]",
		"test_hx_17 ok [%-+10hx]",
		"test_hx_18 ok [% +10.4hx]",
		"test_hx_19 ok [% 10.4hx]",
		"test_hx_20 ok [% .4hx]",
		"test_hx_21 ok [% hx]",
		"test_hx_22 ok [% 10hx]",
		"test_hx_23 ok [% +.4hx]",
		"test_hx_24 ok [% +hx]",
		"test_hx_25 ok [% +10hx]",
		"test_hx_26 ok [% -10.4hx]",
		"test_hx_27 ok [% -.4hx]",
		"test_hx_28 ok [% -hx]",
		"test_hx_29 ok [% -10hx]",
		"test_hx_30 ok [% -+.4hx]",
		"test_hx_31 ok [% -+hx]",
		"test_hx_32 ok [% -+10hx]",
		"test_hx_33 ok [%0-+10.4hx]",
		"test_hx_34 ok [%0+10.4hx]",
		"test_hx_35 ok [%010.4hx]",
		"test_hx_36 ok [%0.4hx]",
		"test_hx_37 ok [%0hx]",
		"test_hx_38 ok [%010hx]",
		"test_hx_39 ok [%0+.4hx]",
		"test_hx_40 ok [%0+hx]",
		"test_hx_41 ok [%0+10hx]",
		"test_hx_42 ok [%0-10.4hx]",
		"test_hx_43 ok [%0-.4hx]",
		"test_hx_44 ok [%0-hx]",
		"test_hx_45 ok [%0-10hx]",
		"test_hx_46 ok [%0-+.4hx]",
		"test_hx_47 ok [%0-+hx]",
		"test_hx_48 ok [%0-+10hx]",
		"test_hx_49 ok [%0 +10.4hx]",
		"test_hx_50 ok [%0 10.4hx]",
		"test_hx_51 ok [%0 .4hx]",
		"test_hx_52 ok [%0 hx]",
		"test_hx_53 ok [%0 10hx]",
		"test_hx_54 ok [%0 +.4hx]",
		"test_hx_55 ok [%0 +hx]",
		"test_hx_56 ok [%0 +10hx]",
		"test_hx_57 ok [%0 -10.4hx]",
		"test_hx_58 ok [%0 -.4hx]",
		"test_hx_59 ok [%0 -hx]",
		"test_hx_60 ok [%0 -10hx]",
		"test_hx_61 ok [%0 -+.4hx]",
		"test_hx_62 ok [%0 -+hx]",
		"test_hx_63 ok [%0 -+10hx]",
		"test_hx_64 ok [%# -+10.4hx]",
		"test_hx_65 ok [%#-+10.4hx]",
		"test_hx_66 ok [%#+10.4hx]",
		"test_hx_67 ok [%#10.4hx]",
		"test_hx_68 ok [%#.4hx]",
		"test_hx_69 ok [%#hx]",
		"test_hx_70 ok [%#10hx]",
		"test_hx_71 ok [%#+.4hx]",
		"test_hx_72 ok [%#+hx]",
		"test_hx_73 ok [%#+10hx]",
		"test_hx_74 ok [%#-10.4hx]",
		"test_hx_75 ok [%#-.4hx]",
		"test_hx_76 ok [%#-hx]",
		"test_hx_77 ok [%#-10hx]",
		"test_hx_78 ok [%#-+.4hx]",
		"test_hx_79 ok [%#-+hx]",
		"test_hx_80 ok [%#-+10hx]",
		"test_hx_81 ok [%# +10.4hx]",
		"test_hx_82 ok [%# 10.4hx]",
		"test_hx_83 ok [%# .4hx]",
		"test_hx_84 ok [%# hx]",
		"test_hx_85 ok [%# 10hx]",
		"test_hx_86 ok [%# +.4hx]",
		"test_hx_87 ok [%# +hx]",
		"test_hx_88 ok [%# +10hx]",
		"test_hx_89 ok [%# -10.4hx]",
		"test_hx_90 ok [%# -.4hx]",
		"test_hx_91 ok [%# -hx]",
		"test_hx_92 ok [%# -10hx]",
		"test_hx_93 ok [%# -+.4hx]",
		"test_hx_94 ok [%# -+hx]",
		"test_hx_95 ok [%# -+10hx]",
		"test_hx_96 ok [%#0-+10.4hx]",
		"test_hx_97 ok [%#0+10.4hx]",
		"test_hx_98 ok [%#010.4hx]",
		"test_hx_99 ok [%#0.4hx]",
		"test_hx_100 ok [%#0hx]",
		"test_hx_101 ok [%#010hx]",
		"test_hx_102 ok [%#0+.4hx]",
		"test_hx_103 ok [%#0+hx]",
		"test_hx_104 ok [%#0+10hx]",
		"test_hx_105 ok [%#0-10.4hx]",
		"test_hx_106 ok [%#0-.4hx]",
		"test_hx_107 ok [%#0-hx]",
		"test_hx_108 ok [%#0-10hx]",
		"test_hx_109 ok [%#0-+.4hx]",
		"test_hx_110 ok [%#0-+hx]",
		"test_hx_111 ok [%#0-+10hx]",
		"test_hx_112 ok [%#0 +10.4hx]",
		"test_hx_113 ok [%#0 10.4hx]",
		"test_hx_114 ok [%#0 .4hx]",
		"test_hx_115 ok [%#0 hx]",
		"test_hx_116 ok [%#0 10hx]",
		"test_hx_117 ok [%#0 +.4hx]",
		"test_hx_118 ok [%#0 +hx]",
		"test_hx_119 ok [%#0 +10hx]",
		"test_hx_120 ok [%#0 -10.4hx]",
		"test_hx_121 ok [%#0 -.4hx]",
		"test_hx_122 ok [%#0 -hx]",
		"test_hx_123 ok [%#0 -10hx]",
		"test_hx_124 ok [%#0 -+.4hx]",
		"test_hx_125 ok [%#0 -+hx]",
		"test_hx_126 ok [%#0 -+10hx]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-123,
		-1,
		0,
		1,
		123,
		111778123,
		2147483647,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %hx); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
