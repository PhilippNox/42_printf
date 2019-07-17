/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:55:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hho] _hhd %hhd

#include "tests.h"

void test_hho(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hho_0 ok [%#0 -+10.4hho]",
		"test_hho_1 ok [%0 -+10.4hho]",
		"test_hho_2 ok [% -+10.4hho]",
		"test_hho_3 ok [%-+10.4hho]",
		"test_hho_4 ok [%+10.4hho]",
		"test_hho_5 ok [%10.4hho]",
		"test_hho_6 ok [%.4hho]",
		"test_hho_7 ok [%10hho]",
		"test_hho_8 ok [%+.4hho]",
		"test_hho_9 ok [%+hho]",
		"test_hho_10 ok [%+10hho]",
		"test_hho_11 ok [%-10.4hho]",
		"test_hho_12 ok [%-.4hho]",
		"test_hho_13 ok [%-hho]",
		"test_hho_14 ok [%-10hho]",
		"test_hho_15 ok [%-+.4hho]",
		"test_hho_16 ok [%-+hho]",
		"test_hho_17 ok [%-+10hho]",
		"test_hho_18 ok [% +10.4hho]",
		"test_hho_19 ok [% 10.4hho]",
		"test_hho_20 ok [% .4hho]",
		"test_hho_21 ok [% hho]",
		"test_hho_22 ok [% 10hho]",
		"test_hho_23 ok [% +.4hho]",
		"test_hho_24 ok [% +hho]",
		"test_hho_25 ok [% +10hho]",
		"test_hho_26 ok [% -10.4hho]",
		"test_hho_27 ok [% -.4hho]",
		"test_hho_28 ok [% -hho]",
		"test_hho_29 ok [% -10hho]",
		"test_hho_30 ok [% -+.4hho]",
		"test_hho_31 ok [% -+hho]",
		"test_hho_32 ok [% -+10hho]",
		"test_hho_33 ok [%0-+10.4hho]",
		"test_hho_34 ok [%0+10.4hho]",
		"test_hho_35 ok [%010.4hho]",
		"test_hho_36 ok [%0.4hho]",
		"test_hho_37 ok [%0hho]",
		"test_hho_38 ok [%010hho]",
		"test_hho_39 ok [%0+.4hho]",
		"test_hho_40 ok [%0+hho]",
		"test_hho_41 ok [%0+10hho]",
		"test_hho_42 ok [%0-10.4hho]",
		"test_hho_43 ok [%0-.4hho]",
		"test_hho_44 ok [%0-hho]",
		"test_hho_45 ok [%0-10hho]",
		"test_hho_46 ok [%0-+.4hho]",
		"test_hho_47 ok [%0-+hho]",
		"test_hho_48 ok [%0-+10hho]",
		"test_hho_49 ok [%0 +10.4hho]",
		"test_hho_50 ok [%0 10.4hho]",
		"test_hho_51 ok [%0 .4hho]",
		"test_hho_52 ok [%0 hho]",
		"test_hho_53 ok [%0 10hho]",
		"test_hho_54 ok [%0 +.4hho]",
		"test_hho_55 ok [%0 +hho]",
		"test_hho_56 ok [%0 +10hho]",
		"test_hho_57 ok [%0 -10.4hho]",
		"test_hho_58 ok [%0 -.4hho]",
		"test_hho_59 ok [%0 -hho]",
		"test_hho_60 ok [%0 -10hho]",
		"test_hho_61 ok [%0 -+.4hho]",
		"test_hho_62 ok [%0 -+hho]",
		"test_hho_63 ok [%0 -+10hho]",
		"test_hho_64 ok [%# -+10.4hho]",
		"test_hho_65 ok [%#-+10.4hho]",
		"test_hho_66 ok [%#+10.4hho]",
		"test_hho_67 ok [%#10.4hho]",
		"test_hho_68 ok [%#.4hho]",
		"test_hho_69 ok [%#hho]",
		"test_hho_70 ok [%#10hho]",
		"test_hho_71 ok [%#+.4hho]",
		"test_hho_72 ok [%#+hho]",
		"test_hho_73 ok [%#+10hho]",
		"test_hho_74 ok [%#-10.4hho]",
		"test_hho_75 ok [%#-.4hho]",
		"test_hho_76 ok [%#-hho]",
		"test_hho_77 ok [%#-10hho]",
		"test_hho_78 ok [%#-+.4hho]",
		"test_hho_79 ok [%#-+hho]",
		"test_hho_80 ok [%#-+10hho]",
		"test_hho_81 ok [%# +10.4hho]",
		"test_hho_82 ok [%# 10.4hho]",
		"test_hho_83 ok [%# .4hho]",
		"test_hho_84 ok [%# hho]",
		"test_hho_85 ok [%# 10hho]",
		"test_hho_86 ok [%# +.4hho]",
		"test_hho_87 ok [%# +hho]",
		"test_hho_88 ok [%# +10hho]",
		"test_hho_89 ok [%# -10.4hho]",
		"test_hho_90 ok [%# -.4hho]",
		"test_hho_91 ok [%# -hho]",
		"test_hho_92 ok [%# -10hho]",
		"test_hho_93 ok [%# -+.4hho]",
		"test_hho_94 ok [%# -+hho]",
		"test_hho_95 ok [%# -+10hho]",
		"test_hho_96 ok [%#0-+10.4hho]",
		"test_hho_97 ok [%#0+10.4hho]",
		"test_hho_98 ok [%#010.4hho]",
		"test_hho_99 ok [%#0.4hho]",
		"test_hho_100 ok [%#0hho]",
		"test_hho_101 ok [%#010hho]",
		"test_hho_102 ok [%#0+.4hho]",
		"test_hho_103 ok [%#0+hho]",
		"test_hho_104 ok [%#0+10hho]",
		"test_hho_105 ok [%#0-10.4hho]",
		"test_hho_106 ok [%#0-.4hho]",
		"test_hho_107 ok [%#0-hho]",
		"test_hho_108 ok [%#0-10hho]",
		"test_hho_109 ok [%#0-+.4hho]",
		"test_hho_110 ok [%#0-+hho]",
		"test_hho_111 ok [%#0-+10hho]",
		"test_hho_112 ok [%#0 +10.4hho]",
		"test_hho_113 ok [%#0 10.4hho]",
		"test_hho_114 ok [%#0 .4hho]",
		"test_hho_115 ok [%#0 hho]",
		"test_hho_116 ok [%#0 10hho]",
		"test_hho_117 ok [%#0 +.4hho]",
		"test_hho_118 ok [%#0 +hho]",
		"test_hho_119 ok [%#0 +10hho]",
		"test_hho_120 ok [%#0 -10.4hho]",
		"test_hho_121 ok [%#0 -.4hho]",
		"test_hho_122 ok [%#0 -hho]",
		"test_hho_123 ok [%#0 -10hho]",
		"test_hho_124 ok [%#0 -+.4hho]",
		"test_hho_125 ok [%#0 -+hho]",
		"test_hho_126 ok [%#0 -+10hho]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hho); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
