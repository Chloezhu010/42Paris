#include "../incl/philo.h"

int mails = 0;
pthread_mutex_t mutex;

void    *routine()
{
    for (int i = 0; i < 1000000; i++)
    {
        // protect the thread from race condition
        pthread_mutex_lock(&mutex);
        mails++;
        pthread_mutex_unlock(&mutex);
    }
    return (NULL);
}

int main()
{
    pthread_t   th[4];
    int i;
    
    // initialize the mutex
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < 4; i++)
    {
        pthread_create(&th[i], NULL, &routine, NULL);
        printf("thread %d has started\n", i);
    }
    for (i = 0; i < 4; i++)
    {
        pthread_join(th[i], NULL);
        printf("thread %d has executed\n", i);
    }

    // destroy mutex at the end
    pthread_mutex_destroy(&mutex);
    printf("# of mails: %d\n", mails);
    return (0);
}