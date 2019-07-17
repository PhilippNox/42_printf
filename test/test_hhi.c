/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:40:16 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hhi] _hhd %hhd

#include "tests.h"

void test_hhi(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hhi_0 ok [%#0 -+10.4hhi]",
		"test_hhi_1 ok [%0 -+10.4hhi]",
		"test_hhi_2 ok [% -+10.4hhi]",
		"test_hhi_3 ok [%-+10.4hhi]",
		"test_hhi_4 ok [%+10.4hhi]",
		"test_hhi_5 ok [%10.4hhi]",
		"test_hhi_6 ok [%.4hhi]",
		"test_hhi_7 ok [%10hhi]",
		"test_hhi_8 ok [%+.4hhi]",
		"test_hhi_9 ok [%+hhi]",
		"test_hhi_10 ok [%+10hhi]",
		"test_hhi_11 ok [%-10.4hhi]",
		"test_hhi_12 ok [%-.4hhi]",
		"test_hhi_13 ok [%-hhi]",
		"test_hhi_14 ok [%-10hhi]",
		"test_hhi_15 ok [%-+.4hhi]",
		"test_hhi_16 ok [%-+hhi]",
		"test_hhi_17 ok [%-+10hhi]",
		"test_hhi_18 ok [% +10.4hhi]",
		"test_hhi_19 ok [% 10.4hhi]",
		"test_hhi_20 ok [% .4hhi]",
		"test_hhi_21 ok [% hhi]",
		"test_hhi_22 ok [% 10hhi]",
		"test_hhi_23 ok [% +.4hhi]",
		"test_hhi_24 ok [% +hhi]",
		"test_hhi_25 ok [% +10hhi]",
		"test_hhi_26 ok [% -10.4hhi]",
		"test_hhi_27 ok [% -.4hhi]",
		"test_hhi_28 ok [% -hhi]",
		"test_hhi_29 ok [% -10hhi]",
		"test_hhi_30 ok [% -+.4hhi]",
		"test_hhi_31 ok [% -+hhi]",
		"test_hhi_32 ok [% -+10hhi]",
		"test_hhi_33 ok [%0-+10.4hhi]",
		"test_hhi_34 ok [%0+10.4hhi]",
		"test_hhi_35 ok [%010.4hhi]",
		"test_hhi_36 ok [%0.4hhi]",
		"test_hhi_37 ok [%0hhi]",
		"test_hhi_38 ok [%010hhi]",
		"test_hhi_39 ok [%0+.4hhi]",
		"test_hhi_40 ok [%0+hhi]",
		"test_hhi_41 ok [%0+10hhi]",
		"test_hhi_42 ok [%0-10.4hhi]",
		"test_hhi_43 ok [%0-.4hhi]",
		"test_hhi_44 ok [%0-hhi]",
		"test_hhi_45 ok [%0-10hhi]",
		"test_hhi_46 ok [%0-+.4hhi]",
		"test_hhi_47 ok [%0-+hhi]",
		"test_hhi_48 ok [%0-+10hhi]",
		"test_hhi_49 ok [%0 +10.4hhi]",
		"test_hhi_50 ok [%0 10.4hhi]",
		"test_hhi_51 ok [%0 .4hhi]",
		"test_hhi_52 ok [%0 hhi]",
		"test_hhi_53 ok [%0 10hhi]",
		"test_hhi_54 ok [%0 +.4hhi]",
		"test_hhi_55 ok [%0 +hhi]",
		"test_hhi_56 ok [%0 +10hhi]",
		"test_hhi_57 ok [%0 -10.4hhi]",
		"test_hhi_58 ok [%0 -.4hhi]",
		"test_hhi_59 ok [%0 -hhi]",
		"test_hhi_60 ok [%0 -10hhi]",
		"test_hhi_61 ok [%0 -+.4hhi]",
		"test_hhi_62 ok [%0 -+hhi]",
		"test_hhi_63 ok [%0 -+10hhi]",
		"test_hhi_64 ok [%# -+10.4hhi]",
		"test_hhi_65 ok [%#-+10.4hhi]",
		"test_hhi_66 ok [%#+10.4hhi]",
		"test_hhi_67 ok [%#10.4hhi]",
		"test_hhi_68 ok [%#.4hhi]",
		"test_hhi_69 ok [%#hhi]",
		"test_hhi_70 ok [%#10hhi]",
		"test_hhi_71 ok [%#+.4hhi]",
		"test_hhi_72 ok [%#+hhi]",
		"test_hhi_73 ok [%#+10hhi]",
		"test_hhi_74 ok [%#-10.4hhi]",
		"test_hhi_75 ok [%#-.4hhi]",
		"test_hhi_76 ok [%#-hhi]",
		"test_hhi_77 ok [%#-10hhi]",
		"test_hhi_78 ok [%#-+.4hhi]",
		"test_hhi_79 ok [%#-+hhi]",
		"test_hhi_80 ok [%#-+10hhi]",
		"test_hhi_81 ok [%# +10.4hhi]",
		"test_hhi_82 ok [%# 10.4hhi]",
		"test_hhi_83 ok [%# .4hhi]",
		"test_hhi_84 ok [%# hhi]",
		"test_hhi_85 ok [%# 10hhi]",
		"test_hhi_86 ok [%# +.4hhi]",
		"test_hhi_87 ok [%# +hhi]",
		"test_hhi_88 ok [%# +10hhi]",
		"test_hhi_89 ok [%# -10.4hhi]",
		"test_hhi_90 ok [%# -.4hhi]",
		"test_hhi_91 ok [%# -hhi]",
		"test_hhi_92 ok [%# -10hhi]",
		"test_hhi_93 ok [%# -+.4hhi]",
		"test_hhi_94 ok [%# -+hhi]",
		"test_hhi_95 ok [%# -+10hhi]",
		"test_hhi_96 ok [%#0-+10.4hhi]",
		"test_hhi_97 ok [%#0+10.4hhi]",
		"test_hhi_98 ok [%#010.4hhi]",
		"test_hhi_99 ok [%#0.4hhi]",
		"test_hhi_100 ok [%#0hhi]",
		"test_hhi_101 ok [%#010hhi]",
		"test_hhi_102 ok [%#0+.4hhi]",
		"test_hhi_103 ok [%#0+hhi]",
		"test_hhi_104 ok [%#0+10hhi]",
		"test_hhi_105 ok [%#0-10.4hhi]",
		"test_hhi_106 ok [%#0-.4hhi]",
		"test_hhi_107 ok [%#0-hhi]",
		"test_hhi_108 ok [%#0-10hhi]",
		"test_hhi_109 ok [%#0-+.4hhi]",
		"test_hhi_110 ok [%#0-+hhi]",
		"test_hhi_111 ok [%#0-+10hhi]",
		"test_hhi_112 ok [%#0 +10.4hhi]",
		"test_hhi_113 ok [%#0 10.4hhi]",
		"test_hhi_114 ok [%#0 .4hhi]",
		"test_hhi_115 ok [%#0 hhi]",
		"test_hhi_116 ok [%#0 10hhi]",
		"test_hhi_117 ok [%#0 +.4hhi]",
		"test_hhi_118 ok [%#0 +hhi]",
		"test_hhi_119 ok [%#0 +10hhi]",
		"test_hhi_120 ok [%#0 -10.4hhi]",
		"test_hhi_121 ok [%#0 -.4hhi]",
		"test_hhi_122 ok [%#0 -hhi]",
		"test_hhi_123 ok [%#0 -10hhi]",
		"test_hhi_124 ok [%#0 -+.4hhi]",
		"test_hhi_125 ok [%#0 -+hhi]",
		"test_hhi_126 ok [%#0 -+10hhi]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hhi); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
