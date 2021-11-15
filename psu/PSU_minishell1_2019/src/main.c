/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** main
*/

#include <minishell.h>

int is_sp(char const *str)
{
    for (int i = 0 ; str[i] ; i++)
        if (str[i] != ' ')
            return (0);
    return (1);
}

void exec_command(char **arg_parsed, char **env, char *arg)
{
    int status = 0;
    pid_t my_pid = 0;

    my_pid = fork();
    if (my_pid < 0)
        perror("fork");
    else if (my_pid > 0) {
        waitpid(my_pid, &status, 0);
        kill(my_pid, SIGTERM);
    } else {
        signal(SIGINT, SIG_DFL);
        if (arg_parsed[0][0] == '.' && arg_parsed[0][0] == '/')
            arg_parsed[0] = &arg_parsed[0][2];
        if (execve(arg_parsed[0], arg_parsed, env) == -1) {
            my_putstr(arg);
            write(2, ": Command not found.\n", 21);
        }
        exit(EXIT_SUCCESS);
    }
    (status == 139) ? write(1, "Segmentation fault\n", 19) : 1;
}

char **minishell(char *buff, char **env)
{
    int is_done = 0;
    char **arg_parsed = NULL;
    char *arg = NULL;

    for (int i = 0 ; buff[i] ; i++);
    if (is_sp(buff) || (arg_parsed = my_str_to_word_array(buff)) == NULL) {
        write(1, "$> ", 3);
        return (env);
    }
    if (my_strcmp(arg_parsed[0], "exit") == 0 && !arg_parsed[1])
        return NULL;
    env = builtin_manage(arg_parsed, env, &is_done);
    if (arg_parsed[0] && !is_done) {
        arg = arg_parsed[0];
        arg_parsed[0] = my_get_env(env, arg_parsed[0]);
        exec_command(arg_parsed, env, arg);
    }
    is_done = 0;
    write(1, "$> ", 3);
    return (env);
}

int main(int ac, char **av, char **env)
{
    char *buff = NULL;

    signal(SIGINT, SIG_IGN);
    write(1, "$> ", 3);
    while ((buff = get_next_line(0)) != NULL) {
        if (!(env = minishell(buff, env)))
            break;
        signal(SIGINT, SIG_IGN);
    }
    write(1, "exit\n", 5);
    return (0);
}
