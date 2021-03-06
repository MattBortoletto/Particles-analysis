/* Matteo Bortoletto 1146169
 particleHist_v1
 */

#include<cmath>

#include "Event.h"
#include "Utilities.h"
#include "Constants.h"


float mass ( const Event& ev ) {
  
  //creo un'oggetto Utilities e Constants
  Utilities U; 
  Constants C;

  // positive / negative track counters
  int positive = 0;
  int negative = 0;

  // variables for momentum sums
  float PtotX = 0;
  float PtotY = 0;
  float PtotZ = 0;  

  // variables for energy sums, for K0 and Lambda0
  float Kenergy = 0;
  float Lenergy = 0;

  // loop over particles - momenta
  for ( int j = 0; j < ev.nParticles(); j++ ) {
    // get particle pointer
    //...
    // update momentum sums
    PtotX = PtotX + ev.particle(j)->px;
    PtotY = PtotY + ev.particle(j)->py;
    PtotZ = PtotZ + ev.particle(j)->pz;
    // update energy sums, for K0 and Lambda0 hyptheses:
    Kenergy = Kenergy + U.energy( ev.particle(j)->px, ev.particle(j)->py, ev.particle(j)->pz, C.massPion ); 

    if (ev.particle(j)->charge == 1)
      Lenergy = Lenergy + U.energy( ev.particle(j)->px, ev.particle(j)->py, ev.particle(j)->pz, C.massProton );

    else if ( ev.particle(j)->charge == -1)
      Lenergy = Lenergy + U.energy( ev.particle(j)->px, ev.particle(j)->py, ev.particle(j)->pz,C.massPion );

    else return -1;

    // pion mass for K0,
    // proton or pion mass for Lambda0,
    // for positive or negative particles respectively    
    
    // update positive/negative track counters
    if ( ev.particle(j)->charge == 1 ) positive++;

    else if ( ev.particle(j)->charge == -1 ) negative++;

    else return -1;
      
  }
  
  // check for exactly one positive and one negative track
  // otherwise return negative (unphysical) invariant mass
  if ( positive != 1 ) return -1;
  
  // invariant masses for different decay product mass hypotheses
  float Kmass, Lmass;
  Kmass = U.invMass ( PtotX, PtotY, PtotZ, Kenergy );
  Lmass = U.invMass ( PtotX, PtotY, PtotZ, Lenergy );
  
  // compare invariant masses with known values and return the nearest one
  if ( fabs( Kmass - C.massK0 ) < fabs( Lmass - C.massLambda0 ) ){
    return Kmass;
  }
  else return Lmass; 

}

