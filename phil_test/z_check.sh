#!/usr/bin/env bash
#https://devhints.io/bash
#https://stackoverflow.com/questions/7069682/how-to-get-arguments-with-flags-in-bash/21128172

# sh z_check.sh [-d]

d_flag=''
path2libftprintf=../ft_printf

while getopts 'd' flag; do
	case "${flag}" in
		d) d_flag='true' ;;
	esac
done

make -C $path2libftprintf
make args=$path2libftprintf
./run_test > z_result;
csplit -s z_result /next_origin_printf/;
tail -n +2 xx01 > xx_origin_printf;
rm xx01;
diff xx00 xx_origin_printf > xx_diff;
diff xx00 xx_origin_printf;
tests_passed=$(head -1 xx_diff);

if [[ -z $tests_passed ]] && test -f "xx00"; then
	echo "Test passed ! ✅  ✅  ✅"
else
	echo "Test NOT passed ! ❌  ❌  ❌"
fi

if [ "$d_flag" = "true" ]; then
	rm xx_diff xx00 xx_origin_printf z_result;
	make fclean -C $path2libftprintf
	make fclean
fi
