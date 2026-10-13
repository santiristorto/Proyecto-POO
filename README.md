# Sistema de Gestión de un Refugio de Animales

## Trabajo Práctico Integrador – Programación Orientada a Objetos

**Carrera:** Ingeniería Informática
**Universidad:** Universidad Católica de Córdoba
**Materia:** Programación Orientada a Objetos
**Lenguaje:** C++17

---

# 1. Descripción del proyecto

Este proyecto consiste en el desarrollo de un sistema de gestión para un refugio de animales.

El programa permite administrar animales, adoptantes y solicitudes de adopción mediante un menú interactivo ejecutado desde la consola.

El sistema fue desarrollado aplicando los principales conceptos de Programación Orientada a Objetos vistos durante la materia, entre ellos:

* Clases y objetos.
* Encapsulamiento.
* Constructores y destructores.
* Herencia.
* Polimorfismo.
* Clases abstractas.
* Funciones virtuales.
* Composición.
* Punteros.
* Memoria dinámica.
* Copia profunda.
* Regla de Tres.
* Sobrecarga de operadores.
* Templates.
* Excepciones.
* Manejo de errores.

## Objetivos

* Gestionar animales (perros y gatos), adoptantes, solicitudes de adopción e historial de adopciones desde la consola.
* Integrar los contenidos de las Unidades 1 a 8: funciones, punteros, memoria dinámica, clases, sobrecarga de operadores, herencia, polimorfismo, templates y excepciones.
* Escribir código modular y simple, en el que cada función tenga una única responsabilidad.

## ¿Por qué este problema se adapta a la Programación Orientada a Objetos?

El refugio está formado por "cosas" con datos y comportamiento propios: un animal tiene nombre, edad y estado, y sabe mostrarse; un adoptante tiene sus datos; una solicitud sabe confirmarse o cancelarse. Cada una se modela como una clase. Perros y gatos comparten datos comunes pero se muestran distinto, lo que se resuelve con herencia y polimorfismo. Con el paradigma procedural habría que repetir `if (tipo == perro) ... else ...` en todas partes; con POO se agrega un tipo nuevo sin tocar el resto.

---

# 2. Requisitos para ejecutar el proyecto

Para ejecutar el programa es necesario contar con:

* Una computadora con Windows.
* Un compilador de C++ compatible con C++17.
* Git, si se desea descargar el proyecto directamente desde GitHub.
* Visual Studio Code es recomendado para editar y ejecutar el proyecto, aunque no es obligatorio.

El proyecto utiliza únicamente la biblioteca estándar de C++, por lo que **no es necesario instalar bibliotecas externas adicionales**.

---

# 3. Instalación del compilador

## 3.1. Instalar MSYS2

Para Windows se recomienda utilizar **MSYS2**, que permite instalar fácilmente el compilador GCC.

1. Descargar MSYS2 desde su sitio oficial.

2. Instalarlo siguiendo las instrucciones del instalador.

3. Una vez instalado, abrir:

**MSYS2 UCRT64**

No utilizar una terminal MSYS común para compilar este proyecto. Se recomienda utilizar la terminal **UCRT64**.

---

## 3.2. Instalar GCC

Dentro de la terminal **MSYS2 UCRT64**, ejecutar:

```bash
pacman -Syu
```

Si MSYS2 solicita cerrar la terminal, cerrarla, volver a abrir **MSYS2 UCRT64** y ejecutar nuevamente:

```bash
pacman -Syu
```

Luego instalar el compilador GCC con:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

Confirmar la instalación cuando sea solicitado.

---

## 3.3. Agregar GCC al PATH de Windows

Para poder utilizar `g++` directamente desde la terminal de Visual Studio Code, se debe agregar la siguiente carpeta al PATH de Windows:

```text
C:\msys64\ucrt64\bin
```

### Pasos:

1. Abrir el menú Inicio de Windows.
2. Buscar:

```text
Variables de entorno
```

3. Seleccionar **Editar las variables de entorno del sistema**.
4. Presionar **Variables de entorno**.
5. En las variables del usuario, buscar `Path`.
6. Seleccionar `Path` y presionar **Editar**.
7. Presionar **Nuevo**.
8. Agregar:

```text
C:\msys64\ucrt64\bin
```

9. Aceptar todas las ventanas.

Después de modificar el PATH, se recomienda cerrar y volver a abrir Visual Studio Code.

---

# 4. Comprobar que el compilador está instalado

Abrir una terminal nueva en Visual Studio Code y ejecutar:

```bash
g++ --version
```

Si la instalación fue correcta, debería aparecer información sobre la versión de GCC.

Por ejemplo:

```text
g++.exe (...) (Rev3, Built by MSYS2 project) ...
```

Si aparece la versión de GCC, el compilador está correctamente instalado.

---

# 5. Descargar el proyecto

Existen dos formas de obtener el proyecto.

## Opción A — Descargar desde GitHub

Para descargar el proyecto desde GitHub, abrir una terminal y ejecutar:

```bash
git clone URL_DEL_REPOSITORIO
```

Por ejemplo:

```bash
git clone https://github.com/santiristorto/Proyecto-POO.git
```

Luego ingresar a la carpeta:

```bash
cd Proyecto-POO
```

---

## Opción B — Descargar el proyecto como ZIP

También se puede descargar el repositorio desde GitHub utilizando:

**Code → Download ZIP**

Luego:

1. Extraer el archivo ZIP.
2. Abrir la carpeta del proyecto.
3. Verificar que dentro se encuentren las carpetas:

```text
include/
src/
docs/
tests/
```

y archivos como:

```text
Makefile
README.md
```

---

# 6. Abrir el proyecto en Visual Studio Code

Se recomienda abrir la carpeta principal del proyecto, no solamente una de sus subcarpetas.

En Visual Studio Code:

1. Seleccionar File → Open Folder.
2. Seleccionar la carpeta principal del proyecto.
3. Verificar que en el explorador aparezcan las carpetas:

```text
include
src
docs
tests
```

La estructura general del proyecto es:

```text
Proyecto-POO/
│
├── include/
│   ├── Animal.h
│   ├── Perro.h
│   ├── Gato.h
│   ├── Adoptante.h
│   ├── SolicitudAdopcion.h
│   ├── Refugio.h
│   ├── Coleccion.h
│   └── Excepciones.h
│
├── src/
│   ├── Animal.cpp
│   ├── Perro.cpp
│   ├── Gato.cpp
│   ├── Adoptante.cpp
│   ├── SolicitudAdopcion.cpp
│   ├── Refugio.cpp
│   ├── Excepciones.cpp
│   └── main.cpp
│
├── docs/
│   ├── pseudocodigo.md
│   └── diagramas.md
│
├── tests/
│   ├── casos_prueba.txt
│   └── test_refugio.cpp
│
├── Makefile
└── README.md
```

---

# 7. Compilar el proyecto

Existen dos formas de compilar el programa.

## Método recomendado: compilación manual

Abrir una terminal dentro de la carpeta principal del proyecto y ejecutar:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -o refugio.exe
```

Si no aparece ningún mensaje de error, la compilación fue exitosa.

Se generará un archivo:

```text
refugio.exe
```

---

# 8. Ejecutar el programa

Una vez compilado, ejecutar:

```bash
.\refugio.exe
```

El programa se iniciará en la terminal y mostrará el menú principal.

---

# 9. Ejecución utilizando Make

Si se dispone de `make`, también es posible utilizar el `Makefile`.

Para compilar:

```bash
make
```

Luego ejecutar:

```bash
.\refugio.exe
```

Para correr las pruebas automáticas: `make test`. Si se desea eliminar los archivos generados por la compilación:

```bash
make clean
```

### Importante

El uso de `make` es opcional.

Si `make` no está instalado, se puede utilizar directamente el comando:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -o refugio.exe
```

---

# 10. Menú principal

Al iniciar el programa se muestra un menú similar al siguiente:

```text
========== REFUGIO DE ANIMALES ==========

1. Registrar perro
2. Registrar gato
3. Listar animales
4. Listar animales disponibles
5. Registrar adoptante
6. Buscar animal por ID
7. Crear solicitud de adopción
8. Confirmar solicitud
9. Cancelar solicitud
10. Devolver animal a disponible
11. Mostrar solicitudes
12. Mostrar historial de adopciones
13. Mostrar adoptantes
14. Demo de templates (Coleccion<T>)
0. Salir
```

El programa permanece ejecutándose hasta seleccionar la opción:

```text
0. Salir
```

---

# 11. Cómo utilizar cada opción

## 11.1. Registrar perro

Permite incorporar un perro al refugio.

El programa solicita los datos necesarios del animal, como:

* ID.
* Nombre.
* Edad.
* Estado de salud.
* Datos específicos del perro.

El ID permite identificar posteriormente al animal.

---

## 11.2. Registrar gato

Funciona de manera similar a la opción anterior, pero permite registrar un gato.

Se solicitan los datos generales del animal y los datos específicos correspondientes al gato.

---

## 11.3. Listar animales

Muestra los animales registrados actualmente en el refugio.

La información se muestra utilizando polimorfismo, de manera que cada tipo de animal puede mostrar sus propios datos mediante la función correspondiente.

---

## 11.4. Listar animales disponibles

Muestra solamente aquellos animales que actualmente pueden ser adoptados.

Un animal deja de estar disponible apenas se crea una solicitud sobre él (queda reservado) y sigue así si la adopción se confirma. Si la solicitud se cancela, vuelve a estar disponible.

---

## 11.5. Registrar adoptante

Permite registrar una persona que desea adoptar.

El sistema solicita los datos correspondientes al adoptante y lo incorpora al sistema.

---

## 11.6. Buscar animal por ID

Permite buscar un animal utilizando su identificador.

Por ejemplo:

```text
Ingrese el ID del animal: 3
```

Si el animal existe, se muestra su información.

Si no existe, el sistema informa el error correspondiente.

---

## 11.7. Crear solicitud de adopción

Permite iniciar una solicitud de adopción.

Para crear una solicitud se debe seleccionar:

1. Un adoptante registrado.
2. Un animal registrado.
3. El animal debe encontrarse disponible.

La solicitud queda registrada para posteriormente ser confirmada o cancelada.

---

## 11.8. Confirmar solicitud

Permite confirmar una solicitud de adopción existente.

Cuando una solicitud se confirma:

* La solicitud pasa a estado *Confirmada*.
* El animal sigue no disponible (ya fue adoptado).
* La adopción aparece en el historial (opción 12).
* Solo se pueden confirmar solicitudes que estén pendientes.

---

## 11.9. Cancelar solicitud

Permite cancelar una solicitud existente.

La solicitud pasa a estado *Cancelada*, el animal vuelve a estar disponible y no se completa la adopción. Solo se pueden cancelar solicitudes pendientes.

---

## 11.10. Devolver animal a disponible

Permite que un animal ya adoptado vuelva a estar disponible para una nueva adopción (por ejemplo, si el adoptante lo devuelve).

Da error si el animal ya está disponible o si tiene una solicitud pendiente (en ese caso hay que cancelarla primero).

---

## 11.11. Mostrar solicitudes

Muestra las solicitudes de adopción registradas y su información correspondiente.

Permite consultar el estado de las solicitudes realizadas.

---

## 11.12. Mostrar historial

Muestra las adopciones realizadas, es decir, las solicitudes confirmadas, con el nombre del animal y del adoptante.

---

## 11.13. Mostrar adoptantes y demo de templates

La opción 13 lista los adoptantes registrados (sirve para ver sus IDs antes de crear una solicitud). La opción 14 muestra `Coleccion<int>`, `Coleccion<string>`, la función genérica `mayor` y el miembro estático.

---

## 11.14. Salir

La opción:

```text
0
```

finaliza la ejecución del programa.

---

# 12. Ejemplo de uso completo

Una posible secuencia de utilización del sistema es:

### Paso 1 — Registrar un animal

Seleccionar:

```text
1. Registrar perro
```

Ingresar los datos solicitados.

---

### Paso 2 — Registrar un adoptante

Seleccionar:

```text
5. Registrar adoptante
```

Ingresar sus datos.

---

### Paso 3 — Verificar los animales disponibles

Seleccionar:

```text
4. Listar animales disponibles
```

Comprobar que el animal registrado aparezca como disponible.

---

### Paso 4 — Crear una solicitud

Seleccionar:

```text
7. Crear solicitud de adopción
```

Seleccionar el adoptante y el animal correspondiente.

---

### Paso 5 — Confirmar la adopción

Seleccionar:

```text
8. Confirmar solicitud
```

Luego de confirmar, el animal dejará de aparecer entre los animales disponibles.

---

### Paso 6 — Consultar el historial

Seleccionar:

```text
12. Mostrar historial de adopciones
```

De esta manera se puede comprobar que la adopción haya quedado registrada.

---

# 13. Manejo de errores

El sistema contempla diferentes situaciones inválidas mediante excepciones.

Entre ellas:

* Intentar registrar animales con IDs duplicados.
* Intentar acceder a una posición inválida de una colección.
* Buscar animales que no existen.
* Intentar adoptar un animal que no está disponible.
* Intentar realizar operaciones sobre solicitudes inexistentes.
* Ingresar datos que no corresponden con el estado actual del sistema.

Cuando ocurre un error, el programa captura la excepción y muestra un mensaje explicativo en lugar de finalizar inesperadamente.

---

# 14. Conceptos de Programación Orientada a Objetos utilizados

El proyecto integra los contenidos principales de la materia.

### Encapsulamiento

Los atributos de las clases se mantienen protegidos mediante modificadores de acceso y se utilizan métodos públicos para interactuar con los objetos.

### Abstracción

`Animal` representa el concepto general de un animal del refugio.

### Herencia

Las clases:

```text
Perro
Gato
```

heredan de:

```text
Animal
```

### Polimorfismo

Los animales se manejan mediante punteros de tipo:

```cpp
Animal*
```

permitiendo trabajar con diferentes tipos de animales mediante una misma interfaz.

### Clase abstracta

`Animal` contiene funciones virtuales puras y funciona como clase abstracta.

### Composición

El sistema relaciona objetos como:

```text
Refugio
Adoptante
SolicitudAdopcion
```

para representar el funcionamiento del refugio.

### Memoria dinámica

Se utilizan punteros y memoria dinámica mediante:

```cpp
new
delete
```

### Regla de Tres

Las clases que administran memoria dinámica implementan:

* Destructor.
* Constructor de copia.
* Operador de asignación.

### Sobrecarga de operadores

Se utilizan operadores sobrecargados para trabajar con los objetos de manera más natural.

Entre ellos:

```cpp
==
[]
()
!
```

### Templates

Se implementa la clase genérica:

```cpp
Coleccion<T>
```

permitiendo utilizar la misma estructura con diferentes tipos de datos.

### Excepciones

Se utilizan:

```cpp
try
throw
catch
```

junto con excepciones personalizadas para controlar situaciones inválidas.

---

## Memoria dinámica: quién crea, administra y libera

| Memoria | La crea | La administra | La libera |
|---|---|---|---|
| Cada `Perro` / `Gato` | `main.cpp` (`new Perro`, `new Gato`) | `Refugio` (guarda el puntero en su catálogo) | `Refugio` (`delete` en `liberarAnimales`, llamado desde el destructor) |
| Arreglo `Animal**` del catálogo | `Refugio` (`new Animal*[5]`, crece al doble) | `Refugio` | `Refugio` (`delete[]`) |
| Arreglos de adoptantes y solicitudes | `Coleccion<T>` (`new T[]`) | `Coleccion<T>` | destructor de `Coleccion<T>` (`delete[]`) |

Si se registra un animal con un ID repetido, `registrarAnimal` hace `delete` del objeto antes de lanzar la excepción, así no hay fuga.

**¿Qué pasa al copiar un Refugio?** Se hace copia profunda: cada animal se duplica con `clonar()` (cada `Perro`/`Gato` devuelve `new` de sí mismo) y las colecciones se copian con su propio constructor de copia. Así cada refugio es dueño de sus propios objetos y nunca se libera la misma memoria dos veces.

**Aritmética de punteros:** `Refugio::listarAnimales()` recorre el catálogo con `actual` y `fin` (`++actual`) en vez de usar índices.

## Miembro estático en `Coleccion<T>`

`Coleccion<T>` tiene `static int instancias`, que cuenta cuántas colecciones de ese tipo existen. Cada instanciación del template es una clase distinta, por lo que tiene su **propio** contador: `Coleccion<int>::instancias` y `Coleccion<string>::instancias` son independientes. En la opción 14 se crean dos `Coleccion<int>` y una `Coleccion<string>`, y se imprime 2 y 1. (`Animal` también tiene un contador estático, `animalesVivos`, que usan las pruebas para comprobar que no hay fugas.)

## Decisiones de diseño

* **`Animal` es abstracta** (`mostrarInfo()` y `clonar()` son virtuales puras) y tiene destructor virtual, para poder hacer `delete` de un `Perro` a través de un `Animal*`.
* **Un único catálogo de `Animal*`** para perros y gatos; se recorre con polimorfismo.
* **`SolicitudAdopcion` guarda IDs** (de adoptante y animal) en lugar de punteros, así no hay dos dueños del mismo objeto.
* **Estados:** al crear una solicitud el animal queda reservado (no disponible); confirmar lo deja adoptado, cancelar lo libera. Así dos solicitudes no pueden competir por el mismo animal.
* **Operadores con sentido:** `==` compara animales por ID (se usa para detectar duplicados), `!animal` significa "no está disponible" (se usa al crear solicitudes), `refugio[i]` da el animal en una posición y `refugio(id)` lo busca por ID.
* **Excepciones propias** (`IdRepetidoException`, `IndiceInvalidoException`, `AnimalNoDisponibleException`, `NoEncontradoException`) que heredan de `ExcepcionRefugio` → `std::exception`. El menú las atrapa por referencia constante y sigue funcionando.
* `Coleccion<T>` se reutiliza para guardar adoptantes y solicitudes, y así no se repite código de arreglos dinámicos.

---

# 15. Documentación adicional

La carpeta `docs/` contiene documentación complementaria del proyecto.

```text
docs/
├── pseudocodigo.md
├── diagramas.md
└── Diagramas
```

El pseudocódigo describe el funcionamiento de cada operación y los diagramas de flujo (Mermaid) representan el menú principal, el proceso de adopción completo y cada opción del sistema. 

---

# 16. Pruebas

La carpeta `tests/` contiene:

```text
tests/
├── casos_prueba.txt     (casos de prueba para hacer a mano desde el menú)
└── test_refugio.cpp     (pruebas automáticas)
```

## Pruebas automáticas

```bash
make test
```

Compila `tests/test_refugio.cpp` junto con el resto del código (sin `main.cpp`), lo ejecuta y muestra `[OK]` o `[FALLA]` por cada caso. Sin `make`:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude tests/test_refugio.cpp src/Adoptante.cpp src/Animal.cpp src/Excepciones.cpp src/Gato.cpp src/Perro.cpp src/Refugio.cpp src/SolicitudAdopcion.cpp -o test_refugio
./test_refugio
```

Cubren:

* **Casos correctos:** registrar perro y gato, listar, registrar adoptante, buscar, crear/confirmar/cancelar solicitud, devolver animal, historial.
* **Casos incorrectos:** ID de animal, adoptante y solicitud duplicado; animal, adoptante y solicitud inexistente; índice inválido; animal no disponible; devolver un animal ya disponible o con solicitud pendiente; confirmar o cancelar una solicitud que ya no está pendiente.
* **Templates:** `Coleccion<int>`, `Coleccion<string>`, `mayor<T>` y el miembro estático.
* **Memoria:** copia profunda con constructor de copia y `operator=`, autoasignación y liberación.

# 17. Solución de problemas frecuentes

## Error: `g++ no se reconoce como un comando`

Significa que Windows no encuentra el compilador.

Comprobar que GCC esté instalado y que la siguiente carpeta se encuentre en el PATH:

```text
C:\msys64\ucrt64\bin
```

Después de modificar el PATH, cerrar y volver a abrir Visual Studio Code.

Comprobar nuevamente:

```bash
g++ --version
```

---

## Error: `src/*.cpp` no se encuentra

Probablemente la terminal no está ubicada en la carpeta principal del proyecto.

Antes de compilar, comprobar que la estructura incluya:

```text
src/
include/
```

En Visual Studio Code se puede abrir una terminal nueva desde:

**Terminal → New Terminal**

y asegurarse de estar ubicado en la carpeta principal del proyecto.

---

## Error al ejecutar `.\refugio.exe`

Primero comprobar que el programa haya sido compilado correctamente:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -o refugio.exe
```

Si la compilación termina sin errores, ejecutar:

```bash
.\refugio.exe
```

---

# 18. Autores

**Integrantes del grupo:**
* Santiago Ristorto
* Alvaro Mercado

---

# 19. Fecha de entrega

13/10/2026

---

# 20. Tecnologías utilizadas

* C++
* C++17
* GCC / MinGW-w64
* MSYS2 UCRT64
* Visual Studio Code
* Git
* GitHub
