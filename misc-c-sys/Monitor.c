#include "Monitor.h"

pthread_mutex_t monito = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t readable = PTHREAD_COND_INITIALIZER;
pthread_cond_t writable = PTHREAD_COND_INITIALIZER;
int nw = 0;
int nr = 0;
int qw = 0;
int qr = 0;
int buffer[1024];

/** Interface for the Readers/Writers monitor.  If I was programming in
    Java or C++, this would all be wrapped up in a class.  Since we're using
    C, it's just a collection of functions, with an initialization
    function to init the state of the whole monitor. */

/** Initialize the monitor. */
void initRWMonitor(int num)
{
}

/** Destroy the monitor, freeing any resources it uses. */
void destroyRWMonitor()
{
}

/** Called by a reader when it's ready to read.  This should block the
    reader until it's OK to read.  If the caller has to wait to get read access
    it prints out a message saying who is waiting to read.  Then, once they get read
    access it prints out another message. */
void startReading(char const *name)
{
  pthread_mutex_lock(&monito);

  if(nw > 0 || qw > 0)
  {
    printf("%s is waiting to read\n", name);

    qr++;
    pthread_cond_wait(&readable, &monito);
    qr--;
  }

  nr++;

  printf("%s is reading\n", name);
  
  pthread_mutex_unlock(&monito);
}

/** Called by a reader when it's done reading.  Prints out a message saywing who is giving
    up read access. */
void stopReading(char const *name)
{
  pthread_mutex_lock(&monito);

  printf("%s is done reading\n", name);

  nr--;

  if (nr == 0)
  {
    if(qw > 0)
      pthread_cond_signal(&writable);
    else if(qr > 0)
      pthread_cond_signal(&readable); 
  }
  
  pthread_mutex_unlock(&monito);
}

/** Called by a writer when it's ready to write.  This should block the
    caller until it's OK to write.  If the caller has to wait to get access
    it prints out a message saying who is waiting to write.  Then, once they get
    access, it prints out another message. */
void startWriting(char const *name)
{
  pthread_mutex_lock(&monito);

  if (nw > 0 || nr > 0)
  {
    printf("%s is waiting to write\n", name);

    qw++;
    pthread_cond_wait(&writable, &monito);
    qw--;
  }

  nw++;

  printf("%s is writing\n", name);
  //pthread_cond_signal(&writable);
  pthread_mutex_unlock(&monito);
}

/** Called by a writer when it's done writing.  Prints out a message saying who is giving
    up write access. */
void stopWriting(char const *name)
{
  pthread_mutex_lock(&monito);

  printf("%s is done writting\n", name);

  nw--;
  
  if (qr > 0) 
    pthread_cond_signal(&readable); 
  else
    pthread_cond_signal(&writable); 
  
  pthread_mutex_unlock(&monito); 
  
}