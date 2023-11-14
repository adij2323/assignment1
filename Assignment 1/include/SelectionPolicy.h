#pragma once

class SelectionPolicy {
    protected:
        virtual int select(const Party& agentParty, const Graph& graph, Agent& agent) const = 0;
 };

class MandatesSelectionPolicy: public SelectionPolicy { 
    public:
         virtual int select(const Party& agentParty, const Graph& graph,Agent& agent) {
            int maxMandates = -1;
            int selectedIdParty = -1;
            vector<int> neighboors = graph.getNeighbors(agentParty.getId());
            for (int i = 0; i < neighboors.size(); ++i) {
                int neighboorID = neighboors[i];
                const Party& neighboorParty=graph.getParty(neighboorID);
                if(neighboorParty.getMandates()>maxMandates || (neighboorParty.getMandates() == maxMandates && neighboorID < selectedIdParty)){
                    maxMandates=neighboorParty.getMandates();
                    selectedIdParty=neighboorID;
                }
            }
            agent.addPartyId(selectedIdParty);
            return selectedIdParty;    
        }
        
        // Return the selected party's index
    };


class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        virtual int select(const Party& agentParty, const Graph& graph,Agent& agent)  {
            int selectedIdParty=-1;
            int myID=agentParty.getId();
            vector <int> neighboors=graph.getNeighbors(agentParty.getId());
            int maxEdgeWeight=-1;
            for(int i=0;i<neighboors.size();i++){
                int currentEdgeWeight=graph.getEdgeWeight(myID,neighboors[i]);
                if(currentEdgeWeight>maxEdgeWeight ||
                (graph.getEdgeWeight(agentParty.getId(), neighboors[i]) == maxEdgeWeight && neighboors[i] < selectedIdParty)){
                    maxEdgeWeight=currentEdgeWeight;
                    selectedIdParty=neighboors[i];
                }
            }
            agent.addPartyId(selectedIdParty);
            return selectedIdParty;

            // Return the selected party's index
        }
 };