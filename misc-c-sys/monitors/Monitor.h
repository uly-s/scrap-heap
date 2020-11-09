#ifndef __Monitor_H__
#define __Monitor_H_
#include <pthread.h>
#include <stdio.h>

/** Interface for the Readers/Writers monitor.  If I was programming in
    Java or C++, this would all be wrapped up in a class.  Since we're using
    C, it's just a collection of functions, with an initialization
    function to init the state of the whole monitor. */

/** Initialize the monitor. */
void initRWMonitor();

/** Destroy the monitor, freeing any resources it uses. */
void destroyRWMonitor();

/** Called by a reader when it's ready to read.  This should block the
    reader until it's OK to read.  If the caller has to wait to get read access
    it prints out a message saying who is waiting to read.  Then, once they get read
    access it prints out another message. */
void startReading( char const *name );

/** Called by a reader when it's done reading.  Prints out a message saywing who is giving
    up read access. */
void stopReading( char const *name );

/** Called by a writer when it's ready to write.  This should block the
    caller until it's OK to write.  If the caller has to wait to get access
    it prints out a message saying who is waiting to write.  Then, once they get
    access, it prints out another message. */
void startWriting( char const *name );

/** Called by a writer when it's done writing.  Prints out a message saying who is giving
    up write access. */
void stopWriting( char const *name );

#endif