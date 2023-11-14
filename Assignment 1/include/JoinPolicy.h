#pragma once
using std::string;
using std::vector;

class Simulation;
class JoinPolicy {
    protected:
        virtual int join(Simulation& s, int partyId) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        // this function added the party to the biggest coalition by mandates
        virtual int join(Simulation& s, int partyId)  {
            int maxMandates = 0;
            int coalitionIndex = -1;
            vector<vector<int>> coalitions = s.getPartiesByCoalitions();

            for(Agent agent: s.getAgents()){
                if(agent.isOffered(partyId)){
                    int agentPos=getAgentCoalitionPosition(coalitions,agent.getPartyId());
                    vector<int> agentCoalition=coalitions[agentPos];
                    int numOfmandates = sumOfMandates(agentCoalition, s);
                    if(numOfmandates > maxMandates) {
                        maxMandates = numOfmandates;
                        coalitionIndex = agentPos;
                    }
                }
            }

            coalitions[coalitionIndex].push_back(partyId);
            s.getParty(partyId).setState(Joined);
            return coalitions[coalitionIndex][0]; //return ID of agent who we are joining to
        }

       static int getAgentCoalitionPosition(vector<vector<int>> coalition,int partyAgentId){
            for(int i=0;i<coalition.size();i++){
                if(coalition[i][0]==partyAgentId){
                    return i; //return the coalition of the agent 
                }
            }
        }

    private:
        int sumOfMandates(vector<int> coalition, Simulation& s) {
            int sum = 0;
            for(size_t i = 0; i < coalition.size(); i++) {
                sum += s.getParty(coalition[i]).getMandates();
            }
            return sum;
        }
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        virtual int join(Simulation& s, int partyId) {
            
        }
                    //return ID of agent who we are joining to

};