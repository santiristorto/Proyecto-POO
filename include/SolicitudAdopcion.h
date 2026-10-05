#ifndef SOLICITUD_ADOPCION_H
#define SOLICITUD_ADOPCION_H

#include <string>

enum class EstadoSolicitud {
    PENDIENTE,
    CONFIRMADA,
    CANCELADA
};

class SolicitudAdopcion {
private:
    int id;
    int idAdoptante;
    int idAnimal;
    EstadoSolicitud estado;

public:
    SolicitudAdopcion();
    SolicitudAdopcion(int id, int idAdoptante, int idAnimal);
    SolicitudAdopcion(const SolicitudAdopcion& otra);
    SolicitudAdopcion& operator=(const SolicitudAdopcion& otra);

    int getId() const;
    int getIdAdoptante() const;
    int getIdAnimal() const;
    EstadoSolicitud getEstado() const;

    void confirmar();
    void cancelar();
    bool estaPendiente() const;
    std::string estadoTexto() const;
    void mostrarInfo() const;
};

#endif
