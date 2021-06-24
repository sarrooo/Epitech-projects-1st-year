/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** redirect_files
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

static int manage_simple_output(head_t *head, cmd_list_t *cmd)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int fd = 0;

    if (is_directory(cmd))
        return 1;
    fd = open(cmd->output_redirection, O_CREAT | O_TRUNC | O_RDWR, mode);
    if (fd == -1) {
        dprintf(2, "%s: Permission denied.\n", cmd->output_redirection);
        return 1;
    }
    cmd->fd_output = fd;
    if (error_handling_dup_out(cmd, fd)) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

static int manage_double_output(head_t *head, cmd_list_t *cmd)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int fd = 0;

    if (is_directory(cmd))
        return 1;
    fd = open(cmd->output_redirection, O_CREAT | O_APPEND | O_RDWR, mode);
    if (fd == -1) {
        dprintf(2, "%s: Permission denied.\n", cmd->output_redirection);
        return 1;
    }
    cmd->fd_output = fd;
    if (error_handling_dup_out(cmd, fd)) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

int manage_redirection_out(head_t *head, cmd_list_t *cmd)
{
    if (cmd->output_redirection != NULL) {
        if (cmd->type_output == SIMPLE_OUTPUT &&
        manage_simple_output(head, cmd) == 1)
            return 1;
        if (cmd->type_output == DOUBLE_OUTPUT &&
        manage_double_output(head, cmd) == 1)
            return 1;
    }
    return 0;
}