#include <iostream>
#include <vector>
using namespace std;
#include "../include/structVoters.hpp"

vector<VotersAlt> createVotersAlt(vector<VotersAlt>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :";
    int numberVoters;
    cin >> numberVoters;
    cout << endl;
    
    //Initialisation d'un vector qui contient les électeurs
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    VectorVoters.resize(numberVoters);

    return VectorVoters;
}