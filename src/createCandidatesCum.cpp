#include <iostream>
#include <vector>
using namespace std;
#include "../include/structCandidates.hpp"


//Fonction qui permet de créer et d'initialiser les candidats.
vector<CandidatesCum>createCandidate(vector<CandidatesCum> VectorCandidates)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer
    bool isGood = false;
    int numberCandidate;
    while (isGood == false) {
        cout << "Veuillez choisir le nombre de candidats que vous souhaitez implémentez :" << endl << "--> ";
        cin >> numberCandidate;
        cin.ignore();
    
        if (cin.fail()) 
        {
            cerr << endl << "Error. Veuillez entrez un nombre valide" << endl;
            cin.clear();
            cin.ignore();
        }
        else 
        {
            isGood = true;
        }
    }

    //Initialsation d'un vector qui contient les candidats
    cout << endl << "Création de " << numberCandidate << " candidats pour le vote ! " << endl;
    VectorCandidates.resize(numberCandidate);

    //Initialiser le nom des candidats.
    
    for(int i = 0; i < numberCandidate ; i++)
    {
        string name;

        cout << endl << "Quelle est le nom du " << i + 1 << " candidat ? " << endl << "--> ";
        getline(cin, name);
        
        if(name.empty() || name == " " || name == "\t" || name == "\n")
        {
            cerr << "Veuillez entrée un nom valide ! " << endl;
            cin.ignore();
            getline(cin , name);
            cin.ignore();
        }
        else 
        {
            VectorCandidates[i].setName(name);
            cout << endl;
        }

    }

    for (int i = 0; i <= numberCandidate - 1; i++)
    {
        cout << "Le candidat numéro " << i + 1 << " se nomme " << VectorCandidates[i].getName() << endl;
    }
    cout << endl;
    return VectorCandidates;
    
}