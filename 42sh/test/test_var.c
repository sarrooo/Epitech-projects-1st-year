/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** test_env
*/

#include <criterion/criterion.h>
#include "../include/shell42.h"

static int check_non_alpha(char letter)
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
        "set: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

int in_dquote(char *cmd)
{
    int inhib = 0;
    int indquote = -1;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == 34)
            indquote *= -1;
        if (cmd[i] == '$' && inhib == 0)
            return (indquote);
        if (cmd[i] == '\\')
            inhib = 1;
        else
            inhib = 0;
    }
    return (0);
}

int get_var_pos(char *cmd)
{
    int inquote = -1;
    int inhib = 0;

    for (int i = 0; cmd[i]; i++) {
        if (cmd[i] == 39)
            inquote *= -1;
        if (cmd[i] == '$' && inquote == -1 && inhib == 0)
            return (i);
        if (cmd[i] == '\\')
            inhib = 1;
        else
            inhib = 0;
    }
}

char *get_name(char *cmd)
{
    int inquote = -1;
    int i = get_var_pos(cmd);
    int j = 0;
    char *name;

    name = malloc(sizeof(char) * (strlen(cmd) - i + 1));
    for (i = i + 1; cmd[i] && cmd[i] != ' ' && cmd[i] != 34; i++, j++)
        name[j] = cmd[i];
    name[j] = '\0';
    return (name);
}

Test(shell42, get_name)
{
    char cmd1[] = {"$lol"};
    char cmd2[] = {"lol$rayou"};

    cr_assert_str_eq(get_name(cmd1), "lol");
    cr_assert_str_eq(get_name(cmd2), "rayou");
}

Test(shell42, get_var_pos)
{
    char cmd1[] = {"$lol"};
    char cmd2[] = {"lol$"};

    cr_assert_eq(get_var_pos(cmd1), 0);
    cr_assert_eq(get_var_pos(cmd2), 3);
}

Test(shell42, check_indquote)
{
    char cmd1[] = {"\"$lol\""};
    char cmd2[] = {"lol"};

    cr_assert_eq(in_dquote(cmd1), 1);
    cr_assert_eq(in_dquote(cmd2), 0);
}

Test(shell42, check_non_alpha)
{
    char c1 = 'a';
    char c2 = '-';

    cr_assert_eq(check_non_alpha(c1), 0);
    cr_assert_eq(check_non_alpha(c2), 1);
}
