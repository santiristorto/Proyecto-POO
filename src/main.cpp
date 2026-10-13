#include <iostream>
#include <limits>
#include <string>
#include "Refugio.h"
#include "Perro.h"
#include "Gato.h"
#include "Excepciones.h"
#include "Coleccion.h"

using namespace std;

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int pedirEntero(const string& mensaje) {
    int valor;

    while (true) {
        cout << mensaje;

        if (cin >> valor) {
            limpiarEntrada();
            return valor;
        }

        if (cin.eof()) {
            return 0;   
        }
        cout << "Entrada invalida. Ingrese un numero.\n";
        limpiarEntrada();
    }
}

string pedirTexto(const string& mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

void registrarPerro(Refugio& refugio) {
    int id = pedirEntero("ID: ");
    string nombre = pedirTexto("Nombre: ");
    int edad = pedirEntero("Edad: ");
    string salud = pedirTexto("Estado de salud: ");
    string raza = pedirTexto("Raza: ");
    string tamano = pedirTexto("Tamano: ");

    Perro* perro = new Perro(id, nombre, edad, salud, raza, tamano);
    refugio.registrarAnimal(perro);

    cout << "Perro registrado correctamente.\n";
}

void registrarGato(Refugio& refugio) {
    int id = pedirEntero("ID: ");
    string nombre = pedirTexto("Nombre: ");
    int edad = pedirEntero("Edad: ");
    string salud = pedirTexto("Estado de salud: ");
    string color = pedirTexto("Color de pelaje: ");
    string condicion = pedirTexto("Condicion (Interior/Exterior): ");

    Gato* gato = new Gato(id, nombre, edad, salud, color, condicion);
    refugio.registrarAnimal(gato);

    cout << "Gato registrado correctamente.\n";
}

void registrarAdoptante(Refugio& refugio) {
    int id = pedirEntero("ID: ");
    string nombre = pedirTexto("Nombre: ");
    string contacto = pedirTexto("Contacto: ");
    string vivienda = pedirTexto("Tipo de vivienda: ");

    Adoptante adoptante(id, nombre, contacto, vivienda);
    refugio.registrarAdoptante(adoptante);

    cout << "Adoptante registrado correctamente.\n";
}

void crearSolicitud(Refugio& refugio) {
    int idSolicitud = pedirEntero("ID de solicitud: ");
    int idAdoptante = pedirEntero("ID del adoptante: ");
    int idAnimal = pedirEntero("ID del animal: ");

    refugio.crearSolicitud(idSolicitud, idAdoptante, idAnimal);

    cout << "Solicitud creada. El animal queda no disponible mientras la solicitud esta pendiente.\n";
}

void confirmarSolicitud(Refugio& refugio) {
    int id = pedirEntero("ID de solicitud: ");
    refugio.confirmarSolicitud(id);
    cout << "Solicitud confirmada. Adopcion registrada.\n";
}

void cancelarSolicitud(Refugio& refugio) {
    int id = pedirEntero("ID de solicitud: ");
    refugio.cancelarSolicitud(id);
    cout << "Solicitud cancelada y animal disponible nuevamente.\n";
}

void devolverAnimal(Refugio& refugio) {
    int id = pedirEntero("ID del animal: ");
    refugio.devolverAnimal(id);
    cout << "Animal devuelto al estado disponible.\n";
}

void buscarAnimal(Refugio& refugio) {
    int id = pedirEntero("ID del animal: ");
    refugio.buscarAnimal(id);
}

void probarTemplates() {
    Coleccion<int> numeros;
    Coleccion<int> otrosNumeros;
    Coleccion<string> nombres;

    numeros.agregar(10);
    numeros.agregar(25);
    nombres.agregar("Luna");
    nombres.agregar("Toby");

    cout << "Coleccion<int> tiene " << numeros.cantidad() << " elementos. Primero: " << numeros[0] << '\n';
    cout << "Coleccion<string> tiene " << nombres.cantidad() << " elementos. Primero: " << nombres[0] << '\n';

    cout << "mayor(10, 25) = " << mayor(10, 25) << '\n';
    cout << "mayor(\"Luna\", \"Toby\") = " << mayor(string("Luna"), string("Toby")) << '\n';

    cout << "Instancias de Coleccion<int>: " << Coleccion<int>::getInstancias() << '\n';
    cout << "Instancias de Coleccion<string>: " << Coleccion<string>::getInstancias() << '\n';
}

void mostrarMenu() {
    cout << "\nREFUGIO DE ANIMALES\n";
    cout << "1. Registrar perro\n";
    cout << "2. Registrar gato\n";
    cout << "3. Listar todos los animales\n";
    cout << "4. Listar animales disponibles\n";
    cout << "5. Registrar adoptante\n";
    cout << "6. Buscar animal por ID\n";
    cout << "7. Crear solicitud de adopcion\n";
    cout << "8. Confirmar solicitud\n";
    cout << "9. Cancelar solicitud\n";
    cout << "10. Devolver animal al estado disponible\n";
    cout << "11. Mostrar solicitudes\n";
    cout << "12. Mostrar historial de adopciones\n";
    cout << "13. Mostrar adoptantes\n";
    cout << "14. Demo de templates (Coleccion<T>)\n";
    cout << "0. Salir\n";
}

void ejecutarOpcion(int opcion, Refugio& refugio) {
    switch (opcion) {
        case 1:
            registrarPerro(refugio);
            break;
        case 2:
            registrarGato(refugio);
            break;
        case 3:
            refugio.listarAnimales();
            break;
        case 4:
            refugio.listarDisponibles();
            break;
        case 5:
            registrarAdoptante(refugio);
            break;
        case 6:
            buscarAnimal(refugio);
            break;
        case 7:
            crearSolicitud(refugio);
            break;
        case 8:
            confirmarSolicitud(refugio);
            break;
        case 9:
            cancelarSolicitud(refugio);
            break;
        case 10:
            devolverAnimal(refugio);
            break;
        case 11:
            refugio.mostrarSolicitudes();
            break;
        case 12:
            refugio.mostrarHistorial();
            break;
        case 13:
            refugio.mostrarAdoptantes();
            break;
        case 14:
            probarTemplates();
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion inexistente.\n";
    }
}

void ejecutarMenu(Refugio& refugio) {
    int opcion;

    do {
        mostrarMenu();
        opcion = pedirEntero("Seleccione una opcion: ");
        cout << '\n';

        try {
            ejecutarOpcion(opcion, refugio);
        } catch (const AnimalNoDisponibleException& e) {
            cout << "Error: " << e.what() << '\n';
        } catch (const IdRepetidoException& e) {
            cout << "Error: " << e.what() << '\n';
        } catch (const IndiceInvalidoException& e) {
            cout << "Error: " << e.what() << '\n';
        } catch (const NoEncontradoException& e) {
            cout << "Error: " << e.what() << '\n';
        } catch (const ExcepcionRefugio& e) {
            cout << "Error del refugio: " << e.what() << '\n';
        } catch (const exception& e) {
            cout << "Error estandar: " << e.what() << '\n';
        }
    } while (opcion != 0);
}

int main() {
    Refugio refugio;
    ejecutarMenu(refugio);
    return 0;
}
