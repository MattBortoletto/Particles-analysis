/* Matteo Bortoletto 1146169
 particleMean_v4
 */

#include "EventReadFromFile.h"

#include "Event.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// read data from file "name"
EventReadFromFile::EventReadFromFile( const string& name ) {
  file = new ifstream( name.c_str() );
}


EventReadFromFile::~EventReadFromFile() {
  delete file;
}


// get an event
const Event* EventReadFromFile::get() {
  return readFile();
}


// read an event
const Event* EventReadFromFile::readFile() {

  // event pointer and identifier
  Event* ev;
  int id, n;
  float x, y, z;

  // try to read input file
  // on success create new event
  if ( (*file) >> id >> x >> y >> z >> n ) ev = new Event( id, x, y, z );
  // on failure return null pointer
  else return 0;

  // read number of points
  int charge[n];
  float px[n], py[n], pz[n];
  

  // read and store all points
  for ( int i = 0; i < n; ++i ) {
    (*file) >> charge[i] >> px[i] >> py[i] >> pz[i];
    ev -> add( px[i], py[i], pz[i], charge[i] );
  }

  return ev;

}

