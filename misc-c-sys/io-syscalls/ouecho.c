#include "fileio.h"

// define buffer size, picked 64 because I figured we wont get any words longer than that
#define BUFFER_SIZE 64

int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: ouecho [string]\n";

  // create and null terminate buffer
  char buffer[BUFFER_SIZE+1];
  buffer[BUFFER_SIZE] = '\0';

  // for each arg (except for last), write to console
  for(int i = 1; i < argc-1; i++)
  {
    WRITE(1, argv[i], strlen(argv[i]));
    WRITE(1, " ", 1);
  }

  // write last arg, if it exists
  if (argc > 1)
	 WRITE(1, argv[argc-1], strlen(argv[argc-1]));

  // finish with newline
  WRITE(1, "\n", 1);

  return 0;
}
