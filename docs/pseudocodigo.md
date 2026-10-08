# Pseudocódigo

## Menú principal

```text
INICIO
    crear refugio

    REPETIR
        mostrar menú
        leer opción

        SEGÚN opción HACER
            1: registrar perro
            2: registrar gato
            3: listar todos los animales
            4: listar animales disponibles
            5: registrar adoptante
            6: buscar animal por ID
            7: crear solicitud
            8: confirmar solicitud
            9: cancelar solicitud
            10: devolver animal
            11: mostrar solicitudes
            12: mostrar historial de adopciones
            13: mostrar adoptantes
            14: demo de templates
            0: salir
            OTRA: informar opción inválida
        FIN SEGÚN

        si ocurre una excepción
            mostrar mensaje
            continuar con el menú
        fin si
    HASTA que opción = 0
FIN
```

## Proceso de adopción

```text
INICIO
    leer ID de solicitud
    leer ID de adoptante
    leer ID de animal

    verificar que el ID de solicitud no exista
    verificar que exista el adoptante
    verificar que exista el animal
    verificar que el animal esté disponible

    crear solicitud en estado PENDIENTE
    marcar animal como NO DISPONIBLE (reservado)

    mostrar mensaje de éxito
FIN
```

## Confirmación

```text
INICIO
    leer ID de solicitud
    buscar solicitud

    SI no existe
        lanzar excepción
    FIN SI

    SI no está pendiente
        lanzar excepción
    FIN SI

    cambiar estado a CONFIRMADA
    el animal sigue NO DISPONIBLE (ya fue adoptado)
FIN
```

## Cancelación

```text
INICIO
    leer ID de solicitud
    buscar solicitud

    SI no existe
        lanzar excepción
    FIN SI

    SI no está pendiente
        lanzar excepción
    FIN SI

    cambiar estado a CANCELADA
    cambiar animal a DISPONIBLE
FIN
```

## Devolver animal

```text
INICIO
    leer ID de animal
    buscar animal

    SI no existe
        lanzar excepción
    FIN SI

    SI el animal ya está disponible
        lanzar excepción
    FIN SI

    SI el animal tiene una solicitud pendiente
        lanzar excepción
    FIN SI

    cambiar animal a DISPONIBLE
FIN
```

## Registrar perro / gato / adoptante

```text
INICIO
    leer datos
    crear el objeto (new Perro / new Gato / Adoptante)

    PARA cada animal ya registrado
        SI tiene el mismo ID
            liberar el objeto nuevo
            lanzar excepción de ID repetido
        FIN SI
    FIN PARA

    agregar al catálogo
FIN
```

## Listar animales

```text
INICIO
    SI no hay animales
        informar y terminar
    FIN SI

    actual <- inicio del catálogo
    fin <- inicio + cantidad

    MIENTRAS actual < fin HACER
        llamar a mostrarInfo() del animal apuntado (polimórfico)
        avanzar actual al siguiente puntero
    FIN MIENTRAS
FIN
```

## Historial de adopciones

```text
INICIO
    PARA cada solicitud
        SI su estado es CONFIRMADA
            mostrar nombre del animal y nombre del adoptante
        FIN SI
    FIN PARA

    SI no se mostró ninguna
        informar que el historial está vacío
    FIN SI
FIN
```
