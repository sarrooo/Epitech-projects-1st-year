/*
** EPITECH PROJECT, 2020
** navy
** File description:
** h
*/

int my_printf(char *format, ...);
int navy_strcmp(char const *s1, char const *s2);

int helper(int argc, char **argv)
{
    if (argc == 2 && navy_strcmp(argv[1], "-h") == 0) {
        my_printf("USAGE\n");
        my_printf("\t./navy [first_player_pid] navy_positions\n");
        my_printf("DESCRIPTION\n");
        my_printf("\tfirst_player_pid: only for the 2nd player. ");
        my_printf("pid of the first player.\n");
        my_printf("\tnavy_positions: file representing the positions ");
        my_printf("of the ships.");
        return (1);
    }
    return (0);
}