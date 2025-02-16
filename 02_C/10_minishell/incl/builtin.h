#ifndef BUILTIN_H
# define BUILTIN_H
# include "../incl/minishell.h"

typedef struct s_builtin
{
    const char *builtin_name;
    int (*builtin_func)(char **args);
}   t_builtin;

/* built-in functions */
int ft_cd(char **args);
int ft_echo(char **args);
int ft_pwd(char **args);
int ft_export(char **args);
int ft_unset(char **args);
int ft_env(char **args);
int ft_exit(char **args);

#endif