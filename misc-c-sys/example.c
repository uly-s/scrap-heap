#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> 


// Total number of sums we've found.
int total = 0;

sem_t lock;
sem_t full; 
sem_t empty; 

// Fixed-sized array of values.
#define MAX_VALUES 200000
int vList[ MAX_VALUES ];
int vCounts[ 10 ];

// Number of values currently on vList.
int vCount = 0;
int vCountOld = 1; 

// Read the list of numbers
void readList() {

  // Read as many values as possible from standard input.
  int val = 0;
  int flag = 0;
  int counter = 0;

      for(int i = 0; i < 10; i++)
    {
      vCounts[i] = 0;
    }
  
  do
  {


    //sem_wait(&empty);

    sem_wait(&lock);

    do
    {
      flag = scanf( "%d", &(vList[counter++]));
    } 
    while(flag == 1 && 
          counter % 100 != 0 && 
          sem_post(&full) == 0);

    vCount = counter - 1;

    for(int i = 0; i < 10; i++)
    {
      vCounts[i] += 1;
    }

    sem_post(&lock);

  } 
  while(flag == 1);

}

void getWork()
{ 

}

/** Start routine for each worker. */
void *routine( void *arg )
{
  int index = (*(int*) arg);

  int val = 0;

  do
  { 

    sem_wait(&full);

    sem_wait(&lock);

    //printf("%d ", vCounts[index]);

    sem_post(&lock);

    //sem_post(&empty);

  } while(1);    
  
  return NULL;
}

int main( int argc, char *argv[] )
{
  
  int workers = 10;
  
  // Make each of the workers.
  int indexes[ workers ];
  pthread_t worker[ workers ];  

  sem_init(&lock, 0, 1);
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, MAX_VALUES);

  //sem_wait(&lock);

    readList();


  for ( int i = 0; i < workers; i++ )
  {
    indexes[i] = i;
    pthread_create(&worker[i], NULL, routine, &(indexes[i])); 
  }


  //to join threads
  for ( int i = 0; i < workers; i++ ) 
  {
    pthread_join(worker[i], NULL);
  } 

  // Then, start getting work for them to do.

  sem_destroy(&lock);
  sem_destroy(&full);
  sem_destroy(&empty);


  return EXIT_SUCCESS;
}