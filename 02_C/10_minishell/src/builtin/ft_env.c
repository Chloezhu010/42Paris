/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:20:22 by czhu              #+#    #+#             */
/*   Updated: 2025/02/18 16:34:28 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/builtin.h"

/* printout the env variables */
void	print_env(t_env *env)
{
	int	i;

	i = 0;
	while (env && env->env_var && env->env_var[i])
	{
		ft_printf("%s\n", env->env_var[i]);
		i++;
	}
}

/* free malloc for env */
void	free_env(t_env *env)
{
	int	i;

	i = 0;
	if (!env || !env->env_var)
		return ;
	while (env->env_var[i])
	{
		free(env->env_var[i]);
		i++;
	}
	free(env->env_var);
}

/* env with no option
    env request
    - print out the env info
    env implementation
    - wrap the init, print, free functions
*/
void	ft_env(t_env *env, char **envp)
{
	if (!envp || !env)
		return ;
	init_env(env, envp);
	print_env(env);
	free_env(env);
}
/*
// === test env ===
int main(int ac, char **av, char **envp)
{
    t_env env;
    
    (void)ac;
    (void)av;
    ft_env(&env, envp);
    return (0);
}*/
