/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** redirect_files_in
*/

#include "shell42.h"

static int is_directory(cmd_list_t *cmd)
{
    struct stat *buf = malloc(sizeof(struct stat));
    int fd = stat(cmd->input_redirection, buf);

    if (fd != -1 && S_ISDIR(buf->st_mode)) {
        dprintf(2, "%s: -: Is a directory.\n", cmd->argument[0]);
        free(buf);
        return 1;
    }
    free(buf);
    return 0;
}

static int strcmp_without_jump_line(char *s1, char *s2)
{
    if (strlen(s1) - 1 != strlen(s2))
        return (1);
    for (int i = 0; s1[i] != '\n'; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    return (0);
}

static int manage_simple_input(head_t *head, cmd_list_t *cmd)
{
    int fd = 0;

    if (is_directory(cmd))
        return (1);
    fd = open(cmd->input_redirection, O_RDWR);
    if (fd == -1) {
        if (errno == EACCES) {
            dprintf(2, "%s: Permission denied.\n", cmd->input_redirection);
        } else {
            dprintf(2, "%s: No such file or directory.\n",
            cmd->input_redirection);
        }
        return 1;
    }
    cmd->fd_input = fd;
    if (error_handling_dup_in(cmd, fd)) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

static int manage_double_input(head_t *head, cmd_list_t *cmd)
{
    char *tmp = calloc(1, sizeof(char));
    char *str = calloc(1, sizeof(char));
    size_t len;

    while (strcmp(tmp, cmd->input_redirection) != 0 &&
    strcmp_without_jump_line(tmp, cmd->input_redirection) != 0) {
        free(tmp);
        tmp = NULL;
        write(1, "? ", 2);
        getline(&tmp, &len, stdin);
        if (strcmp(tmp, cmd->input_redirection) != 0 &&
        strcmp_without_jump_line(tmp, cmd->input_redirection) != 0) {
            str = realloc(str, sizeof(char) * (strlen(str) + strlen(tmp) + 1));
            strcat(str, tmp);
        }
    }
    return (finish_double_input(cmd, tmp, str));
}

int manage_redirection_in(head_t *head, cmd_list_t *cmd)
{
    if (cmd->input_redirection != NULL) {
        if (cmd->type_input == SIMPLE_INPUT &&
        manage_simple_input(head, cmd) == 1)
            return (1);
        if (cmd->type_input == DOUBLE_INPUT &&
        manage_double_input(head, cmd) == 1)
            return (1);
    }
    return (0);
}