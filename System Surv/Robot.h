#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED
#include <string>
#include <vector>
#include<iostream>

class Robot
{
private:
    int id;
    std::string nom_departement;
    std::vector<int> dispositifs_associated;

public:
    Robot();
    Robot(int _id, std::string _nom_departement);
    int getId(){return id;}
    void setId(int _id){id = _id;}
    bool dispositif_exist(int _id_dispositif);
    bool ajouter_dispositif(int _id_dispositif);
    bool supprimer_dispositif(int _id_dispositif);
    void afficher(){std::cout<<"Id Robot:"<<id<<"\n";} //todo
private:
    unsigned int get_index(int _id_dispositif);
    std::vector<int>::iterator get_position(int _id_dispositif);
};


#endif // ROBOT_H_INCLUDED
