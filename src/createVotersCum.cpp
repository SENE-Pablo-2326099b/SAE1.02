#include <iostream>
#include <vector>
using namespace std;
#include "../include/structVoters.hpp"


vector<VotersCum> createVoters(vector<VotersCum>VectorVoters)
{
    //Enregistrement du nombre d'électeurs que l'on souhaite créer.
    bool isGood = false;
    int numberVoters;
    //Condition pour verifier si l'entrée utilisateur est correct
    while (isGood == false) 
    {
        cout << "Veuillez choisir le nombre de d'électeurs que vous souhaitez implémentez :" << endl << "--> ";
        cin >> numberVoters;
        cin.ignore();
        
        if (cin.fail()) 
        {   
            cerr << endl << "Error. Veuillez entrez un nombre valide" << endl;
            cin.clear();
            cin.ignore();
        }
        else {
            isGood = true;
        }     
    }
    isGood = false;
    cout << endl; 

    //Initialsation d'un vector qui contient les électeurs
    cout << "Création de " << numberVoters << " électeurs pour le vote ! " << endl << endl;
    VectorVoters.resize(numberVoters);

    //Attribution du nom des electeurs
    for(int i = 0; i < numberVoters ; i++)
    {
        string name;

        cout << endl << "Quelle est le nom du " << i + 1 << " électeur ? " << endl << "--> ";
        getline(cin, name);

        if( name == " " || name == "\t" || name == "\n")
        {
            cerr << "Veuillez entrée un nom valide ! " << endl;
            cin.ignore();
            getline(cin , name);
            cin.ignore();
        }
        else 
        {
            VectorVoters[i].SetName(name);
            cout << endl;
        }
    }

    //Attribution des points au électeurs
    int pointsDistributed = 0;
    while (isGood == false) 
    {
        // Condition qui verifie que l'entrée utilisateur est correct.
        cout << "Choisisez le nombre de points que chaque électeurs détient :" << endl << "--> ";
        cin >> pointsDistributed;

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

    for(int i = 0; i <= numberVoters - 1; i++)
    {
        VectorVoters[i].SetPoint(pointsDistributed);
    }

    cout << endl;

    for (int i = 0; i <= numberVoters - 1; i++)
    {
        cout << "L'électeur " << VectorVoters[i].GetName() << " à " << VectorVoters[i].GetPoint() << " points" << endl;
    }
    cout << endl;
        
    return VectorVoters;
}