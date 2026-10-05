#include "Perro.h"
#include <iostream>

Perro::Perro() : Animal(), raza("Sin raza"), tamano("Sin especificar") {}

Perro::Perro(int id, const std::string& nombre, int edad, const std::string& estadoSalud,
             const std::string& raza, const std::string& tamano)
    : Animal(id, nombre, edad, estadoSalud), raza(raza), tamano(tamano) {}

Perro::Perro(const Perro& otro) : Animal(otro), raza(otro.raza), tamano(otro.tamano) {}

void Perro::mostrarInfo() const {
    std::cout << "[PERRO] ID: " << id
              << " | Nombre: " << nombre
              << " | Edad: " << edad
              << " | Salud: " << estadoSalud
              << " | Raza: " << raza
              << " | Tamano: " << tamano
              << " | Estado: " << (disponible ? "Disponible" : "No disponible")
              << '\n';
}

Animal* Perro::clonar() const {
    return new Perro(*this);
}
