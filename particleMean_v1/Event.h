/* Matteo Bortoletto 1146169
 particleMean_v1
 */

#ifndef Event_h
#define Event_h

#include "Particle.h"

struct Event {
    
  int id, n;
  float x, y, z;
  Particle** pp;

};

#endif
