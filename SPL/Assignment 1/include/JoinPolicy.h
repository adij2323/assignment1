#pragma once

class JoinPolicy {
    public:
        virtual bool join(Party& party, int coalitionId) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        bool join(Party& party, int coalitionId) override {
       

    }
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        bool join(Party& party, int coalitionId) override {
            
        }
};