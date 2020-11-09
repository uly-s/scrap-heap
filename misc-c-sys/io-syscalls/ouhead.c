#include "fileio.h"

int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: ouhead [-n N] <file>\n";

  // opt flag, used to keep track of number of arguments
  int opt_flag = 0;

  // get opt
  int opt = getopt(argc, argv, ":n:");

  // declare N
  int N;

  // switch on opt, parse arg if opt, throw error for bad opt
  // and set N to 10 if no opt
  switch(opt)
  {
    case 'n':
        N = PARSE_INT(optarg);
	opt_flag = 2;
	break;
    case '?':
        ERROR();
        break;
    case ':':
	ERROR();
	break;
    case -1:
	N = 10;
	break;
  }

  // if we got no opt but have more than 1 arg
  // something went wrong
  if(opt == -1 && argc > 2)
  {
    ERROR();
  }

  // declare file descriptor, lines var, bytes var, and buffer
  int fd;
  int lines = 0;
  ssize_t bytes = 1;
  char buffer[2];
  buffer[1] = '\0';

  // if argc == 1 we are reading from stdin, else reading from file
  if(argc - opt_flag == 1)
  {
    fd = 0;
  }
  else
  {
    fd = OPEN(argv[argc - 1], O_RDONLY);
  }

  // read and write each byte
  while(bytes > 0 && lines < N)
  {
    bytes = READ(fd, buffer, bytes);
    WRITE(1, buffer, bytes);
    if(buffer[0] == '\n') lines++;
  }

  return 0;
}
