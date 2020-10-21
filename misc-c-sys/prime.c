#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <math.h>

/**
  @file prime.c
  @author David Sturgill (dbsturgill)
  @author Reeha Nidamarty (snidama2)
  A program that uses multiple CPU cores
  to read in a list of integer values, checks 
  each value to see whether it’s prime or 
  composite, and report how many prime values 
  are in the input and it will (optionally) report 
  each prime value as it detects it. It will be done 
  by dividing up the work dynamically so different 
  workers may get different sub-tasks from execution to 
  execution using anonymous, POSIX semaphores for 
  synchronization. 

  Credit: Some of this code, specifically for the implementation 
  of finding a prime value efficiently in the input file is inspired 
  from Melody Griessen in question @120 on Piazza. Some of the code
  is also inspired from race6.c and the Synchronization presentation
  by Professor Sturgill.  
 */


/** Prints an error message, using the msg parameter passed
  * to standard error, and exits the program. 
  * @param msg the error message to be printed to standard
  * error. */
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( EXIT_FAILURE );
}

/** Print out a usage message, then exits */
static void usage() {
  printf( "usage: prime <workers>\n" );
  printf( "       prime <workers> report\n" );
  exit( 1 );
}

/** True if we're supposed to report what we find. */
bool report = false;

/** Total number of prime numbers we've found. */
int total = 0;

/** Fixed-sized array for holding the input values. */
#define MAX_VALUES 500000
int vList[ MAX_VALUES ];

/** Number of values on the list. */
int vCount = 0;

/** MY ADDITION **/
int valIdx = 0;

/** Integer value to represent that all the values from the input file have been read. */
int inputTaken = 0;

/** Values that have already been read from the vCount. */
int vCountPrevious = 0;

/** Integer value to represent that the workers can begin finding prime values. */
int canStartWork = 0;

/** Integer value to represent the number of workers. */
int numWorkers = 1;

/** Semaphore to protect access to the critical section. */
sem_t lock;

/** Semaphore to protect access to counting the number of primes. */
sem_t fill;

/** Semaphore to protect access to reading in the number of values for space. */
sem_t empty;

/** Reads the list of input values, to see if there is enough 
  * room. */
void readList() {

  // Keep reading as many input values as we can.
  int v;

  //printf("begin reading\n");

  while ( true )
  {
    // Make sure we have enough room, then store it on the list.
    
    int flag = scanf( " %d", &v );

    if(flag != 1)
    {
      break;
    }  
    else
    {
      if ( vCount > MAX_VALUES )
        fail( "Too many input values" );

      sem_wait( &empty );
      sem_wait( &lock );

      // Store the latest value
      vList[ vCount ] = v;
      vCount += 1;
          
      sem_post( &lock );
      sem_post( &fill );
    }
    
  }

  sem_post( &fill );

  //printf("end reading\n");
}

/** Start routine for each worker. 
  * @param arg argument passed by the worker thread 
  * created with this start routine. */
void *workerRoutine( void *arg ) {
  int threadIdx = *( int * ) arg;
  int flag = 1; 

  //printf("thread %d begin\n", threadIdx);

  while ( true ) {

    int val;

    sem_wait( &fill );
    sem_wait( &lock );
    // printf( "thread index: %d in lock\n", currIdx );

    if (valIdx < vCount)
    {
      val = vList[valIdx];
      valIdx++;
    }
    else
    {
      val = -1;
    }

    if (flag == 0)
    {
      total++;
      flag = 0;
    }
    
    sem_post( &lock );
    sem_post( &empty );

    flag = 0;

    for ( int j = 2; j <= sqrt( val ); ++j ) {
      if ( val % j == 0 ) {
        flag = 1;
        break;
      }
    }
    /*
    if (val != -1 && flag == 0 && report ) 
    {
      printf( "%d \n", val );
    }*/
  
    if ( val == -1 ) 
    {
      break;
    } 
  }

  sem_post( &fill );

  //printf("thread %d end\n", threadIdx);

  return NULL;
}

/** Starting point for the program that parses the command-line 
  * arguments, creates the worker threads, reads the list of values, 
  * and reports the total number of primes and releases the semaphores.
  * @param argc the integer representing how many
  * command-line arguments there are.
  * @param argv an array of all the char pointers, with
  * each element pointing to the start of one of the
  * command-line arguments.
  * @return exit status. */
int main( int argc, char *argv[] ) {
  // Parse command-line arguments.
  if ( argc < 2 || argc > 3 )
    usage();
  
  if ( sscanf( argv[ 1 ], "%d", &numWorkers ) != 1 ||
       numWorkers < 1 )
    usage();

  // If there's a second argument, it better be "report"
  if ( argc == 3 ) {
    if ( strcmp( argv[ 2 ], "report" ) != 0 )
      usage();
    report = true;
  }

  sem_init( &lock, 0, 1 );
  sem_init( &fill, 0, 0 );
  sem_init( &empty, 0, MAX_VALUES );
  vCountPrevious = 1;

  // Make each of the workers.
  pthread_t worker[ numWorkers ];
  int threadArgPass[ numWorkers ];

  

  for ( int i = 0; i < numWorkers; i++ ) {
    threadArgPass[ i ] = i; 
    pthread_create( &worker[ i ], NULL, workerRoutine, ( void * )&( threadArgPass[ i ] ) );
  }

  // Then, start getting work for them to do.
  readList();

  // Wait until all the workers finish.
  for ( int i = 0; i < numWorkers; i++ ) {
      pthread_join( worker[ i ], NULL   );
  }

  sem_destroy( &lock );
  sem_destroy( &fill );
  sem_destroy( &empty );

  // Report the total and release the semaphores.
  printf( "Prime count: %d\n", total );
  
  return EXIT_SUCCESS;
}
