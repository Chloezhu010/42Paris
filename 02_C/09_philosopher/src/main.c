#include "../incl/philo.h"

int main(int ac, char **av)
{
    t_data  data;

    // parse command-line arg
    data = parse_argument(ac, av);
    
    // initialize shared data (forks, philo states etc.)

    // create philo threads

    // monitor the simulation (check for philo death or completion)

    // cleanup resource (destroy mutex, free memeory etc.)

}