/* Matteo Bortoletto 1146169
 particleHist_v2
 */

#ifndef MassMean_h
#define MassMean_h

class Event;

class MassMean {

 public:

  MassMean( float min, float max ); // mass range
  ~MassMean();

  bool add( const Event& ev );      // add data from a new event
  void compute();                   // compute mean and rms

  unsigned int nEvents() const;           // return number of accepted events
  double mMean() const;                   // return mean mass
  double mRMS() const;                    // return rms  mass

 private:

  float min; // min mass
  float max; // max mass

  unsigned int accepted; // number of accepted events
  double SumInvMass; // sum of masses
  double SumSquares; // sum of masses square

  double MEAN; // mean mass
  double RMS; // rms  mass

};

#endif

