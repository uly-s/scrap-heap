void startReading(char const *name)
{
  while (nw > 0)
  {
    printf("%s is waiting to read\n", name);
    pthread_cond_wait(&readable, &monito);
  }
  nr++;

  printf("%s is reading\n", name);

  pthread_cond_broadcast(&readable);
  //pthread_mutex_unlock(&monito);
}

/** Called by a reader when it's done reading.  Prints out a message saywing who is giving
    up read access. */
void stopReading(char const *name)
{

  nr--;
  printf("%s is done reading\n", name);
  if (nr == 0)
  {
    // printf("Number of READERS is zero\n");
    pthread_cond_broadcast(&writable);
    pthread_mutex_unlock(&monito);
  }
  
}

/** Called by a writer when it's ready to write.  This should block the
    caller until it's OK to write.  If the caller has to wait to get access
    it prints out a message saying who is waiting to write.  Then, once they get
    access, it prints out another message. */
void startWriting(char const *name)
{
  while (nr > 0 || nw > 0)
  {
    printf("%s is waiting to write\n", name);
    pthread_cond_wait(&writable, &monito);
  }
  nw++;

  printf("%s is writing\n", name);
  //pthread_cond_broadcast(&writable);
  //pthread_mutex_unlock(&monito);
}

/** Called by a writer when it's done writing.  Prints out a message saying who is giving
    up write access. */
void stopWriting(char const *name)
{

  nw--;
  printf("%s is done writting\n", name);
  if (nw == 0)
  {
    //printf("Num writers zero\n");
    pthread_cond_broadcast(&readable);
    pthread_mutex_unlock(&monito);
    
  }
  
}