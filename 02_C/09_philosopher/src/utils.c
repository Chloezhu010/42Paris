#include "../incl/philo.h"

/* convert str to int */
int	ft_atoi(const char *nptr)
{
	int	negative;
	int	i;
	int	result;

	i = 0;
	negative = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			negative = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * negative);
}

/*
    get the current time in milliseconds
    - 1 second = 1000 milliseconds
    - 1 milliseond = 1000 microseconds
    - struct timeval
           time_t       tv_sec;   // Seconds
           suseconds_t  tv_usec;  // Microseconds
*/
size_t    get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

/* improved version of usleep function */
int	ft_usleep(size_t ms)
{
	size_t start;

	start = get_current_time();
	if (get_current_time() - start < ms)
		usleep(500);
	return (0);
}

/* destroy all mutex */
void	destory_all(t_program *program, pthread_mutex_t *fork, char *str)
{
	int i;

	i = 0;
	printf("%s\n", str);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < program->philo->num_philo)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
}