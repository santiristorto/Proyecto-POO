# Diagramas de flujo

Los siguientes diagramas pueden pegarse en un editor compatible con Mermaid o utilizarse como guía para dibujarlos en Word/diagrams.net.

## Menú principal

```mermaid
flowchart TD
    A([Inicio]) --> B[Mostrar menu]
    B --> C[Leer opcion]
    C --> D{Opcion}
    D -->|1| E[Registrar perro]
    D -->|2| F[Registrar gato]
    D -->|3| G[Listar animales]
    D -->|4| H[Listar disponibles]
    D -->|5| I[Registrar adoptante]
    D -->|6| J[Buscar animal]
    D -->|7| K[Crear solicitud]
    D -->|8| L[Confirmar solicitud]
    D -->|9| M[Cancelar solicitud]
    D -->|10| N[Devolver animal]
    D -->|11| O[Mostrar solicitudes]
    D -->|12| P[Mostrar historial]
    D -->|13| S[Mostrar adoptantes]
    D -->|14| Q[Demo de templates]
    D -->|0| R([Fin])
    E --> B
    F --> B
    G --> B
    H --> B
    I --> B
    J --> B
    K --> B
    L --> B
    M --> B
    N --> B
    O --> B
    P --> B
    Q --> B
    S --> B
```

## Registrar perro/gato

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer datos]
    B --> E[Crear objeto con new]
    E --> C{ID repetido? operator==}
    C -->|Si| D[delete del objeto y Throw IdRepetidoException]
    C -->|No| F[Refugio guarda el puntero en el catalogo]
    F --> G[Mostrar exito]
    D --> H[Catch y mostrar error]
    G --> I([Fin])
    H --> I
```

## Registrar adoptante

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer datos]
    B --> C{ID repetido?}
    C -->|Si| D[Throw IdRepetidoException]
    C -->|No| E[Agregar adoptante]
    E --> F[Mostrar exito]
    D --> G[Catch y mostrar error]
    F --> H([Fin])
    G --> H
```

## Buscar animal

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer ID]
    B --> C[Buscar con operator parentesis]
    C --> D{Existe?}
    D -->|No| E[Throw NoEncontradoException]
    D -->|Si| F[mostrarInfo polimorfico]
    E --> G[Catch y mostrar error]
    F --> H([Fin])
    G --> H
```

## Crear solicitud

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer IDs]
    B --> C{Solicitud repetida?}
    C -->|Si| D[Throw ID repetido]
    C -->|No| E{Adoptante existe?}
    E -->|No| F[Throw NoEncontrado]
    E -->|Si| G{Animal existe?}
    G -->|No| H[Throw NoEncontrado]
    G -->|Si| I{Animal disponible?}
    I -->|No| J[Throw AnimalNoDisponible]
    I -->|Si| K[Crear solicitud pendiente]
    K --> L[Marcar animal no disponible]
    L --> M[Mostrar exito]
    D --> N[Catch]
    F --> N
    H --> N
    J --> N
    M --> O([Fin])
    N --> O
```

## Confirmar solicitud

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer ID solicitud]
    B --> C{Existe?}
    C -->|No| D[Throw NoEncontrado]
    C -->|Si| E{Esta pendiente?}
    E -->|No| F[Throw ExcepcionRefugio]
    E -->|Si| G[Estado = CONFIRMADA]
    G --> H[Animal sigue no disponible: ya fue adoptado]
    H --> I([Fin])
    D --> J[Catch]
    F --> J
    J --> I
```

## Cancelar solicitud

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer ID solicitud]
    B --> C{Existe?}
    C -->|No| D[Throw NoEncontrado]
    C -->|Si| E{Esta pendiente?}
    E -->|No| F[Throw ExcepcionRefugio]
    E -->|Si| G[Estado = CANCELADA]
    G --> H[Animal = disponible]
    H --> I([Fin])
    D --> J[Catch]
    F --> J
    J --> I
```

## Devolver animal

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer ID animal]
    B --> C{Existe?}
    C -->|No| D[Throw NoEncontrado]
    C -->|Si| C2{Ya esta disponible?}
    C2 -->|Si| D2[Throw ExcepcionRefugio]
    C2 -->|No| C3{Tiene solicitud pendiente?}
    C3 -->|Si| D2
    C3 -->|No| E[Animal = disponible]
    E --> F[Mostrar exito]
    D --> G[Catch]
    D2 --> G
    F --> H([Fin])
    G --> H
```

## Listar todos los animales

```mermaid
flowchart TD
    A([Inicio]) --> B{Hay animales?}
    B -->|No| C[Informar que no hay]
    B -->|Si| D[actual = inicio del catalogo]
    D --> E{actual menor que fin?}
    E -->|Si| F[mostrarInfo polimorfico]
    F --> G[actual avanza al siguiente puntero]
    G --> E
    E -->|No| H([Fin])
    C --> H
```

## Listar animales disponibles

```mermaid
flowchart TD
    A([Inicio]) --> B[i = 0]
    B --> C{i menor que cantidad?}
    C -->|No| G{Se mostro alguno?}
    C -->|Si| D{animal i disponible?}
    D -->|Si| E[mostrarInfo]
    D -->|No| F[siguiente]
    E --> F
    F --> C
    G -->|No| H[Informar que no hay]
    G -->|Si| I([Fin])
    H --> I
```

## Mostrar solicitudes

```mermaid
flowchart TD
    A([Inicio]) --> B{Hay solicitudes?}
    B -->|No| C[Informar que no hay]
    B -->|Si| D[Recorrer solicitudes]
    D --> E[Mostrar cada una con su estado]
    E --> F([Fin])
    C --> F
```

## Mostrar historial de adopciones

```mermaid
flowchart TD
    A([Inicio]) --> B[Recorrer solicitudes]
    B --> C{Quedan solicitudes?}
    C -->|No| G{Se mostro alguna?}
    C -->|Si| D{Estado CONFIRMADA?}
    D -->|Si| E[Mostrar animal y adoptante]
    D -->|No| B
    E --> B
    G -->|No| H[Historial vacio]
    G -->|Si| I([Fin])
    H --> I
```

## Mostrar adoptantes

```mermaid
flowchart TD
    A([Inicio]) --> B{Hay adoptantes?}
    B -->|No| C[Informar que no hay]
    B -->|Si| D[Mostrar cada adoptante]
    D --> E([Fin])
    C --> E
```

## Demo de templates

```mermaid
flowchart TD
    A([Inicio]) --> B[Crear Coleccion int x2 y Coleccion string x1]
    B --> C[Agregar elementos]
    C --> D[Mostrar mayor con int y con string]
    D --> E[Mostrar instancias de cada tipo]
    E --> F([Fin])
```

## Proceso completo de adopcion

```mermaid
flowchart TD
    A([Animal disponible]) --> B[Crear solicitud]
    B --> C[Solicitud PENDIENTE y animal reservado]
    C --> D{Decision}
    D -->|Confirmar| E[Solicitud CONFIRMADA, animal adoptado]
    D -->|Cancelar| F[Solicitud CANCELADA]
    F --> A
    E --> G[Aparece en el historial]
    G --> H{Se devuelve el animal?}
    H -->|Si| I[Devolver animal]
    I --> A
    H -->|No| J([Fin])
```
