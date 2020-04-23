/* Matteo Bortoletto 1146169
 particleHist_v4
 */

#include<iostream>
#include <math.h>
#include<vector>

#include "LifetimeFit.h"
#include "Event.h"
#include "ParticleReco.h"

using namespace std;


LifetimeFit::LifetimeFit( float min, float max):
 min(min), max(max) { // initializations
}


LifetimeFit::~LifetimeFit() {
}


// add data from a new event
bool LifetimeFit::add( const Event& ev ) {
  double M;
  M = ParticleReco::instance()->invariantMass(); 
  // check for mass being in range
  if( M > min && M < max ) {
    accepted++;
    return true;
  }
  else return false;
}


// compute mean and rms
void LifetimeFit::compute() {
}


// return number of selected events
unsigned int LifetimeFit::nEvents() const {
  return accepted;
}




