#include "../incl/philo.h"
#include <time.h>
/* get return value in thread: pthread_join */
// void    *roll_dice()
// {
//     int value = (rand() % 6) + 1;
//     int *result = malloc(sizeof(int));
//     *result = value;
//     // printf("%d\n", value);
//     return (void *) result;
// }

// int main()
// {
//     pthread_t   th;
//     int         *res;
//     srand(time(NULL));

//     if (pthread_create(&th, NULL, &roll_dice, NULL) != 0)
//         return (1);
//     if (pthread_join(th, (void **) &res) != 0)
//         return (2);
//     printf("result %d\n", *res);
//     free(res);
//     return (0);
// }

/* pass arg to threads in C 
    - multithreaded issue
*/
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    sleep(1);
    int index = *(int *)arg;
    printf("%d\n", primes[index]);
    free(arg);
    return (NULL);
}

int main()
{
    pthread_t   th[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
    }
    for (i = 0; i < 10; i++)
    {
        pthread_join(th[i], NULL);
    }
    return (0);
}
