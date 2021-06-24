/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** foreach_parsing
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <stdio.h>

int check_non_alpha(char letter)
{
    int ok = 0;

    if (!(letter > 64 && letter < 91))
        ok = 1;
    if (ok == 1 && letter > 96 && letter < 123)
        ok = 0;
    if (ok == 1 && letter > 47 && letter < 58)
        ok = 0;
    if (ok == 1 && letter == '.')
        ok = 0;
    if (ok == 1) {
        dprintf(2,
                "setenv: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int setenv_error_handling(char **args)
{
    int ok = 0;
    int i = 0;

    if (!(args[1][0] > 64 && args[1][0] < 91))
        ok = 1;
    if (ok == 1 && args[1][0] > 96 && args[1][0] < 123)
        ok = 0;
    if (ok == 0) {
        for (i = 0; args[1][i] != 0 && args[1][i] != 32; i++);
        if (i != strlen(args[1]))
            ok = 1;
    }
    if (ok == 1) {
        dprintf(2, "setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (check_non_alpha(args[1][i]) == 1)
            return 1;
    }
    return 0;
}

Test(check_non_alpha, unit_test)
{
    char letter = 62;
    int value = check_non_alpha(letter);

    cr_assert_eq(value, 1);
}

Test(setenv_error_handling, unit_test)
{
    char *array[3] = {"setenv", "+", NULL};
    int value = setenv_error_handling(array);

    cr_assert_eq(value, 1);
}