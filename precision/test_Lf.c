/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Lf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/08 01:19:05 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: Lf] _Lf_ %Lf

#include "tests.h"

void test_Lf(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_Lf_0 ok [%#0 -+10.4Lf]",
		"test_Lf_1 ok [%0 -+10.4Lf]",
		"test_Lf_2 ok [% -+10.4Lf]",
		"test_Lf_3 ok [%-+10.4Lf]",
		"test_Lf_4 ok [%+10.4Lf]",
		"test_Lf_5 ok [%10.4Lf]",
		"test_Lf_6 ok [%.4Lf]",
		"test_Lf_7 ok [%10Lf]",
		"test_Lf_8 ok [%+.4Lf]",
		"test_Lf_9 ok [%+Lf]",
		"test_Lf_10 ok [%+10Lf]",
		"test_Lf_11 ok [%-10.4Lf]",
		"test_Lf_12 ok [%-.4Lf]",
		"test_Lf_13 ok [%-Lf]",
		"test_Lf_14 ok [%-10Lf]",
		"test_Lf_15 ok [%-+.4Lf]",
		"test_Lf_16 ok [%-+Lf]",
		"test_Lf_17 ok [%-+10Lf]",
		"test_Lf_18 ok [% +10.4Lf]",
		"test_Lf_19 ok [% 10.4Lf]",
		"test_Lf_20 ok [% .4Lf]",
		"test_Lf_21 ok [% Lf]",
		"test_Lf_22 ok [% 10Lf]",
		"test_Lf_23 ok [% +.4Lf]",
		"test_Lf_24 ok [% +Lf]",
		"test_Lf_25 ok [% +10Lf]",
		"test_Lf_26 ok [% -10.4Lf]",
		"test_Lf_27 ok [% -.4Lf]",
		"test_Lf_28 ok [% -Lf]",
		"test_Lf_29 ok [% -10Lf]",
		"test_Lf_30 ok [% -+.4Lf]",
		"test_Lf_31 ok [% -+Lf]",
		"test_Lf_32 ok [% -+10Lf]",
		"test_Lf_33 ok [%0-+10.4Lf]",
		"test_Lf_34 ok [%0+10.4Lf]",
		"test_Lf_35 ok [%010.4Lf]",
		"test_Lf_36 ok [%0.4Lf]",
		"test_Lf_37 ok [%0Lf]",
		"test_Lf_38 ok [%010Lf]",
		"test_Lf_39 ok [%0+.4Lf]",
		"test_Lf_40 ok [%0+Lf]",
		"test_Lf_41 ok [%0+10Lf]",
		"test_Lf_42 ok [%0-10.4Lf]",
		"test_Lf_43 ok [%0-.4Lf]",
		"test_Lf_44 ok [%0-Lf]",
		"test_Lf_45 ok [%0-10Lf]",
		"test_Lf_46 ok [%0-+.4Lf]",
		"test_Lf_47 ok [%0-+Lf]",
		"test_Lf_48 ok [%0-+10Lf]",
		"test_Lf_49 ok [%0 +10.4Lf]",
		"test_Lf_50 ok [%0 10.4Lf]",
		"test_Lf_51 ok [%0 .4Lf]",
		"test_Lf_52 ok [%0 Lf]",
		"test_Lf_53 ok [%0 10Lf]",
		"test_Lf_54 ok [%0 +.4Lf]",
		"test_Lf_55 ok [%0 +Lf]",
		"test_Lf_56 ok [%0 +10Lf]",
		"test_Lf_57 ok [%0 -10.4Lf]",
		"test_Lf_58 ok [%0 -.4Lf]",
		"test_Lf_59 ok [%0 -Lf]",
		"test_Lf_60 ok [%0 -10Lf]",
		"test_Lf_61 ok [%0 -+.4Lf]",
		"test_Lf_62 ok [%0 -+Lf]",
		"test_Lf_63 ok [%0 -+10Lf]",
		"test_Lf_64 ok [%# -+10.4Lf]",
		"test_Lf_65 ok [%#-+10.4Lf]",
		"test_Lf_66 ok [%#+10.4Lf]",
		"test_Lf_67 ok [%#10.4Lf]",
		"test_Lf_68 ok [%#.4Lf]",
		"test_Lf_69 ok [%#Lf]",
		"test_Lf_70 ok [%#10Lf]",
		"test_Lf_71 ok [%#+.4Lf]",
		"test_Lf_72 ok [%#+Lf]",
		"test_Lf_73 ok [%#+10Lf]",
		"test_Lf_74 ok [%#-10.4Lf]",
		"test_Lf_75 ok [%#-.4Lf]",
		"test_Lf_76 ok [%#-Lf]",
		"test_Lf_77 ok [%#-10Lf]",
		"test_Lf_78 ok [%#-+.4Lf]",
		"test_Lf_79 ok [%#-+Lf]",
		"test_Lf_80 ok [%#-+10Lf]",
		"test_Lf_81 ok [%# +10.4Lf]",
		"test_Lf_82 ok [%# 10.4Lf]",
		"test_Lf_83 ok [%# .4Lf]",
		"test_Lf_84 ok [%# Lf]",
		"test_Lf_85 ok [%# 10Lf]",
		"test_Lf_86 ok [%# +.4Lf]",
		"test_Lf_87 ok [%# +Lf]",
		"test_Lf_88 ok [%# +10Lf]",
		"test_Lf_89 ok [%# -10.4Lf]",
		"test_Lf_90 ok [%# -.4Lf]",
		"test_Lf_91 ok [%# -Lf]",
		"test_Lf_92 ok [%# -10Lf]",
		"test_Lf_93 ok [%# -+.4Lf]",
		"test_Lf_94 ok [%# -+Lf]",
		"test_Lf_95 ok [%# -+10Lf]",
		"test_Lf_96 ok [%#0-+10.4Lf]",
		"test_Lf_97 ok [%#0+10.4Lf]",
		"test_Lf_98 ok [%#010.4Lf]",
		"test_Lf_99 ok [%#0.4Lf]",
		"test_Lf_100 ok [%#0Lf]",
		"test_Lf_101 ok [%#010Lf]",
		"test_Lf_102 ok [%#0+.4Lf]",
		"test_Lf_103 ok [%#0+Lf]",
		"test_Lf_104 ok [%#0+10Lf]",
		"test_Lf_105 ok [%#0-10.4Lf]",
		"test_Lf_106 ok [%#0-.4Lf]",
		"test_Lf_107 ok [%#0-Lf]",
		"test_Lf_108 ok [%#0-10Lf]",
		"test_Lf_109 ok [%#0-+.4Lf]",
		"test_Lf_110 ok [%#0-+Lf]",
		"test_Lf_111 ok [%#0-+10Lf]",
		"test_Lf_112 ok [%#0 +10.4Lf]",
		"test_Lf_113 ok [%#0 10.4Lf]",
		"test_Lf_114 ok [%#0 .4Lf]",
		"test_Lf_115 ok [%#0 Lf]",
		"test_Lf_116 ok [%#0 10Lf]",
		"test_Lf_117 ok [%#0 +.4Lf]",
		"test_Lf_118 ok [%#0 +Lf]",
		"test_Lf_119 ok [%#0 +10Lf]",
		"test_Lf_120 ok [%#0 -10.4Lf]",
		"test_Lf_121 ok [%#0 -.4Lf]",
		"test_Lf_122 ok [%#0 -Lf]",
		"test_Lf_123 ok [%#0 -10Lf]",
		"test_Lf_124 ok [%#0 -+.4Lf]",
		"test_Lf_125 ok [%#0 -+Lf]",
		"test_Lf_126 ok [%#0 -+10Lf]",
		"test_Lfr_1 ok [%Lf]",
		"test_Lfr_2 ok [%.5Lf]",
		"test_Lfr_3 ok [%.4Lf]",
		"test_Lfr_4 ok [%.3Lf]",
		"test_Lfr_5 ok [%.2Lf]",
		"test_Lfr_6 ok [%.1Lf]",
		"test_Lfr_7 ok [%.0Lf]",
		NULL
	};

	long double stop_num = -42;
	long double num[] = {
		FLT_MIN,
		FLT_MAX,
		FLT_EPSILON,
		//0,
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
		stop_num
	};

	idx = -1;
	while (str[++idx])
	{
		idxn = -1;
		while (num[++idxn] != stop_num)
		{
			fun(str[idx], num[idxn]);
			fun("\t\t\t\t//\tprintf(\"%s\", %Lf); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
