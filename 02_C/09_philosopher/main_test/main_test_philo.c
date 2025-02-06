#include "../incl/philo.h"

/*
    Unit test: think, sleep
*/
void    test_think_sleep()
{
    t_philosopher   philo;
    t_data  data;

    philo.id = 1;
    philo.data = &data;
    data.time_to_sleep = 100;

    think(&philo);
    sleep_philo(&philo);
}

/*
    Unit test: eat
*/
void    test_eat()
{
    t_philosopher   philo;
    t_data  data;

    data.time_to_eat = 100;
    pthread_mutex_init(&data.log_mutex, NULL);

    philo.id = 1;
    philo.data = &data;
    philo.last_meal_time = 0;
    philo.meals_eaten = 0;
    printf("before: last meal time %ld, meals eaten %d\n", philo.last_meal_time, philo.meals_eaten);

    eat(&philo);
    printf("after: last meal time %ld, meals eaten %d\n", philo.last_meal_time, philo.meals_eaten);
}

/*
    Test philo_routine
*/
void    *test_philo_thread(void *arg)
{
    philo_routine(arg);
    return (NULL);
}

void    test_philo_routine()
{
    t_philosopher   philo;
    t_data  data;

    data.time_to_eat = 100;
    data.time_to_sleep = 200
}

int main()
{
    test_think_sleep();
    test_eat();
}