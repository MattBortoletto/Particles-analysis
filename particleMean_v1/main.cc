/* Matteo Bortoletto 1146169
 particleMean_v1
 */

#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

#include "Particle.h"
#include "Event.h"

using namespace std;


//****************    FUNCTION DECLARATIONS    ******************

const Event* read ( ifstream& file1 );
void dump ( const Event& ev );
void clear ( const Event* ev );
bool add ( const Event& ev, float minMass, float maxMass, double& SumInvMass, double& SumSquares );


//****************    MAIN    ******************

int main () {
  
  int accepted = 0;
  double SumInvMass, SumSquares;
  double MEAN, RMS;

  const Event* ev;
  ifstream inputfile ( "particle_events.txt" );
  while ( ( ev = read ( inputfile ) ) ) {
	if ( !ev ) return 0;
	if( add( *ev, 0.490, 0.505, SumInvMass, SumSquares ) ) accepted++;
	MEAN = SumInvMass / accepted + 0.490;
	RMS = sqrt( SumSquares / accepted - MEAN * MEAN );
	cout << MEAN << " " << RMS << endl << endl;
	//dump (*ev);
	clear(ev);
	}

  return 0;
    
}


//****************    READ    ******************

const Event* read ( ifstream& file ) {

  Event* ev;
  int id, n;
  float x, y, z;
  if ( file >> id >> x >> y >> z >> n ) ev = new Event;
	
  else return 0;

  ev -> id = id;
  ev -> x = x;
  ev -> y = y;
  ev -> z = z;
  ev -> n = n;

  int c[n];
  float px[n], py[n], pz[n];
  ev -> pp = new Particle*[n];
  for ( int i = 0; i < n; i++ ) {
	ev -> pp[i] = new Particle;
	file >> c[i] >> px[i] >> py[i] >> pz[i];
	ev -> pp[i] -> c = c[i];
	ev -> pp[i] -> px = px[i];
	ev -> pp[i] -> py = py[i];
	ev -> pp[i] -> pz = pz[i];
	}

  return ev;
    
}


//****************    DUMP    ******************

void dump ( const Event& ev ) {

  cout << ev.id << endl;
  cout << ev.x <<  ' ' << ev.y << ' ' << ev.z << endl;
  cout << ev.n << endl;

  for ( int i = 0; i < ev.n; i++ )
	cout << ev.pp[i]-> c << ' ' << ev.pp[i]-> px << ' ' << ev.pp[i]-> py << ' ' << ev.pp[i]-> pz << endl;
    
  }


//****************    CLEAR    ******************

void clear ( const Event* ev ) {

  for ( int i = 0; i < ev->n; i++ )
	delete ev->pp[i];
	
  delete[] ev->pp;
  delete ev;
    
}










