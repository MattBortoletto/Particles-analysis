/* Matteo Bortoletto 1146169
 particleDump_v2
 */

#ifndef Event.h
#define Event.h

struct Event {
    
	int id;
	float x, y, z;
	int n;
	Particle** P; 
	//array of pointers to Particle struct, i.e. Particle**
    
};

#endif
