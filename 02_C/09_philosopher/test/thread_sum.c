#include "../incl/philo.h"
#include <time.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    int index = *(int *)arg;
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += primes[index + i];
    }
    *(int *)arg = sum;
    return arg;
}

int main()
{
    pthread_t   th[2];
    int i;
    for (i = 0; i < 2; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i * 5;
        pthread_create(&th[i], NULL, &routine, a);
    }
    int globalSum = 0;
    for (i = 0; i < 2; i++)
    {
        int *res;
        pthread_join(th[i], &res);
        globalSum += *res;
        free(res);
    }
    printf("global sum: %d\n", globalSum);
    return (0);
}
