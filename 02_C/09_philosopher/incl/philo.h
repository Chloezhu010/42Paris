#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
    state & behavior of a single philo
*/
typedef struct s_philosopher
{
    int id;
    int meals_eaten;
    long    last_meal_time;
    pthread_t   thread;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    struct s_data   *data;
}   t_philosopher;

/*
    global data: shared by all philosophers and the main program
        - initialize once at the start of the program
        - shared among all philos
        - each fork is a mutex that philo must lock to eat
        - log_mutex ensure log msg from different threads don't overlap
*/
typedef struct  s_data
{
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int num_meals;
    long    start_time;
    pthread_mutex_t *fork;
    pthread_mutex_t log_mutex;
    t_philosopher   *philosophers;
    int simulation_running;
}   t_data;

/* Argument parsing */
t_data  parse_argument(int ac, char **av);

/* Time module */
long    get_current_time();
void    sleep_for(long milliseconds);

/* Logging module */
void    log_message(t_philosopher *philo, const char *message);

/* Initialization */
void    init_mutex(t_data *data);
void    init_philo(t_data *data);
void    init_time(t_data *data);
void    init_threads(t_data *data);
void    initialization(t_data *data, int ac, char **av);

/* Philo module */
void    *philo_routine(void *arg);
void    eat(t_philosopher *philo);
void    think(t_philosopher *philo);
void    sleep_philo(t_philosopher *philo);


/* Fork module */
void    pick_fork(t_philosopher *philo);
void    drop_fork(t_philosopher *philo);

/* Cleanup module */
void    cleanup_mutex(t_data *data, int fork_initialized);
void    cleanup_thread(t_data *data, int thread_created);
void    cleanup_philo(t_data *data);

/* utils */
void    exit_with_error(char *message);
int	ft_atoi(const char *nptr);

#endif