#include <iostream>
#include "Dispositif.h"

using namespace std;


Dispositif::Dispositif()
{
    id = 0;
    energie_consommer = 1;
    position = "";
    id_robot = -1;
}
Dispositif::Dispositif(int id, float _energie_consommer, string _position, int _id_robot)
{
    this->id = id;
    energie_consommer = _energie_consommer;
    position = _position;
    id_robot = _id_robot;
}
void Dispositif::afficher() const
{
    std::cout << "id :" <<id<<std::endl;
    cout << "energie_consommer : " << energie_consommer<<endl;
    cout << "position : " << position<<endl;
    cout << "id_robot : " << id_robot<<endl;
}

Dispositif Dispositif::operator+(float _val)
{
    Dispositif Resultat(id,energie_consommer+_val,position,id_robot);
    return Resultat;
}

Dispositif operator+(float _lhVal, const Dispositif& _rh)
{
    Dispositif Resultat(_rh.id, _rh.energie_consommer+_lhVal,
                        _rh.position, _rh.id_robot);
    return Resultat;
}

Dispositif Dispositif::operator-(float _val)
{
    Dispositif Resultat(id,energie_consommer-_val,position,id_robot);
    return Resultat;
}

bool Dispositif::operator < (const Dispositif& _rh)
{
    return (this->energie_consommer < _rh.getEnergie_consommer());
}
