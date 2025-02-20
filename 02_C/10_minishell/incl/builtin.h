#ifndef BUILTIN_H
# define BUILTIN_H
# include "../incl/minishell.h"

typedef struct s_env
{
    char	**env_var;
}		t_env;

/* ft_echo */
void	ft_echo(char **args);
/* ft_pwd */
void	ft_pwd(char **args);
/* ft_exit */
void	ft_exit(char **args);
int		is_digit(char *str);
/* ft_env */
void	ft_env(t_env *env, char **envp);
void	init_env(t_env *env, char **envp);
void	print_env(t_env *env);
void	free_env(t_env *env);
/* ft_unset */
void	ft_unset(char **av, t_env *env, char **envp);
int		ft_env_len(t_env *env);
int		is_valid_name(char *name);
void	ft_unsetenv(char *name, t_env *env);
/* ft_cd */
void	ft_cd(char **args);
/* ft_export */
void	ft_export(char **args);

#endif
