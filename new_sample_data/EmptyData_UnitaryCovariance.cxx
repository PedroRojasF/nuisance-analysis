#include <TFile.h>
#include <TH1D.h>
#include <TH2D.h>

void create_empty_data() {
    TFile *file = new TFile("atmospheric_numu_xsec_empty.root", "RECREATE");

    // Empty histogram
    TH1D *hResultTot = new TH1D("hResultTot", "Empty Data", 1, 0, 1);
    hResultTot->SetBinContent(1,0);
    hResultTot->Write();

    // Empty covariance matrix
    TH2D *covar = new TH2D("TotalCovariance", "TotalCovariance", 1, 0, 1, 1, 0, 1);
    covar->SetBinContent(1,1,1e-6);
    covar->Write();

    file->Close();
}

int main(){
	create_empty_data();
	return 0;
}