/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** is_separator
*/

#include <criterion/criterion.h>

int is_alpha_num(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
        return true;
    if (letter >= 'a' && letter <= 'z')
        return true;
    if (letter >= '0' && letter <= '9')
        return true;
    return false;
}

int is_double_separator(char letter)
{
    if (letter == '&')
        return true;
    if (letter == '|' || letter == '&')
        return true;
    if (letter == '>' || letter == '<')
        return true;
    return false;
}

int is_simple_separator(char letter)
{
    if (letter == '(' || letter == ')')
        return true;
    if (letter == ';')
        return true;
    return false;
}

Test(is_alpha_num, unit_test)
{
    char letter = 'a';
    int ret = is_alpha_num(letter);

    cr_assert_eq(ret, 1);
}

Test(is_double_separator, unit_test)
{
    char letter = '&';
    int ret = is_double_separator(letter);

    cr_assert_eq(ret, 1);
}

Test(is_simple_separator, unit_test)
{
    char letter = ';';
    int ret = is_simple_separator(letter);

    cr_assert_eq(ret, 1);
}