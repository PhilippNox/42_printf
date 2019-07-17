/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 19:56:25 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hd] _hd %hd

#include "tests.h"

void test_hd(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hd_0 ok [%#0 -+10.4hd]",
		"test_hd_1 ok [%0 -+10.4hd]",
		"test_hd_2 ok [% -+10.4hd]",
		"test_hd_3 ok [%-+10.4hd]",
		"test_hd_4 ok [%+10.4hd]",
		"test_hd_5 ok [%10.4hd]",
		"test_hd_6 ok [%.4hd]",
		"test_hd_7 ok [%10hd]",
		"test_hd_8 ok [%+.4hd]",
		"test_hd_9 ok [%+hd]",
		"test_hd_10 ok [%+10hd]",
		"test_hd_11 ok [%-10.4hd]",
		"test_hd_12 ok [%-.4hd]",
		"test_hd_13 ok [%-hd]",
		"test_hd_14 ok [%-10hd]",
		"test_hd_15 ok [%-+.4hd]",
		"test_hd_16 ok [%-+hd]",
		"test_hd_17 ok [%-+10hd]",
		"test_hd_18 ok [% +10.4hd]",
		"test_hd_19 ok [% 10.4hd]",
		"test_hd_20 ok [% .4hd]",
		"test_hd_21 ok [% hd]",
		"test_hd_22 ok [% 10hd]",
		"test_hd_23 ok [% +.4hd]",
		"test_hd_24 ok [% +hd]",
		"test_hd_25 ok [% +10hd]",
		"test_hd_26 ok [% -10.4hd]",
		"test_hd_27 ok [% -.4hd]",
		"test_hd_28 ok [% -hd]",
		"test_hd_29 ok [% -10hd]",
		"test_hd_30 ok [% -+.4hd]",
		"test_hd_31 ok [% -+hd]",
		"test_hd_32 ok [% -+10hd]",
		"test_hd_33 ok [%0-+10.4hd]",
		"test_hd_34 ok [%0+10.4hd]",
		"test_hd_35 ok [%010.4hd]",
		"test_hd_36 ok [%0.4hd]",
		"test_hd_37 ok [%0hd]",
		"test_hd_38 ok [%010hd]",
		"test_hd_39 ok [%0+.4hd]",
		"test_hd_40 ok [%0+hd]",
		"test_hd_41 ok [%0+10hd]",
		"test_hd_42 ok [%0-10.4hd]",
		"test_hd_43 ok [%0-.4hd]",
		"test_hd_44 ok [%0-hd]",
		"test_hd_45 ok [%0-10hd]",
		"test_hd_46 ok [%0-+.4hd]",
		"test_hd_47 ok [%0-+hd]",
		"test_hd_48 ok [%0-+10hd]",
		"test_hd_49 ok [%0 +10.4hd]",
		"test_hd_50 ok [%0 10.4hd]",
		"test_hd_51 ok [%0 .4hd]",
		"test_hd_52 ok [%0 hd]",
		"test_hd_53 ok [%0 10hd]",
		"test_hd_54 ok [%0 +.4hd]",
		"test_hd_55 ok [%0 +hd]",
		"test_hd_56 ok [%0 +10hd]",
		"test_hd_57 ok [%0 -10.4hd]",
		"test_hd_58 ok [%0 -.4hd]",
		"test_hd_59 ok [%0 -hd]",
		"test_hd_60 ok [%0 -10hd]",
		"test_hd_61 ok [%0 -+.4hd]",
		"test_hd_62 ok [%0 -+hd]",
		"test_hd_63 ok [%0 -+10hd]",
		"test_hd_64 ok [%# -+10.4hd]",
		"test_hd_65 ok [%#-+10.4hd]",
		"test_hd_66 ok [%#+10.4hd]",
		"test_hd_67 ok [%#10.4hd]",
		"test_hd_68 ok [%#.4hd]",
		"test_hd_69 ok [%#hd]",
		"test_hd_70 ok [%#10hd]",
		"test_hd_71 ok [%#+.4hd]",
		"test_hd_72 ok [%#+hd]",
		"test_hd_73 ok [%#+10hd]",
		"test_hd_74 ok [%#-10.4hd]",
		"test_hd_75 ok [%#-.4hd]",
		"test_hd_76 ok [%#-hd]",
		"test_hd_77 ok [%#-10hd]",
		"test_hd_78 ok [%#-+.4hd]",
		"test_hd_79 ok [%#-+hd]",
		"test_hd_80 ok [%#-+10hd]",
		"test_hd_81 ok [%# +10.4hd]",
		"test_hd_82 ok [%# 10.4hd]",
		"test_hd_83 ok [%# .4hd]",
		"test_hd_84 ok [%# hd]",
		"test_hd_85 ok [%# 10hd]",
		"test_hd_86 ok [%# +.4hd]",
		"test_hd_87 ok [%# +hd]",
		"test_hd_88 ok [%# +10hd]",
		"test_hd_89 ok [%# -10.4hd]",
		"test_hd_90 ok [%# -.4hd]",
		"test_hd_91 ok [%# -hd]",
		"test_hd_92 ok [%# -10hd]",
		"test_hd_93 ok [%# -+.4hd]",
		"test_hd_94 ok [%# -+hd]",
		"test_hd_95 ok [%# -+10hd]",
		"test_hd_96 ok [%#0-+10.4hd]",
		"test_hd_97 ok [%#0+10.4hd]",
		"test_hd_98 ok [%#010.4hd]",
		"test_hd_99 ok [%#0.4hd]",
		"test_hd_100 ok [%#0hd]",
		"test_hd_101 ok [%#010hd]",
		"test_hd_102 ok [%#0+.4hd]",
		"test_hd_103 ok [%#0+hd]",
		"test_hd_104 ok [%#0+10hd]",
		"test_hd_105 ok [%#0-10.4hd]",
		"test_hd_106 ok [%#0-.4hd]",
		"test_hd_107 ok [%#0-hd]",
		"test_hd_108 ok [%#0-10hd]",
		"test_hd_109 ok [%#0-+.4hd]",
		"test_hd_110 ok [%#0-+hd]",
		"test_hd_111 ok [%#0-+10hd]",
		"test_hd_112 ok [%#0 +10.4hd]",
		"test_hd_113 ok [%#0 10.4hd]",
		"test_hd_114 ok [%#0 .4hd]",
		"test_hd_115 ok [%#0 hd]",
		"test_hd_116 ok [%#0 10hd]",
		"test_hd_117 ok [%#0 +.4hd]",
		"test_hd_118 ok [%#0 +hd]",
		"test_hd_119 ok [%#0 +10hd]",
		"test_hd_120 ok [%#0 -10.4hd]",
		"test_hd_121 ok [%#0 -.4hd]",
		"test_hd_122 ok [%#0 -hd]",
		"test_hd_123 ok [%#0 -10hd]",
		"test_hd_124 ok [%#0 -+.4hd]",
		"test_hd_125 ok [%#0 -+hd]",
		"test_hd_126 ok [%#0 -+10hd]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hd); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
