/* Matteo Bortoletto 1146169
 particleMean_v1
*/


#include "Event.h"

float mass ( const Event& ev );

bool add ( const Event& ev, float minMass, float maxMass, double& SumInvMass, double& SumSquares ) {

  double M;
  M = mass( ev ); //perchè no *ev? Perchè bool add chiede una referenza
  if( M > minMass && M < maxMass ) {
	double M1 = M - minMass;	
	SumInvMass = SumInvMass + M1;
	SumSquares = SumSquares + M*M;
	return true;
	}
  else return false;

}





