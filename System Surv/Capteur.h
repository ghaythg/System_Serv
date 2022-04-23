#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include<string>
#include "Dispositif.h"

class Capteur : public Dispositif
{
        bool etat;      //=true if actif, =false if not activated
    public:
        Capteur();
        Capteur(int _id, float _energie_consommer,
                std::string _position, int _id_robot, bool _etat);
        bool isActive() const {return etat;}
        void activate() {etat = true;}
        void disactivate () {etat = false;}
        void afficher() const;
};

#endif // CAPTEUR_H_INCLUDED
