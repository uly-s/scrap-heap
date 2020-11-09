#include "fileio.h"

int main(int argc, char* argv[])
{
  // set usage string
  usage = "usage: ouwc [-l | -c] <file>\n";

  // option flags, needed to keep track of argc
  int lines_opt = 0;
  int chars_opt = 0;

  // keeps track of what we are counting
  int lines_flag = 0;
  int chars_flag = 0;

  // options
  char* options = "lc";

  // get option
  int opt = getopt(argc, argv, options);

  // if no option set both flags to 1
  if(opt == -1)
  {
    lines_flag = 1;
    chars_flag = 1;
  }
  else
  {    // switch on option, set flag and opt flag, or throw error
    switch(opt)
    {
      case 'l':
          lines_flag = 1;
	  lines_opt = 1;
          break;
      case 'c':
          chars_flag = 1;
	  chars_opt = 1;
          break;
      case '?':
          ERROR();
          break;
     }

    // update options for procured flag
    if(lines_flag)
    {
      options = "c";
    }
    else if(chars_flag)
    {
      options = "l";
    }

    // check for other option
    opt = getopt(argc, argv, options);

    // if we have both options switch on option to see which one
    if(opt != -1)
    {
      switch(opt)
      {
        case 'l':
            lines_flag = 1;
	    lines_opt = 1;
            break;
        case 'c':
            chars_flag = 1;
	    chars_opt = 1;
            break;
        case '?':
            ERROR();
            break;
       }
    }
  }

  // line and char counters
  int lines = 0;
  int chars = 0;

  // file descriptor, bytes var, and buffer
  int fd;
  int bytes = 1;
  char buffer[2];
  buffer[1] = '\0';

  // if no file given, (argc - options == 1), read from stdin
  if(argc - lines_opt - chars_opt == 1)
  {
    fd = 0;
  }
  else  // else open file
  {
    fd = OPEN(argv[argc-1], O_RDONLY);
  }

  // while not at end of file, increment lines and characters
  while(bytes > 0)
  {
    bytes = READ(fd, buffer, bytes);
    if(bytes > 0) chars++;
    if(bytes > 0 && buffer[0] == '\n') lines++;
  }

  // create buffers for lines and chars
  char lines_buff[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};
  char chars_buff[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'};

  // convert into into char arrays, format width 8
  sprintf(lines_buff, "%8d", lines);
  sprintf(chars_buff, "%8d", chars);

  // handle different cases, just chars, just lines
  // chars and lines, and else for error
  if(lines_flag && !chars_flag)
  {
    WRITE(1, lines_buff, 8);
    WRITE(1, "\n", 1);
  }
  else if(!lines_flag && chars_flag)
  {
    WRITE(1, chars_buff, 8);
    WRITE(1, "\n", 1);
  }
  else if(lines_flag && chars_flag)
  {
    WRITE(1, lines_buff, 8);
    WRITE(1, chars_buff, 8);
    WRITE(1, "\n", 1);
  }
  else
  {
    ERROR();
  }

  return 0;
}
