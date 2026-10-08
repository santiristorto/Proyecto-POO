# Guía para la defensa oral

Proyecto: Sistema de Gestión de un Refugio de Animales (C++17, POO).
Todos los nombres de archivo y función son los del código real.

---

## 1. La idea en 30 segundos

El **Refugio** guarda un único catálogo de **`Animal*`** (que apuntan a `Perro` o `Gato`), una colección de **Adoptantes** y una colección de **Solicitudes**. Para adoptar: se registra un animal y un adoptante, se **crea una solicitud** (el animal queda reservado), y después se **confirma** (adoptado, entra al historial) o se **cancela** (el animal vuelve a estar disponible). Los errores se manejan con **excepciones** y el menú nunca se cierra por un error.

---

## 2. Las clases

### Animal (`include/Animal.h`, `src/Animal.cpp`)
* **Qué representa:** un animal del refugio, en general. Es **abstracta**: no se puede crear un `Animal` solo, solo perros o gatos.
* **Atributos (protected):** `id`, `nombre`, `edad`, `estadoSalud`, `disponible`; y `static int animalesVivos`.
* **Métodos importantes:** `estaDisponible()`, `setDisponible()`, `operator==` (compara IDs), `operator!` ("no está disponible"), `mostrarInfo()` y `clonar()` (virtuales puras), destructor virtual.
* **Quién la usa:** `Refugio` (guarda `Animal*`), `Perro` y `Gato` (heredan).
* **Por qué existe:** concentra lo que perros y gatos tienen en común.

### Perro / Gato (`Perro.h/.cpp`, `Gato.h/.cpp`)
* **Qué representan:** un tipo concreto de animal.
* **Atributos propios:** Perro: `raza`, `tamano`. Gato: `colorPelaje`, `condicion` (interior/exterior).
* **Métodos:** `mostrarInfo()` (muestra sus datos propios) y `clonar()` (devuelve `new` de una copia de sí mismo), ambos con `override`.
* **Quién los usa:** `main.cpp` los crea con `new`; `Refugio` los guarda como `Animal*`.

### Adoptante (`Adoptante.h/.cpp`)
* **Qué representa:** la persona que quiere adoptar.
* **Atributos:** `id`, `nombre`, `contacto`, `tipoVivienda` (todos privados).
* **Métodos:** getters, `mostrarInfo()`, constructores (defecto, parametrizado, copia) y `operator=`.
* **Quién la usa:** `Refugio` (dentro de `Coleccion<Adoptante>`).

### SolicitudAdopcion (`SolicitudAdopcion.h/.cpp`)
* **Qué representa:** el pedido de un adoptante por un animal, con su estado (`PENDIENTE`, `CONFIRMADA`, `CANCELADA`, un `enum class`).
* **Atributos:** `id`, `idAdoptante`, `idAnimal`, `estado`. Guarda IDs, no punteros.
* **Métodos:** `confirmar()`, `cancelar()`, `estaPendiente()`, `estadoTexto()`, `mostrarInfo()`.
* **Quién la usa:** `Refugio` (dentro de `Coleccion<SolicitudAdopcion>`).

### Refugio (`Refugio.h/.cpp`)
* **Qué representa:** el sistema completo; es la clase que coordina todo.
* **Atributos (privados):** `Animal** animales` + `cantidadAnimales` + `capacidadAnimales`; `Coleccion<Adoptante> adoptantes`; `Coleccion<SolicitudAdopcion> solicitudes`.
* **Métodos importantes:** `registrarAnimal`, `registrarAdoptante`, `crearSolicitud`, `confirmarSolicitud`, `cancelarSolicitud`, `devolverAnimal`, `listarAnimales`, `listarDisponibles`, `buscarAnimal`, `mostrarSolicitudes`, `mostrarHistorial`, `operator[]`, `operator()`, y la Regla de los Tres (copia, `=`, destructor).
* **Quién la usa:** `main.cpp` y las pruebas.

### Coleccion<T> (`Coleccion.h`)
* **Qué representa:** un arreglo dinámico genérico que crece solo. Se usa con `int`, `string`, `Adoptante` y `SolicitudAdopcion`.
* **Miembros:** `elementos`, `cantidadElementos`, `capacidad`, `static int instancias`. Métodos `agregar`, `cantidad`, `operator[]` (lanza `IndiceInvalidoException`), `getInstancias`. Tiene Regla de los Tres.
* Contiene también la función genérica `mayor<T>`.

### Excepciones (`Excepciones.h/.cpp`)
* `ExcepcionRefugio` hereda de `std::exception`. De ella heredan `IdRepetidoException`, `IndiceInvalidoException`, `AnimalNoDisponibleException` y `NoEncontradoException`.

### main.cpp
* Funciones chicas, una por opción (`registrarPerro`, `crearSolicitud`, ...), `mostrarMenu`, `ejecutarOpcion` (un `switch`) y `ejecutarMenu` (el `do...while` con `try/catch`).

---

## 3. Dónde aparece cada concepto de POO

| Concepto | Dónde | Explicación sencilla |
|---|---|---|
| Encapsulamiento | Todas las clases: atributos `private`/`protected`, acceso con getters y métodos | Nadie modifica los datos directamente; se hace por métodos (ej. `setDisponible`). |
| Abstracción | `Animal` | Representa "un animal" sin decir de qué tipo. |
| Herencia | `Perro : public Animal`, `Gato : public Animal` | Reutilizan id, nombre, edad, etc. |
| Polimorfismo | `Refugio::listarAnimales()` y `listarDisponibles()` | Con un `Animal*` se llama a `mostrarInfo()` y se ejecuta la versión de Perro o de Gato. |
| Composición | `Refugio` contiene `Coleccion<Adoptante>`, `Coleccion<SolicitudAdopcion>` y los animales | El refugio "tiene" adoptantes, solicitudes y animales; si el refugio desaparece, desaparecen con él. |
| Memoria dinámica | `Refugio::registrarAnimal`, `redimensionarAnimales`, `liberarAnimales`; `Coleccion<T>`; `main.cpp` (`new Perro`) | `new` crea, `delete`/`delete[]` libera. Ver tabla del README. |
| Aritmética de punteros | `Refugio::listarAnimales()` | `actual` y `fin` son `Animal* const*`; `++actual` pasa al siguiente. |
| Regla de los Tres | `Refugio` y `Coleccion<T>` | Manejan memoria dinámica, así que definen destructor, constructor de copia y `operator=`. |
| Copia profunda | `Refugio::copiarAnimales()` y constructor de copia de `Coleccion<T>` | Se crean copias nuevas de cada animal con `clonar()`, no se copian los punteros. |
| Operadores | `Animal::operator==`, `Animal::operator!`, `Refugio::operator[]`, `Refugio::operator()`, `Coleccion::operator[]` | Ver preguntas más abajo. |
| Templates | `Coleccion<T>`, `mayor<T>` (`Coleccion.h`) | Una sola clase/función sirve para varios tipos. |
| Miembro estático | `Coleccion<T>::instancias`, `Animal::animalesVivos` | Un valor compartido por todos los objetos de esa clase. |
| Excepciones | `Excepciones.h`; `throw` en `Refugio.cpp`; `try/catch` en `main.cpp::ejecutarMenu` | Los errores se avisan con `throw` y se atrapan sin cerrar el programa. |

---

## 4. Requisito → archivo → función → explicación

```text
Clase abstracta con destructor virtual y función virtual pura
→ Animal.h
→ virtual ~Animal(); virtual void mostrarInfo() const = 0;
→ No se puede instanciar Animal; el destructor virtual permite hacer delete de un Perro desde un Animal*.

Herencia pública + override
→ Perro.h / Gato.h
→ mostrarInfo() override, clonar() override
→ Cada tipo muestra y copia sus propios datos.

Único catálogo de punteros a Animal, recorrido polimórfico
→ Refugio.cpp
→ listarAnimales(), listarDisponibles()
→ Animal** guarda Perros y Gatos juntos; mostrarInfo() es virtual.

Aritmética de punteros
→ Refugio.cpp
→ listarAnimales()
→ while (actual < fin) { (*actual)->mostrarInfo(); ++actual; }

Colección con memoria dinámica
→ Refugio.cpp (Animal**) y Coleccion.h (T*)
→ registrarAnimal(), redimensionarAnimales(), Coleccion::agregar()
→ new[] al crear/crecer, delete[] al destruir.

Constructor por defecto, parametrizado, de copia y destructor
→ Animal, Perro, Gato, Adoptante, SolicitudAdopcion, Refugio, Coleccion
→ ver cada .cpp
→ Constructores con y sin parámetros; copia profunda donde hay memoria dinámica.

Regla de los Tres
→ Refugio.cpp, Coleccion.h
→ Refugio(const Refugio&), operator=, ~Refugio(); idem Coleccion
→ Los tres se definen juntos porque hay memoria dinámica.

Operador ==
→ Animal.cpp
→ Animal::operator==
→ Compara IDs; Refugio::registrarAnimal lo usa para detectar duplicados.

Operador []
→ Refugio.cpp
→ Refugio::operator[](int)
→ refugio[0] devuelve el animal en esa posición; lanza IndiceInvalidoException si no existe. Lo usa listarDisponibles().

Operador ()
→ Refugio.cpp
→ Refugio::operator()(int id)
→ refugio(5) busca por ID y devuelve nullptr si no existe. Lo usa buscarAnimal().

Operador unario
→ Animal.cpp
→ Animal::operator!
→ !animal significa "no está disponible". Lo usa crearSolicitud().

Coleccion<T> con agregar, cantidad y acceso, instanciada con dos tipos
→ Coleccion.h; main.cpp (probarTemplates); Refugio.h
→ Coleccion<int>, Coleccion<string> (demo); Coleccion<Adoptante>, Coleccion<SolicitudAdopcion> (uso real)
→ El mismo código sirve para cualquier tipo.

Miembro estático dentro de clase genérica
→ Coleccion.h
→ static int instancias; getInstancias()
→ Cada instanciación tiene su propio contador (int: 2, string: 1 en la demo).

Función genérica con dos tipos
→ Coleccion.h / main.cpp
→ mayor<T>() usada con int y con string
→ Devuelve el mayor de dos valores del mismo tipo.

Excepciones personalizadas, try/throw/catch múltiples por const&
→ Excepciones.h; Refugio.cpp (throw); main.cpp::ejecutarMenu (catch)
→ IdRepetido, IndiceInvalido, AnimalNoDisponible, NoEncontrado
→ El menú sigue después del error.

Adopción: crear / confirmar / cancelar / devolver
→ Refugio.cpp
→ crearSolicitud(), confirmarSolicitud(), cancelarSolicitud(), devolverAnimal()
→ Cada una valida antes de cambiar el estado.

Historial
→ Refugio.cpp
→ mostrarHistorial()
→ Muestra las solicitudes CONFIRMADAS con nombres de animal y adoptante.

Copia profunda demostrable y sin fugas
→ tests/test_refugio.cpp
→ pruebasMemoria()
→ Animal::getAnimalesVivos() vuelve al valor inicial al destruir los refugios.
```

---

## 5. Cómo se usa el programa (para la demo)

1. `make` y `./refugio` (o `make test` para correr las pruebas).
2. Registrar un perro (1), un gato (2) y un adoptante (5).
3. Listar disponibles (4), crear solicitud (7) → el animal desaparece de disponibles.
4. Confirmar (8) → mirar el historial (12). O cancelar (9) → el animal vuelve a disponibles.
5. Probar un error: crear otra solicitud sobre el mismo animal → "El animal no esta disponible" y el menú sigue.

---

## 6. Preguntas que podría hacer el profesor

**¿Por qué `Animal` es abstracta?**
Porque "un animal" a secas no existe en el refugio: siempre es un perro o un gato. Tiene una función virtual pura (`mostrarInfo`), entonces C++ no deja crear un `Animal` directamente. Sirve de molde común.

**¿Qué significa `virtual`?**
Que, al llamar a la función a través de un puntero a `Animal`, C++ decide en tiempo de ejecución qué versión usar según el objeto real. Si apunta a un `Perro`, se ejecuta la de `Perro`.

**¿Qué significa `override`?**
Le avisa al compilador que esa función redefine una virtual de la clase base. Si me equivoco en el nombre o los parámetros, da error en vez de crear una función nueva sin querer.

**¿Por qué usamos `Animal*`?**
Porque perros y gatos son tipos distintos y necesito guardarlos en un solo arreglo. Un puntero a la clase base puede apuntar a cualquiera de los dos y permite el polimorfismo. Si guardara `Animal` por valor se perdería la parte de Perro/Gato.

**¿Por qué usamos `new`?**
Porque los animales se registran mientras el programa corre y no sé cuántos habrá; además deben seguir existiendo después de que termine la función que los registró. `new` los crea en el heap.

**¿Quién libera la memoria?**
El `Refugio`. Cuando se registra un animal, el refugio se hace dueño del puntero; lo libera con `delete` en `liberarAnimales()` (llamada por el destructor). El arreglo de punteros lo libera con `delete[]`. Los adoptantes y solicitudes los libera `Coleccion<T>` en su destructor.

**¿Por qué el destructor de `Animal` es virtual?**
Porque hago `delete` sobre un `Animal*` que en realidad apunta a un `Perro` o un `Gato`. Sin `virtual` solo se ejecutaría el destructor de `Animal` (comportamiento indefinido).

**¿Qué es una copia profunda?**
Es copiar también lo que está "apuntado", no solo el puntero. En `Refugio`, por cada `Animal*` hago `clonar()`, que crea un objeto nuevo igual. Una copia superficial copiaría los punteros y los dos refugios compartirían los mismos animales: al destruirse el primero, el segundo quedaría con punteros rotos y se haría `delete` dos veces.

**¿Por qué existe `clonar()`?**
Porque desde un `Animal*` no sé si es Perro o Gato, y no puedo hacer `new Animal(...)` (es abstracta). Cada clase se copia a sí misma: `Perro::clonar()` hace `new Perro(*this)`.

**¿Qué es la Regla de los Tres?**
Si una clase maneja memoria dinámica, necesita definir destructor, constructor de copia y operador de asignación. Si no, C++ usa los automáticos, que copian punteros (copia superficial). `Refugio` y `Coleccion<T>` cumplen la regla.

**¿Qué hace `operator[]`?**
En `Refugio`, `refugio[i]` devuelve el animal que está en la posición `i`. Si `i` no existe, lanza `IndiceInvalidoException`. En `Coleccion<T>` hace lo mismo con sus elementos.

**¿Qué hace `operator()`?**
`refugio(5)` busca el animal con ID 5 y devuelve su puntero, o `nullptr` si no existe. Es una forma corta de escribir una búsqueda por ID.

**¿Por qué `==` compara IDs?**
Porque el ID identifica a cada animal: dos animales con el mismo ID son "el mismo" para el refugio, aunque se llamen distinto. Lo uso para impedir IDs repetidos.

**¿Qué hace `!animal`?**
Es un operador unario: devuelve `true` si el animal NO está disponible. Lo uso en `crearSolicitud` para rechazar animales no disponibles.

**¿Qué es un template?**
Una plantilla: escribo el código una vez con un tipo genérico `T` y el compilador genera una versión para cada tipo que uso.

**¿Qué significa `Coleccion<T>`?**
Es un arreglo dinámico genérico. `Coleccion<int>` guarda enteros, `Coleccion<string>` textos, `Coleccion<Adoptante>` adoptantes. Todas usan el mismo código.

**¿Qué hace el miembro estático?**
`instancias` es una variable compartida por todos los objetos de una misma clase: sube en el constructor y baja en el destructor. En un template, cada tipo tiene su propia copia: `Coleccion<int>` y `Coleccion<string>` cuentan por separado.

**¿Por qué usamos excepciones?**
Para separar el error del flujo normal. La función que detecta el problema hace `throw`, y el menú lo atrapa con `catch` y muestra un mensaje. El programa no se cierra y el usuario sigue operando.

**¿Por qué `catch (const ...& e)`?**
`const` porque solo leo el mensaje y no lo modifico; `&` (referencia) para no copiar la excepción y para que funcione el polimorfismo (se puede atrapar una excepción hija como `ExcepcionRefugio`). Se ordenan de la más específica a la más general.

**¿Qué pasa si se intenta adoptar un animal no disponible?**
`crearSolicitud` detecta `!(*animal)` y lanza `AnimalNoDisponibleException`. No se crea la solicitud, el menú muestra el error y continúa.

**¿Cómo funciona el proceso completo de adopción?**
1. El animal está disponible. 2. `crearSolicitud` valida que no se repita el ID de solicitud y que existan el adoptante y el animal y que este esté disponible; guarda la solicitud como PENDIENTE y marca el animal como no disponible (reservado). 3. `confirmarSolicitud` pasa la solicitud a CONFIRMADA (el animal queda adoptado y aparece en el historial) o `cancelarSolicitud` la pasa a CANCELADA y devuelve el animal a disponible. 4. Si un animal adoptado vuelve al refugio, `devolverAnimal` lo deja disponible (no se permite si ya estaba disponible o tiene una solicitud pendiente).

**¿Por qué `SolicitudAdopcion` guarda IDs y no punteros?**
Para no tener dos dueños de un mismo objeto ni punteros que puedan quedar colgando. Con el ID, el refugio busca el animal o adoptante cuando lo necesita.

**¿Por qué `Refugio` usa `Coleccion<T>` para adoptantes y solicitudes pero un `Animal**` a mano?**
Los adoptantes y solicitudes se guardan por valor, y `Coleccion<T>` ya resuelve ese caso. Los animales son punteros polimórficos que el refugio debe crear/liberar y recorrer con aritmética de punteros, así que ahí el manejo manual es parte de lo que se pide mostrar.

**¿Qué diferencia hay entre composición y herencia en este proyecto?**
Herencia = "es un": un Perro *es un* Animal. Composición = "tiene un": el Refugio *tiene* adoptantes, solicitudes y animales.
