#include "fileio.h"

int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: outail [-n N] <file>\n";

  // declare opt flag for arg count and get opt
  int opt_flag = 0;
  int opt = getopt(argc, argv, ":n:");

  // declare N
  int N;

  // switch on opt, parse arg for n, throw error
  // for bad opt, set N to 10 for -1
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

  // if no file listed or if opt not given but there
  // is more than 1 arg throw error
  if(argc - opt_flag == 1 || (opt == -1 && argc > 2))
  {
    ERROR();
  }

  // declare fd, line, lines, bytes, and buffer
  int fd = 0;
  int line = 0;
  int lines = 0;
  ssize_t bytes = 1;
  char buffer[2];
  buffer[1] = '\0';

  // get lines count
  lines = COUNT_LINES(argv[argc - 1]);

  // open file
  fd = OPEN(argv[argc - 1], O_RDONLY);

  // read the first lines - N lines
  while(bytes > 0 && line < lines - N)
  {
    bytes = READ(fd, buffer, bytes);
    if(bytes == 0) break;
    if(buffer[0] == '\n') line++;
  }

  // reset bytes
  bytes = 1;

  // read and write the last N lines
  while(bytes > 0 && line < lines)
  {
    bytes = READ(fd, buffer, bytes);
    WRITE(1, buffer, bytes);
    if(buffer[0] == '\n') line++;
  }

  return 0;
}
