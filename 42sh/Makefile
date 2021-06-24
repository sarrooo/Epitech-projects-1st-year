##
## EPITECH PROJECT, 2021
## Makefile of 42sh
## File description:
## Makefile
##

NAME	=	42sh

SRC	=	src/shell.c	\
		src/main_shell.c	\
		src/var/local_var.c	\
		src/var/get_var_funcs.c	\
		src/exec/manage_builtin.c	\
		src/exec/manage_builtin2.c	\
		src/exec/manage_command.c	\
		src/exec/exec_binary.c	\
		src/exec/error_message.c	\
		src/exec/create_path_env.c	\
		src/parentheses/exec_parentheses.c	\
		src/read_command/read_command_line.c	\
		src/read_command/reformat/reformat_str.c	\
		src/read_command/reformat/count_extra_space.c	\
		src/read_command/reformat/separator.c	\
		src/read_command/reformat/double_quote.c	\
		src/read_command/reformat/simple_quote.c	\
		src/read_command/reformat/backtick.c	\
		src/read_command/command_line_to_array.c	\
		src/read_command/error_handling/error_handling.c	\
		src/read_command/error_handling/redirection_error_handling.c	\
		src/read_command/error_handling/backtick_quote.c	\
		src/env/init_env_linked_list.c	\
		src/builtin/alias/alias.c	\
		src/builtin/alias/print_alias.c	\
		src/builtin/alias/tools_alias.c	\
		src/builtin/alias/repars_command.c	\
		src/builtin/cd/cd.c	\
		src/builtin/cd/error_handling.c	\
		src/builtin/env.c	\
		src/builtin/exit.c	\
		src/builtin/unsetenv.c	\
		src/builtin/setenv.c	\
		src/builtin/unalias.c	\
		src/builtin/where.c	\
		src/builtin/which.c	\
		src/builtin/foreach.c	\
		src/builtin/foreach_parsing.c	\
		src/builtin/repeat.c	\
		src/var/set.c	\
		src/var/print_var.c	\
		src/var/unset.c	\
		src/var/error_handling_set.c	\
		src/backtick/backtick.c	\
		src/backtick/reformat_array.c	\
		src/globbing/check_globbing.c	\
		src/globbing/error_handling.c	\
		src/redirection/error_handling_dup.c	\
		src/redirection/redirect_files_in.c	\
		src/redirection/redirect_files_out.c	\
		src/redirection/redirect_files.c	\
		src/redirection/reset_redirection.c	\
		src/redirection/redirect_file_in_aux.c	\
		src/pipe/init_pipe.c	\
		src/pipe/pipe_loop.c	\
		src/pipe/wait_pipe_pid.c	\
		src/pipe/stock_pipe_pid.c	\
		src/exec/manage_builtin_pipe.c	\
		src/parsing/pars_command.c	\
		src/parsing/tokenisation/get_type_token.c	\
		src/parsing/tokenisation/tokenisation.c	\
		src/parsing/cmd_list/init_cmd_list.c	\
		src/parsing/cmd_list/destroy_cmd_list.c	\
		src/parsing/cmd_list/get_cmd_cell.c	\
		src/parsing/cmd_list/tools.c	\
		src/tools/display_prompt.c	\
		src/tools/is_separator.c	\
		src/tools/destroy_array.c	\
		src/tools/str_to_word_array/count_word.c	\
		src/tools/str_to_word_array/my_str_to_word_array.c	\
		src/tools/env_linked_list/env_linked_list.c	\
		src/tools/env_linked_list/get_path.c	\
		src/tools/print_array.c	\
		src/tools/count_array_element.c	\
		src/tools/env_linked_list/get_var.c	\
		src/tools/copy_array.c	\
		src/history/stock_history.c \
		src/history/check_history.c \
		src/history/check_history_aux.c	\
		src/history/destroy_history.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

test: all
	@test/./test.sh ./42sh

soft:
	gcc -Wextra -Werror $(SRC) -I./include -o $(NAME)

hard:
	gcc -Wall -Wextra -Werror $(SRC) -I./include -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all test soft hard clean fclean re