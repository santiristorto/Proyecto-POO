# Sistema de Gestión de un Refugio de Animales

## Trabajo Práctico Integrador - POO 2026

Proyecto en C++ que modela un refugio de animales y permite registrar perros, gatos, adoptantes y solicitudes de adopción.

## Integrantes

- Integrante 1: ______________________________
- Integrante 2: ______________________________

## Objetivo

Integrar los contenidos trabajados en las Unidades 1 a 8 mediante un sistema de consola modular, con clases, memoria dinámica, sobrecarga de operadores, herencia, polimorfismo, templates y excepciones.

## Estructura

```text
RefugioPOO/
├── include/
│   ├── Animal.h
│   ├── Perro.h
│   ├── Gato.h
│   ├── Adoptante.h
│   ├── SolicitudAdopcion.h
│   ├── Refugio.h
│   ├── Coleccion.h
│   └── Excepciones.h
├── src/
│   ├── Animal.cpp
│   ├── Perro.cpp
│   ├── Gato.cpp
│   ├── Adoptante.cpp
│   ├── SolicitudAdopcion.cpp
│   ├── Refugio.cpp
│   ├── Excepciones.cpp
│   └── main.cpp
├── docs/
│   ├── pseudocodigo.md
│   └── diagramas.md
├── tests/
├── Makefile
└── README.md
```

## Diseño de clases

- `Animal`: clase abstracta base. Contiene los datos comunes y declara `mostrarInfo()` como función virtual pura.
- `Perro`: hereda públicamente de `Animal` y agrega raza y tamaño.
- `Gato`: hereda públicamente de `Animal` y agrega color de pelaje y condición.
- `Adoptante`: representa a una persona que puede solicitar una adopción.
- `SolicitudAdopcion`: relaciona un adoptante con un animal y mantiene el estado de la solicitud.
- `Refugio`: administra las colecciones dinámicas y las operaciones del sistema.
- `Coleccion<T>`: clase genérica dinámica con `agregar()`, `cantidad()` y `operator[]`.
- Excepciones personalizadas: derivan de `std::exception` y permiten mantener el menú funcionando ante errores.

## Contenidos de POO utilizados

### Unidades 1 y 2
- Paradigma orientado a objetos.
- Funciones.
- `if`, `switch`, `for`, `while` y `do-while`.
- Entrada y salida por consola.
- Arrays.

### Unidades 3 y 4
- Punteros.
- Arrays dinámicos.
- `new` y `delete` / `delete[]`.
- Encapsulamiento con `private` y `protected`.
- Constructores por defecto, parametrizados y de copia.
- Destructores.
- Composición entre objetos.

### Unidad 5
- `Animal::operator==` compara por ID.
- `Refugio::operator[]` accede a un animal por posición.
- `Refugio::operator()` busca un animal por ID.
- `Animal::operator!` indica que el animal no está disponible.
- Regla de los Tres en `Refugio` y `Coleccion<T>`.

### Unidad 6
- `Animal` es abstracta.
- `mostrarInfo()` es virtual pura.
- `Perro` y `Gato` utilizan herencia pública y `override`.
- El refugio mantiene un catálogo de `Animal*`.
- El recorrido del catálogo utiliza polimorfismo dinámico.

### Unidad 7
- `Coleccion<T>` es una clase template.
- Se instancia con `int` y `string`.
- Tiene un miembro estático: `instancias`.
- Se utiliza la función genérica `mayor<T>` con `int` y `string`.

### Unidad 8
- `try`, `throw` y múltiples `catch`.
- Excepciones personalizadas derivadas de `std::exception`.
- Los errores de ID repetido, índice inválido, animal no disponible y elementos inexistentes son controlados sin cerrar el menú.

## Gestión de memoria

`Refugio` es dueño de los objetos `Animal` que recibe mediante `registrarAnimal`. Por eso los libera en su destructor.

El catálogo utiliza un array dinámico de punteros `Animal**`. Al copiar un `Refugio`, no se copian solamente las direcciones: cada animal se duplica mediante `clonar()`, realizando una copia profunda.

`Coleccion<T>` administra su propio array dinámico y aplica la Regla de los Tres.

## Compilación

Con `g++` y Make:

```bash
make
./refugio
```

O directamente:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/*.cpp -o refugio
./refugio
```

## Casos de prueba

1. Registrar un perro y un gato.
2. Listar todos los animales.
3. Listar únicamente disponibles.
4. Registrar un adoptante.
5. Crear una solicitud válida.
6. Intentar crear otra solicitud para el mismo animal y verificar la excepción de animal no disponible.
7. Confirmar una solicitud.
8. Cancelar una solicitud pendiente y comprobar que el animal vuelve a estar disponible.
9. Buscar un ID inexistente y comprobar que el menú continúa.
10. Registrar dos elementos con el mismo ID y comprobar la excepción.
11. Probar `operator[]` con una posición inválida.
12. Ejecutar la opción de templates.
13. Comprobar la copia profunda creando copias de `Refugio`; cada copia libera sus propios animales al destruirse.
