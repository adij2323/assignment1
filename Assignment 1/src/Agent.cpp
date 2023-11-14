#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

Agent:: Agent(){}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    this->mSelectionPolicy.select()// selects a party
    //offer party to join
    // TODO: implement this method
}

vector<int> GetPartiesId() const{
    return this.PartiesId;
}

void addPartyId(const int partyId) {
    this.PartiesId.push_back(partyId);
}

boolean isOffered(const int partyId) const {
    if(std::find(this.PartiesId.begin(), this.PartiesId.end(), partyId) != this.PartiesId.end()) {
        return true;
    } else {
        return false;
    }
}

