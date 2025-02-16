/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:56:07 by czhu              #+#    #+#             */
/*   Updated: 2025/02/16 16:56:28 by czhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/builtin.h"

/* change working dir
    - if no args provide
        - print error msg, return 1
    - 
*/
int ft_cd(char **args)
{

}

// int ft_echo(char **args)
// {

// }

/* print the current dir
	- ignore args
	- if getcwd(path, size) works
        - print the current working dir path
	    - return 0
    - else
		- print error msg & return 1
*/
int ft_pwd(char **args)
{
	char	cwd[1024];

	(void)args;
    if (getcwd(cwd, sizeof(cwd)))
	{
		ft_printf("%s\n", cwd);
		return (0);
	}
	else
	{
		perror("pwd");
		return (1);
	}
}

// === testing pwd ===
int main(void)
{
    char *args1[] = {NULL};
    ft_pwd(args1);

    char *args2[] = {"pwd", "arg1", "arg2", NULL};
    ft_pwd(args2);

    chdir("..");
    char *args3[] = {"pwd", "arg1", "arg2", NULL};
    ft_pwd(args3);
}