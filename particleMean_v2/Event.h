/* Matteo Bortoletto 1146169
 particleMean_v2
 */

#ifndef Event_h
#define Event_h

class Event {

 public:

  Event( int n, float x, float y, float z ); // create an event with number "n"
                                             // and coordinates x, y, z
  ~Event();

  // composite object Particle to hold all information for each particle
  // ( x,y,z momentum components and electric charge )
  struct Particle {
    int charge;
    float px, py, pz;
  };
  typedef const Particle* part_ptr;

  // add a particle to the event
  void add( float px, float py, float pz, int charge );

  // get event id.
  int eventNumber() const;
  // get decay point coordinates
  float x() const;
  float y() const;
  float z() const;
  // get number of particles
  int nParticles() const;
  // get particle
  part_ptr particle( unsigned int i ) const;

 private:

  // event-specific informations:
  int id1; // event id
  float x1, y1, z1; // decay point

  // particles: number and array of pointers
  int n;
  Particle** pp;
  //Include an additional const private member,to contain the maximum
  //number of particles (10)
  const int maxN;
  
};

#endif

