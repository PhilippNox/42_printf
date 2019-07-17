/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_hi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:40:17 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: hi] _hd %hd

#include "tests.h"

void test_hi(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_hi_0 ok [%#0 -+10.4hi]",
		"test_hi_1 ok [%0 -+10.4hi]",
		"test_hi_2 ok [% -+10.4hi]",
		"test_hi_3 ok [%-+10.4hi]",
		"test_hi_4 ok [%+10.4hi]",
		"test_hi_5 ok [%10.4hi]",
		"test_hi_6 ok [%.4hi]",
		"test_hi_7 ok [%10hi]",
		"test_hi_8 ok [%+.4hi]",
		"test_hi_9 ok [%+hi]",
		"test_hi_10 ok [%+10hi]",
		"test_hi_11 ok [%-10.4hi]",
		"test_hi_12 ok [%-.4hi]",
		"test_hi_13 ok [%-hi]",
		"test_hi_14 ok [%-10hi]",
		"test_hi_15 ok [%-+.4hi]",
		"test_hi_16 ok [%-+hi]",
		"test_hi_17 ok [%-+10hi]",
		"test_hi_18 ok [% +10.4hi]",
		"test_hi_19 ok [% 10.4hi]",
		"test_hi_20 ok [% .4hi]",
		"test_hi_21 ok [% hi]",
		"test_hi_22 ok [% 10hi]",
		"test_hi_23 ok [% +.4hi]",
		"test_hi_24 ok [% +hi]",
		"test_hi_25 ok [% +10hi]",
		"test_hi_26 ok [% -10.4hi]",
		"test_hi_27 ok [% -.4hi]",
		"test_hi_28 ok [% -hi]",
		"test_hi_29 ok [% -10hi]",
		"test_hi_30 ok [% -+.4hi]",
		"test_hi_31 ok [% -+hi]",
		"test_hi_32 ok [% -+10hi]",
		"test_hi_33 ok [%0-+10.4hi]",
		"test_hi_34 ok [%0+10.4hi]",
		"test_hi_35 ok [%010.4hi]",
		"test_hi_36 ok [%0.4hi]",
		"test_hi_37 ok [%0hi]",
		"test_hi_38 ok [%010hi]",
		"test_hi_39 ok [%0+.4hi]",
		"test_hi_40 ok [%0+hi]",
		"test_hi_41 ok [%0+10hi]",
		"test_hi_42 ok [%0-10.4hi]",
		"test_hi_43 ok [%0-.4hi]",
		"test_hi_44 ok [%0-hi]",
		"test_hi_45 ok [%0-10hi]",
		"test_hi_46 ok [%0-+.4hi]",
		"test_hi_47 ok [%0-+hi]",
		"test_hi_48 ok [%0-+10hi]",
		"test_hi_49 ok [%0 +10.4hi]",
		"test_hi_50 ok [%0 10.4hi]",
		"test_hi_51 ok [%0 .4hi]",
		"test_hi_52 ok [%0 hi]",
		"test_hi_53 ok [%0 10hi]",
		"test_hi_54 ok [%0 +.4hi]",
		"test_hi_55 ok [%0 +hi]",
		"test_hi_56 ok [%0 +10hi]",
		"test_hi_57 ok [%0 -10.4hi]",
		"test_hi_58 ok [%0 -.4hi]",
		"test_hi_59 ok [%0 -hi]",
		"test_hi_60 ok [%0 -10hi]",
		"test_hi_61 ok [%0 -+.4hi]",
		"test_hi_62 ok [%0 -+hi]",
		"test_hi_63 ok [%0 -+10hi]",
		"test_hi_64 ok [%# -+10.4hi]",
		"test_hi_65 ok [%#-+10.4hi]",
		"test_hi_66 ok [%#+10.4hi]",
		"test_hi_67 ok [%#10.4hi]",
		"test_hi_68 ok [%#.4hi]",
		"test_hi_69 ok [%#hi]",
		"test_hi_70 ok [%#10hi]",
		"test_hi_71 ok [%#+.4hi]",
		"test_hi_72 ok [%#+hi]",
		"test_hi_73 ok [%#+10hi]",
		"test_hi_74 ok [%#-10.4hi]",
		"test_hi_75 ok [%#-.4hi]",
		"test_hi_76 ok [%#-hi]",
		"test_hi_77 ok [%#-10hi]",
		"test_hi_78 ok [%#-+.4hi]",
		"test_hi_79 ok [%#-+hi]",
		"test_hi_80 ok [%#-+10hi]",
		"test_hi_81 ok [%# +10.4hi]",
		"test_hi_82 ok [%# 10.4hi]",
		"test_hi_83 ok [%# .4hi]",
		"test_hi_84 ok [%# hi]",
		"test_hi_85 ok [%# 10hi]",
		"test_hi_86 ok [%# +.4hi]",
		"test_hi_87 ok [%# +hi]",
		"test_hi_88 ok [%# +10hi]",
		"test_hi_89 ok [%# -10.4hi]",
		"test_hi_90 ok [%# -.4hi]",
		"test_hi_91 ok [%# -hi]",
		"test_hi_92 ok [%# -10hi]",
		"test_hi_93 ok [%# -+.4hi]",
		"test_hi_94 ok [%# -+hi]",
		"test_hi_95 ok [%# -+10hi]",
		"test_hi_96 ok [%#0-+10.4hi]",
		"test_hi_97 ok [%#0+10.4hi]",
		"test_hi_98 ok [%#010.4hi]",
		"test_hi_99 ok [%#0.4hi]",
		"test_hi_100 ok [%#0hi]",
		"test_hi_101 ok [%#010hi]",
		"test_hi_102 ok [%#0+.4hi]",
		"test_hi_103 ok [%#0+hi]",
		"test_hi_104 ok [%#0+10hi]",
		"test_hi_105 ok [%#0-10.4hi]",
		"test_hi_106 ok [%#0-.4hi]",
		"test_hi_107 ok [%#0-hi]",
		"test_hi_108 ok [%#0-10hi]",
		"test_hi_109 ok [%#0-+.4hi]",
		"test_hi_110 ok [%#0-+hi]",
		"test_hi_111 ok [%#0-+10hi]",
		"test_hi_112 ok [%#0 +10.4hi]",
		"test_hi_113 ok [%#0 10.4hi]",
		"test_hi_114 ok [%#0 .4hi]",
		"test_hi_115 ok [%#0 hi]",
		"test_hi_116 ok [%#0 10hi]",
		"test_hi_117 ok [%#0 +.4hi]",
		"test_hi_118 ok [%#0 +hi]",
		"test_hi_119 ok [%#0 +10hi]",
		"test_hi_120 ok [%#0 -10.4hi]",
		"test_hi_121 ok [%#0 -.4hi]",
		"test_hi_122 ok [%#0 -hi]",
		"test_hi_123 ok [%#0 -10hi]",
		"test_hi_124 ok [%#0 -+.4hi]",
		"test_hi_125 ok [%#0 -+hi]",
		"test_hi_126 ok [%#0 -+10hi]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %hi); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
