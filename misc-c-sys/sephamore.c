#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> 


int workers = 10;

sem_t lock;

int index = 0;

int val = 0;

int vals[128];

int flag = 0;

/** Start routine for each worker. */
void *routine( void *arg )
{ 
    do
    {
        sem_wait(&lock);

        for (int i = 0; i < index; i++)
            printf("%d ", vals[i]);

        printf("\n");

        sem_post(&lock);

        sleep(1);

    } while(1);    

    return NULL;
}

void getVals()
{
    scanf("%d", &val);
    vals[index++] = val;
    scanf("%d", &val);
    vals[index++] = val;
    scanf("%d", &val);
    vals[index++] = val;
    scanf("%d", &val);
    vals[index++] = val;
    scanf("%d", &val);
    vals[index++] = val;
}

int main( int argc, char *argv[] ) {

    pthread_t worker[ workers ];

    sem_init(&lock, 0, 1);

    sem_wait(&lock);

    for ( int i = 0; i < workers; i++ )
    {
        pthread_create(&worker[i], NULL, routine, NULL); 
    }

    sem_post(&lock);

    do 
    {
        sem_wait(&lock);

        getVals();

        sleep(1);

        sem_post(&lock);

        sleep(1);

    } while(1);

    //sem_post(&lock);

    //to join threads
    for ( int i = 0; i < workers; i++ ) {
        pthread_join(worker[i], NULL);
    } 

    // Then, start getting work for them to do.

    sem_destroy(&lock);

    return EXIT_SUCCESS;
}
