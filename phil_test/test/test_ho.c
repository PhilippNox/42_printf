/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 02:14:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/06 20:55:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// replace: ho] _hd %hd

#include "tests.h"

void test_ho(int (*fun)(const char *format, ...))
{
	int idx;
	int idxn;
	char *str[] = {
		"test_ho_0 ok [%#0 -+10.4ho]",
		"test_ho_1 ok [%0 -+10.4ho]",
		"test_ho_2 ok [% -+10.4ho]",
		"test_ho_3 ok [%-+10.4ho]",
		"test_ho_4 ok [%+10.4ho]",
		"test_ho_5 ok [%10.4ho]",
		"test_ho_6 ok [%.4ho]",
		"test_ho_7 ok [%10ho]",
		"test_ho_8 ok [%+.4ho]",
		"test_ho_9 ok [%+ho]",
		"test_ho_10 ok [%+10ho]",
		"test_ho_11 ok [%-10.4ho]",
		"test_ho_12 ok [%-.4ho]",
		"test_ho_13 ok [%-ho]",
		"test_ho_14 ok [%-10ho]",
		"test_ho_15 ok [%-+.4ho]",
		"test_ho_16 ok [%-+ho]",
		"test_ho_17 ok [%-+10ho]",
		"test_ho_18 ok [% +10.4ho]",
		"test_ho_19 ok [% 10.4ho]",
		"test_ho_20 ok [% .4ho]",
		"test_ho_21 ok [% ho]",
		"test_ho_22 ok [% 10ho]",
		"test_ho_23 ok [% +.4ho]",
		"test_ho_24 ok [% +ho]",
		"test_ho_25 ok [% +10ho]",
		"test_ho_26 ok [% -10.4ho]",
		"test_ho_27 ok [% -.4ho]",
		"test_ho_28 ok [% -ho]",
		"test_ho_29 ok [% -10ho]",
		"test_ho_30 ok [% -+.4ho]",
		"test_ho_31 ok [% -+ho]",
		"test_ho_32 ok [% -+10ho]",
		"test_ho_33 ok [%0-+10.4ho]",
		"test_ho_34 ok [%0+10.4ho]",
		"test_ho_35 ok [%010.4ho]",
		"test_ho_36 ok [%0.4ho]",
		"test_ho_37 ok [%0ho]",
		"test_ho_38 ok [%010ho]",
		"test_ho_39 ok [%0+.4ho]",
		"test_ho_40 ok [%0+ho]",
		"test_ho_41 ok [%0+10ho]",
		"test_ho_42 ok [%0-10.4ho]",
		"test_ho_43 ok [%0-.4ho]",
		"test_ho_44 ok [%0-ho]",
		"test_ho_45 ok [%0-10ho]",
		"test_ho_46 ok [%0-+.4ho]",
		"test_ho_47 ok [%0-+ho]",
		"test_ho_48 ok [%0-+10ho]",
		"test_ho_49 ok [%0 +10.4ho]",
		"test_ho_50 ok [%0 10.4ho]",
		"test_ho_51 ok [%0 .4ho]",
		"test_ho_52 ok [%0 ho]",
		"test_ho_53 ok [%0 10ho]",
		"test_ho_54 ok [%0 +.4ho]",
		"test_ho_55 ok [%0 +ho]",
		"test_ho_56 ok [%0 +10ho]",
		"test_ho_57 ok [%0 -10.4ho]",
		"test_ho_58 ok [%0 -.4ho]",
		"test_ho_59 ok [%0 -ho]",
		"test_ho_60 ok [%0 -10ho]",
		"test_ho_61 ok [%0 -+.4ho]",
		"test_ho_62 ok [%0 -+ho]",
		"test_ho_63 ok [%0 -+10ho]",
		"test_ho_64 ok [%# -+10.4ho]",
		"test_ho_65 ok [%#-+10.4ho]",
		"test_ho_66 ok [%#+10.4ho]",
		"test_ho_67 ok [%#10.4ho]",
		"test_ho_68 ok [%#.4ho]",
		"test_ho_69 ok [%#ho]",
		"test_ho_70 ok [%#10ho]",
		"test_ho_71 ok [%#+.4ho]",
		"test_ho_72 ok [%#+ho]",
		"test_ho_73 ok [%#+10ho]",
		"test_ho_74 ok [%#-10.4ho]",
		"test_ho_75 ok [%#-.4ho]",
		"test_ho_76 ok [%#-ho]",
		"test_ho_77 ok [%#-10ho]",
		"test_ho_78 ok [%#-+.4ho]",
		"test_ho_79 ok [%#-+ho]",
		"test_ho_80 ok [%#-+10ho]",
		"test_ho_81 ok [%# +10.4ho]",
		"test_ho_82 ok [%# 10.4ho]",
		"test_ho_83 ok [%# .4ho]",
		"test_ho_84 ok [%# ho]",
		"test_ho_85 ok [%# 10ho]",
		"test_ho_86 ok [%# +.4ho]",
		"test_ho_87 ok [%# +ho]",
		"test_ho_88 ok [%# +10ho]",
		"test_ho_89 ok [%# -10.4ho]",
		"test_ho_90 ok [%# -.4ho]",
		"test_ho_91 ok [%# -ho]",
		"test_ho_92 ok [%# -10ho]",
		"test_ho_93 ok [%# -+.4ho]",
		"test_ho_94 ok [%# -+ho]",
		"test_ho_95 ok [%# -+10ho]",
		"test_ho_96 ok [%#0-+10.4ho]",
		"test_ho_97 ok [%#0+10.4ho]",
		"test_ho_98 ok [%#010.4ho]",
		"test_ho_99 ok [%#0.4ho]",
		"test_ho_100 ok [%#0ho]",
		"test_ho_101 ok [%#010ho]",
		"test_ho_102 ok [%#0+.4ho]",
		"test_ho_103 ok [%#0+ho]",
		"test_ho_104 ok [%#0+10ho]",
		"test_ho_105 ok [%#0-10.4ho]",
		"test_ho_106 ok [%#0-.4ho]",
		"test_ho_107 ok [%#0-ho]",
		"test_ho_108 ok [%#0-10ho]",
		"test_ho_109 ok [%#0-+.4ho]",
		"test_ho_110 ok [%#0-+ho]",
		"test_ho_111 ok [%#0-+10ho]",
		"test_ho_112 ok [%#0 +10.4ho]",
		"test_ho_113 ok [%#0 10.4ho]",
		"test_ho_114 ok [%#0 .4ho]",
		"test_ho_115 ok [%#0 ho]",
		"test_ho_116 ok [%#0 10ho]",
		"test_ho_117 ok [%#0 +.4ho]",
		"test_ho_118 ok [%#0 +ho]",
		"test_ho_119 ok [%#0 +10ho]",
		"test_ho_120 ok [%#0 -10.4ho]",
		"test_ho_121 ok [%#0 -.4ho]",
		"test_ho_122 ok [%#0 -ho]",
		"test_ho_123 ok [%#0 -10ho]",
		"test_ho_124 ok [%#0 -+.4ho]",
		"test_ho_125 ok [%#0 -+ho]",
		"test_ho_126 ok [%#0 -+10ho]",
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
			fun("\t\t\t\t//\tprintf(\"%s\", %ho); // RUN THIS CODE FOR DEBUG\n", str[idx], num[idxn]);
		}
	}
}
