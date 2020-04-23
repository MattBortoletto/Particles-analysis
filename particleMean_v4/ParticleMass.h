/* Matteo Bortoletto 1146169
 particleMean_v4
 */

#ifndef ParticleMass_h
#define ParticleMass_h

#include "AnalysisSteering.h"
#include <vector>

class Event;
class MassMean;

class ParticleMass: public AnalysisSteering {

 public:

  ParticleMass();
  virtual ~ParticleMass();

  //create and store the pointers to 2 "MassMean" objects for the 2 decay modes
  virtual void beginJob();
  //loop over the "MassMean" objects and for each one compute mean and rms masses and print result
  virtual void endJob();
  //loop over the "MassMean" objects and for each one call the "add" function
  virtual void process( const Event& ev );

 private:

  // dummy copy constructor and assignment to prevent unadvertent copy
  ParticleMass           ( const MassMean& x );
  ParticleMass& operator=( const MassMean& x );

  //vector of pointers to MassMean objects
  std::vector<MassMean*> pList;
  
};

#endif
