/* Matteo Bortoletto 1146169
 particleHist_v4
 */

#ifndef LifetimeFit_h
#define LifetimeFit_h

class Event;

class LifetimeFit {

 public:

  LifetimeFit( float min, float max ); // mass range
  ~LifetimeFit();

  bool add( const Event& ev );      // add data from a new event
  void compute();                   // compute mean and rms

  unsigned int nEvents() const;     // return number of accepted events
                                

 private:

  float min; // min mass
  float max; // max mass

  unsigned int accepted; // number of accepted events 

};

#endif

