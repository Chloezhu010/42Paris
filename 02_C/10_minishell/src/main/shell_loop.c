#include "../incl/minishell.h"

int status = 0;

/* read the input from user
    - print the cwd before $>
    - read the input
*/
char *read_line(void)
{
    char *buf;
    size_t bufsize;
    char cwd[1024];

    buf = NULL;
    if (!getcwd(cwd, sizeof(cwd)))
        perror("getcwd");
    printf("%s $>", cwd);

    if (getline(&buf, &bufsize, stdin) == -1) // TODO replace getline
    {
        free(buf);
        buf = NULL;
        if (feof(stdin)) // when enter ctl+D, TODO replace feof
            printf("EOF"); 
        else
            printf("getline failed");
    }
    return (buf);
}

/* tokenize the input line */
char    **cell_split_line(char *line)
{
    char            **tokens;
    unsigned int    position;
    size_t          bufsize;

    bufsize = BUFSIZ;
    position = 0;
    tokens = malloc(bufsize * sizeof(*tokens));
    if (!tokens)
        return (NULL);

    for (char *token = strtok(line, DEL); token; token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
        if (position >= bufsize)
        {
            bufsize *= 2;
            tokens = realloc(tokens, bufsize * sizeof(*tokens));
            if (!tokens)
                return (NULL);
        }
    }
    tokens[position] = NULL;
    return (tokens);
}

/* launch external programs */
void launch_execution(char **args)
{
    if (Fork() == CHILD_PROCESS)
        Execvp(args[0], args);
    else
        Wait(&status);
}

/* execute shell
    - if it's build in function, call it
    - if not, launch external programs
*/
void execute_shell(char **args)
{
    // TODO builtin functions
    if (strcmp(args[0], "pwd") == 0)
    {
        ft_pwd(args);
        return ;
    }
    launch_execution(args);
}

int main()
{
    char *line;
    char **args;

    while (1)
    {
        // 1. handle signal
        // 2. read line from command
        line = read_line();
            // check the read_line function
        if (line == NULL)
        {
            printf("\nexit\n");
            break;
        }
        printf("you entered: %s\n", line);
        // 3. parse the args
        args = cell_split_line(line);
            // check if the args are tokenized
        int i = 0;
        while (args[i])
        {
            printf("token[%d]: %s\n", i, args[i]);
            i++;
        }
        // 4. execute the command
        execute_shell(args);
        // 5. add history


        // 6. cleanup
        free(line);
        free(args);
    }
}