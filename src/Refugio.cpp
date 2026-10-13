#include "Refugio.h"
#include "Excepciones.h"
#include <iostream>

using namespace std;

Refugio::Refugio()
    : animales(new Animal*[5]), cantidadAnimales(0), capacidadAnimales(5),
      adoptantes(), solicitudes() {}

Refugio::Refugio(const Refugio& otro)
    : animales(nullptr), cantidadAnimales(0), capacidadAnimales(0),
      adoptantes(otro.adoptantes), solicitudes(otro.solicitudes) {
    copiarAnimales(otro);
}

Refugio& Refugio::operator=(const Refugio& otro) {
    if (this != &otro) {
        liberarAnimales();
        copiarAnimales(otro);
        adoptantes = otro.adoptantes;
        solicitudes = otro.solicitudes;
    }
    return *this;
}

Refugio::~Refugio() {
    liberarAnimales();
}

void Refugio::liberarAnimales() {
    for (int i = 0; i < cantidadAnimales; ++i) {
        delete animales[i];
    }
    delete[] animales;
    animales = nullptr;
    cantidadAnimales = 0;
    capacidadAnimales = 0;
}

void Refugio::copiarAnimales(const Refugio& otro) {
    capacidadAnimales = otro.capacidadAnimales;
    cantidadAnimales = otro.cantidadAnimales;
    animales = new Animal*[capacidadAnimales];
    for (int i = 0; i < cantidadAnimales; ++i) {
        animales[i] = otro.animales[i]->clonar();
    }
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

Animal* Refugio::buscarAnimalPtr(int id) const {
    for (int i = 0; i < cantidadAnimales; ++i) {
        if (animales[i]->getId() == id) {
            return animales[i];
        }
    }
    return nullptr;
}

const Adoptante* Refugio::buscarAdoptante(int id) const {
    for (int i = 0; i < adoptantes.cantidad(); ++i) {
        if (adoptantes[i].getId() == id) {
            return &adoptantes[i];
        }
    }
    return nullptr;
}

SolicitudAdopcion* Refugio::buscarSolicitud(int id) {
    for (int i = 0; i < solicitudes.cantidad(); ++i) {
        if (solicitudes[i].getId() == id) {
            return &solicitudes[i];
        }
    }
    return nullptr;
}

bool Refugio::tieneSolicitudPendiente(int idAnimal) const {
    for (int i = 0; i < solicitudes.cantidad(); ++i) {
        if (solicitudes[i].getIdAnimal() == idAnimal && solicitudes[i].estaPendiente()) {
            return true;
        }
    }
    return false;
}

void Refugio::registrarAnimal(Animal* animal) {
    if (animal == nullptr) {
        throw ExcepcionRefugio("No se puede registrar un animal nulo.");
    }

    for (int i = 0; i < cantidadAnimales; ++i) {
        if (*animales[i] == *animal) {
            delete animal;   // el Refugio es el dueno del puntero, asi que lo libera
            throw IdRepetidoException("Ya existe un animal con ese ID.");
        }
    }

    if (cantidadAnimales == capacidadAnimales) {
        redimensionarAnimales();
    }
    animales[cantidadAnimales] = animal;
    ++cantidadAnimales;
}

void Refugio::registrarAdoptante(const Adoptante& adoptante) {
    if (buscarAdoptante(adoptante.getId()) != nullptr) {
        throw IdRepetidoException("Ya existe un adoptante con ese ID.");
    }
    adoptantes.agregar(adoptante);
}

void Refugio::crearSolicitud(int idSolicitud, int idAdoptante, int idAnimal) {
    if (buscarSolicitud(idSolicitud) != nullptr) {
        throw IdRepetidoException("Ya existe una solicitud con ese ID.");
    }
    if (buscarAdoptante(idAdoptante) == nullptr) {
        throw NoEncontradoException("No existe el adoptante indicado.");
    }

    Animal* animal = buscarAnimalPtr(idAnimal);
    if (animal == nullptr) {
        throw NoEncontradoException("No existe el animal indicado.");
    }
    if (!(*animal)) {  
        throw AnimalNoDisponibleException("El animal no esta disponible para una nueva solicitud.");
    }

    solicitudes.agregar(SolicitudAdopcion(idSolicitud, idAdoptante, idAnimal));
    animal->setDisponible(false);   
}

void Refugio::confirmarSolicitud(int idSolicitud) {
    SolicitudAdopcion* solicitud = buscarSolicitud(idSolicitud);
    if (solicitud == nullptr) {
        throw NoEncontradoException("No existe la solicitud indicada.");
    }
    if (!solicitud->estaPendiente()) {
        throw ExcepcionRefugio("La solicitud ya no esta pendiente.");
    }
    solicitud->confirmar();  
}

void Refugio::cancelarSolicitud(int idSolicitud) {
    SolicitudAdopcion* solicitud = buscarSolicitud(idSolicitud);
    if (solicitud == nullptr) {
        throw NoEncontradoException("No existe la solicitud indicada.");
    }
    if (!solicitud->estaPendiente()) {
        throw ExcepcionRefugio("La solicitud ya no esta pendiente.");
    }

    solicitud->cancelar();
    Animal* animal = buscarAnimalPtr(solicitud->getIdAnimal());
    if (animal != nullptr) {
        animal->setDisponible(true);
    }
}

void Refugio::devolverAnimal(int idAnimal) {
    Animal* animal = buscarAnimalPtr(idAnimal);
    if (animal == nullptr) {
        throw NoEncontradoException("No existe el animal indicado.");
    }
    if (animal->estaDisponible()) {
        throw ExcepcionRefugio("El animal ya esta disponible.");
    }
    if (tieneSolicitudPendiente(idAnimal)) {
        throw ExcepcionRefugio("El animal tiene una solicitud pendiente: cancelela primero.");
    }
    animal->setDisponible(true);
}

void Refugio::listarAnimales() const {
    if (cantidadAnimales == 0) {
        cout << "No hay animales registrados.\n";
        return;
    }

    Animal* const* actual = animales;
    Animal* const* fin = animales + cantidadAnimales;

    while (actual < fin) {
        (*actual)->mostrarInfo();
        ++actual;
    }
}

void Refugio::listarDisponibles() const {
    bool hayDisponibles = false;

    for (int i = 0; i < cantidadAnimales; ++i) {
        const Animal& animal = (*this)[i];   
        if (animal.estaDisponible()) {
            animal.mostrarInfo();
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles) {
        cout << "No hay animales disponibles.\n";
    }
}

void Refugio::buscarAnimal(int id) const {
    const Animal* animal = (*this)(id);  

    if (animal == nullptr) {
        throw NoEncontradoException("No existe un animal con ese ID.");
    }
    animal->mostrarInfo();
}

void Refugio::mostrarSolicitudes() const {
    if (solicitudes.cantidad() == 0) {
        cout << "No hay solicitudes registradas.\n";
        return;
    }
    for (int i = 0; i < solicitudes.cantidad(); ++i) {
        solicitudes[i].mostrarInfo();
    }
}

void Refugio::mostrarHistorial() const {
    bool hayAdopciones = false;

    for (int i = 0; i < solicitudes.cantidad(); ++i) {
        const SolicitudAdopcion& s = solicitudes[i];
        if (s.getEstado() != EstadoSolicitud::CONFIRMADA) {
            continue;
        }

        const Animal* animal = (*this)(s.getIdAnimal());
        const Adoptante* adoptante = buscarAdoptante(s.getIdAdoptante());

        cout << "Solicitud " << s.getId() << ": "
             << (animal != nullptr ? animal->getNombre() : "?")
             << " (animal " << s.getIdAnimal() << ") adoptado por "
             << (adoptante != nullptr ? adoptante->getNombre() : "?")
             << " (adoptante " << s.getIdAdoptante() << ")\n";
        hayAdopciones = true;
    }

    if (!hayAdopciones) {
        cout << "Todavia no hay adopciones en el historial.\n";
    }
}

void Refugio::mostrarAdoptantes() const {
    if (adoptantes.cantidad() == 0) {
        cout << "No hay adoptantes registrados.\n";
        return;
    }
    for (int i = 0; i < adoptantes.cantidad(); ++i) {
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

int Refugio::cantidadAnimalesRegistrados() const {
    return cantidadAnimales;
}

int Refugio::cantidadSolicitudesRegistradas() const {
    return solicitudes.cantidad();
}
