#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int err(char *str)
{
    while(*str)
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
        return (err("error: cd: cannot change dir to "), err(av[1]), err("\n"));
    return (0);
}

int exec(char **av, char **envp, int i)
{
    int fd[2];
    int status;
    int pid;
    int has_pipe;

    // check if av[i] is pipe
    has_pipe = av[i] && (strcmp(av[i], "|") == 0);
    // creates pipe
    if (has_pipe && pipe(fd) == -1)
        err("error: fatal\n");
    // creates fork
    if ((pid = fork()) == -1)
        err("error: fatal\n");
    // child process
    if (!pid)
    {
        // replace "|" with NULL to terminate arg list
        av[i] = 0;
        // redirect stdout to write end and close fd
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            err("error: fatal\n");
        // execute the cmd
        execve(*av, av, envp);
        // if error, return err msg
        return (err("error: cannot execute "), err(*av), err("\n"));
    }
    // parent process
    // wait for child process
    waitpid(pid, &status, 0);
    // redirect stdin to read end and close fd
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        err("error: fatal\n");
    // return child's exit status
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
            // advance i until it hits | or ; or NULL
            while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
                i++;
            // handle cd
            if (strcmp(*av, "cd") == 0)
            {
                status = cd(av, i);

                // print out current dir
                char cwd[1024];
                getcwd(cwd, sizeof(cwd));
                printf("microshell cmd: %s\n", cwd);
            }
            // handle regular cmd
            else if (i)
                status = exec(av, envp, i);
        }
    }
    return (status);
}

/* testing cmd
    - 
*/