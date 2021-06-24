/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** local_var
*/

#include "shell42.h"

bool has_local_var(char *arg)
{
    int inquote = -1;
    int inhib = 0;

    for (int i = 0; arg[i]; i++) {
        if (arg[i] == 39)
            inquote *= -1;
        if (arg[i] == '$' && inhib == 0 && inquote == -1)
            return (true);
        if (arg[i] == '\\')
            inhib = 1;
        else
            inhib = 0;
    }
    return (false);
}

char *replace_name(char *cmd, char *value, int name_len)
{
    int k = 0;
    int i = get_var_pos(cmd);
    int len = 0;
    char *cmd_dup = strdup(cmd);

    check_indquote(cmd, &i, &k);
    for (int j = 0; cmd[i] && value && value[j]; i++, j++)
        cmd[i] = value[j];
    if (in_dquote(cmd) == 1)
        name_len += 2;
    for (; cmd_dup[i + name_len + 1]; i++)
        cmd[i] = cmd_dup[i + name_len + 1];
    cmd[i] = '\0';
    free(cmd_dup);
    return (cmd);
}

char *replace_var(char *cmd, char *value, int name_len)
{
    int k = 0;
    int i = get_var_pos(cmd);
    int len = strlen(value);
    char *cmd_dup = strdup(cmd);

    check_indquote(cmd, &i, &k);
    cmd = realloc(cmd, strlen(cmd) + len);
    for (int j = 0; cmd[i] && value && value[j]; i++, j++)
        cmd[i] = value[j];
    k += i + name_len - 2;
    if (k > 0 && k <= strlen(cmd_dup)) {
        for (; cmd_dup[k] && cmd[i]; i++, k++)
            cmd[i] = cmd_dup[k];
        cmd[i] = '\0';
    }
    cmd[i] = '\0';
    free(cmd_dup);
    return (cmd);
}

char *replace_local_var(char *cmd, head_t *head)
{
    env_list_t *wanted;
    char *name;

    name = get_name(cmd);
    wanted = get_var(head->var, name);
    if (wanted == NULL) {
        dprintf(2, "%s: Undefined variable.\n", name);
        free(name);
        return (NULL);
    }
    if (wanted->value == NULL)
        cmd = replace_name(cmd, wanted->value, strlen(name));
    else
        cmd = replace_var(cmd, wanted->value, strlen(name));
    if (has_local_var(cmd) == true)
        replace_local_var(cmd, head);
    free(name);
    return (cmd);
}

int check_local_var(head_t *head)
{
    if (has_local_var(head->command_line) == true) {
        head->command_line = replace_local_var(head->command_line, head);
        if (head->command_line == NULL) {
            head->exit_status = 1;
            return (-1);
        }
        return (1);
    }
    return (0);
}