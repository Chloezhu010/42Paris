#include "../incl/philo.h"

void    *routine()
{
    
    return (NULL);
}

int main()
{
    pthread_t   t1;
    pthread_t   t2;

    // initialize
    // if success, return 0, otherwise return != 0
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    // ask the main thread to wait until the subthreads finish their execution
    // use pthread_join to synchronize
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}