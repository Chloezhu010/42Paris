#include "../incl/push_swap.h"

// count the word in the str
static int   count_word(char *str, char c)
{
    int count; // store the word count
    int i;
    bool flag; // indidate if inside of a word or not

    count = 0;
    i = 0;
    flag = false;
    while (str[i])
    {
       if (str[i] != c && flag == false)
        {
            count++;
            flag = true;
        }
        else if (str[i] == c && flag == true)
            flag = false;
        i++;
    }
    return (count);
}

// used to subtrack the word in place
static char *get_next_word(char *str, char c)
{
    static int  curr = 0; // initialize curr to 0 only once here
    char        *next_word;
    int         len;
    int         i;

    len = 0;
    i = 0;
    while (str[curr] == c) // if the char == c, then skip
        curr++;
    while (str[curr + len] && str[curr + len] != c) // if the char != \0 and not c, increase the word len
        len++;
    next_word = malloc(sizeof(char)*(len + 1)); // malloc for the next word
    if (!next_word)
        return (NULL);
    while (str[curr] && str[curr] != c) // copy str char to the next word
        next_word[i++] = str[curr++];
    next_word[i] = '\0';
    return (next_word);
}

// free the split string array
void    free_split(char **str)
{
    int i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        free(str[i]);
        str[i] = NULL;
        i++;
    }
    free(str);
}

// main split function
char    **av_split(char *str, char c)
{
    int     count;
    int     i;
    char    **res;

    count = count_word(str, c);
    res = malloc(sizeof(char *) * (count + 2));
    if (!res)
        return (NULL);
    i = 0;
    while (i < count)
    {
        res[i] = get_next_word(str, c);
        if (!res[i])
        {
            free_split(res);
            return (NULL);
        }
        i++;
    }
    res[i] = NULL;
    return (res);
}
