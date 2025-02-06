#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
    pthread_t thread;
    int id;
    int eating;
    int meals_eaten;
    size_t last_meal;
    size_t time_to_die;
    size_t time_to_eat;
    size_t time_to_sleep;
    size_t start_time;
    int num_philo;
    int num_times_to_eat;
    int *dead;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *meal_lock;
}   t_philo;

typedef struct  s_program
{
    int dead_flag;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    t_philo *philo;
}   t_program;

/* main */

/* init */
void    init_input(t_philo *philo, char **av);
void    init_philo(t_philo *philo, t_program *program, pthread_mutex_t *fork, char **av);
void    init_fork(pthread_mutex_t *fork, int philo_num);
void    init_program(t_program *program, t_philo *philo);

/* thread */
int dead_loop(t_philo *philo);
void    *philo_routine(void *arg);
int create_thread(t_program *program, pthread_mutex_t *fork);
void	print_message(t_philo *philo, char *str, int id);

/* philo routine */
void    think(t_philo *philo);
void    sleep_philo(t_philo *philo);
void    eat(t_philo *philo);

/* monitor */
int philo_dead(t_philo *philo, size_t time_to_die);
int check_dead(t_philo *philo);
int check_all_eat(t_philo *philo);
void    *monitor(void *arg);

/* utils */
int	ft_atoi(const char *nptr);
size_t    get_current_time();
int	ft_usleep(size_t ms);
void	destory_all(t_program *program, pthread_mutex_t *fork, char *str);

#endif