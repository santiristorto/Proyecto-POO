#ifndef REFUGIO_H
#define REFUGIO_H

#include "Animal.h"
#include "Adoptante.h"
#include "SolicitudAdopcion.h"
#include "Coleccion.h"

class Refugio {
private:
    Animal** animales;
    int cantidadAnimales;
    int capacidadAnimales;

    Adoptante* adoptantes;
    int cantidadAdoptantes;
    int capacidadAdoptantes;

    SolicitudAdopcion* solicitudes;
    int cantidadSolicitudes;
    int capacidadSolicitudes;

    void redimensionarAnimales();
    void redimensionarAdoptantes();
    void redimensionarSolicitudes();
    void limpiar();
    void copiarDesde(const Refugio& otro);

    Animal* buscarAnimalPtr(int id) const;
    Adoptante* buscarAdoptantePtr(int id);
    SolicitudAdopcion* buscarSolicitudPtr(int id);

public:
    Refugio();
    Refugio(const Refugio& otro);
    Refugio& operator=(const Refugio& otro);
    ~Refugio();

    void registrarAnimal(Animal* animal);
    void registrarAdoptante(const Adoptante& adoptante);
    void crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal);
    void confirmarSolicitud(int idSolicitud);
    void cancelarSolicitud(int idSolicitud);
    void devolverAnimal(int idAnimal);

    void listarAnimales() const;
    void listarDisponibles() const;
    void buscarAnimal(int id) const;
    void mostrarSolicitudes() const;
    void mostrarAdoptantes() const;

    Animal& operator[](int posicion);
    const Animal& operator[](int posicion) const;
    Animal* operator()(int id);
    const Animal* operator()(int id) const;

    int cantidadAnimalesRegistrados() const;
    int cantidadSolicitudesRegistradas() const;
};

// Funcion generica solicitada por la consigna.
template <typename T>
const T& mayor(const T& a, const T& b) {
    return (a < b) ? b : a;
}

#endif
