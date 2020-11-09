#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "fileio.h"

// converts an int to string array and writes
// to stdout, arg is int to bee written, no return
void INTOUT(int arg)
{
  // function breaks on 0 so we handle it first
  if (arg == 0)
  {
    WRITE(1, "0\n", 2);
    return;
  }

  // val is what we use in the function
  // size will be size of the array
  int val;
  int size;

  // we need to handle negatives, so if 
  // arg is less than 0 we flip it
  if(arg >= 0)
    val = arg;
  else
    val = -arg;

  // count the number of digits using log10
  int digits = (int) log10((double) val) + 1;

  // handling negatives again, size of
  // negative numbers is greater by 1
  // for negative sign
  if(arg >= 0)
    size = digits + 1;
  else
    size = digits + 2;

  // create buffer of size and null terminate
  char buff[size];
  buff[size - 1] = '\0';

  // here is what actually converts the int to a
  // char array
  sprintf(buff, "%d", arg);

  // then just write string
  WRITE(1, buff, strlen(buff));
  WRITE(1, "\n", 1);
}


int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: ouseq [M] N\n";

  // declare M and N
  int M = 0;
  int N = 0;

  // if argc == 2 we have only N to deal with
  if(argc == 2)
  {
    // parse int
    N = PARSE_INT(argv[1]);

    // if N > 0, print 0 to N
    if(N > 0)
    {
      for(int i = 0; i <= N; i++)
      {
        INTOUT(i);
      }
    }  // else if N < 0, print 0 to N
    else if(N < 0)
    {
      for(int i = 0; i >= N; i--)
      {
        INTOUT(i);
      }
    }  // if N == 0 just print it
    else
    {
      INTOUT(N);
    }
  }  // if we have both M and N
  else if(argc == 3)
  {
    // parse args
    M = PARSE_INT(argv[1]);
    N = PARSE_INT(argv[2]);

    // if M < N, print in ascending order
    if(M < N)
    {
      for(int i = M; i <= N; i++)
      {
        INTOUT(i);
      }
    }  // else if M > N, print in descending
    else if(M > N)
    {
      for(int i = M; i >= N; i--)
      {
        INTOUT(i);
      }
    }  // else if M = N, just print M
    else
    {
      INTOUT(M);
    }
  }  // else number of args is wrong, throw error
  else
  {
    ERROR();
  }

  return 0;
}
