#ifndef REFUGIO_H
#define REFUGIO_H

#include "Animal.h"
#include "Adoptante.h"
#include "SolicitudAdopcion.h"
#include "Coleccion.h"

/*
 * MEMORIA DINAMICA - quien crea, administra y libera:
 *
 *  - Animal: lo CREA quien llama (main hace "new Perro" / "new Gato").
 *            Al llamar registrarAnimal(), el Refugio pasa a ser DUENO del puntero.
 *            El Refugio lo guarda en su arreglo "animales" y lo LIBERA (delete) en
 *            su destructor. Si el ID esta repetido, registrarAnimal lo libera antes de lanzar la excepcion.
 *  - Arreglo animales (Animal**): lo crea y libera el Refugio (new[] / delete[]).
 *  - Adoptantes y solicitudes: viven dentro de Coleccion<T>, que administra su propio
 *            arreglo dinamico y lo libera en su destructor.
 *  - Copiar un Refugio: copia PROFUNDA. Cada animal se duplica con clonar(), asi
 *            cada Refugio tiene sus propios objetos y nunca se hace delete dos veces.
 */
class Refugio {
private:
    Animal** animales;          // catalogo unico de punteros a Animal (Perro o Gato)
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
    Refugio(const Refugio& otro);              // Regla de los Tres: copia
    Refugio& operator=(const Refugio& otro);   // Regla de los Tres: asignacion
    ~Refugio();                                // Regla de los Tres: destructor

    void registrarAnimal(Animal* animal);      // el Refugio se queda con el puntero
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

    // refugio[0]  -> animal por posicion (lanza IndiceInvalidoException)
    Animal& operator[](int posicion);
    const Animal& operator[](int posicion) const;
    // refugio(5)  -> animal por ID (nullptr si no existe)
    Animal* operator()(int id);
    const Animal* operator()(int id) const;

    int cantidadAnimalesRegistrados() const;
    int cantidadSolicitudesRegistradas() const;
};

#endif
