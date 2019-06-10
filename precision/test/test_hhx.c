/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hhx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 21:28:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hhx] _hhd %hhd

#include "tests.h"

void test_hhx(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hhx_0 ok [%#0 -+10.4hhx]",
		"test_hhx_1 ok [%0 -+10.4hhx]",
		"test_hhx_2 ok [% -+10.4hhx]",
		"test_hhx_3 ok [%-+10.4hhx]",
		"test_hhx_4 ok [%+10.4hhx]",
		"test_hhx_5 ok [%10.4hhx]",
		"test_hhx_6 ok [%.4hhx]",
		"test_hhx_7 ok [%10hhx]",
		"test_hhx_8 ok [%+.4hhx]",
		"test_hhx_9 ok [%+hhx]",
		"test_hhx_10 ok [%+10hhx]",
		"test_hhx_11 ok [%-10.4hhx]",
		"test_hhx_12 ok [%-.4hhx]",
		"test_hhx_13 ok [%-hhx]",
		"test_hhx_14 ok [%-10hhx]",
		"test_hhx_15 ok [%-+.4hhx]",
		"test_hhx_16 ok [%-+hhx]",
		"test_hhx_17 ok [%-+10hhx]",
		"test_hhx_18 ok [% +10.4hhx]",
		"test_hhx_19 ok [% 10.4hhx]",
		"test_hhx_20 ok [% .4hhx]",
		"test_hhx_21 ok [% hhx]",
		"test_hhx_22 ok [% 10hhx]",
		"test_hhx_23 ok [% +.4hhx]",
		"test_hhx_24 ok [% +hhx]",
		"test_hhx_25 ok [% +10hhx]",
		"test_hhx_26 ok [% -10.4hhx]",
		"test_hhx_27 ok [% -.4hhx]",
		"test_hhx_28 ok [% -hhx]",
		"test_hhx_29 ok [% -10hhx]",
		"test_hhx_30 ok [% -+.4hhx]",
		"test_hhx_31 ok [% -+hhx]",
		"test_hhx_32 ok [% -+10hhx]",
		"test_hhx_33 ok [%0-+10.4hhx]",
		"test_hhx_34 ok [%0+10.4hhx]",
		"test_hhx_35 ok [%010.4hhx]",
		"test_hhx_36 ok [%0.4hhx]",
		"test_hhx_37 ok [%0hhx]",
		"test_hhx_38 ok [%010hhx]",
		"test_hhx_39 ok [%0+.4hhx]",
		"test_hhx_40 ok [%0+hhx]",
		"test_hhx_41 ok [%0+10hhx]",
		"test_hhx_42 ok [%0-10.4hhx]",
		"test_hhx_43 ok [%0-.4hhx]",
		"test_hhx_44 ok [%0-hhx]",
		"test_hhx_45 ok [%0-10hhx]",
		"test_hhx_46 ok [%0-+.4hhx]",
		"test_hhx_47 ok [%0-+hhx]",
		"test_hhx_48 ok [%0-+10hhx]",
		"test_hhx_49 ok [%0 +10.4hhx]",
		"test_hhx_50 ok [%0 10.4hhx]",
		"test_hhx_51 ok [%0 .4hhx]",
		"test_hhx_52 ok [%0 hhx]",
		"test_hhx_53 ok [%0 10hhx]",
		"test_hhx_54 ok [%0 +.4hhx]",
		"test_hhx_55 ok [%0 +hhx]",
		"test_hhx_56 ok [%0 +10hhx]",
		"test_hhx_57 ok [%0 -10.4hhx]",
		"test_hhx_58 ok [%0 -.4hhx]",
		"test_hhx_59 ok [%0 -hhx]",
		"test_hhx_60 ok [%0 -10hhx]",
		"test_hhx_61 ok [%0 -+.4hhx]",
		"test_hhx_62 ok [%0 -+hhx]",
		"test_hhx_63 ok [%0 -+10hhx]",
		"test_hhx_64 ok [%# -+10.4hhx]",
		"test_hhx_65 ok [%#-+10.4hhx]",
		"test_hhx_66 ok [%#+10.4hhx]",
		"test_hhx_67 ok [%#10.4hhx]",
		"test_hhx_68 ok [%#.4hhx]",
		"test_hhx_69 ok [%#hhx]",
		"test_hhx_70 ok [%#10hhx]",
		"test_hhx_71 ok [%#+.4hhx]",
		"test_hhx_72 ok [%#+hhx]",
		"test_hhx_73 ok [%#+10hhx]",
		"test_hhx_74 ok [%#-10.4hhx]",
		"test_hhx_75 ok [%#-.4hhx]",
		"test_hhx_76 ok [%#-hhx]",
		"test_hhx_77 ok [%#-10hhx]",
		"test_hhx_78 ok [%#-+.4hhx]",
		"test_hhx_79 ok [%#-+hhx]",
		"test_hhx_80 ok [%#-+10hhx]",
		"test_hhx_81 ok [%# +10.4hhx]",
		"test_hhx_82 ok [%# 10.4hhx]",
		"test_hhx_83 ok [%# .4hhx]",
		"test_hhx_84 ok [%# hhx]",
		"test_hhx_85 ok [%# 10hhx]",
		"test_hhx_86 ok [%# +.4hhx]",
		"test_hhx_87 ok [%# +hhx]",
		"test_hhx_88 ok [%# +10hhx]",
		"test_hhx_89 ok [%# -10.4hhx]",
		"test_hhx_90 ok [%# -.4hhx]",
		"test_hhx_91 ok [%# -hhx]",
		"test_hhx_92 ok [%# -10hhx]",
		"test_hhx_93 ok [%# -+.4hhx]",
		"test_hhx_94 ok [%# -+hhx]",
		"test_hhx_95 ok [%# -+10hhx]",
		"test_hhx_96 ok [%#0-+10.4hhx]",
		"test_hhx_97 ok [%#0+10.4hhx]",
		"test_hhx_98 ok [%#010.4hhx]",
		"test_hhx_99 ok [%#0.4hhx]",
		"test_hhx_100 ok [%#0hhx]",
		"test_hhx_101 ok [%#010hhx]",
		"test_hhx_102 ok [%#0+.4hhx]",
		"test_hhx_103 ok [%#0+hhx]",
		"test_hhx_104 ok [%#0+10hhx]",
		"test_hhx_105 ok [%#0-10.4hhx]",
		"test_hhx_106 ok [%#0-.4hhx]",
		"test_hhx_107 ok [%#0-hhx]",
		"test_hhx_108 ok [%#0-10hhx]",
		"test_hhx_109 ok [%#0-+.4hhx]",
		"test_hhx_110 ok [%#0-+hhx]",
		"test_hhx_111 ok [%#0-+10hhx]",
		"test_hhx_112 ok [%#0 +10.4hhx]",
		"test_hhx_113 ok [%#0 10.4hhx]",
		"test_hhx_114 ok [%#0 .4hhx]",
		"test_hhx_115 ok [%#0 hhx]",
		"test_hhx_116 ok [%#0 10hhx]",
		"test_hhx_117 ok [%#0 +.4hhx]",
		"test_hhx_118 ok [%#0 +hhx]",
		"test_hhx_119 ok [%#0 +10hhx]",
		"test_hhx_120 ok [%#0 -10.4hhx]",
		"test_hhx_121 ok [%#0 -.4hhx]",
		"test_hhx_122 ok [%#0 -hhx]",
		"test_hhx_123 ok [%#0 -10hhx]",
		"test_hhx_124 ok [%#0 -+.4hhx]",
		"test_hhx_125 ok [%#0 -+hhx]",
		"test_hhx_126 ok [%#0 -+10hhx]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hhx); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
