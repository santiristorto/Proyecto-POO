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
    D -->|12| P[Mostrar adoptantes]
    D -->|13| Q[Probar templates]
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
```

## Registrar perro/gato

```mermaid
flowchart TD
    A([Inicio]) --> B[Leer datos]
    B --> C{ID repetido?}
    C -->|Si| D[Throw IdRepetidoException]
    C -->|No| E[Crear objeto]
    E --> F[Agregar al catalogo]
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
    B --> C[Buscar con operator]
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
    G --> H[Animal queda no disponible]
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
    C -->|Si| E[Animal = disponible]
    E --> F[Mostrar exito]
    D --> G[Catch]
    F --> H([Fin])
    G --> H
```

## Listados

```mermaid
flowchart TD
    A([Inicio]) --> B[Recorrer catalogo de Animal*]
    B --> C{Quedan animales?}
    C -->|Si| D[mostrarInfo]
    D --> B
    C -->|No| E([Fin])
```
