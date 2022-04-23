#include "Application.h"
#include <typeinfo>
using namespace std;


bool Application::ajouter(const Dispositif& A)
{
    vector <Dispositif*>::iterator it = check_id_dispositif(A.getId());
    if(it != dispositifs.end()) {return false;}
    Dispositif* p = new Dispositif(A); 
    dispositifs.push_back(p);
    return true;
}

bool Application::ajouter(const Capteur& A)
{
    vector <Dispositif*>::iterator it = check_id_dispositif(A.getId());
    if(it != dispositifs.end()) {return false;}
    Dispositif* p = new Capteur(A); 
    dispositifs.push_back(p);
    return true;
}

vector <Dispositif*>::iterator Application::check_id_dispositif(int _id)
{
    vector <Dispositif*>::iterator it = dispositifs.begin();
    for(; it!=dispositifs.end();it++)
    {
        if((**it).getId() == _id ) {return it;}
    }
    return dispositifs.end();
}

void Application::afficher()
{
    cout<<"Liste des dispositifs: \n";
    for(vector <Dispositif*>::iterator it = dispositifs.begin();
        it!=dispositifs.end();it++)
    {
        (**it).afficher();
    }

    cout<<"Liste des Robots: \n";
    for(vector <Robot>::iterator it_robot = robots.begin();
        it_robot != robots.end(); it_robot++)
    {
        it_robot->afficher(); //ou (*it_robot).afficher();
    }
}

Application::~Application()
{
    for(vector <Dispositif*>::iterator it = dispositifs.begin();
        it!=dispositifs.end();it++)
    {
        delete (*it);
    }
}

bool Application::supprimer_dispositif(int _id_dispositif_a_supprimer)
{
    vector <Dispositif*>::iterator it = check_id_dispositif(_id_dispositif_a_supprimer);
    if (it == dispositifs.end()) { return false;}
    delete (*it);
    dispositifs.erase(it);
    return true;
}

int Application::nb_capteurs_actif()
{
    int total = 0;
    Capteur *p;
    for(vector <Dispositif*>::iterator it = dispositifs.begin();
        it!=dispositifs.end();it++)
    {
        if(typeid(**it) == typeid(Capteur))
        {
            p = (Capteur*) (*it);
            if(p->isActive())
            {
                total++;
            }
        }
    }
    return total;
}
