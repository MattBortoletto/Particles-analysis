/* Matteo Bortoletto 1146169
 particleHist_v1
 */

#include<vector>
#include "Event.h"

Event::Event( int id, float x, float y, float z ):
 // initializations
  id1(id),
  x1(x),
  y1(y),
  z1(z) {
  // allocate a buffer for particle pointers
  pp.reserve( 10 );
}


Event::~Event() {
  // delete all the particle pointers
  for( int i = 0; i < pp.size(); i++ ) delete pp[i];
}


void Event::add( float px, float py, float pz, int charge ) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if ( pp.size() >= 10 ) return;

  // create the new particle and fill with data
  Particle* p = new Particle;
  p->charge = charge;
  p->px = px;
  p->py = py;
  p->pz = pz;

  pp.push_back(p);

  return;

}


// get event id.
int Event::eventNumber() const {
  return id1;
}


// get decay point coordinates
float Event::x() const {
  return x1;
}

float Event::y() const {
  return y1;
}

float Event::z() const {
  return z1;
}

// get number of particles
int Event::nParticles() const {
  return pp.size();
}

// get particle
Event::part_ptr Event::particle( unsigned int i ) const {
  return pp[i];
}

