#include "../incl/philo.h"

/* Unit test
    - test each function
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

int main()
{
    test_think_sleep();
}