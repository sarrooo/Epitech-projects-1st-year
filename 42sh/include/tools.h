/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** tools
*/

#ifndef TOOLS_H_
#define TOOLS_H_

#include "shell42.h"

// ARRAY //
void print_array(char **array);
int count_nb_element_array(char **array);
char **copy_array(char **array);

// REFORMAT STRING //
int is_double_separator(char letter);
int is_simple_separator(char letter);
int count_words_str(char const *str);
char **my_str_to_word_array(char const *str);
int check_alphanum_str(char const *str, int j);

// DESTROY //
void destroy_array(char ***array);
void destroy_head(head_t *head);

//LINKED LIST //
void add_element_env(char *name, char *value, env_list_t **list);
void destroy_env_list(env_list_t **list);
env_list_t *get_last_element_env(env_list_t *list);
char **env_list_to_array(env_list_t *env);
env_list_t *get_var(env_list_t *list, char *name);
char **get_path_arr(env_list_t *list);
int count_nb_path(char *path);

#endif /* !TOOLS_H_ */