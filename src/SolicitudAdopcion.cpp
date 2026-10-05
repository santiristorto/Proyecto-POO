#include "SolicitudAdopcion.h"
#include <iostream>

SolicitudAdopcion::SolicitudAdopcion()
    : id(0), idAdoptante(0), idAnimal(0), estado(EstadoSolicitud::PENDIENTE) {}

SolicitudAdopcion::SolicitudAdopcion(int id, int idAdoptante, int idAnimal)
    : id(id), idAdoptante(idAdoptante), idAnimal(idAnimal), estado(EstadoSolicitud::PENDIENTE) {}

SolicitudAdopcion::SolicitudAdopcion(const SolicitudAdopcion& otra)
    : id(otra.id), idAdoptante(otra.idAdoptante), idAnimal(otra.idAnimal), estado(otra.estado) {}

SolicitudAdopcion& SolicitudAdopcion::operator=(const SolicitudAdopcion& otra) {
    if (this != &otra) {
        id = otra.id;
        idAdoptante = otra.idAdoptante;
        idAnimal = otra.idAnimal;
        estado = otra.estado;
    }
    return *this;
}

int SolicitudAdopcion::getId() const { return id; }
int SolicitudAdopcion::getIdAdoptante() const { return idAdoptante; }
int SolicitudAdopcion::getIdAnimal() const { return idAnimal; }
EstadoSolicitud SolicitudAdopcion::getEstado() const { return estado; }

void SolicitudAdopcion::confirmar() { estado = EstadoSolicitud::CONFIRMADA; }
void SolicitudAdopcion::cancelar() { estado = EstadoSolicitud::CANCELADA; }
bool SolicitudAdopcion::estaPendiente() const { return estado == EstadoSolicitud::PENDIENTE; }

std::string SolicitudAdopcion::estadoTexto() const {
    switch (estado) {
        case EstadoSolicitud::PENDIENTE: return "Pendiente";
        case EstadoSolicitud::CONFIRMADA: return "Confirmada";
        case EstadoSolicitud::CANCELADA: return "Cancelada";
    }
    return "Desconocido";
}

void SolicitudAdopcion::mostrarInfo() const {
    std::cout << "Solicitud " << id
              << " | Adoptante: " << idAdoptante
              << " | Animal: " << idAnimal
              << " | Estado: " << estadoTexto() << '\n';
}
