#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <errno.h>
#define _GNU_SOURC

#define MAX_CLIENTS 32

/** Port number used by my server */
#define PORT_NUMBER "2399"

// Print out an error message and exit.
static void fail( char const *message ) {
  fprintf( stderr, "%s\n", message );
  exit( 1 );
}

/** handle a client connection, close it when we're done. */
void handleClient( int sock ) {
  // Here's a nice trick, wrap a C standard IO FILE around the
  // socket, so we can communicate the same way we would read/write
  // a file.
  FILE *fp = fdopen( sock, "a+" );
  
  // Prompt the user for a command.
  fprintf( fp, "cmd> " );

  char cmd[ 11 ];
  int match;
  while ( ( match = fscanf( fp, "%s", cmd ) ) == 1 &&
          strcmp( cmd, "quit" ) != 0 ) {
    // Just echo the command back to the client.
    fprintf( fp, "%s\n", cmd );

    // Prompt the user for the next command.
    fprintf( fp, "cmd> " );
    fflush( fp );
  }

  // Close the connection with this client.
  fclose( fp );
}

struct comment
{
  char name[9];
  char text[71];
  int score;
};

struct comment comments[6];

void init()
{
  for(int i = 0; i < 6; i++)
  {
    memset(comments[i].name, '\0', 9);
    memset(comments[i].text, '\0', 71);
  }
}

void* client(void* arg)
{
  int* ptr = (int*)arg;

  int sock = *ptr;

  printf("%d\n", sock);

  return NULL;
}




int main()
{

  init();




  // Prepare a description of server address criteria.
  
  struct addrinfo addrCriteria;
  memset(&addrCriteria, 0, sizeof(addrCriteria));
  addrCriteria.ai_family = AF_INET;
  addrCriteria.ai_flags = AI_PASSIVE;
  addrCriteria.ai_socktype = SOCK_STREAM;
  addrCriteria.ai_protocol = IPPROTO_TCP;

  // Lookup a list of matching addresses
  struct addrinfo *servAddr;
  if ( getaddrinfo( NULL, PORT_NUMBER, &addrCriteria, &servAddr) )
    fail( "Can't get address info" );

  // Try to just use the first one.
  if ( servAddr == NULL )
    fail( "Can't get address" );

  // Create a TCP socket
  int servSock = socket( servAddr->ai_family, servAddr->ai_socktype,
                         servAddr->ai_protocol);
  if ( servSock < 0 )
    fail( "Can't create socket" );

  // Bind to the local address
  if ( bind(servSock, servAddr->ai_addr, servAddr->ai_addrlen) != 0 )
    fail( "Can't bind socket" );
  
  // Tell the socket to listen for incoming connections.
  if ( listen( servSock, 5 ) != 0 )
    fail( "Can't listen on socket" );

  // Free address list allocated by getaddrinfo()
  freeaddrinfo(servAddr);

  // Fields for accepting a client connection.
  struct sockaddr_storage clntAddr; // Client address
  socklen_t clntAddrLen = sizeof(clntAddr);

  int index = 0;

  int socks[MAX_CLIENTS];

  memset(socks, 0, MAX_CLIENTS * 4);

  pthread_t threads[MAX_CLIENTS];

  while ( true  ) {

    // Accept a client connection.
    int sock = accept( servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);

    socks[index] = sock;

    pthread_create(threads + index, NULL, client, &socks[index]);

    index++;

    // Talk to this client
    //handleClient( sock );
  }

  // Stop accepting client connections (never reached).
  close( servSock );

  return 0;
}
