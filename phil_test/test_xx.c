/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/05 19:12:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: X] _X %X

#include "tests.h"

void test_X(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_X_0 ok [%#0 -+10.4X]",
		"test_X_1 ok [%0 -+10.4X]",
		"test_X_2 ok [% -+10.4X]",
		"test_X_3 ok [%-+10.4X]",
		"test_X_4 ok [%+10.4X]",
		"test_X_5 ok [%10.4X]",
		"test_X_6 ok [%.4X]",
		"test_X_7 ok [%10X]",
		"test_X_8 ok [%+.4X]",
		"test_X_9 ok [%+X]",
		"test_X_10 ok [%+10X]",
		"test_X_11 ok [%-10.4X]",
		"test_X_12 ok [%-.4X]",
		"test_X_13 ok [%-X]",
		"test_X_14 ok [%-10X]",
		"test_X_15 ok [%-+.4X]",
		"test_X_16 ok [%-+X]",
		"test_X_17 ok [%-+10X]",
		"test_X_18 ok [% +10.4X]",
		"test_X_19 ok [% 10.4X]",
		"test_X_20 ok [% .4X]",
		"test_X_21 ok [% X]",
		"test_X_22 ok [% 10X]",
		"test_X_23 ok [% +.4X]",
		"test_X_24 ok [% +X]",
		"test_X_25 ok [% +10X]",
		"test_X_26 ok [% -10.4X]",
		"test_X_27 ok [% -.4X]",
		"test_X_28 ok [% -X]",
		"test_X_29 ok [% -10X]",
		"test_X_30 ok [% -+.4X]",
		"test_X_31 ok [% -+X]",
		"test_X_32 ok [% -+10X]",
		"test_X_33 ok [%0-+10.4X]",
		"test_X_34 ok [%0+10.4X]",
		"test_X_35 ok [%010.4X]",
		"test_X_36 ok [%0.4X]",
		"test_X_37 ok [%0X]",
		"test_X_38 ok [%010X]",
		"test_X_39 ok [%0+.4X]",
		"test_X_40 ok [%0+X]",
		"test_X_41 ok [%0+10X]",
		"test_X_42 ok [%0-10.4X]",
		"test_X_43 ok [%0-.4X]",
		"test_X_44 ok [%0-X]",
		"test_X_45 ok [%0-10X]",
		"test_X_46 ok [%0-+.4X]",
		"test_X_47 ok [%0-+X]",
		"test_X_48 ok [%0-+10X]",
		"test_X_49 ok [%0 +10.4X]",
		"test_X_50 ok [%0 10.4X]",
		"test_X_51 ok [%0 .4X]",
		"test_X_52 ok [%0 X]",
		"test_X_53 ok [%0 10X]",
		"test_X_54 ok [%0 +.4X]",
		"test_X_55 ok [%0 +X]",
		"test_X_56 ok [%0 +10X]",
		"test_X_57 ok [%0 -10.4X]",
		"test_X_58 ok [%0 -.4X]",
		"test_X_59 ok [%0 -X]",
		"test_X_60 ok [%0 -10X]",
		"test_X_61 ok [%0 -+.4X]",
		"test_X_62 ok [%0 -+X]",
		"test_X_63 ok [%0 -+10X]",
		"test_X_64 ok [%# -+10.4X]",
		"test_X_65 ok [%#-+10.4X]",
		"test_X_66 ok [%#+10.4X]",
		"test_X_67 ok [%#10.4X]",
		"test_X_68 ok [%#.4X]",
		"test_X_69 ok [%#X]",
		"test_X_70 ok [%#10X]",
		"test_X_71 ok [%#+.4X]",
		"test_X_72 ok [%#+X]",
		"test_X_73 ok [%#+10X]",
		"test_X_74 ok [%#-10.4X]",
		"test_X_75 ok [%#-.4X]",
		"test_X_76 ok [%#-X]",
		"test_X_77 ok [%#-10X]",
		"test_X_78 ok [%#-+.4X]",
		"test_X_79 ok [%#-+X]",
		"test_X_80 ok [%#-+10X]",
		"test_X_81 ok [%# +10.4X]",
		"test_X_82 ok [%# 10.4X]",
		"test_X_83 ok [%# .4X]",
		"test_X_84 ok [%# X]",
		"test_X_85 ok [%# 10X]",
		"test_X_86 ok [%# +.4X]",
		"test_X_87 ok [%# +X]",
		"test_X_88 ok [%# +10X]",
		"test_X_89 ok [%# -10.4X]",
		"test_X_90 ok [%# -.4X]",
		"test_X_91 ok [%# -X]",
		"test_X_92 ok [%# -10X]",
		"test_X_93 ok [%# -+.4X]",
		"test_X_94 ok [%# -+X]",
		"test_X_95 ok [%# -+10X]",
		"test_X_96 ok [%#0-+10.4X]",
		"test_X_97 ok [%#0+10.4X]",
		"test_X_98 ok [%#010.4X]",
		"test_X_99 ok [%#0.4X]",
		"test_X_100 ok [%#0X]",
		"test_X_101 ok [%#010X]",
		"test_X_102 ok [%#0+.4X]",
		"test_X_103 ok [%#0+X]",
		"test_X_104 ok [%#0+10X]",
		"test_X_105 ok [%#0-10.4X]",
		"test_X_106 ok [%#0-.4X]",
		"test_X_107 ok [%#0-X]",
		"test_X_108 ok [%#0-10X]",
		"test_X_109 ok [%#0-+.4X]",
		"test_X_110 ok [%#0-+X]",
		"test_X_111 ok [%#0-+10X]",
		"test_X_112 ok [%#0 +10.4X]",
		"test_X_113 ok [%#0 10.4X]",
		"test_X_114 ok [%#0 .4X]",
		"test_X_115 ok [%#0 X]",
		"test_X_116 ok [%#0 10X]",
		"test_X_117 ok [%#0 +.4X]",
		"test_X_118 ok [%#0 +X]",
		"test_X_119 ok [%#0 +10X]",
		"test_X_120 ok [%#0 -10.4X]",
		"test_X_121 ok [%#0 -.4X]",
		"test_X_122 ok [%#0 -X]",
		"test_X_123 ok [%#0 -10X]",
		"test_X_124 ok [%#0 -+.4X]",
		"test_X_125 ok [%#0 -+X]",
		"test_X_126 ok [%#0 -+10X]",
		NULL
	};

	int stop_num = -42;
	int num[] = {
		-2147483648,
		-111778123,
		-1234,
		-123,
		-1,
		0,
		1,
		123,
		1234,
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
			fun("\t\t\t\t//\tprintf(\"%s\", %X); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
