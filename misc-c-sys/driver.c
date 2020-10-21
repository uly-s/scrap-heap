// Sample driver that's simple enough that we can tell what should
// happen.  A thread acquires a write lock, then two more ask for read
// locks and one more asks for a write lock.  After this, the
// remaining threads have to take turns, starting with the reader
// (since the writer just had a lock).

#include <stdio.h>
#include <pthread.h>   // for pthreads
#include <stdlib.h>    // for exit
#include <unistd.h>    // for sleep/usleep

#include "Monitor.h"

// General-purpose fail function.  Print a message and exit.
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( 1 );
}

void *johnThread( void *arg ) {
  const char *name = "john";
  
  sleep( 2 ); // Wait 3 seconds before trying to acquire a read lock.
  
  startReading( name );
  
  sleep( 1 );   // Hold that lock for 1 second.
  
  stopReading( name );
  
  return NULL;
}

void *paulThread( void *arg ) {
  const char *name = "paul";
  
  sleep( 3 ); // Wait 2 seconds before trying to acquire a read lock.
  
  startReading( name );
  
  sleep( 1 );   // Hold that lock for 1 second.
  
  stopReading( name );
  
  return NULL;
}

void *georgeThread( void *arg ) {
  const char *name = "george";
  
  sleep( 1 ); // Wait 1 second before trying to acquire a write lock.
  
  startWriting( name );
  
  sleep( 3 );   // Hold that lock for 3 seconds.
  
  stopWriting( name );
  
  return NULL;
}

void *ringoThread( void *arg ) {
  const char *name = "ringo";
  
  sleep( 2 ); // Wait 2 seconds before trying to acquire a write lock.
  
  startWriting( name );
  
  sleep( 1 );   // Hold that lock for 1 second.
  
  stopWriting( name );
  
  return NULL;
}

int main( int argc, char *argv[] ) {
  // For testing, to buffer only one output line at a time.
  setvbuf( stdout, NULL, _IOLBF, 0 );
  
  // Initialize our monitor.
  initRWMonitor( 1 );

  // Make a few threads
  pthread_t thread[ 4 ];
  if ( pthread_create( thread + 0, NULL, johnThread, NULL ) != 0 ||
       pthread_create( thread + 1, NULL, paulThread, NULL ) != 0 ||
       pthread_create( thread + 2, NULL, georgeThread, NULL ) != 0 ||
       pthread_create( thread + 3, NULL, ringoThread, NULL ) != 0 )
    fail( "Can't make a thread we need.\n" );

  // Wait until all the threads finish.
  for ( int i = 0; i < sizeof( thread ) / sizeof( thread[ 0 ] ); i++ )
    pthread_join( thread[ i ], NULL );

  // Free any monitor resources.
  destroyRWMonitor();

  return 0;
}