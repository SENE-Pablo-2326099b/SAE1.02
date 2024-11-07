#ifndef CREATEVOTERSALT_HPP
#define CREATEVOTERSALT_HPP

#include <iostream>
using namespace std;

struct VotersAlt
{
    string VotedCandidate = "";

    void setVote (string& candidateName)
    {
        VotedCandidate = candidateName;
    }

    string getVote() const
    {
        return VotedCandidate;
    }
};

#endif
