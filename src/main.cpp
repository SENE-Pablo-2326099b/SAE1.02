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

// // PAS SUR DE L'IMPLEMENTATION : 
// // void egal(vector<CandidatesCum> aComparerPourEgalite){

// //     vector<CandidatesCum> equalityCandidates;
// //     for (size_t i = 0 ; i < aComparerPourEgalite.size() ; i++) {
        
// //         equalityCandidates.push_back(aComparerPourEgalite[0]);

// //         if (aComparerPourEgalite[i].getPointCollected() == aComparerPourEgalite[i + 1].getPointCollected()) {
// //             equalityCandidates.push_back(aComparerPourEgalite[i+1]);
// //         }
// //     }
// // }

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
