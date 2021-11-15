/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** cd builtin
*/

#include <minishell.h>

char **cd_without_arg(char **env)
{
    char *old_pwd = NULL;
    char *new_pwd = NULL;
    char **new_env = NULL;
    char **env_pwd = NULL;
    size_t size = 0;

    for (int i = 0 ; env[i] ; i++)
        if (!is_arg(env[i], "HOME")) {
            old_pwd = my_strdup(getcwd(old_pwd, size));
            new_env = my_str_to_word_array(my_strcat
                                        ("setenv OLDPWD ", old_pwd));
            chdir(&env[i][5]);
            new_pwd = my_strdup(getcwd(new_pwd, size));
            env_pwd = my_str_to_word_array(my_strcat
                                        ("setenv PWD ", new_pwd));
            env = my_setenv(env, env_pwd);
            env = my_setenv(env, new_env);
        }
    return (env);
}

char **cd_tiret(char **env)
{
    int is_done = 0;
    char **new_env = NULL;
    char **env_pwd = NULL;
    size_t size = 0;

    for (int i = 0 ; env[i] ; i++)
        if (!is_arg(env[i], "OLDPWD")) {
            new_env = my_str_to_word_array(my_strcat
                                    ("setenv OLDPWD ", getcwd(NULL, size)));
            chdir(&env[i][7]);
            env_pwd = my_str_to_word_array(my_strcat
                                        ("setenv PWD ", getcwd(NULL, size)));
            env = my_setenv(my_setenv(env, new_env), env_pwd);
            is_done = 1;
        }
    if (!is_done) {
        write(2, ": No such file or directory.\n", 29);
    }
    return (env);
}

char **cd_engine(char **env, char **arg, int *is_error)
{
    char *old_pwd = NULL;
    char *new_pwd = NULL;
    char **new_env = NULL;
    char **env_pwd = NULL;
    size_t size = 0;

    old_pwd = my_strdup(getcwd(old_pwd, size));
    new_env = my_str_to_word_array(my_strcat
                                    ("setenv OLDPWD ", old_pwd));
    *is_error = chdir(arg[1]);
    new_pwd = my_strdup(getcwd(new_pwd, size));
    env_pwd = my_str_to_word_array(my_strcat
                                    ("setenv PWD ", new_pwd));
    if (*is_error != -1) {
        env = my_setenv(env, new_env);
        env = my_setenv(env, env_pwd);
    }
    return (env);
}

char **cd_builtin(char **arg, char **env)
{
    int is_error = 0;

    if (arg[2]) {
        write(2, "Too many args for cd command\n", 29);
        return (env);
    }
    if (!arg[1] || !my_strcmp(arg[1], "~") || !my_strcmp(arg[1], "~/")) {
        env = cd_without_arg(env);
        return (env);
    }
    if (!my_strcmp(arg[1], "-")) {
        env = cd_tiret(env);
        return (env);
    }
    if (arg[1])
        env = cd_engine(env, arg, &is_error);
    if (is_error == -1)
        perror(arg[1]);
    return (env);
}
