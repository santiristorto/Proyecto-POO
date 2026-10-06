#include "Gato.h"
#include <iostream>

using namespace std;

Gato::Gato()
    : Animal(), colorPelaje("Sin especificar"), condicion("Interior") {}

Gato::Gato(int id, const string& nombre, int edad, const string& estadoSalud,
           const string& colorPelaje, const string& condicion)
    : Animal(id, nombre, edad, estadoSalud),
      colorPelaje(colorPelaje), condicion(condicion) {}

Gato::Gato(const Gato& otro)
    : Animal(otro), colorPelaje(otro.colorPelaje), condicion(otro.condicion) {}

void Gato::mostrarInfo() const {
    cout << "[GATO] ID: " << id
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
