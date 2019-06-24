/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Lff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/09 23:03:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: LF] _LF_ %Lf

#include "tests.h"

void test_Lff(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_LF_0 ok [%#0 -+10.4LF]",
		"test_LF_1 ok [%0 -+10.4LF]",
		"test_LF_2 ok [% -+10.4LF]",
		"test_LF_3 ok [%-+10.4LF]",
		"test_LF_4 ok [%+10.4LF]",
		"test_LF_5 ok [%10.4LF]",
		"test_LF_6 ok [%.4LF]",
		"test_LF_7 ok [%10LF]",
		"test_LF_8 ok [%+.4LF]",
		"test_LF_9 ok [%+LF]",
		"test_LF_10 ok [%+10LF]",
		"test_LF_11 ok [%-10.4LF]",
		"test_LF_12 ok [%-.4LF]",
		"test_LF_13 ok [%-LF]",
		"test_LF_14 ok [%-10LF]",
		"test_LF_15 ok [%-+.4LF]",
		"test_LF_16 ok [%-+LF]",
		"test_LF_17 ok [%-+10LF]",
		"test_LF_18 ok [% +10.4LF]",
		"test_LF_19 ok [% 10.4LF]",
		"test_LF_20 ok [% .4LF]",
		"test_LF_21 ok [% LF]",
		"test_LF_22 ok [% 10LF]",
		"test_LF_23 ok [% +.4LF]",
		"test_LF_24 ok [% +LF]",
		"test_LF_25 ok [% +10LF]",
		"test_LF_26 ok [% -10.4LF]",
		"test_LF_27 ok [% -.4LF]",
		"test_LF_28 ok [% -LF]",
		"test_LF_29 ok [% -10LF]",
		"test_LF_30 ok [% -+.4LF]",
		"test_LF_31 ok [% -+LF]",
		"test_LF_32 ok [% -+10LF]",
		"test_LF_33 ok [%0-+10.4LF]",
		"test_LF_34 ok [%0+10.4LF]",
		"test_LF_35 ok [%010.4LF]",
		"test_LF_36 ok [%0.4LF]",
		"test_LF_37 ok [%0LF]",
		"test_LF_38 ok [%010LF]",
		"test_LF_39 ok [%0+.4LF]",
		"test_LF_40 ok [%0+LF]",
		"test_LF_41 ok [%0+10LF]",
		"test_LF_42 ok [%0-10.4LF]",
		"test_LF_43 ok [%0-.4LF]",
		"test_LF_44 ok [%0-LF]",
		"test_LF_45 ok [%0-10LF]",
		"test_LF_46 ok [%0-+.4LF]",
		"test_LF_47 ok [%0-+LF]",
		"test_LF_48 ok [%0-+10LF]",
		"test_LF_49 ok [%0 +10.4LF]",
		"test_LF_50 ok [%0 10.4LF]",
		"test_LF_51 ok [%0 .4LF]",
		"test_LF_52 ok [%0 LF]",
		"test_LF_53 ok [%0 10LF]",
		"test_LF_54 ok [%0 +.4LF]",
		"test_LF_55 ok [%0 +LF]",
		"test_LF_56 ok [%0 +10LF]",
		"test_LF_57 ok [%0 -10.4LF]",
		"test_LF_58 ok [%0 -.4LF]",
		"test_LF_59 ok [%0 -LF]",
		"test_LF_60 ok [%0 -10LF]",
		"test_LF_61 ok [%0 -+.4LF]",
		"test_LF_62 ok [%0 -+LF]",
		"test_LF_63 ok [%0 -+10LF]",
		"test_LF_64 ok [%# -+10.4LF]",
		"test_LF_65 ok [%#-+10.4LF]",
		"test_LF_66 ok [%#+10.4LF]",
		"test_LF_67 ok [%#10.4LF]",
		"test_LF_68 ok [%#.4LF]",
		"test_LF_69 ok [%#LF]",
		"test_LF_70 ok [%#10LF]",
		"test_LF_71 ok [%#+.4LF]",
		"test_LF_72 ok [%#+LF]",
		"test_LF_73 ok [%#+10LF]",
		"test_LF_74 ok [%#-10.4LF]",
		"test_LF_75 ok [%#-.4LF]",
		"test_LF_76 ok [%#-LF]",
		"test_LF_77 ok [%#-10LF]",
		"test_LF_78 ok [%#-+.4LF]",
		"test_LF_79 ok [%#-+LF]",
		"test_LF_80 ok [%#-+10LF]",
		"test_LF_81 ok [%# +10.4LF]",
		"test_LF_82 ok [%# 10.4LF]",
		"test_LF_83 ok [%# .4LF]",
		"test_LF_84 ok [%# LF]",
		"test_LF_85 ok [%# 10LF]",
		"test_LF_86 ok [%# +.4LF]",
		"test_LF_87 ok [%# +LF]",
		"test_LF_88 ok [%# +10LF]",
		"test_LF_89 ok [%# -10.4LF]",
		"test_LF_90 ok [%# -.4LF]",
		"test_LF_91 ok [%# -LF]",
		"test_LF_92 ok [%# -10LF]",
		"test_LF_93 ok [%# -+.4LF]",
		"test_LF_94 ok [%# -+LF]",
		"test_LF_95 ok [%# -+10LF]",
		"test_LF_96 ok [%#0-+10.4LF]",
		"test_LF_97 ok [%#0+10.4LF]",
		"test_LF_98 ok [%#010.4LF]",
		"test_LF_99 ok [%#0.4LF]",
		"test_LF_100 ok [%#0LF]",
		"test_LF_101 ok [%#010LF]",
		"test_LF_102 ok [%#0+.4LF]",
		"test_LF_103 ok [%#0+LF]",
		"test_LF_104 ok [%#0+10LF]",
		"test_LF_105 ok [%#0-10.4LF]",
		"test_LF_106 ok [%#0-.4LF]",
		"test_LF_107 ok [%#0-LF]",
		"test_LF_108 ok [%#0-10LF]",
		"test_LF_109 ok [%#0-+.4LF]",
		"test_LF_110 ok [%#0-+LF]",
		"test_LF_111 ok [%#0-+10LF]",
		"test_LF_112 ok [%#0 +10.4LF]",
		"test_LF_113 ok [%#0 10.4LF]",
		"test_LF_114 ok [%#0 .4LF]",
		"test_LF_115 ok [%#0 LF]",
		"test_LF_116 ok [%#0 10LF]",
		"test_LF_117 ok [%#0 +.4LF]",
		"test_LF_118 ok [%#0 +LF]",
		"test_LF_119 ok [%#0 +10LF]",
		"test_LF_120 ok [%#0 -10.4LF]",
		"test_LF_121 ok [%#0 -.4LF]",
		"test_LF_122 ok [%#0 -LF]",
		"test_LF_123 ok [%#0 -10LF]",
		"test_LF_124 ok [%#0 -+.4LF]",
		"test_LF_125 ok [%#0 -+LF]",
		"test_LF_126 ok [%#0 -+10LF]",
		"test_Lfr_1 ok [%LF]",
		"test_Lfr_2 ok [%.5LF]",
		"test_Lfr_3 ok [%.4LF]",
		"test_Lfr_4 ok [%.3LF]",
		"test_Lfr_5 ok [%.2LF]",
		"test_Lfr_6 ok [%.1LF]",
		"test_Lfr_7 ok [%.0LF]",
		NULL
	};

	long double stop_num = -42;
	long double num[] = {
		FLT_MIN,
		FLT_MAX,
		FLT_EPSILON,
		0,
		-0,
		1,
		-1,
		2,
		-2,
		0.2,
		-0.2,
		2.0625,
		3.03125,
		4.09375,
		4.00001,
		1.0 / 0.0,
		-1.0 / 0.0,
		0.0 / 0.0,
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %LF); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
