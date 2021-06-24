/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** backtick
*/

#include "shell42.h"

static void son_backtick(head_t *head, char **cmd, int i)
{
    if (head->command_line != NULL)
        free(head->command_line);
    head->command_line = NULL;
    cmd[i][strlen(cmd[i]) - 1] = 0;
    head->command_line = strdup(cmd[i] + 1);
    if (head->command_array != NULL)
        destroy_array(&head->command_array);
    if (head->cmd_list != NULL)
        destroy_cmd_list(head->cmd_list);
    head->cmd_list = NULL;
    head->command_array = NULL;
    reformat_str(head);
    head->command_line = check_history(&head->cmd_history, head->command_line);
    command_line_to_array(head);
    if (redirection_error_handling(head->command_array))
        exit(1);
    pars_command(head);
    exec_command_line(head);
    printf("%c", 0);
    exit(1);
}

static void rm_i_element_array(char ***array, int n)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < n; i++);
    free((*array)[i]);
    j = i;
    i++;
    for (i; (*array)[i] != NULL; i++, j++) {
        (*array)[j] = (*array)[i];
    }
    (*array)[j] = NULL;
}

static void father_backtick(head_t *head, pid_t pid,
save_fd_t save_fd, int i)
{
    int status;
    char *letter = malloc(sizeof(char) * 2);
    char *buff = malloc(sizeof(char) * 1);

    waitpid(pid, &status, WCONTINUED);
    buff[0] = 0;
    letter[0] = 0;
    letter[1] = 0;
    while (read(0, letter, 1) == 1) {
        buff = realloc(buff, sizeof(char) * (strlen(buff) + 2));
        buff = strcat(buff, letter);
        if (letter[0] == 0)
            break;
    }
    if (buff[0] != 0)
        get_backtick_return(head, buff, i);
    else
        rm_i_element_array(&(head->cmd_list->argument), i);
    free(buff);
    free(letter);
}

static void exec_backtick_command(head_t *head, pid_t pid,
save_fd_t save_fd, int i)
{
    if (pid != 0) {
        father_backtick(head, pid, save_fd, i);
        dup2(save_fd.in, 0);
        dup2(save_fd.out, 1);
    }
    else
        son_backtick(head, head->cmd_list->argument, i);
}

void check_backtick_command(head_t *head)
{
    pid_t pid;
    save_fd_t save_fd;
    int pipefd[2];

    for (int i = 0; head->cmd_list->argument[i] != NULL; i++) {
        if (head->cmd_list->argument[i][0] == '`') {
            save_fd.in = dup(0);
            save_fd.out = dup(1);
            pipe(pipefd);
            dup2(pipefd[1], 1);
            dup2(pipefd[0], 0);
            pid = fork();
            exec_backtick_command(head, pid, save_fd, i);
        }
    }
}