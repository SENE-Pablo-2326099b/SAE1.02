#include <iostream>
#include <vector>
using namespace std;
#include "structCandidates.hpp"

vector<CandidatesAlt> createCandidateAlt(vector<CandidatesAlt> VectorCandidates)
{
    //Enregistrement du nombre de candidats que l'on souhaite créer
    // cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << ": ";
    size_t numberCandidate;
    cin >> numberCandidate;

    //Initialisation d'un vector qui contient les candidats
    // cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    //Initialiser le nom des candidats.
    for(size_t i = 0; i < numberCandidate; ++i)
    {
        string name;
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
