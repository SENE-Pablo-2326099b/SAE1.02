#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
#include "../include/createVotersAlt.hpp"
#include "../include/createCandidateAlt.hpp"
#include "../include/collectVotesAlt.hpp"
#include "../include/countVotesAlt.hpp"
#include "../include/alternativeVote.hpp"

using namespace std;   


int main()
{
    vector<VotersAlt> VectorVoters;
    vector<CandidatesAlt> VectorCandidates;

    vector <VotersAlt> a = createVotersAlt(VectorVoters);
    vector <CandidatesAlt> b = createCandidateAlt(VectorCandidates);
    a = collectVotesAlt(a, b);
    b = countVotesAlt(a, b);
    CandidatesAlt winner = alternativeVote(a, b);
    cout << winner.getName() << endl;
}