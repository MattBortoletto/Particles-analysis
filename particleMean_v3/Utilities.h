/* Matteo Bortoletto 1146169
 particleMean_v3
 */

#ifndef Utilities_h
#define Utilities_h

class Utilities {

public:
  Utilities();
  ~Utilities();
  
  static double energy( double PtotX, double PtotY, double PtotZ, double invMass );
  static double invMass( double PtotX, double PtotY, double PtotZ, double energy );
  
};

#endif 
