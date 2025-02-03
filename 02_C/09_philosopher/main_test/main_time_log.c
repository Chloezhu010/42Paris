#include "../incl/philo.h"

// int main()
// {
//     t_data  data;
//     t_philosopher   philo;

//     philo.id = 1;
//     philo.data = &data;

//     log_message(&philo, "is thinking");
//     log_message(&philo, "is eating");
    
// }

// int main()
// {
//     long    start_time = get_current_time();
//     printf("start time: %ld ms\n", start_time);

//     sleep_for(2000);
//     long    end_time = get_current_time();
//     printf("end time: %ld ms\n", end_time);

//     long    elapsed_time = end_time - start_time;
//     printf("elasped time: %ld ms\n", elapsed_time);
// }

void    *thread_routine(void *arg)
{
    t_philosopher   *philo = (t_philosopher *)arg;

    log_message(philo, "is thinking");
    sleep_for(1000);
    log_message(philo, "is eating");
    sleep_for(1000);
    log_message(philo, "is sleeping");

    return (NULL);
}

int main()
{
    t_data  data;
    t_philosopher   philo1, philo2;
    pthread_t   t1, t2;

    philo1.id = 1;
    philo1.data = &data;
    philo2.id = 2;
    philo2.data = &data;

    pthread_create(&t1, NULL, &thread_routine, &philo1);
    pthread_create(&t2, NULL, &thread_routine, &philo2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return (0);
}