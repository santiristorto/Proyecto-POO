#include "Animal.h"

using namespace std;

Animal::Animal()
    : id(0), nombre("Sin nombre"), edad(0), estadoSalud("No informado"), disponible(true) {
}

Animal::Animal(int id, const string& nombre, int edad, const string& estadoSalud)
    : id(id), nombre(nombre), edad(edad), estadoSalud(estadoSalud), disponible(true) {
}

Animal::Animal(const Animal& otro)
    : id(otro.id), nombre(otro.nombre), edad(otro.edad),
      estadoSalud(otro.estadoSalud), disponible(otro.disponible) {
}

Animal::~Animal() {
}

int Animal::getId() const { return id; }
string Animal::getNombre() const { return nombre; }
int Animal::getEdad() const { return edad; }
string Animal::getEstadoSalud() const { return estadoSalud; }
bool Animal::estaDisponible() const { return disponible; }

void Animal::setDisponible(bool disponible) {
    this->disponible = disponible;
}

bool Animal::operator==(const Animal& otro) const {
    return id == otro.id;
}

bool Animal::operator!() const {
    return !disponible;
}
