#include <iostream>
#include <vector>
using namespace std;
#include "structCandidates.hpp"

vector<CandidatesAlt> createCandidateAlt(vector<CandidatesAlt> VectorCandidates)
{
    //Enregistrement du nombre de candidats que l'on souhaite créer
    // cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << ": ";
    int numberCandidate;
    cin >> numberCandidate;

    //Initialisation d'un vector qui contient les candidats
    // cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    string name;
    //Initialiser le nom des candidats.
    for(int i = 0; i < numberCandidate; ++i)
    {
        // cout << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        cin >> name ;
        VectorCandidates[i].setName(name);
    }
    // for (int i = 0; i < numberCandidate; ++i)
    // {
    //     cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl;
    // }

    return VectorCandidates;
}
