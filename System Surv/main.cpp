#include <iostream>
#include <string>
#include <vector>
#include "Dispositif.h"
#include "Capteur.h"
#include "Robot.h"
#include "Application.h"

using namespace std;


int main()
{
    Dispositif Disp(12,0,"1er étage",15);
    Capteur Cap (147,1,"2eme étage",99,true);
    Robot R(58,"Securité bloc principal");

    Application A; //appel de ctor par defaut pour A
    A.ajouter(Disp);
    A.ajouter(Cap);
    A.ajouter(R);

    A.afficher();


    return 0;
}

void testPolymorphisme()
{
    Dispositif Disp(12,0,"1er étage",15);
    Capteur Cap (147,1,"2eme étage",99,true);

    Disp = Cap;
    

    Dispositif *p;
    p = new Dispositif(13,1,"rdc",18);
    p->afficher();
    delete p;

    p = new Capteur(149,0,"2eme étage",99,true);
    p->afficher();
    delete p;
}

void testSurcharge()
{
    Dispositif G(12,0,"1er étage",15);
    Dispositif E;
    E = 0.1 + G;
    E = G + 0.1;
    G.afficher();
    E.afficher();

    if(G < E)
    {
        cout<<"Niveau energie plus faible: ";
        G.afficher();
    }
    else
    {
        cout<<"Niveau energie plus faible: ";
        E.afficher();
    }
}
void testVector()
{
vector <int> tab1;
    tab1.push_back(2);
    tab1.push_back(7);
    tab1.push_back(8);
    tab1.push_back(1);
    tab1.insert(tab1.begin()+2, 9);
    tab1[3] = 47;
    for (unsigned int i = 0; i < tab1.size(); ++i)
    {
        cout<< tab1[i] << "\n";
    }
    tab1.erase(tab1.begin()+3); 

    vector <int> tab2;
    tab2.push_back(45);



    tab1.clear();
}
void testCapteur()
{
    Capteur C1;
    Capteur C2(147,1,"2eme étage",99,true);
    C1.afficher();
    C2.afficher();
}

void testDIspositif()
{
    Dispositif D; 
    Dispositif G(12,0,"1er étage",15);
    if (G.getEnergie_consommer() == 0 )
    {
        cout<<"Batterie pleine !";
        G.setEnergie_consommer( G.getEnergie_consommer() - 0.1 );
    }
}
