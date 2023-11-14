#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    Agent();

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);

    vector<int> GetPartiesId() const;
    void addPartyId(const int PartyId) const;
    boolean isOffered(const int PartyId) const;

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    vector<int> PartiesId; //which parties the agent has offered to join
    
};
