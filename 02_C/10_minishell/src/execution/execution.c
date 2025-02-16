#include "../incl/execution.h"

extern char **environ; // to be delete

/* core execution steps
    - fork(): create a child process
	- if pid == 0
    	- execve(): execute a command in the child process
	- if pid > 0
    	- waitpid(): wait for the that process to finish
	- if pid < 0
		- return error message
	- args: an array of tokens after parsing
		- args[0]: the absolute/ relative path
		- always terminate with NULL
*/
void	exec_basic(char **args)
{
	pid_t	pid;

	// TODO: add path input control on args[0]
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Execve");
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("Fork");
}

/* check if built-in
 * if yes, execute the corresponding built-in function
 * else, return 0
*/
int	exec_builtin(char **args)
{
	if (!args || !args[0])
		return (0);
	// TODO: need to check the args
	if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args[1]));
	if (ft_strcmp(args[0], "echo") == 0)
		return (ft_echo(args[1]));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd(args[1]));
	if (ft_strcmp(args[0], "export") == 0)
		return (ft_export(args[1]));
	if (ft_strcmp(args[0], "unset") == 0)
		return (ft_unset(args[1]));
	if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(args[1]));
	if (ft_strcmp(args[0], "exit") == 0)
		return (ft_exit(args[1]));
}

// // === test exec_basic ===
// int main()
// {
// 	char *args[] = {"/bin/ls", "-a", "-l", NULL};
// 	// char *args[] = {"/bin/nonexit", "-a", "-l", NULL};
// 	// char *args[] = {NULL};
// 	// char *args[] = {"/home/czhu/Downloads", "-la", NULL};
// 	// char *args[] = {"/bin/ls", "-invalid-flag", NULL};

// 	exec_basic(args);
// }
