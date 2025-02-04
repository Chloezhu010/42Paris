#include "../incl/philo.h"

void    cleanup_mutex(t_data *data, int fork_initialized)
{
    int i;

    i = 0;
    while (i < fork_initialized)
    {
        pthread_mutex_destroy(&data->fork[i]);
        i++;
    }
    free(data->fork);
}

void    cleanup_thread(t_data *data, int thread_created)
{
    int i;

    i = 0;
    while (i < thread_created)
    {
        pthread_detach(data->philosophers[i].thread);
        i++;
    }
}


void    cleanup_philo(t_data *data)
{
    free(data->philosophers);
}