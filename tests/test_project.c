/*
** EPITECH PROJECT, 2019
** Navy
** File description:
** Unit Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototype.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(utils, usage_attempt_1)
{
    cr_assert(usage() == 0);
}

Test(lib_attempt6, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lama";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_attempt7, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str, str2);
    cr_expect_eq(result, 0);
}

Test(lib_attempt8, simple_string, .init = redirect_all_std)
{
    char *str = "lama";
    char *str2 = "lamascotte";
    int result = 0;

    result = my_str(str2, str);
    cr_expect_eq(result, 1);
}

Test(lib_attempt9, simple_string, .init = redirect_all_std)
{
    my_putstr("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(lib_attempt10, string)
{
    int a = 42;
    char *str = NULL;

    str = my_putint_in_str(str, a);
    cr_assert_str_eq(str, "42");
}

Test(lib_attempt11, string)
{
    char *str = "hello";
    char *str2 = malloc(sizeof(char) * 6);

    str2 = my_revstr(str);
    cr_assert_str_neq(str, str2);
}

Test(asserts, string)
{
    cr_assert_str_empty("");
    cr_assert_str_not_empty("foo");
    cr_assert_str_eq("hello", "hello");
    cr_assert_str_neq("hello", "olleh");
    cr_assert_str_gt("hello", "hell");
    cr_assert_str_geq("hello", "hell");
    cr_assert_str_geq("hello", "hello");
    cr_assert_str_lt("hell", "hello");
    cr_assert_str_leq("hell", "hello");
    cr_assert_str_leq("hello", "hello");
}
