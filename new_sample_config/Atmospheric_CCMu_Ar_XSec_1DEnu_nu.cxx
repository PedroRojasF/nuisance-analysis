#include "Atmospheric_CCMu_Ar_XSec_1DEnergy_nu.h"

Atmospheric_CCMu_Ar_XSec_1DEnergy_nu::Atmospheric_CCMu_Ar_XSec_1DEnergy_nu(
    std::string inputfile, FitWeight *rw, 
    std::string type, std::string fakeDataFile) {

  // Setting the name, plot titles, and energy range for the neutrino sample
  fName = "Atmospheric_CCMu_Ar_XSec_1DEnergy_nu";
  fPlotTitles = "; E_{\nu} (GeV); d\sigma/dE_{\nu} (cm^{2}/GeV/nucleon)";
  EnuMin = 0.0;
  EnuMax = 100.0;
  
  // Setup the measurement with the input parameters
  Measurement1D::SetupMeasurement(inputfile, type, rw, fakeDataFile);

  // Load data and covariance matrix from file
  SetDataFromFile(GeneralUtils::GetTopLevelDir() +
      "/data/Atmospheric/CCMu/Ar/atmospheric_numu_xsec_Ar.root",
      "Enu/hResultTot");
  SetCovarFromDataFile(GeneralUtils::GetTopLevelDir() +
      "/data/Atmospheric/CCMu/Ar/atmospheric_numu_xsec_Ar.root",
      "Enu/TotalCovariance", true);

  // Setup the default histograms
  SetupDefaultHist();

  // Calculate the scaling factor for cross-section conversion
  fScaleFactor = (fEventHist->Integral("width") * 1E-38) /
        double(fNEvents) / TotalIntegratedFlux("width");
}

// Fill event variables needed for the measurement
void Atmospheric_CCMu_Ar_XSec_1DEnergy_nu::FillEventVariables(FitEvent *event) {
  // Ensure there is a muon in the event
  if (event->NumFSParticle(13) == 0) return;

  // Get the neutrino energy
  double enu = event->GetNeutrinoIn()->fP.E();
  fXVar = enu;
  return;
}

// Specify the signal definition for the atmospheric sample
bool Atmospheric_CCMu_Ar_XSec_1DEnergy_nu::isSignal(FitEvent *event) {
  return SignalDef::isCCMu(event);
}