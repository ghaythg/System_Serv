#include "Robot.h"
using namespace std;
Robot::Robot(): id(0), nom_departement("Ops")
{
   
}

Robot::Robot(int _id, std::string _nom_departement):id(_id), nom_departement(_nom_departement)
{ }

bool Robot::dispositif_exist(int _id_dispositif)
{
    for(unsigned int i = 0; i < dispositifs_associated.size(); ++i)
    {
        if(dispositifs_associated[i] == _id_dispositif) {return true;}
    }
    return false;
}

bool Robot::ajouter_dispositif(int _id_dispositif)
{
    if (dispositif_exist(_id_dispositif) == true ) {return false;}
    dispositifs_associated.push_back(_id_dispositif);
    return true;
}

bool Robot::supprimer_dispositif(int _id_dispositif)
{
 
   vector<int>::iterator it = get_position(_id_dispositif);
   if (it == dispositifs_associated.end()) {return false;}
   dispositifs_associated.erase(it);
   return true;
}

unsigned int Robot::get_index(int _id_dispositif)
{
    for(unsigned int i = 0; i < dispositifs_associated.size(); ++i)
    {
        if(dispositifs_associated[i] == _id_dispositif) {return i;}
    }
    return 0;
}

vector<int>::iterator Robot::get_position(int _id_dispositif)
{
    vector<int>::iterator it;
    for(it = dispositifs_associated.begin();
        it != dispositifs_associated.end();
        it++)
    {
        if(*it == _id_dispositif) {return it;}
    }
    return dispositifs_associated.end();
}
