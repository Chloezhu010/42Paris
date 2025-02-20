#include "../incl/builtin.h"

/* init the env from envp
    - count the env variables
    - malloc for env variables
    - copy env variables to my own struct
    - null terminated
*/
void	init_env(t_env *env, char **envp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!envp)
	{
		env->env_var = NULL;
		return ;
	}
	while (envp[count])
		count++;
	env->env_var = (char **)malloc((count + 1) * sizeof(char *));
	if (!env->env_var)
	{
		perror("malloc");
		exit (1);
	}
	while (envp[i])
	{
		env->env_var[i] = ft_strdup(envp[i]);
		i++;
	}
	env->env_var[i] = NULL;
}