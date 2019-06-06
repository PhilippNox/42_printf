/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:10:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hhu] _hhd %hhd

#include "tests.h"

void test_hhu(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hhu_0 ok [%#0 -+10.4hhu]",
		"test_hhu_1 ok [%0 -+10.4hhu]",
		"test_hhu_2 ok [% -+10.4hhu]",
		"test_hhu_3 ok [%-+10.4hhu]",
		"test_hhu_4 ok [%+10.4hhu]",
		"test_hhu_5 ok [%10.4hhu]",
		"test_hhu_6 ok [%.4hhu]",
		"test_hhu_7 ok [%10hhu]",
		"test_hhu_8 ok [%+.4hhu]",
		"test_hhu_9 ok [%+hhu]",
		"test_hhu_10 ok [%+10hhu]",
		"test_hhu_11 ok [%-10.4hhu]",
		"test_hhu_12 ok [%-.4hhu]",
		"test_hhu_13 ok [%-hhu]",
		"test_hhu_14 ok [%-10hhu]",
		"test_hhu_15 ok [%-+.4hhu]",
		"test_hhu_16 ok [%-+hhu]",
		"test_hhu_17 ok [%-+10hhu]",
		"test_hhu_18 ok [% +10.4hhu]",
		"test_hhu_19 ok [% 10.4hhu]",
		"test_hhu_20 ok [% .4hhu]",
		"test_hhu_21 ok [% hhu]",
		"test_hhu_22 ok [% 10hhu]",
		"test_hhu_23 ok [% +.4hhu]",
		"test_hhu_24 ok [% +hhu]",
		"test_hhu_25 ok [% +10hhu]",
		"test_hhu_26 ok [% -10.4hhu]",
		"test_hhu_27 ok [% -.4hhu]",
		"test_hhu_28 ok [% -hhu]",
		"test_hhu_29 ok [% -10hhu]",
		"test_hhu_30 ok [% -+.4hhu]",
		"test_hhu_31 ok [% -+hhu]",
		"test_hhu_32 ok [% -+10hhu]",
		"test_hhu_33 ok [%0-+10.4hhu]",
		"test_hhu_34 ok [%0+10.4hhu]",
		"test_hhu_35 ok [%010.4hhu]",
		"test_hhu_36 ok [%0.4hhu]",
		"test_hhu_37 ok [%0hhu]",
		"test_hhu_38 ok [%010hhu]",
		"test_hhu_39 ok [%0+.4hhu]",
		"test_hhu_40 ok [%0+hhu]",
		"test_hhu_41 ok [%0+10hhu]",
		"test_hhu_42 ok [%0-10.4hhu]",
		"test_hhu_43 ok [%0-.4hhu]",
		"test_hhu_44 ok [%0-hhu]",
		"test_hhu_45 ok [%0-10hhu]",
		"test_hhu_46 ok [%0-+.4hhu]",
		"test_hhu_47 ok [%0-+hhu]",
		"test_hhu_48 ok [%0-+10hhu]",
		"test_hhu_49 ok [%0 +10.4hhu]",
		"test_hhu_50 ok [%0 10.4hhu]",
		"test_hhu_51 ok [%0 .4hhu]",
		"test_hhu_52 ok [%0 hhu]",
		"test_hhu_53 ok [%0 10hhu]",
		"test_hhu_54 ok [%0 +.4hhu]",
		"test_hhu_55 ok [%0 +hhu]",
		"test_hhu_56 ok [%0 +10hhu]",
		"test_hhu_57 ok [%0 -10.4hhu]",
		"test_hhu_58 ok [%0 -.4hhu]",
		"test_hhu_59 ok [%0 -hhu]",
		"test_hhu_60 ok [%0 -10hhu]",
		"test_hhu_61 ok [%0 -+.4hhu]",
		"test_hhu_62 ok [%0 -+hhu]",
		"test_hhu_63 ok [%0 -+10hhu]",
		"test_hhu_64 ok [%# -+10.4hhu]",
		"test_hhu_65 ok [%#-+10.4hhu]",
		"test_hhu_66 ok [%#+10.4hhu]",
		"test_hhu_67 ok [%#10.4hhu]",
		"test_hhu_68 ok [%#.4hhu]",
		"test_hhu_69 ok [%#hhu]",
		"test_hhu_70 ok [%#10hhu]",
		"test_hhu_71 ok [%#+.4hhu]",
		"test_hhu_72 ok [%#+hhu]",
		"test_hhu_73 ok [%#+10hhu]",
		"test_hhu_74 ok [%#-10.4hhu]",
		"test_hhu_75 ok [%#-.4hhu]",
		"test_hhu_76 ok [%#-hhu]",
		"test_hhu_77 ok [%#-10hhu]",
		"test_hhu_78 ok [%#-+.4hhu]",
		"test_hhu_79 ok [%#-+hhu]",
		"test_hhu_80 ok [%#-+10hhu]",
		"test_hhu_81 ok [%# +10.4hhu]",
		"test_hhu_82 ok [%# 10.4hhu]",
		"test_hhu_83 ok [%# .4hhu]",
		"test_hhu_84 ok [%# hhu]",
		"test_hhu_85 ok [%# 10hhu]",
		"test_hhu_86 ok [%# +.4hhu]",
		"test_hhu_87 ok [%# +hhu]",
		"test_hhu_88 ok [%# +10hhu]",
		"test_hhu_89 ok [%# -10.4hhu]",
		"test_hhu_90 ok [%# -.4hhu]",
		"test_hhu_91 ok [%# -hhu]",
		"test_hhu_92 ok [%# -10hhu]",
		"test_hhu_93 ok [%# -+.4hhu]",
		"test_hhu_94 ok [%# -+hhu]",
		"test_hhu_95 ok [%# -+10hhu]",
		"test_hhu_96 ok [%#0-+10.4hhu]",
		"test_hhu_97 ok [%#0+10.4hhu]",
		"test_hhu_98 ok [%#010.4hhu]",
		"test_hhu_99 ok [%#0.4hhu]",
		"test_hhu_100 ok [%#0hhu]",
		"test_hhu_101 ok [%#010hhu]",
		"test_hhu_102 ok [%#0+.4hhu]",
		"test_hhu_103 ok [%#0+hhu]",
		"test_hhu_104 ok [%#0+10hhu]",
		"test_hhu_105 ok [%#0-10.4hhu]",
		"test_hhu_106 ok [%#0-.4hhu]",
		"test_hhu_107 ok [%#0-hhu]",
		"test_hhu_108 ok [%#0-10hhu]",
		"test_hhu_109 ok [%#0-+.4hhu]",
		"test_hhu_110 ok [%#0-+hhu]",
		"test_hhu_111 ok [%#0-+10hhu]",
		"test_hhu_112 ok [%#0 +10.4hhu]",
		"test_hhu_113 ok [%#0 10.4hhu]",
		"test_hhu_114 ok [%#0 .4hhu]",
		"test_hhu_115 ok [%#0 hhu]",
		"test_hhu_116 ok [%#0 10hhu]",
		"test_hhu_117 ok [%#0 +.4hhu]",
		"test_hhu_118 ok [%#0 +hhu]",
		"test_hhu_119 ok [%#0 +10hhu]",
		"test_hhu_120 ok [%#0 -10.4hhu]",
		"test_hhu_121 ok [%#0 -.4hhu]",
		"test_hhu_122 ok [%#0 -hhu]",
		"test_hhu_123 ok [%#0 -10hhu]",
		"test_hhu_124 ok [%#0 -+.4hhu]",
		"test_hhu_125 ok [%#0 -+hhu]",
		"test_hhu_126 ok [%#0 -+10hhu]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hhu); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
