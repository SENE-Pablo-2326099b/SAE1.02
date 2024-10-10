#include <iostream>
using namespace std;

class candidats {

//Attributs
private:
    int id;
    int pointsRecolte;
    bool gagnée = false;

//Méthodes
public:
    void ajouterPoints();
    candidats(int id, int pointsRecolte);

};