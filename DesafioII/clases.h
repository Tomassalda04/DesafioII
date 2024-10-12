#ifndef CLASES_H
#define CLASES_H
#include <string>
using namespace std;
class EstacionServicio {
private:
    string nombre, codigo, gerente, region;
    string gps[3];
    float regular, premium, ecoExtra;
    unsigned char surtidores, naves;
    string* modeloSurtidor;
    bool* estadoSurtidor;

public:
    EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region,string gps[3], int &cont);
    float obtenerCantidadCombustible(const string& tipo) const;
    unsigned char obtenerSurtidores() const;
    unsigned char obtenerNaves() const;
    void ventaCombustible(const string& tipo, float cantidad);
    void modificarSurtidores();
    void asignarModelosSurtidores();
    unsigned char obtenerNaves();
    void asignarEstadoSurtidores();
    void cambiarEstadoSurtidorPorModelo(const string& modelo, bool activar);
    void mostrarSurtidores();
    int contarSurtidoresActivos();
    void simulacionVentas(float cantidadMaximaVenta);
    string* obtenerModelosSurtidores();
    string obtenerNombre();
    string obtenerCodigo();
    string obtenerGerente();
    string obtenerRegion();
    string obtenerGps();
};

class redEstaciones {
private:
    EstacionServicio** estaciones;
    string fijarPrecio[3][3];
    int cantEstaciones;

public:
    redEstaciones();
    void agregarEstacion(EstacionServicio* newEstacion);
    void eliminarEstacion(string& cod);
    void fijarPrecioCombustible();
    EstacionServicio** getRedEstaciones();
    void mostrarRedEstaciones();
    int getCantEstaciones();
};

#endif // CLASES_H
