#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
}

Party:: Party(){}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(this->getState()==CollectingOffers){
        //update timer
    }
    if(timer==3){
        if(this->mJoinPolicy instance of MandatesJoinPolicy){
            //join by mandates
        }

        this->setState(Joined);
    }
    // TODO: implement this method
}
