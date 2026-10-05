#ifndef EXCEPCIONES_H
#define EXCEPCIONES_H

#include <exception>
#include <string>

class ExcepcionRefugio : public std::exception {
private:
    std::string mensaje;
public:
    explicit ExcepcionRefugio(const std::string& mensaje);
    const char* what() const noexcept override;
};

class IdRepetidoException : public ExcepcionRefugio {
public:
    explicit IdRepetidoException(const std::string& mensaje);
};

class IndiceInvalidoException : public ExcepcionRefugio {
public:
    explicit IndiceInvalidoException(const std::string& mensaje);
};

class AnimalNoDisponibleException : public ExcepcionRefugio {
public:
    explicit AnimalNoDisponibleException(const std::string& mensaje);
};

class NoEncontradoException : public ExcepcionRefugio {
public:
    explicit NoEncontradoException(const std::string& mensaje);
};

#endif
