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

    Coleccion<Adoptante> adoptantes;
    Coleccion<SolicitudAdopcion> solicitudes;

    void redimensionarAnimales();
    void liberarAnimales();
    void copiarAnimales(const Refugio& otro);

    Animal* buscarAnimalPtr(int id) const;
    const Adoptante* buscarAdoptante(int id) const;
    SolicitudAdopcion* buscarSolicitud(int id);
    bool tieneSolicitudPendiente(int idAnimal) const;

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
    void mostrarHistorial() const;
    void mostrarAdoptantes() const;

    Animal& operator[](int posicion);
    const Animal& operator[](int posicion) const;
    Animal* operator()(int id);
    const Animal* operator()(int id) const;

    int cantidadAnimalesRegistrados() const;
    int cantidadSolicitudesRegistradas() const;
};

#endif
