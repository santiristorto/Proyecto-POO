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
            11: mostrar solicitudes e historial
            12: mostrar adoptantes
            13: ejecutar pruebas de templates
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
    marcar animal como NO DISPONIBLE

    mostrar solicitud creada
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
    mantener animal como NO DISPONIBLE
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
