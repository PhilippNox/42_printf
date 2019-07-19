#### tests ####
####

{
	cd /Users/wgorold/42FileChecker
	sh 42FileChecker.sh
}
{
	cd /Users/wgorold/d04_printf_gitlab/42_printf_unit_tests/tests
	make test
	ok
}

{
	cd /Users/wgorold/d04_printf_gitlab/printf-unit-test
	./run_test
	./run_test f
}
{
	cd /Users/wgorold/d04_printf_gitlab/pft
	./test
}
{
	cd /Users/wgorold/d04_printf_gitlab/phil_test
	sh z_check.sh -d
}
{
	### RUN target tests

	cd /Users/wgorold/d04_printf_gitlab/

	make -C ./ft_printf && gcc -Wall -Wextra test.c -I./ft_printf -L./ft_printf -lftprintf && ./a.out

	make fclean -C ./ft_printf && rm a.out
}
