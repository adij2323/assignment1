#pragma once

class SelectionPolicy {
    protected:
        virtual Party* select(const Party& agentParty, const Graph& graph) const = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy{ 
    public:
         Party* select(const Party& agentParty, const Graph& graph) override {
            int maxMandates=-1;
            for(int neighboorID; graph.get  
                
            }
        
        // Return the selected party's index
    }
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        Party* select(const Party& agentParty, const Graph& graph) override {
            
            // Return the selected party's index
        }
 };