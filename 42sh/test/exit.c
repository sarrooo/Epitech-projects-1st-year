/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** exit
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>

int count_nb_element_array2(char **array)
{
    int i;

    for (i = 1; array[i] != NULL; i++);
    return i;
}

int builtin_exit(char **cmd)
{
    int nb_var = count_nb_element_array2(cmd);

    if (nb_var > 2) {
        write(2, "exit: Expression Syntax.\n", 25);
        return 1;
    }
    else {
        return 0;
    }
}

Test(builtin_exit, unit_test)
{
    char *array[2] = {"exit", "1"};
    int value = builtin_exit(array);

    cr_assert_eq(value, 1);
}
