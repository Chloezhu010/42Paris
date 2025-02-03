#include "../incl/philo.h"

/*
    get the current time in milliseconds
    - 1 second = 1000 milliseconds
    - 1 milliseond = 1000 microseconds
    - struct timeval
           time_t       tv_sec;   // Seconds
           suseconds_t  tv_usec;  // Microseconds
*/
long    get_current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

/*
    simulate delay for sleep
*/
void    sleep_for(long milliseconds)
{
    usleep(milliseconds * 1000);
}