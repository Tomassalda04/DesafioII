#ifndef CLASES_H
#define CLASES_H
#include <string>
using namespace std;

class redEstaciones;
class TanqueCombustible {
private:
    float regular, premium, ecoExtra;
    unsigned char surtidores, naves;
    string* modeloSurtidor;

public:
    //constructor
    TanqueCombustible();

    // Métodos para obtener la cantidad de combustible y vender
    // Getter
    float obtenerCantidadCombustible(const string& tipo) const;
    unsigned char obtenerSurtidores() const;
    unsigned char obtenerNaves()const;

    //metodo
    void ventaCombustible(const string& tipo, float cantidad);
    void modificarSurtidores();

    unsigned char obtenerNaves();
    void asignarModelosSurtidores();


};
#endif // CLASES_H
