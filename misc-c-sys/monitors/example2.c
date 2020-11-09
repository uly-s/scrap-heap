#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h> 
#include <unistd.h> 

// Print out an error message and exit.
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( EXIT_FAILURE );
}

// Print out a usage message, then exit.
static void usage() {
  printf( "usage: abc <workers>\n" );
  printf( "       abc <workers> report\n" );
  exit( 1 );
}

// True if we're supposed to report what we find.
bool report = false;

// workers
int workers = 1;

// Total number of sums we've found.
int total = 0;

sem_t lock;
sem_t count; 
sem_t empty; 

// Fixed-sized array of values.
#define MAX_VALUES 200000
int vList[ MAX_VALUES ];

// Number of values currently on vList.
int vIndex = 0;
int vCount = 0;

// Read the list of numbers
void readList() 
{

  // Read as many values as possible from standard input.
  int val;
  while ( scanf( "%d", &val ) == 1 )
  {
    // Make sure we have enough room, then store it on the list.
    if ( vCount > MAX_VALUES )
      fail( "Too many input values" );
    sem_wait(&empty); 
    sem_wait(&lock); 
    vList[ vCount++ ] = val;
    if(vCount > 50)
      exit(0);
    sem_post(&lock); 
    sem_post(&count);
  }
}

/** Start routine for each worker. */
void *workerRoutine( void *arg )
{
  int a = 0, 
      b = 0, 
      c = 0;

  int index = *(int*) arg;

  while(1) 
  { 
    sem_wait(&count); 
    sem_wait(&lock); 
    
    if(vIndex + (workers * 2) < vCount)
    {
      a = vList[vIndex + index];
      b = vList[vIndex + index + 1];
      c = vList[vIndex + index + 2];

      printf("%d + %d = %d\n", a, b, c);
    }

    sem_post(&lock); 
    sem_post(&empty);
  }

  return NULL;
}

int main( int argc, char *argv[] ) {
  
  // Parse command-line arguments.
  if ( argc < 2 || argc > 3 )
    usage();
  
  if ( sscanf( argv[ 1 ], "%d", &workers ) != 1 ||
       workers < 1 )
    usage();

  // If there's a second argument, it better be "report"
  if ( argc == 3 ) {
    if ( strcmp( argv[ 2 ], "report" ) != 0 )
      usage();
    report = true;
  }

  // Make each of the workers.
  int indexes[ workers ];
  pthread_t worker[ workers ];

  sem_init(&lock, 0, 1);
  sem_init(&count, 0, 0);
  sem_init(&empty, 0, MAX_VALUES);

  for ( int i = 0; i < workers; i++ )
  {
    indexes[i] = i;
    pthread_create(&worker[i], NULL, workerRoutine, &(indexes[i])); 
  }


  readList();

  //to join threads
  for ( int i = 0; i < workers; i++ ) {
    pthread_join(worker[i], NULL);
  } 

  // Then, start getting work for them to do.

  sem_destroy(&lock);
  sem_destroy(&count);
  sem_destroy(&empty);

  // Report the total and release the semaphores.
  printf( "Sums: %d\n", total );
  
  return EXIT_SUCCESS;
}
