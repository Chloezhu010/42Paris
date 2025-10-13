#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#include <stdio.h>

int err(char *str)
{
    while (*str)
    {
        write(2, str, 1);
        str++;
    }
    return (1);
}

int cd(char **av, int i)
{
    if (i != 2)
        return (err("error: cd: bad arguments\n"));
    else if (chdir(av[1]) == -1)
        return (err("error: cd: cannot change directory to "), err(av[1]), err("\n"));
    return (0);
}

int exec(char **av, char **envp, int i)
{
    int fd[2];
    int status;
    int pid;
    int has_pipe;

    has_pipe = av[i] && (strcmp(av[i], "|") == 0);
    // create fd
    if (has_pipe && pipe(fd))
        err("error: fatal\n");
    // create fork
    if ((pid = fork()) == -1)
        err("error: fatal\n");
    // child proces
    if (!pid)
    {
        av[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            err("error: fatal\n");
        execve(av[0], av, envp);
        return (err("error: cannot execute "), err(av[0]), err("\n"));
    }
    // parent process
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n");
    // return
    return (WIFEXITED(status) && WEXITSTATUS(status));
}

int main(int ac, char **av, char **envp)
{
    int i = 0;
    int status = 0;

    if (ac > 1)
    {
        while (av[i] && av[++i])
        {
            av += i;
            i = 0;
            // advance i
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            // handle cd
            if (strcmp(av[0], "cd") == 0)
                status = cd(av, i);
            // handle regular cmd
            else if (i)
                status = exec(av, envp, i);
        }
    }
    return (status);
}