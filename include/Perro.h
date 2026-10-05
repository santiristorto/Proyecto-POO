#ifndef PERRO_H
#define PERRO_H

#include "Animal.h"

class Perro : public Animal {
private:
    std::string raza;
    std::string tamano;

public:
    Perro();
    Perro(int id, const std::string& nombre, int edad, const std::string& estadoSalud,
          const std::string& raza, const std::string& tamano);
    Perro(const Perro& otro);

    void mostrarInfo() const override;
    Animal* clonar() const override;
};

#endif
