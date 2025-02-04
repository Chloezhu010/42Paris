#include "../incl/philo.h"

/*
    main loop where each philo thinks, eats, and sleeps
    - for the even philo, delay the start time a bit
        - avoid fork contention
        - if all philo start to grab fork at the same time, deadlock will happen
    - process
        - think
        - pick forks & eat
        - drop fork
        - sleep
*/
void    *philo_routine(void *arg)
{
    t_philosopher *philo;

    philo = (t_philosopher *)arg;
    if (philo->id % 2 == 0)
        usleep(1000);
    while (philo->data->simulation_running)
    {
        think(philo);
        pick_fork(philo);
        eat(philo);
        drop_fork(philo);
        sleep_philo(philo);
    }
    return (NULL);
}

/*
    eat module
    - print "is eating"
    - update last_meal_time & meals_eaten
        - protected by locking log_mutex
    - sleep for time_to_eat
*/
void    eat(t_philosopher *philo)
{
    log_message(philo, "is eating");
    pthread_mutex_lock(&philo->data->log_mutex);
    philo->last_meal_time = get_current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(&philo->data->log_mutex);
    sleep_for(philo->data->time_to_eat);
}

/*
    think module
    - print "is thinking"
*/
void    think(t_philosopher *philo)
{
    log_message(philo, "is thinking");
}

/*
    sleep module
    - print "is sleeping"
    - call sleep_for
*/
void    sleep_philo(t_philosopher *philo)
{
    log_message(philo, "is sleeping");
    sleep_for(philo->data->time_to_sleep);
}