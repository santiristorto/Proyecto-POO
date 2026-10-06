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

Si el proyecto se encuentra en GitHub, abrir una terminal y ejecutar:

```bash
git clone URL_DEL_REPOSITORIO
```

Por ejemplo:

```bash
git clone https://github.com/USUARIO/REPOSITORIO.git
```

Luego ingresar a la carpeta:

```bash
cd REPOSITORIO
```

> Reemplazar `URL_DEL_REPOSITORIO` y `REPOSITORIO` por los datos correspondientes al repositorio.

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
RefugioPOO/
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
│   └── casos_prueba.txt
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

Si se desea eliminar los archivos generados por la compilación:

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
===== SISTEMA DE GESTIÓN DEL REFUGIO =====

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
12. Mostrar historial
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

Un animal deja de estar disponible cuando su adopción es confirmada.

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

* La solicitud cambia a su estado correspondiente.
* El animal deja de estar disponible.
* La operación queda registrada en el historial.

---

## 11.9. Cancelar solicitud

Permite cancelar una solicitud existente.

La solicitud queda registrada con el estado correspondiente y no se completa la adopción.

---

## 11.10. Devolver animal a disponible

Permite cambiar nuevamente el estado de disponibilidad de un animal.

Esta opción puede utilizarse cuando un animal debe volver a estar disponible para una nueva adopción.

---

## 11.11. Mostrar solicitudes

Muestra las solicitudes de adopción registradas y su información correspondiente.

Permite consultar el estado de las solicitudes realizadas.

---

## 11.12. Mostrar historial

Muestra el historial de operaciones de adopción registradas por el sistema.

---

## 11.13. Salir

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
12. Mostrar historial
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

# 15. Documentación adicional

La carpeta `docs/` contiene documentación complementaria del proyecto.

```text
docs/
├── pseudocodigo.md
└── diagramas.md
```

El pseudocódigo describe el funcionamiento general del sistema y los diagramas representan los principales procesos del programa.

---

# 16. Pruebas

La carpeta `tests/` contiene los casos de prueba utilizados para comprobar el funcionamiento del sistema.

```text
tests/
└── casos_prueba.txt
```

Las pruebas contemplan tanto situaciones correctas como situaciones de error.

Se incluyen pruebas relacionadas con:

* Registro de animales.
* Búsqueda.
* Disponibilidad.
* Solicitudes de adopción.
* IDs duplicados.
* Índices inválidos.
* Manejo de excepciones.
* Copia de objetos.
* Liberación de memoria.

---

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

## Error: `make no se reconoce`

No es un problema del proyecto.

`make` es opcional.

Se puede compilar directamente utilizando:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -o refugio.exe
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

# 18. Compilación rápida

Para una persona que ya tiene todo instalado, los pasos mínimos son:

### 1. Abrir la carpeta del proyecto

### 2. Abrir una terminal

### 3. Compilar

```bash
g++ -std=c++17 -Wall -Wextra -pedantic src/*.cpp -Iinclude -o refugio.exe
```

### 4. Ejecutar

```bash
.\refugio.exe
```

### 5. Utilizar el menú

Seguir las instrucciones mostradas por el programa.


# 19. Resumen de instalación desde cero

Si una persona comienza completamente desde cero en Windows, debe realizar estos pasos en orden:

1. Instalar Git (si va a descargar el proyecto desde GitHub).
                ↓
2. Instalar Visual Studio Code.
                ↓
3. Instalar MSYS2.
                ↓
4. Instalar GCC mediante MSYS2.
                ↓
5. Agregar C:\msys64\ucrt64\bin al PATH.
                ↓
6. Descargar/clonar el proyecto.
                ↓
7. Abrir la carpeta del proyecto en VS Code.
                ↓
8. Abrir una terminal.
                ↓
9. Verificar g++ --version.
                ↓
10. Compilar con g++.
                ↓
11. Ejecutar .\refugio.exe
                ↓
12. Utilizar el menú principal.
```

---

# 20. Autores

**Integrantes del grupo:**

* Santiago Ristorto
* Alvaro Mercado

---

# 21. Fecha de entrega

13/10/2026

---

# 22. Tecnologías utilizadas

* C++
* C++17
* GCC / MinGW-w64
* MSYS2 UCRT64
* Visual Studio Code
* Git
* GitHub
