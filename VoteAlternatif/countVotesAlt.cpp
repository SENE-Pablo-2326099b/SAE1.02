#include <iostream>
#include <vector>
#include "structVoters.hpp"
#include "structCandidates.hpp"
using namespace std;

vector<CandidatesAlt> countVotesAlt(vector<VotersAlt> vectorVoters, vector<CandidatesAlt> vectorCandidates)
{
    // vectorVoters
    for (size_t v = 0; v < vectorVoters.size() ; ++v)
    {
        cout << "\n\n\n\n\n\n\n";
        for(size_t c = 0; c < vectorCandidates.size() ; ++c)
        {
            if (vectorVoters[v].getVote() == vectorCandidates[c].getName())
            {
                vectorCandidates[c].Vote += 1;
            }
        }
    }
    return vectorCandidates;
}
