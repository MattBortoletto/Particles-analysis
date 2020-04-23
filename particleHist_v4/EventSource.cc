/* Matteo Bortoletto 1146169
 particleHist_v4
 */

#include "EventSource.h"
#include "Event.h"
#include "util/include/Dispatcher.h"

EventSource::EventSource() {
}


EventSource::~EventSource() {
}

void EventSource::run() {
 const Event *ev;
 while ( ( ev = get() ) != 0 ) {
   Dispatcher<Event>::notify( *ev );
   delete ev;
 }
 return;
}
