#ifndef CLASES_H
#define CLASES_H
#include <string>
using namespace std;
class redEstaciones;
class EstacionServicio {
private:
    string nombre, codigo, gerente, region;
    string gps[3];
    float regular, premium, ecoExtra;
    int precioRegularN, precioPremiumN, precioEcoExtraN,precioRegularC, precioPremiumC, precioEcoExtraC,precioRegularS, precioPremiumS, precioEcoExtraS;
    unsigned char surtidores, naves;
    string* modeloSurtidor;
    int ventasDelDia[3]{0,0,0};
    bool* estadoSurtidor;

public:
    EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region,string gps[3],int &cont);
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
    bool surtidoresActivos();
    void simulacionVentas(int cantidadMaximaVenta);
    string* obtenerModelosSurtidores();
    string obtenerNombre();
    string obtenerCodigo();
    string obtenerGerente();
    string obtenerRegion();
    string obtenerGps();
    void setPrecioPremiumN(int precio);
    void setPrecioRegularN(int precio);
    void setPrecioEcoExtraN(int precio);
    void setPrecioPremiumC(int precio);
    void setPrecioRegularC(int precio);
    void setPrecioEcoExtraC(int precio);
    void setPrecioPremiumS(int precio);
    void setPrecioRegularS(int precio);
    void setPrecioEcoExtraS(int precio);
    int getPrecioPremiumN();
    int getPrecioRegularN();
    int getPrecioEcoExtraN();
    int getPrecioPremiumC();
    int getPrecioRegularC();
    int getPrecioEcoExtraC();
    int getPrecioPremiumS();
    int getPrecioRegularS();
    int getPrecioEcoExtraS();
    int getventasDelDiaPremimum();
    int getventasDelDiaRegular();
    int getventasDelDiaEcoExtra();
    void setNombre(string _nombre);
    void setCodigo(string _codigo);
    void setGerente(string _gerente);
};

class redEstaciones {
private:
    EstacionServicio** estaciones;
    string fijarPrecio[3][3];
    int cantEstaciones;

public:
    redEstaciones();
    void agregarEstacion(EstacionServicio* nuevaEstacion);
    void eliminarEstacion(string& cod);
    void fijarPrecioCombustible();
    void getredEstaciones();
    string getCodigo(int index);
    void precios();
    void obtenerPrecios(string region, string codigo);
    EstacionServicio** getRedEstaciones();
    void mostrarRedEstaciones();
    int getCantEstaciones();
    void setNombreEstacion(string _codigo,string nombre);
    void setCodigoEstacion(string _codigo,string codigo);
    void setGerenteEstacion(string _codigo,string gerente);

    void modificarSurtidoresRed(string _codigo);
    void modificarEstadoRed(string codigo);
    void simulacionVentasRed(string codigo);
};

#endif // CLASES_H
