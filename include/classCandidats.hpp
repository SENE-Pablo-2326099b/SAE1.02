#include <iostream>
using namespace std;

// class candidats {

// //Attributs
// private:
//     int id;
//     int pointsRecolte;
//     bool gagnée = false;

// //Méthodes
// public:
//     void ajouterPoints();
//     candidats(int id, int pointsRecolte);

// };

struct Candidat
{
    string Name;
    int pointCollected = 0;
    bool Winner;

    void setName()
    {
        cout << "Entrez le nom de ce candidat " << endl;
        cin >> Name;
    }  

    void getName()
    {
        cout << "Le candidat se nomme : " << Name << endl;
    }

};
