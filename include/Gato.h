#ifndef GATO_H
#define GATO_H

#include <string>
#include "Animal.h"

class Gato : public Animal {
private:
    std::string colorPelaje;
    std::string condicion;

public:
    Gato();
    Gato(int id, const std::string& nombre, int edad, const std::string& estadoSalud,
         const std::string& colorPelaje, const std::string& condicion);
    Gato(const Gato& otro);

    void mostrarInfo() const override;
    Animal* clonar() const override;
};

#endif
