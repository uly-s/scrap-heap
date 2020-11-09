#include "fileio.h"

// define buff size
#define BUFF_SIZE 1024


int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: oucat <files>\n";

  // check for help flag
  int opt = getopt(argc, argv, "h");

  switch(opt)
  {
    case 'h':
        write(1, usage, strlen(usage));
	return 0;
	break;
    case '?':
        write(2, usage, strlen(usage));
	exit(EXIT_FAILURE);
	return -1;
    case -1:
	break;
  }

  // create file descriptor, flag variable, bytes variable, and buffer
  int fd;
  int flags = O_RDONLY;
  ssize_t bytes = BUFF_SIZE;
  char buffer[BUFF_SIZE+1];

  // null terminate
  buffer[BUFF_SIZE] = '\0';

  // check if we are reading from stdin
  if(argc == 1)
  {
    FILE2FILE(0, 1, buffer, BUFF_SIZE);
  }
  else
  {
    // else we are reading from stream of files, open and read/write each file
    for (int i = 1; i < argc; i++)
    {
      fd = OPEN(argv[i], flags);

      FILE2FILE(fd, 1, buffer, BUFF_SIZE);
    }
  }

  return 0;
}
