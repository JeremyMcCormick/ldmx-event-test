#include "Event/SimEvent.h"

ClassImp(event::SimEvent)

namespace event {

SimEvent::SimEvent() :
        simParticles_(new TClonesArray(event::SIM_PARTICLE, event::DEFAULT_COLLECTION_SIZE)),
        recoilSimHits_(new TClonesArray(event::SIM_TRACKER_HIT, event::DEFAULT_COLLECTION_SIZE)) {

    collMap_[RECOIL_SIM_HITS] = recoilSimHits_;
    collMap_[SIM_PARTICLES] = simParticles_;
}

}
