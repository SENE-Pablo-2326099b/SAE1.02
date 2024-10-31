#include <iostream>
#include <vector>
using namespace std;
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"

vector<CandidatesCum>collectVotes(vector<VotersCum> vectorVoters, vector<CandidatesCum> vectorCandidates);

string isWinnerName(vector<CandidatesCum> vectorCandidatesWin);