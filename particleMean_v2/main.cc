/* Matteo Bortoletto 1146169
 particleMean_v2
 */

#include <iostream>
#include <fstream>

#include "Event.h"
#include "MassMean.h" 

using namespace std;

//declare functions to read and dump events
const Event* read (ifstream& file1);
void dump (const MassMean& MM1);

int main( int argc, char* argv[] ) {

  // open input file
  ifstream inputfile ("particle_events.txt");

  // create MassMean objects
  MassMean K0(0.490, 0.505);
  MassMean Lambda0(1.114, 1.118);

  // loop over events
  const Event* ev;
  while ( (ev = read (inputfile)) ) {
    K0.add(*ev);
    Lambda0.add(*ev);
    delete ev;
  }

  // compute results
  K0.compute();
  Lambda0.compute();

  // print number of selected events and results for both particles
  dump(K0);
  dump(Lambda0);

  return 0;

}

