/* Matteo Bortoletto 1146169
 particleHist_v2
 */

#include "MassMean.h"
#include "Event.h"

#include <math.h>

float mass( const Event& ev );


MassMean::MassMean( float min, float max ):
 // initializations
  min(min),
  max(max) {
}


MassMean::~MassMean() {
}


// add data from a new event
bool MassMean::add( const Event& ev ) {

  // check for mass being in range
  // update number of events and sums
  double M;
  M = mass( ev );
  if( M > min && M < max ) {
    double M1 = M - min;	
    SumInvMass = SumInvMass + M1;
    SumSquares = SumSquares + M * M;
    accepted++;
    return true;
  }
  else return false;
  
}


// compute mean and rms
void MassMean::compute() {
  MEAN = SumInvMass / accepted + min;
  RMS = sqrt( SumSquares / accepted - MEAN * MEAN );
}


// return number of selected events
unsigned int MassMean::nEvents() const {
  return accepted;
}


// return mean and rms
double MassMean::mMean() const {
  return MEAN;
}

double MassMean::mRMS() const {
  return RMS;
}

