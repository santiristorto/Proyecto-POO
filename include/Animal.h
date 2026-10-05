#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    int id;
    std::string nombre;
    int edad;
    std::string estadoSalud;
    bool disponible;

public:
    Animal();
    Animal(int id, const std::string& nombre, int edad, const std::string& estadoSalud);
    Animal(const Animal& otro);
    virtual ~Animal();

    int getId() const;
    std::string getNombre() const;
    int getEdad() const;
    std::string getEstadoSalud() const;
    bool estaDisponible() const;

    void setDisponible(bool disponible);

    bool operator==(const Animal& otro) const;
    bool operator!() const;

    virtual void mostrarInfo() const = 0;
    virtual Animal* clonar() const = 0;
};

#endif
