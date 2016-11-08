#include "Event/SimEvent.h"
#include "Event/SimTrackerHit.h"

#include "TClonesArray.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"

using event::SimEvent;
using event::SimTrackerHit;

int main(int, const char* argv[])  {

    TFile* rootFile = new TFile("ldmx_simple_event_test.root", "RECREATE");
    TTree *tree = new TTree("LDMX_Event", "LDMX event tree");
    SimEvent* event = new SimEvent();
    tree->Branch("Event", "event::SimEvent", &event, 32000, 3);

    TClonesArray* coll = event->getCollection(event::RECOIL_SIM_HITS);
    SimTrackerHit* trackerHit = (SimTrackerHit*) coll->ConstructedAt(0);
    trackerHit->setEdep(2.345);
    trackerHit->setPosition(50., 40., 2000.);
    trackerHit->setID(11111111L);
    trackerHit->setMomentum(1.0, 2.0, 3.0);
    trackerHit->setTime(42.);
    trackerHit->setPathLength(5.678);

    tree->Fill();
    rootFile->Write();
    rootFile->Close();

    return 0;
}
