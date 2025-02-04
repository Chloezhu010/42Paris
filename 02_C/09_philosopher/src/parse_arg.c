#include "../incl/philo.h"

/*
    check if a string only contains digits
        - return 1 if only numeric
        - return 0 if not
*/
static int  ft_only_digit(char *str)
{
    int i;

    if (!str || !*str)
        return (0);
    i = 0;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/*
    parse and validate a numeric & positive arg
        - return 1 if successful
        - return 0 if not
*/
static int  parse_numeric_arg(char *av, int *dest)
{
    if (!ft_only_digit(av))
    {
        printf("Error: input invalid\n");
        return (0);
    }
    *dest = ft_atoi(av);
    if (*dest <= 0)
    {
        printf("Error: input invalid\n");
        return (0);
    }
    return (1);
}

/*
    - validate # of arguments: need to be progoram arg + 4 or 5
    - parse & validate each argument
        - number_of_philosophers
        - time_to_die (in ms)
        - time_to_eat (in ms)
        - time_to_sleep (in ms)
        - number_of_times_each_philosopher_must_eat (optional arg)
    - return data with input values
*/
t_data  parse_argument(int ac, char **av)
{
    t_data  data;

    if (ac < 5 || ac > 6)
        printf("Error: invalid number of arguments\n");
    if (!parse_numeric_arg(av[1], &data.num_philosophers)
        || (!parse_numeric_arg(av[2], &data.time_to_die))
        || (!parse_numeric_arg(av[3], &data.time_to_eat))
        || (!parse_numeric_arg(av[4], &data.time_to_sleep)))
        exit(1);
    if (ac == 6)
    {
        if (!parse_numeric_arg(av[5], &data.num_meals))
            exit (1);
    }
    else
        data.num_meals = -1;
    return (data);
}