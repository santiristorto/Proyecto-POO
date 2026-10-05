#include "Gato.h"
#include <iostream>

Gato::Gato() : Animal(), colorPelaje("Sin especificar"), condicion("Interior") {}

Gato::Gato(int id, const std::string& nombre, int edad, const std::string& estadoSalud,
           const std::string& colorPelaje, const std::string& condicion)
    : Animal(id, nombre, edad, estadoSalud), colorPelaje(colorPelaje), condicion(condicion) {}

Gato::Gato(const Gato& otro) : Animal(otro), colorPelaje(otro.colorPelaje), condicion(otro.condicion) {}

void Gato::mostrarInfo() const {
    std::cout << "[GATO] ID: " << id
              << " | Nombre: " << nombre
              << " | Edad: " << edad
              << " | Salud: " << estadoSalud
              << " | Pelaje: " << colorPelaje
              << " | Condicion: " << condicion
              << " | Estado: " << (disponible ? "Disponible" : "No disponible")
              << '\n';
}

Animal* Gato::clonar() const {
    return new Gato(*this);
}
