#ifndef DISPOSITIF_H_INCLUDED
#define DISPOSITIF_H_INCLUDED
#include<string>


class Dispositif
{
    protected:
        int id;
        float energie_consommer; // =0 batterie pleine, =1 batteri 100% consommé
        std::string position;
        int id_robot;
    public:
        Dispositif();
        Dispositif(int , float, std::string, int = 99);
        virtual ~Dispositif(){}
        virtual void afficher()const;
        int getId() const {return id;}
        float getEnergie_consommer() const {return energie_consommer;}
        bool setEnergie_consommer(float _energie_consommer)
        {
             if ( _energie_consommer >= 0 && _energie_consommer <=1 )
             {
                   energie_consommer =_energie_consommer;
                    return true;
             }
            return false;
        }
        Dispositif operator+(float _val);
        Dispositif operator-(float _val);
        bool operator < (const Dispositif&);
        friend Dispositif operator+(float _lh, const Dispositif& _rh);
};

Dispositif operator+(float _lh, const Dispositif& _rh);

#endif // DISPOSITIF_H_INCLUDED
