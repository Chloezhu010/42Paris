#include "../incl/philo.h"

int main(int ac, char **av)
{
    t_data  data;

    // initialize shared data (forks, philo states etc.)
    initialization(&data, ac, av);
    // create philo threads

    // monitor the simulation (check for philo death or completion)

    // cleanup resource (destroy mutex, free memeory etc.)

}