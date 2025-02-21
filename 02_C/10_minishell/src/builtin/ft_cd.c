/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:41:16 by czhu              #+#    #+#             */
/*   Updated: 2025/02/18 17:41:23 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/builtin.h"

/* create a new entry of a key-value pair in env array
    - malloc for the new entry
    - copy the key, "=", new value, "\0" to the env array
    - return the new_entry
*/
char	*create_env_entry(char *key, char *value)
{
	int		key_len;
	int		value_len;
	char	*new_entry;

	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	new_entry = (char *)malloc(key_len + value_len + 2);
	if (!new_entry)
		perror("malloc");
	ft_memcpy(new_entry, key, key_len);
	new_entry[key_len] = '=';
	ft_memcpy(new_entry + key_len + 1, value, value_len);
	new_entry[key_len + value_len + 1] = '\0';
	return (new_entry);
}

/* update the env var after calling ft_cd
    - malloc for the new entry
    - loop through the env array
        - if find key matches, update the old entry with new entry
        - if not, add the new entry at the end, null terminated
*/
void	update_env(char *key, char *value, t_env *env)
{
	int		i;
	int		key_len;
	char	*new_entry;

	key_len = ft_strlen(key);
	new_entry = create_env_entry(key, value);
	i = 0;
	while (env->env_var[i])
	{
		if (ft_strncmp(env->env_var[i], key, key_len) == 0 && env->env_var[i][key_len] == '=')
		{
			free(env->env_var[i]);
			env->env_var[i] = new_entry;
		}
        env->env_var[i] = new_entry;
        env->env_var[i + 1] = NULL;
		i++;
	}
}

/*
    cd with only a relative or absolute path
    - implementation
        - init env
        - input control
            - if ac = 1, dir = HOME
            - if ac = 2 or more than 2, dir = args[1]
        - store current dir for OLDPWD
        - change dir using chdir
            - if succeed, chdir return 0
            - if fail, return -1
        - update the OLDPWD and PWD env var
*/
void	ft_cd(char **args, t_env *env, char **envp)
{
	char *dir;
	char cwd[1024];
    // init env
	if (!env->env_var)
		init_env(env, envp);
    // input control
	if (!args[1])
	{
		dir = getenv("HOME");
		if (!dir)
			printf("cd: HOME not set\n");
	}
	else
		dir = args[1];
    // store current dir for updating OLDPWD
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd");
    // change dir
	if (chdir(dir) != 0)
		perror("cd");
    // update the OLDPWD, PWD env var
	update_env("OLDPWD", cwd, env);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		update_env("PWD", cwd, env);
}
/*
// // === test create_env_entry ===
// int main()
// {
//     char *key = "PWD";
//     char *value = "/home/user";
//     char *new_entry = create_env_entry(key, value);
//     printf("%s\n", new_entry);
// }

// === test cd ===
int main(int ac, char **av, char **envp)
{    
    t_env env;
    env.env_var = NULL;
    
    (void)ac;
    ft_cd(av, &env, envp);

    // char cwd[1024];
    // if (getcwd(cwd, sizeof(cwd)) != NULL)
    //     printf("current dir: %s\n\n", cwd);
    // else
    //     perror("cd");
    // === check env status ===
    printf("=== print out env to check ===\n");
    print_env(&env);

    // free up memory
    free_env(&env);
    return (0);
}*/
