#include "Excepciones.h"

using namespace std;

ExcepcionRefugio::ExcepcionRefugio(const string& mensaje)
    : mensaje(mensaje) {}

const char* ExcepcionRefugio::what() const noexcept {
    return mensaje.c_str();
}

IdRepetidoException::IdRepetidoException(const string& mensaje)
    : ExcepcionRefugio(mensaje) {}

IndiceInvalidoException::IndiceInvalidoException(const string& mensaje)
    : ExcepcionRefugio(mensaje) {}

AnimalNoDisponibleException::AnimalNoDisponibleException(const string& mensaje)
    : ExcepcionRefugio(mensaje) {}

NoEncontradoException::NoEncontradoException(const string& mensaje)
    : ExcepcionRefugio(mensaje) {}
