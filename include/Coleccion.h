#ifndef COLECCION_H
#define COLECCION_H

#include "Excepciones.h"

template <typename T>
class Coleccion {
private:
    T* elementos;
    int cantidadElementos;
    int capacidad;
    static int instancias;

    void redimensionar();

public:
    explicit Coleccion(int capacidadInicial = 5);
    Coleccion(const Coleccion<T>& otra);
    Coleccion<T>& operator=(const Coleccion<T>& otra);
    ~Coleccion();

    void agregar(const T& elemento);
    int cantidad() const;
    T& operator[](int indice);
    const T& operator[](int indice) const;
    static int getInstancias();
};

template <typename T>
int Coleccion<T>::instancias = 0;

template <typename T>
Coleccion<T>::Coleccion(int capacidadInicial)
    : elementos(nullptr), cantidadElementos(0), capacidad(capacidadInicial > 0 ? capacidadInicial : 5) {
    elementos = new T[capacidad];
    ++instancias;
}

template <typename T>
void Coleccion<T>::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    T* nuevos = new T[nuevaCapacidad];
    for (int i = 0; i < cantidadElementos; ++i) {
        nuevos[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevos;
    capacidad = nuevaCapacidad;
}

template <typename T>
Coleccion<T>::Coleccion(const Coleccion<T>& otra)
    : elementos(new T[otra.capacidad]),
      cantidadElementos(otra.cantidadElementos),
      capacidad(otra.capacidad) {
    for (int i = 0; i < cantidadElementos; ++i) {
        elementos[i] = otra.elementos[i];
    }
    ++instancias;
}

template <typename T>
Coleccion<T>& Coleccion<T>::operator=(const Coleccion<T>& otra) {
    if (this != &otra) {
        T* nuevos = new T[otra.capacidad];
        for (int i = 0; i < otra.cantidadElementos; ++i) {
            nuevos[i] = otra.elementos[i];
        }
        delete[] elementos;
        elementos = nuevos;
        cantidadElementos = otra.cantidadElementos;
        capacidad = otra.capacidad;
    }
    return *this;
}

template <typename T>
Coleccion<T>::~Coleccion() {
    delete[] elementos;
    --instancias;
}

template <typename T>
void Coleccion<T>::agregar(const T& elemento) {
    if (cantidadElementos == capacidad) {
        redimensionar();
    }
    elementos[cantidadElementos++] = elemento;
}

template <typename T>
int Coleccion<T>::cantidad() const {
    return cantidadElementos;
}

template <typename T>
T& Coleccion<T>::operator[](int indice) {
    if (indice < 0 || indice >= cantidadElementos) {
        throw IndiceInvalidoException("Indice fuera de rango en Coleccion.");
    }
    return elementos[indice];
}

template <typename T>
const T& Coleccion<T>::operator[](int indice) const {
    if (indice < 0 || indice >= cantidadElementos) {
        throw IndiceInvalidoException("Indice fuera de rango en Coleccion.");
    }
    return elementos[indice];
}

template <typename T>
int Coleccion<T>::getInstancias() {
    return instancias;
}

template <typename T>
const T& mayor(const T& a, const T& b) {
    return (a < b) ? b : a;
}

#endif
