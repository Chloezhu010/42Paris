#include "../incl/philo.h"

void    log_message(t_philosopher *philo, const char *message)
{
    pthread_mutex_lock(&philo->data->log_mutex);
    printf("%lu Philosopher %d %s\n", get_current_time(), philo->id, message);
    pthread_mutex_unlock(&philo->data->log_mutex);
}