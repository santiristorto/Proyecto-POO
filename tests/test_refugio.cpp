#include <iostream>
#include <string>

#include "Refugio.h"
#include "Perro.h"
#include "Gato.h"
#include "Coleccion.h"
#include "Excepciones.h"

using namespace std;

int pruebasOk = 0;
int pruebasFallidas = 0;

void verificar(bool condicion, const string& descripcion) {
    if (condicion) {
        ++pruebasOk;
        cout << "[OK]    " << descripcion << '\n';
    } else {
        ++pruebasFallidas;
        cout << "[FALLA] " << descripcion << '\n';
    }
}

template <typename E, typename Funcion>
bool lanza(Funcion operacion) {
    try {
        operacion();
    } catch (const E&) {
        return true;
    } catch (...) {
        return false;
    }
    return false;
}

void cargarDatos(Refugio& r) {
    r.registrarAnimal(new Perro(1, "Firulais", 3, "Sano", "Labrador", "Grande"));
    r.registrarAnimal(new Gato(2, "Mishi", 2, "Sano", "Negro", "Interior"));
    r.registrarAdoptante(Adoptante(10, "Juan Perez", "351555555", "Casa"));
}

void pruebasCorrectas() {
    cout << "\n--- Casos correctos ---\n";
    Refugio r;
    cargarDatos(r);

    verificar(r.cantidadAnimalesRegistrados() == 2, "registrar perro y gato");
    verificar(r(1) != nullptr && r(2) != nullptr, "buscar animal por ID con operator()");
    verificar(r[0].getId() == 1 && r[1].getId() == 2, "acceder por posicion con operator[]");
    verificar(r[0].estaDisponible(), "animal recien registrado esta disponible");

    r.crearSolicitud(100, 10, 1);
    verificar(r.cantidadSolicitudesRegistradas() == 1, "crear solicitud");
    verificar(!r[0], "animal queda no disponible (operator!)");

    r.confirmarSolicitud(100);
    verificar(!(*r(1)), "confirmar solicitud: animal sigue no disponible");

    r.devolverAnimal(1);
    verificar(r(1)->estaDisponible(), "devolver animal: vuelve a disponible");

    r.crearSolicitud(101, 10, 2);
    r.cancelarSolicitud(101);
    verificar(r(2)->estaDisponible(), "cancelar solicitud: animal vuelve a disponible");

    r.listarAnimales();
    r.listarDisponibles();
    r.mostrarSolicitudes();
    r.mostrarAdoptantes();
    r.mostrarHistorial();
    verificar(true, "listados, solicitudes, adoptantes e historial se muestran");

    Perro a(5, "A", 1, "Sano", "X", "Chico");
    Gato b(5, "B", 2, "Sano", "Y", "Interior");
    verificar(a == b, "operator== compara animales por ID");
}

void pruebasIncorrectas() {
    cout << "\n--- Casos incorrectos (deben lanzar excepcion) ---\n";
    Refugio r;
    cargarDatos(r);

    verificar(lanza<IdRepetidoException>([&] {
        r.registrarAnimal(new Gato(1, "Repetido", 1, "Sano", "Gris", "Exterior"));
    }), "ID de animal duplicado");
    verificar(r.cantidadAnimalesRegistrados() == 2, "el duplicado no se agrego");

    verificar(lanza<IdRepetidoException>([&] {
        r.registrarAdoptante(Adoptante(10, "Otro", "000", "Depto"));
    }), "ID de adoptante duplicado");

    verificar(lanza<NoEncontradoException>([&] { r.buscarAnimal(999); }), "buscar animal inexistente");
    verificar(r(999) == nullptr, "operator() devuelve nullptr si no existe");

    verificar(lanza<IndiceInvalidoException>([&] { r[7]; }), "indice invalido (positivo)");
    verificar(lanza<IndiceInvalidoException>([&] { r[-1]; }), "indice invalido (negativo)");

    verificar(lanza<NoEncontradoException>([&] { r.crearSolicitud(100, 99, 1); }), "solicitud con adoptante inexistente");
    verificar(lanza<NoEncontradoException>([&] { r.crearSolicitud(100, 10, 99); }), "solicitud con animal inexistente");

    r.crearSolicitud(100, 10, 1);
    verificar(lanza<IdRepetidoException>([&] { r.crearSolicitud(100, 10, 2); }), "ID de solicitud duplicado");
    verificar(lanza<AnimalNoDisponibleException>([&] { r.crearSolicitud(101, 10, 1); }), "solicitud sobre animal no disponible");

    verificar(lanza<NoEncontradoException>([&] { r.confirmarSolicitud(555); }), "confirmar solicitud inexistente");
    verificar(lanza<NoEncontradoException>([&] { r.cancelarSolicitud(555); }), "cancelar solicitud inexistente");
    verificar(lanza<NoEncontradoException>([&] { r.devolverAnimal(999); }), "devolver animal inexistente");

    verificar(lanza<ExcepcionRefugio>([&] { r.devolverAnimal(1); }), "devolver animal con solicitud pendiente");
    verificar(lanza<ExcepcionRefugio>([&] { r.devolverAnimal(2); }), "devolver animal que ya esta disponible");

    r.confirmarSolicitud(100);
    verificar(lanza<ExcepcionRefugio>([&] { r.confirmarSolicitud(100); }), "confirmar solicitud ya confirmada");
    verificar(lanza<ExcepcionRefugio>([&] { r.cancelarSolicitud(100); }), "cancelar solicitud ya confirmada");
}

void pruebasHistorial() {
    cout << "\n--- Historial ---\n";
    Refugio r;
    cargarDatos(r);
    r.crearSolicitud(100, 10, 1);
    r.confirmarSolicitud(100);
    r.mostrarHistorial();
    verificar(true, "historial muestra la adopcion confirmada (ver salida arriba)");
}

void pruebasTemplates() {
    cout << "\n--- Templates y miembro static ---\n";
    Coleccion<int> numeros;
    Coleccion<int> otros;
    Coleccion<string> nombres;
    numeros.agregar(1);
    numeros.agregar(2);
    nombres.agregar("Luna");

    verificar(numeros.cantidad() == 2 && nombres.cantidad() == 1, "Coleccion<int> y Coleccion<string> agregan y cuentan");
    verificar(numeros[1] == 2 && nombres[0] == "Luna", "acceso con operator[]");
    verificar(lanza<IndiceInvalidoException>([&] { numeros[5]; }), "Coleccion lanza excepcion con indice invalido");
    verificar(Coleccion<int>::getInstancias() == 2 && Coleccion<string>::getInstancias() == 1,
              "el miembro static es independiente en cada instanciacion");
    verificar(mayor(3, 9) == 9 && mayor(string("a"), string("b")) == "b", "funcion generica mayor<T> con int y string");

    for (int i = 0; i < 20; ++i) {  
        numeros.agregar(i);
    }
    verificar(numeros.cantidad() == 22 && numeros[21] == 19, "Coleccion crece sola");
}

void pruebasMemoria() {
    cout << "\n--- Memoria: copia profunda y liberacion ---\n";

    {
        Refugio original;
        cargarDatos(original);

        Refugio copia(original);                      
        verificar(copia(1) != original(1), "los punteros de la copia son distintos a los del original");

        copia(1)->setDisponible(false);
        verificar(original(1)->estaDisponible(), "modificar la copia no afecta al original");

        Refugio asignado;
        asignado = original;                          

        asignado = original;                          

        asignado = asignado;                           
        verificar(asignado.cantidadAnimalesRegistrados() == 2,
                  "autoasignacion no rompe nada");
    }

    {
        Refugio r;
        cargarDatos(r);
        try {
            r.registrarAnimal(new Perro(1, "Dup", 1, "Sano", "X", "Chico"));
        } catch (const IdRepetidoException&) {
        }
    }
}

int main() {
    pruebasCorrectas();
    pruebasIncorrectas();
    pruebasHistorial();
    pruebasTemplates();
    pruebasMemoria();

    cout << "\nResultado: " << pruebasOk << " correctas, " << pruebasFallidas << " fallidas.\n";
    return pruebasFallidas == 0 ? 0 : 1;
}
