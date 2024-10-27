#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
#include "../include/CreateVotersCum.hpp"
#include "../include/CreateCandidatesCum.hpp"
#include "../include/votesManagement.hpp"

using namespace std;   


int main()
{
    //Mes vecteurs électeur et candidats
    vector<VotersCum> VectorVoters;
    vector<CandidatesCum> VectorCandidates;

    //Appel des fonctions pour manipuler mes vecteurs
    vector <VotersCum> a = createVoters(VectorVoters);
    vector <CandidatesCum> b = createCandidate(VectorCandidates);
    vector<CandidatesCum> win = collectVotes(a, b);
    isWinnerName(win);
    return 0;
}
