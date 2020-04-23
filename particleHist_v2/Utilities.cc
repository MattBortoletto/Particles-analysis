/* Matteo Bortoletto 1146169
 particleHist_v2
 */

#include "Utilities.h"
#include <math.h>


Utilities::Utilities(){
}

Utilities::~Utilities(){
}

// compute energy from momentum x,y,z components and invariant mass
double Utilities::energy ( double PtotX, double PtotY, double PtotZ, double invMass ) {

  double energy = sqrt( PtotX * PtotX + PtotY * PtotY + PtotZ * PtotZ + invMass * invMass );
  return energy;
    
} 

// compute invariant mass from momentum x,y,z components and energy
double Utilities::invMass ( double PtotX, double PtotY, double PtotZ, double energy ) {

  double Ptot;
  Ptot = sqrt( PtotX * PtotX + PtotY * PtotY + PtotZ * PtotZ );
  double invMass = sqrt( energy * energy - Ptot * Ptot );
  return invMass;
    
} 
