#!/usr/bin/env bash
#https://devhints.io/bash
#https://stackoverflow.com/questions/7069682/how-to-get-arguments-with-flags-in-bash/21128172

# sh z_check.sh [-d]

d_flag=''

while getopts 'd' flag; do
	case "${flag}" in
		d) d_flag='true' ;;
	esac
done

gcc -Wall -Wextra ft_atoi.c ft_put.c ft_printf.c ft_make_c.c ft_printf_helper.c ft_printf_task.c ft_make_p.c ft_make_s.c ft_make_d.c;
./a.out > z_result;
csplit -s z_result /ok_end/;
tail -n +2 xx01 > xx_origin;
rm xx01;
diff xx00 xx_origin > xx_diff;
diff xx00 xx_origin;
tests_passed=$(head -1 xx_diff);

if [[ -z $tests_passed ]] && test -f "xx00"; then
	echo "Test passed ! ✅  ✅  ✅"
else
	echo "Test NOT passed ! ❌  ❌  ❌"
fi

if [ "$d_flag" = "true" ]; then
	rm xx_diff xx00 xx_origin z_result;
fi
