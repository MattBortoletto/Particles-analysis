/* Matteo Bortoletto 1146169
 particleDump_v1
 */

#include<iostream>
#include<fstream>
using namespace std;


//****************	READ	******************

int read( ifstream& ifile1, float& x1, float& y1, float& z1, int c1[10], float px1[10], float py1[10], float pz1[10] ) {
  
  int n1, id1;
  
  ifile1 >> id1 >> x1 >> y1 >> z1 >> n1; 

  for (int k = 0; k < n1; k++) {
    ifile1 >> c1[k] >> px1[k] >> py1[k] >> pz1[k];
  }

  return n1; // ritorna il numero delle particelle

}


//****************	DUMP	******************

void dump( int id2, int n2, float x2, float y2, float z2, int c2[10], float px2[10], float py2[10], float pz2[10] ) {

  cout << id2 << endl;
  cout << x2 << ' ' << y2 << ' ' << z2 << endl;
  cout << n2 << endl;
  for (int j = 0; j < n2; j++ ) {
    cout << c2[j] << ' ' <<  px2[j] << ' ' << py2[j] << ' ' << pz2[j] << endl;
  }

  return;

}


//****************	MAIN	******************

int main() {

  // open input file
  ifstream ifile( "dataFile.txt" );

  // declare event variables
  int id;	//event identifier
  float x;      //point coordinates
  float y;
  float z;
  int n;        //number of particles
  int c[10];    //electric charges
  float px[10]; //momentum components
  float py[10];
  float pz[10];

  while ( ifile >> id ) {	
      n = read( ifile, x, y, z, c, px, py, pz );
      dump( id, n, x, y, z, c, px, py, pz );
  }
  
  return 0;

}

