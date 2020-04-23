/* Matteo Bortoletto 1146169
 particleMean_v2
 */

#include "Event.h"

Event::Event( int id, float x, float y, float z ):
 // initializations
  id1(id),
  x1(x),
  y1(y),
  z1(z),
  n(0),
  maxN(10){
  // allocate a buffer for particle pointers
  pp = new Particle*[maxN];
}


Event::~Event() {
  // delete all the particle pointers
  for( int i = 0; i < n; i++ ) delete pp[i];
  // delete the pointers array
  delete[] pp;
}


void Event::add( float px, float py, float pz, int charge ) {

  // check for the number of particles, if maximum reached do nothing
  // and return
  if ( n >= maxN ) return;

  // create the new particle and fill with data
  pp[n] = new Particle;
  pp[n]->charge = charge;
  pp[n]->px = px;
  pp[n]->py = py;
  pp[n]->pz = pz;
  
  // store the new particle pointer in the array and increase counter
  // già fatto in pp[n] = new Particle;
  //Altrimenti andava fatto nel seguente modo:
  /*
  Particle* p = new Particle;
  p->charge = charge;
  p->px = px;
  p->py = py;
  p->pz = pz;
  
  pp[n] = p;
  */
  
  n++;

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
  return n;
}


// get particle
const Event::Particle* Event::particle( unsigned int i ) const {
  return pp[i];
}

