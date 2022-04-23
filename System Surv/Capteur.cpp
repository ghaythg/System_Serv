#include "Capteur.h"
#include <iostream>

using namespace std;

Capteur::Capteur(): Dispositif()
{
    etat = false;
}

Capteur::Capteur(int _id, float _energie_consommer,
                std::string _position, int _id_robot, bool _etat):
                Dispositif(_id,_energie_consommer, _position, _id_robot)
{
    etat = _etat;
}

void Capteur::afficher() const
{
    //Dispositif::afficher();
    std::cout << "id du capteur:" <<id<<std::endl;
    cout << "energie_consommer : " << energie_consommer<<endl;
    cout << "position : " << position<<endl;
    cout << "id_robot : " << id_robot<<endl;
    if (etat)
    {
        cout << "Le capteur est acctif \n";
    }
    else
    {
         cout << "Le capteur est inactif \n";
    }
}
