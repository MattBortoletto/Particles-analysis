/* Matteo Bortoletto 1146169
 particleDump_v2
 */

#include<iostream>
#include<fstream>
using namespace std;

//****************    STRUCTS    ******************

struct Particle {
    
	int c;
	float px, py, pz;
    
};

struct Event {
    
	int id, n;
	float x, y, z;
	Particle** pp;
	//array of pointers to Particle struct, i.e. Particle**
    
};


//****************	READ	******************

const Event* read( ifstream& file ) {
	
	Event* ev;

	int id1, n1;
	float x1, y1, z1;

	if ( file >> id1 >> x1 >> y1 >> z1 >> n1 )
		ev = new Event;
	
	else return 0;
	
	ev -> id = id1;
	ev -> x = x1;
	ev -> y = y1;
	ev -> z = z1;
	ev -> n = n1;
	
	int c[n1];
	float px[n1], py[n1], pz[n1];

	ev -> pp = new Particle*[n1];
	for ( int i = 0; i < n1; i++ ) {
		ev -> pp[i] = new Particle;
		file >> c[i] >> px[i] >> py[i] >> pz[i];	
		ev -> pp[i] -> c = c[i];
		ev -> pp[i] -> px = px[i];
		ev -> pp[i] -> py = py[i];	
		ev -> pp[i] -> pz = pz[i];
    }

	/* FATTO IN MODO PIU' LUNGO
	Particle** pp = new Particle*[n1];

	for ( int i = 0; i < n1; i++ ) {
		Particle* p = new Particle;
		file >> c[i] >> px[i] >> py[i] >> pz[i];
		p -> c = c[n1];
		p -> px = px[n1];
		p -> py = py[n1];
		p -> pz = pz[n1];
		pp[i] = p;
		}
	*/

	return ev;
    
}


//****************	DUMP	******************

void dump( const Event& ev ) {

  	cout << ev.id << endl;
  	cout << ev.x << ' ' << ev.y << ' ' << ev.z << endl;
  	cout << ev.n << endl;

  	for ( int j = 0; j < ev.n; j++ )
	cout << ev.pp[j] -> c << ' ' << ev.pp[j] -> px << ' ' << ev.pp[j] -> py << ' ' << ev.pp[j] -> pz << ' ' << endl;

	//return;

}


//****************	CLEAR	******************

void clear( const Event* ev ) {

  	for( int i = 0; i < ev->n; i++ ) delete ev->pp[i];
	
	delete[] ev->pp;

  	delete ev;
	
  	//return;

}


//****************	MAIN	******************

int main() {

	const Event* ev;

	ifstream inputfile ( "dataFile.txt" );

	while ( ( ev = read( inputfile ) ) ) {
		if ( !ev ) return 0;
		dump( *ev );
		clear( ev );
	}

	return 0;
}


