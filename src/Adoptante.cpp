#include "Adoptante.h"
#include <iostream>

Adoptante::Adoptante() : id(0), nombre("Sin nombre"), contacto("Sin contacto"), tipoVivienda("Sin especificar") {}

Adoptante::Adoptante(int id, const std::string& nombre, const std::string& contacto,
                     const std::string& tipoVivienda)
    : id(id), nombre(nombre), contacto(contacto), tipoVivienda(tipoVivienda) {}

Adoptante::Adoptante(const Adoptante& otro)
    : id(otro.id), nombre(otro.nombre), contacto(otro.contacto), tipoVivienda(otro.tipoVivienda) {}

Adoptante& Adoptante::operator=(const Adoptante& otro) {
    if (this != &otro) {
        id = otro.id;
        nombre = otro.nombre;
        contacto = otro.contacto;
        tipoVivienda = otro.tipoVivienda;
    }
    return *this;
}

int Adoptante::getId() const { return id; }
std::string Adoptante::getNombre() const { return nombre; }
std::string Adoptante::getContacto() const { return contacto; }
std::string Adoptante::getTipoVivienda() const { return tipoVivienda; }

void Adoptante::mostrarInfo() const {
    std::cout << "ID: " << id
              << " | Nombre: " << nombre
              << " | Contacto: " << contacto
              << " | Vivienda: " << tipoVivienda << '\n';
}
