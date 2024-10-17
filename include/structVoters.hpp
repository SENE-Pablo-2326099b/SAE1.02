#include <iostream>
using namespace std;

struct VotersCum
{
    int pointsDistributed = 0;
    bool hasVoted = false;

    void SetPoint(int pointsDistributedCin)
    {
        pointsDistributed = pointsDistributedCin;
    }

    const int GetPoint() const 
    {
        return pointsDistributed;
    }



    // void setVotes();
};

struct VotersAlt
{
    bool hasVoted = false;
    string VotedCandidate = '';

    void setVote (string& candidateName)
    {
        hasVoted = true;
        VotedCandidate = candidateName;
    }

    string getVote() const
    {
        return VotedCandidate;
    }
};
