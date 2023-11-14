#pragma once
#include <string>

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    Party();

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;

    int getId() const;

    vector<int> GetAgentsId() const;
    void addAgentId(const int agnetId) const;
    boolean isOffered(const int agnetId) const;

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> agentsId; // vector of all the agents id who offered this party to join their coalition
};
