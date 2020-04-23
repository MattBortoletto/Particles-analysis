/* Matteo Bortoletto 1146169
 particleMean_v3
 */

#include<iostream>

#include "Event.h"
#include "MassMean.h"

void dump ( const MassMean& MM ) {

  std::cout << MM.nEvents() << " " << MM.mMean() << " " << MM.mRMS() << std::endl;
    
  }
