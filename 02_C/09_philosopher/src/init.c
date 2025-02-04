#include "../incl/philo.h"

/*
    initialize mutex
    - allocate memory for forks: # of philo * size of mutex
    - initialize each fork (mutex)
    - initialize log_mutex
*/
void    init_mutex(t_data *data)
{
    int i;

    data->fork = malloc(data->num_philosophers * sizeof(pthread_mutex_t));
    if (!data->fork)
        exit_with_error("Error: fail to malloc for forks");
    i = 0;
    while (i < data->num_philosophers)
    {
        if (pthread_mutex_init(&data->fork[i], NULL) != 0)
        {
            cleanup_mutex(data, i);
            exit_with_error("Error: fail to initialize fork mutex");
        }
        i++;
    }
    if (pthread_mutex_init(&data->log_mutex, NULL) != 0)
    {
        cleanup_mutex(data, data->num_philosophers);
        exit_with_error("Error: fail to initialize log mutex");
    }
}

/*
    initialize philo
    - malloc for the philo array: # of philo * size of t_philosopher
    - initialize each philo's field
        - set id
        - set the meals_eaten to 0
        - set the last_meal_time to the current time
        - assign left, right forks
        - set the data pointer to the shared t_data
    - assign fork: eg. # of philo = 4
        - philo 1: left fork = fork[0], right fork = fork[1]
        - philo 4: left fork = fork[3], right fork = fork[0]
*/
void    init_philo(t_data *data)
{
    int i;
    
    data->philosophers = malloc(data->num_philosophers * sizeof(t_philosopher));
    if (!data->philosophers)
        exit_with_error("Error: fail to malloc for philo array");
    i = 0;
    while (i < data->num_philosophers)
    {
        data->philosophers[i].id = i + 1;
        data->philosophers[i].meals_eaten = 0;
        data->philosophers[i].last_meal_time = get_current_time();
        data->philosophers[i].left_fork = &data->fork[i];
        data->philosophers[i].right_fork = &data->fork[(i + 1) % data->num_philosophers];
        data->philosophers[i].data = data;
        i++;
    }
}

/*
    set the simulation start time
    - set start time as current time
    - mark simulation as active = 1
*/
void    init_time(t_data *data)
{
    data->start_time = get_current_time();
    data->simulation_running = 1;
}

/*
    intialize thread for each philo
    - thread creation better be separate for debugging
*/
void    init_threads(t_data *data)
{
    int i;
    
    i = 0;
    while (i < data->num_philosophers)
    {
        if (pthread_create(&data->philosophers[i].thread, NULL, 
            philo_routine, &data->philosophers[i]) != 0)
        {
            cleanup_thread(data, i);
            exit_with_error("Error: fail to create philo thread");
        }
        i++;
    }
}

/*
    - parse input arg into global data
    - init forks + log mutex
    - init philosopher data
    - start philosopher thread
*/
void    initialization(t_data *data, int ac, char **av)
{
    *data = parse_argument(ac, av);
    init_mutex(data);
    init_philo(data);
    init_time(data);
    init_threads(data);
}