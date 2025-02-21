#include "../incl/builtin.h"



void    update_env(char *key, char *value, t_env *env)
{
    int  key_len = ft_strlen(key);
    int  value_len = ft_strlen(value);
    int  i = 0;
    char *new_entry;

    new_entry = (char *)malloc(key_len + value_len + 2);
    if (!new_entry)
        return ;
    while(env->env_var[i])
}

void    ft_cd(char **args, t_env *env, char **envp)
{
    char *dir;
    char cwd[1024];

    // init env var
    if (!env->env_var)
        init_env(env, envp);
    // args control
    if (!args[1])
    {
        dir = getenv("HOME");
        if (!dir)
            printf("error");
    }
    else
        dir = args[1];
    // store cwd for updating OLDPWD
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        perror("getcwd");
    // change dir
    if (chdir(dir) != 0)
        printf("error");
    // update the OLDPWD, PWD env var
    update_env("OLDPWD", cwd, env);
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        update_env("PWD", cwd, env);
}

int main(int ac, char **av, char **envp)
{
    t_env env;
    
    (void)ac;
    ft_cd(av, &env, envp);

    // check if the cwd changed
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("current dir: %s\n\n", cwd);
    else
        printf("error\n");
    // check if the PWD, OLDPWD changed
    print_env(&env);
}