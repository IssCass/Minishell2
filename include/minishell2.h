/*
** EPITECH PROJECT, 2024
** PSU_minishell2_2019
** File description:
** Created by Enzo Ventura
*/
#ifndef PSU_MINISHELL2_2019_MINISHELL2_H
#define PSU_MINISHELL2_2019_MINISHELL2_H

#include "my.h"
#include "my_printf.h"
#include <unistd.h>

typedef struct s_set_minishell
{
    char **envp;
    char **path;
    int count_cd;
    int return_value;
    pid_t pid;
    int pipe;
}t_minishell;

//initialisation
void init_struct(t_minishell *minishell);

//errors
int errors(int ac);

//return value
void return_value(t_minishell *minishell, int value);

//paths
char *find_path(char *cmd, t_minishell *minishell);
char **fill_tab(t_minishell *minishell, char **tab);
char **new_get_path(t_minishell *minishell);
char **my_get_paths(t_minishell *minishell);

//process
void process_cmd(t_minishell *minishell, char *cmd, int fdin, int fdout);

//semicolons
void process_semicolons(t_minishell *minishell, char *cmd, int fdin, int fdout);

//pipes
void process_pipes(t_minishell *minishell, char *cmd, int fdin, int fdout);

//right redir
void process_right_redir(t_minishell *minishell, char *cmd, int fdout,
    int fdin);
int create_file(char *name, int flags);

//left redir
void process_left_redir(t_minishell *minishell, char *cmd, int fdin, int fdout);

//exec cmd
void exec_cmd(t_minishell *minishell, char **arg, char *path, int *fds);
void loop_wait(t_minishell *minishell, pid_t pid);
void simple_wait(t_minishell *minishell);

//getenv
void my_get_env(t_minishell *minishell, char **env);
char *my_get_line_env(t_minishell *minishell, char *name);

//env
void env(t_minishell *minishell, char **input);

//exit
void exit_shell(t_minishell *minishell, char **input);

//setenv
void set_env(t_minishell *minishell, char *name, char *value);
char *set_env_already(char *name, char *value);

//unsetenv
char **unset_env(t_minishell *minishell, char *name);
void unset_env_redir(t_minishell *minishell, char **input);

//cd
void cd_builtin(t_minishell *minishell, char *dir);
void cd_wtout_arg(t_minishell *minishell);
void cd_tiret(t_minishell *minishell);
void cd_slash(t_minishell *minishell);

//redirections
void set_env_redir(t_minishell *minishell, char **input);
void redirect_cd(t_minishell *minishell, char **input);
void redirect_cd_two(t_minishell *minishell, char **input, int i);
void fptr_builtins(t_minishell *minishell, char **input, int fdin, int fdout);

//tools
void free_all(t_minishell *minishell);
int my_str_is_equal(char *s1, char *s2);
int search_var(t_minishell *minishell, char *name);
char *pars_arg(char *cmd);
char *rm_name_var(char *str);
int check_arr(char **input, char *path);
int check_cmd(char *cmd);
int check_input(char *input);
int check_char(char *str, char c);
int size_tab(char **tab);
int check_just_tokens(char *cmd);
int check_right_redir(char *cmd);
char *useless_spaces(char *str);


#endif
