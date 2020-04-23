/* Matteo Bortoletto 1146169
 particleMean_v2
 */

#include<fstream>

#include "Event.h"


const Event* read ( std::ifstream& file ) {

  Event* ev;
  int id, n;
  float x, y, z;
  if ( file >> id >> x >> y >> z >> n ) ev = new Event( id, x, y, z );
  else return 0;

  int charge[n];
  float px[n], py[n], pz[n];
  //ev -> pp = new Particle*[n]; lo fa il costruttore di Event
  for ( int i = 0; i < n; i++ ) {
        //ev -> pp[i] = new Particle; lo aggiungo dentro la add
	file >> charge[i] >> px[i] >> py[i] >> pz[i];
	ev -> add( px[i], py[i], pz[i], charge[i] );
  }

  return ev;
    
}
