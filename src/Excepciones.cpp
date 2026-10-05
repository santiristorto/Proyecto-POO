#include "Excepciones.h"

ExcepcionRefugio::ExcepcionRefugio(const std::string& mensaje) : mensaje(mensaje) {}

const char* ExcepcionRefugio::what() const noexcept {
    return mensaje.c_str();
}

IdRepetidoException::IdRepetidoException(const std::string& mensaje)
    : ExcepcionRefugio(mensaje) {}

IndiceInvalidoException::IndiceInvalidoException(const std::string& mensaje)
    : ExcepcionRefugio(mensaje) {}

AnimalNoDisponibleException::AnimalNoDisponibleException(const std::string& mensaje)
    : ExcepcionRefugio(mensaje) {}

NoEncontradoException::NoEncontradoException(const std::string& mensaje)
    : ExcepcionRefugio(mensaje) {}
