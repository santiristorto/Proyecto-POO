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

    refugio.registrarAnimal(new Perro(id, nombre, edad, salud, raza, tamano));
    cout << "Perro registrado correctamente.\n";
}

void registrarGato(Refugio& refugio) {
    int id = pedirEntero("ID: ");
    string nombre = pedirTexto("Nombre: ");
    int edad = pedirEntero("Edad: ");
    string salud = pedirTexto("Estado de salud: ");
    string color = pedirTexto("Color de pelaje: ");
    string condicion = pedirTexto("Condicion (Interior/Exterior): ");

    refugio.registrarAnimal(new Gato(id, nombre, edad, salud, color, condicion));
    cout << "Gato registrado correctamente.\n";
}

void registrarAdoptante(Refugio& refugio) {
    int id = pedirEntero("ID: ");
    string nombre = pedirTexto("Nombre: ");
    string contacto = pedirTexto("Contacto: ");
    string vivienda = pedirTexto("Tipo de vivienda: ");

    refugio.registrarAdoptante(Adoptante(id, nombre, contacto, vivienda));
    cout << "Adoptante registrado correctamente.\n";
}

void gestionarSolicitud(Refugio& refugio) {
    int idSolicitud = pedirEntero("ID de solicitud: ");
    int idAdoptante = pedirEntero("ID del adoptante: ");
    int idAnimal = pedirEntero("ID del animal: ");

    refugio.crearSolicitud(idSolicitud, idAdoptante, idAnimal);
    cout << "Solicitud creada. El animal queda no disponible mientras la solicitud esta pendiente.\n";
}

void menu(Refugio& refugio) {
    int opcion;
    do {
        cout << "\n========== REFUGIO DE ANIMALES ==========\n";
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
        cout << "11. Mostrar solicitudes e historial\n";
        cout << "12. Mostrar adoptantes\n";
        cout << "13. Pruebas de templates\n";
        cout << "0. Salir\n";

        opcion = pedirEntero("Seleccione una opcion: ");
        cout << '\n';

        try {
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
                case 6: {
                    int id = pedirEntero("ID del animal: ");
                    refugio.buscarAnimal(id);
                    break;
                }
                case 7:
                    gestionarSolicitud(refugio);
                    break;
                case 8: {
                    int id = pedirEntero("ID de solicitud: ");
                    refugio.confirmarSolicitud(id);
                    cout << "Solicitud confirmada. Adopcion registrada.\n";
                    break;
                }
                case 9: {
                    int id = pedirEntero("ID de solicitud: ");
                    refugio.cancelarSolicitud(id);
                    cout << "Solicitud cancelada y animal disponible nuevamente.\n";
                    break;
                }
                case 10: {
                    int id = pedirEntero("ID del animal: ");
                    refugio.devolverAnimal(id);
                    cout << "Animal devuelto al estado disponible.\n";
                    break;
                }
                case 11:
                    refugio.mostrarSolicitudes();
                    break;
                case 12:
                    refugio.mostrarAdoptantes();
                    break;
                case 13: {
                    Coleccion<int> numeros;
                    numeros.agregar(10);
                    numeros.agregar(25);
                    Coleccion<string> nombres;
                    nombres.agregar("Luna");
                    nombres.agregar("Toby");
                    cout << "Mayor entre 10 y 25: " << mayor(10, 25) << '\n';
                    cout << "Mayor alfabeticamente entre Luna y Toby: " << mayor(string("Luna"), string("Toby")) << '\n';
                    cout << "Instancias de Coleccion<int>: " << Coleccion<int>::getInstancias() << '\n';
                    cout << "Instancias de Coleccion<string>: " << Coleccion<string>::getInstancias() << '\n';
                    cout << "Acceso con [] al primer numero: " << numeros[0] << '\n';
                    break;
                }
                case 0:
                    cout << "Saliendo del sistema...\n";
                    break;
                default:
                    cout << "Opcion inexistente.\n";
            }
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

    // Prueba sencilla de copia profunda de Refugio.
    Refugio copia(refugio);
    Refugio otraCopia;
    otraCopia = refugio;

    menu(refugio);
    return 0;
}
