#ifndef ATMOSPHERIC_CCMU_AR_XSEC_1DENU_NU_H_SEEN
#define ATMOSPHERIC_CCMU_AR_XSEC_1DENU_NU_H_SEEN

#include "Measurement1D.h"
#include "SignalDef.h"

class Atmospheric_CCMu_Ar_XSec_1DEnu_nu : public Measurement1D {
public:
  Atmospheric_CCMu_Ar_XSec_1DEnu_nu(std::string inputfile, 
     FitWeight *rw, std::string type, std::string fakeDataFile);
  virtual ~Atmospheric_CCMu_Ar_XSec_1DEnu_nu() {};

  void FillEventVariables(FitEvent *event);
  bool isSignal(FitEvent *event);

private:
};

#endif
