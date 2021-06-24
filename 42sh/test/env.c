/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** env
*/

#include <criterion/criterion.h>
#include <unistd.h>

int count_nb_element_array(char **array)
{
    int i;

    for (i = 1; array[i] != NULL; i++);
    return i;
}

int builtin_env(char **cmd)
{
    if (count_nb_element_array(cmd) != 1) {
        write(2, "env: Too many arguments.\n", 25);
            return 1;
    }
    return 0;
}

Test(builtin_env, unit_test)
{
    char *array[2] = {"env", NULL};
    int value = builtin_env(array);

    cr_assert_eq(value, 0);
}
