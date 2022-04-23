#ifndef APPLICATION_H_INCLUDED
#define APPLICATION_H_INCLUDED
#include "Robot.h"
#include "Dispositif.h"
#include "Capteur.h"
#include <vector>

class Application
{
    std::vector <Robot> robots;
    std::vector <Dispositif*> dispositifs;

public:
    Application(){}
    ~Application();
    Application(const Application&) = delete; 
    Application& operator=(const Application&) = delete; 

    //méthodes
    bool ajouter(const Robot& _R){robots.push_back(_R); return true;} //:check id robot
    bool supprimer_robot(int _id){return true;} 
    bool robot_exist(int _id){return true;} 
    void afficher_robots(){}
    bool ajouter(const Dispositif&);
    bool ajouter(const Capteur&);
    bool supprimer_dispositif(int _id_dispositif_a_supprimer);
    std::vector <Dispositif*>::iterator check_id_dispositif(int _id);
    int nb_capteurs_actif();
    void afficher();
};

#endif // APPLICATION_H_INCLUDED
