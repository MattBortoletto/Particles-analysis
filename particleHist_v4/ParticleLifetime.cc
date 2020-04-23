/* Matteo Bortoletto 1146169
 particleHist_v4
 */

#include "ParticleLifetime.h"

#include "Event.h"
#include "AnalysisInfo.h"
#include "AnalysisFactory.h"
#include "MassMean.h"
#include "ProperTime.h"

#include "TH1F.h"
#include "TFile.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#include "util/include/ActiveObserver.h"

using namespace std;


// concrete factory to create a ParticleLifetime analyzer
class ParticleLifetimeFactory: public AnalysisFactory::AbsFactory {
 public:
  // assign "plot" as name for this analyzer and factory
  ParticleLifetimeFactory(): AnalysisFactory::AbsFactory( "pplot" ) {}
  // create a ParticleLifetime when builder is run
  virtual AnalysisSteering* create( const AnalysisInfo* info ) {
    return new ParticleLifetime( info );
  }
};
// create a global ParticleLifetimeFactory, so that it is created
// and registered before main execution start:
// when the AnalysisFactory::create function is run,
// a ParticleLifetimeFactory will be available with name "pplot".
static ParticleLifetimeFactory er;

ParticleLifetime::ParticleLifetime( const AnalysisInfo* info ):
 AnalysisSteering( info ) {
}


ParticleLifetime::~ParticleLifetime() {
}


// function to be called at execution start
void ParticleLifetime::beginJob() {
  pCreate ( "K0", 0.495, 0.500, 10.0, 500.0 );
  pCreate ( "Lambda0", 1.115, 1.116, 10.0, 1000.0);
  return;
}


// function to be called at execution end
void ParticleLifetime::endJob() {

  // save current working area
  TDirectory* currentDir = gDirectory;
  // open histogram file
  TFile* file = new TFile( aInfo->value( "pplot" ).c_str(), "RECREATE" );

  // loop over elements
  int n = pList.size();
  int i;
  for ( i = 0; i < n; ++i ) {
    LifetimeFit* LF = pList[i]->LFit;
    TH1F*     hMean = pList[i]->hMean;
    // compute results
    LF->compute();
    // print number of events
    cout << LF->nEvents() << endl;
    // save 
    hMean->Write();
  }
  
  // close file
  file->Close();
  delete file;
  // restore working area
  currentDir->cd();

  return;
}


// function to be called for each event
void ParticleLifetime::update( const Event& ev ) {
  
  unsigned int n = pList.size();
  unsigned int i;
  double DT = ProperTime::instance()->decayTime();
  for ( i = 0; i < n; ++i ) {
	if( pList[i]->LFit->add( ev ) ) pList[i]->hMean->Fill( DT );
  }
  return;
}

void ParticleLifetime::pCreate( const string& name, float min, float max, float timeMin, float timeMax) {

  // create name for TH1F object
  const string& name1 = "time" + name;
  const char* hName = name1.c_str();

  // create TH1F and statistic objects and store their pointers
  Particle* p = new Particle;
  p-> name = name;
  p->LFit = new LifetimeFit( min, max );
  p->hMean = new TH1F( hName, hName, 100, timeMin, timeMax );
  pList.push_back( p );

  return;
}

