#include "Refugio.h"
#include "Excepciones.h"
#include <iostream>

Refugio::Refugio()
    : animales(new Animal*[5]), cantidadAnimales(0), capacidadAnimales(5),
      adoptantes(new Adoptante[5]), cantidadAdoptantes(0), capacidadAdoptantes(5),
      solicitudes(new SolicitudAdopcion[5]), cantidadSolicitudes(0), capacidadSolicitudes(5) {}

void Refugio::limpiar() {
    for (int i = 0; i < cantidadAnimales; ++i) {
        delete animales[i];
    }
    delete[] animales;
    delete[] adoptantes;
    delete[] solicitudes;

    animales = nullptr;
    adoptantes = nullptr;
    solicitudes = nullptr;
    cantidadAnimales = cantidadAdoptantes = cantidadSolicitudes = 0;
    capacidadAnimales = capacidadAdoptantes = capacidadSolicitudes = 0;
}

void Refugio::copiarDesde(const Refugio& otro) {
    capacidadAnimales = otro.capacidadAnimales;
    capacidadAdoptantes = otro.capacidadAdoptantes;
    capacidadSolicitudes = otro.capacidadSolicitudes;

    cantidadAnimales = otro.cantidadAnimales;
    cantidadAdoptantes = otro.cantidadAdoptantes;
    cantidadSolicitudes = otro.cantidadSolicitudes;

    animales = new Animal*[capacidadAnimales];
    for (int i = 0; i < cantidadAnimales; ++i) {
        animales[i] = otro.animales[i]->clonar();
    }

    adoptantes = new Adoptante[capacidadAdoptantes];
    for (int i = 0; i < cantidadAdoptantes; ++i) {
        adoptantes[i] = otro.adoptantes[i];
    }

    solicitudes = new SolicitudAdopcion[capacidadSolicitudes];
    for (int i = 0; i < cantidadSolicitudes; ++i) {
        solicitudes[i] = otro.solicitudes[i];
    }
}

Refugio::Refugio(const Refugio& otro) : animales(nullptr), adoptantes(nullptr), solicitudes(nullptr) {
    copiarDesde(otro);
}

Refugio& Refugio::operator=(const Refugio& otro) {
    if (this != &otro) {
        limpiar();
        copiarDesde(otro);
    }
    return *this;
}

Refugio::~Refugio() {
    limpiar();
}

void Refugio::redimensionarAnimales() {
    int nuevaCapacidad = capacidadAnimales * 2;
    Animal** nuevos = new Animal*[nuevaCapacidad];
    for (int i = 0; i < cantidadAnimales; ++i) {
        nuevos[i] = animales[i];
    }
    delete[] animales;
    animales = nuevos;
    capacidadAnimales = nuevaCapacidad;
}

void Refugio::redimensionarAdoptantes() {
    int nuevaCapacidad = capacidadAdoptantes * 2;
    Adoptante* nuevos = new Adoptante[nuevaCapacidad];
    for (int i = 0; i < cantidadAdoptantes; ++i) {
        nuevos[i] = adoptantes[i];
    }
    delete[] adoptantes;
    adoptantes = nuevos;
    capacidadAdoptantes = nuevaCapacidad;
}

void Refugio::redimensionarSolicitudes() {
    int nuevaCapacidad = capacidadSolicitudes * 2;
    SolicitudAdopcion* nuevos = new SolicitudAdopcion[nuevaCapacidad];
    for (int i = 0; i < cantidadSolicitudes; ++i) {
        nuevos[i] = solicitudes[i];
    }
    delete[] solicitudes;
    solicitudes = nuevos;
    capacidadSolicitudes = nuevaCapacidad;
}

Animal* Refugio::buscarAnimalPtr(int id) const {
    for (int i = 0; i < cantidadAnimales; ++i) {
        if (animales[i]->getId() == id) return animales[i];
    }
    return nullptr;
}

Adoptante* Refugio::buscarAdoptantePtr(int id) {
    for (int i = 0; i < cantidadAdoptantes; ++i) {
        if (adoptantes[i].getId() == id) return &adoptantes[i];
    }
    return nullptr;
}

SolicitudAdopcion* Refugio::buscarSolicitudPtr(int id) {
    for (int i = 0; i < cantidadSolicitudes; ++i) {
        if (solicitudes[i].getId() == id) return &solicitudes[i];
    }
    return nullptr;
}

void Refugio::registrarAnimal(Animal* animal) {
    if (animal == nullptr) {
        throw ExcepcionRefugio("No se puede registrar un animal nulo.");
    }
    if (buscarAnimalPtr(animal->getId()) != nullptr) {
        delete animal;
        throw IdRepetidoException("Ya existe un animal con ese ID.");
    }
    if (cantidadAnimales == capacidadAnimales) redimensionarAnimales();
    animales[cantidadAnimales++] = animal;
}

void Refugio::registrarAdoptante(const Adoptante& adoptante) {
    if (buscarAdoptantePtr(adoptante.getId()) != nullptr) {
        throw IdRepetidoException("Ya existe un adoptante con ese ID.");
    }
    if (cantidadAdoptantes == capacidadAdoptantes) redimensionarAdoptantes();
    adoptantes[cantidadAdoptantes++] = adoptante;
}

void Refugio::crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal) {
    if (buscarSolicitudPtr(idSolicitud) != nullptr) {
        throw IdRepetidoException("Ya existe una solicitud con ese ID.");
    }
    Adoptante* adoptante = buscarAdoptantePtr(idAdoptante);
    if (adoptante == nullptr) throw NoEncontradoException("No existe el adoptante indicado.");

    Animal* animal = buscarAnimalPtr(idAnimal);
    if (animal == nullptr) throw NoEncontradoException("No existe el animal indicado.");
    if (!animal->estaDisponible()) {
        throw AnimalNoDisponibleException("El animal no esta disponible para una nueva solicitud.");
    }

    if (cantidadSolicitudes == capacidadSolicitudes) redimensionarSolicitudes();
    solicitudes[cantidadSolicitudes++] = SolicitudAdopcion(idSolicitud, idAdoptante, idAnimal);
    animal->setDisponible(false);
}

void Refugio::confirmarSolicitud(int idSolicitud) {
    SolicitudAdopcion* solicitud = buscarSolicitudPtr(idSolicitud);
    if (solicitud == nullptr) throw NoEncontradoException("No existe la solicitud indicada.");
    if (!solicitud->estaPendiente()) throw ExcepcionRefugio("La solicitud ya no esta pendiente.");

    Animal* animal = buscarAnimalPtr(solicitud->getIdAnimal());
    if (animal == nullptr) throw NoEncontradoException("El animal de la solicitud no existe.");

    solicitud->confirmar();
    animal->setDisponible(false);
}

void Refugio::cancelarSolicitud(int idSolicitud) {
    SolicitudAdopcion* solicitud = buscarSolicitudPtr(idSolicitud);
    if (solicitud == nullptr) throw NoEncontradoException("No existe la solicitud indicada.");
    if (!solicitud->estaPendiente()) throw ExcepcionRefugio("La solicitud ya no esta pendiente.");

    Animal* animal = buscarAnimalPtr(solicitud->getIdAnimal());
    if (animal != nullptr) animal->setDisponible(true);
    solicitud->cancelar();
}

void Refugio::devolverAnimal(int idAnimal) {
    Animal* animal = buscarAnimalPtr(idAnimal);
    if (animal == nullptr) throw NoEncontradoException("No existe el animal indicado.");
    animal->setDisponible(true);
}

void Refugio::listarAnimales() const {
    if (cantidadAnimales == 0) {
        std::cout << "No hay animales registrados.\n";
        return;
    }
    for (int i = 0; i < cantidadAnimales; ++i) {
        animales[i]->mostrarInfo();
    }
}

void Refugio::listarDisponibles() const {
    bool hayDisponibles = false;
    for (int i = 0; i < cantidadAnimales; ++i) {
        if (animales[i]->estaDisponible()) {
            animales[i]->mostrarInfo();
            hayDisponibles = true;
        }
    }
    if (!hayDisponibles) std::cout << "No hay animales disponibles.\n";
}

void Refugio::buscarAnimal(int id) const {
    const Animal* animal = (*this)(id);
    if (animal == nullptr) throw NoEncontradoException("No existe un animal con ese ID.");
    animal->mostrarInfo();
}

void Refugio::mostrarSolicitudes() const {
    if (cantidadSolicitudes == 0) {
        std::cout << "No hay solicitudes registradas.\n";
        return;
    }
    for (int i = 0; i < cantidadSolicitudes; ++i) {
        solicitudes[i].mostrarInfo();
    }
}

void Refugio::mostrarAdoptantes() const {
    if (cantidadAdoptantes == 0) {
        std::cout << "No hay adoptantes registrados.\n";
        return;
    }
    for (int i = 0; i < cantidadAdoptantes; ++i) {
        adoptantes[i].mostrarInfo();
    }
}

Animal& Refugio::operator[](int posicion) {
    if (posicion < 0 || posicion >= cantidadAnimales) {
        throw IndiceInvalidoException("Posicion de animal fuera de rango.");
    }
    return *animales[posicion];
}

const Animal& Refugio::operator[](int posicion) const {
    if (posicion < 0 || posicion >= cantidadAnimales) {
        throw IndiceInvalidoException("Posicion de animal fuera de rango.");
    }
    return *animales[posicion];
}

Animal* Refugio::operator()(int id) {
    return buscarAnimalPtr(id);
}

const Animal* Refugio::operator()(int id) const {
    return buscarAnimalPtr(id);
}

int Refugio::cantidadAnimalesRegistrados() const { return cantidadAnimales; }
int Refugio::cantidadSolicitudesRegistradas() const { return cantidadSolicitudes; }
