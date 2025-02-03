#include "../incl/philo.h"

// - number_of_philosophers
//         - time_to_die (in ms)
//         - time_to_eat (in ms)
//         - time_to_sleep (in ms)
//         - number_of_times_each_philosopher_must_eat (optional arg)

int main(int ac, char **av)
{
    t_data  data;
    data = parse_argument(ac, av);
    
    printf("number of philo: %d\n", data.num_philosophers);
    printf("time to die: %d\n", data.time_to_die);
    printf("time to eat: %d\n", data.time_to_eat);
    printf("time to sleep: %d\n", data.time_to_sleep);
    printf("num of meals: %d\n", data.num_meals);
}