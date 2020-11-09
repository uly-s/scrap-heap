#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// global var for usage string
char* usage;

// throw error helper method, writes to stderr
// and exits with 1
void ERROR()
{
  write(2, usage, strlen(usage));
  exit(EXIT_FAILURE);
}

// checks if value is -1, throws error if so
void CHECK_ERROR(int val)
{
  if(val == -1)
  {
    ERROR();
  }
}

// open [string file_name] with [int flag] options, return file descriptor
int OPEN(char* file_name, int flags)
{
  // open file and check for error
  int fd = open(file_name, flags);

  CHECK_ERROR(fd);

  return fd;
}

// read from file [int fd] into [char* buffer] for [size_t (int) bytes], returns number read
ssize_t READ(int fd, char* buffer, size_t bytes)
{
  // check for error
  CHECK_ERROR(fd);

  // read fd
  ssize_t bytes_read = read(fd, buffer, bytes);

  // check for error again
  CHECK_ERROR(bytes_read);

  return bytes_read;
}

// write to file [int fd] from [char* buffer] for a total of [size_t(int) bytes], return number written
ssize_t WRITE(int fd, char* buffer, size_t bytes)
{
  // check for error
  CHECK_ERROR(fd);

  // write
  ssize_t bytes_written = write(fd, buffer, bytes);

  // check for error again
  CHECK_ERROR(bytes_written);

  return bytes_written;
}

// read from file [int in_fd] to file [int out_fd] using [char* buffer] of [size_t(int) buffer_size]
void FILE2FILE(int in_fd, int out_fd, char* buffer, size_t buffer_size)
{
  ssize_t bytes = buffer_size;

  while(bytes > 0)
  {
    bytes = READ(in_fd, buffer, buffer_size);
    WRITE(out_fd, buffer, bytes);
  }
}

// parse [char* arg] into an integer and return it, checks for bad input
int PARSE_INT(char* arg)
{
  // we start i at 1 for negative numbers
  int i;

  if(arg[0] == '-')
      i = 1;
  else
      i = 0;

  // check for bad input
  for(i; i < strlen(arg); i++)
  {
    if(!isdigit(arg[i]))
    {
      WRITE(2, usage, strlen(usage));
      exit(EXIT_FAILURE);
    }
  }

  // strtol converts char* to int
  int val = strtol(arg, &arg, 10);

  return val;
}

// counters the number of lines in file [char* file_name], returns number of lines
int COUNT_LINES(char* file_name)
{
  // open file, declare variables
  int fd = OPEN(file_name, O_RDONLY);
  int lines = 0;
  ssize_t bytes = 1;
  char buffer[2];
  buffer[1] = '\0';

  // read til end of file
  while(bytes > 0)
  {
    bytes = READ(fd, buffer, bytes);
    if(bytes == 0) break;
    if(buffer[0] == '\n') lines++;
  }

  int status = close(fd);

  return lines;
}
