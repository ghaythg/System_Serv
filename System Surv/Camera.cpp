#include "Camera.h"
#include<iostream>

using namespace std;

Camera::Camera(): Dispositif(), resolution(1024), marque("NA")
{

}



Camera::Camera(int _id, float _energie_consommer, std::string _position, int _id_robot,
                unsigned int _resolution, string _marque):
                Dispositif(_id,_energie_consommer, _position, _id_robot),
                resolution(_resolution), marque(_marque)
{}

Camera::~Camera()
{}

void Camera::afficher() const
{
    cout << "Camera : \n";
    Dispositif::afficher();
    cout << "marque : " << marque<<"\n";
    cout << "resolution : " << resolution<<endl;

}
