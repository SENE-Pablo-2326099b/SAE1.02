#include <cstddef>
#include <iostream>
#include <vector>
#include "../include/structVoters.hpp"
#include "../include/structCandidates.hpp"
using namespace std;   

int numberCandidate;




vector<Candidates> createCandidate(vector<Candidates> VectorCandidates)
{
    cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl;
    cin >> numberCandidate;
    cout << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    for(int i = 0; i <= numberCandidate - 1; i++)
    {   
        string name;
        cout << "Quelle est le nom du " << i + 1 << " candidat ? " << endl;
        cin >> name ;
        VectorCandidates[i].setName(name);
        cout << endl << endl;
    }
    for (int i = 0; i < numberCandidate; i++)
    {
        cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl;
    }
    return VectorCandidates;
}



vector<Voters> createVoters(vector<Voters>VectorVoters)
{
    cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl;
    int numberVoters;
    cin >> numberVoters;
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl;
    VectorVoters.resize(numberVoters);

    cout << "Choisisez le nombre de points que chaque électeurs détient : " << endl;
    int pointsDistributed = 0;
    cin >> pointsDistributed;
    for(int i = 0; i <= numberVoters - 1; i++)
    {
        VectorVoters[i].SetPoint(pointsDistributed);
    }
    for (int i = 0; i<= numberVoters - 1; i++)
    {
        cout << "L'électeur " << i << " à " << VectorVoters[i].GetPoint() << " points" << endl;
    }
    return VectorVoters;
}








//A finir car trop mal a la tete la mdr
//Mais en gros faut juste que je trouve le moyen de faire voter chaque electeur pour chaque candidat 
void collectVotes(vector<Voters> vectorVoters, vector<Candidates> vectorCandidates)
{
    int pointCollected;
        // vectorVoters 
    for (size_t v = 0; v < vectorVoters.size(); v++)
    {
        //vectorCandidates
        for(size_t c = 0; c < vectorCandidates.size(); c++)
        {
        
            cout << "Voici le candidat " << endl << vectorCandidates[c].getName() << endl;
            cout << "Electeurs numéro " << v << " , veuilliez choisir combien de points vous lui mettez" << endl;
            
            cin >> pointCollected;
            vectorCandidates[c].setPointCollected(pointCollected);
        }
    }
}
    



int main()
{
    vector<Voters> VectorVoters;
    vector<Candidates> VectorCandidates;

    vector <Voters> a = createVoters(VectorVoters);
    vector <Candidates> b = createCandidate(VectorCandidates);
    collectVotes(a, b);
    return 0;
}

