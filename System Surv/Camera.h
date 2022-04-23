#ifndef CAMERA_H
#define CAMERA_H

#include "Dispositif.h"
#include <string>


class Camera : public Dispositif
{
    private:
        unsigned int resolution;
        std::string marque;
    public:
        Camera();
        Camera(int _id, float _energie_consommer, std::string _position, int _id_robot,
                unsigned int _resolution, std::string _marque);
        ~Camera();

        unsigned int get_resolution() { return resolution; }
        void set_resolution(unsigned int val) { resolution = val; }
        std::string get_marque() { return marque; }
        void set_marque(std::string val) { marque = val; }

        void afficher() const;
};

#endif // CAMERA_H
