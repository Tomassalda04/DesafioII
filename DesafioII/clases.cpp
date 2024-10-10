#include "clases.h"
#include <iostream>
#include <string>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
using namespace std;

TanqueCombustible::TanqueCombustible() {
    regular = rand() % 101 + 100;  // 100 - 200 litros para Regular
    premium = rand() % 101 + 100;  // 100 - 200 litros para Premium
    ecoExtra = rand() % 101 + 100; // 100 - 200 litros para EcoExtra
    surtidores = static_cast<unsigned char>(rand() % 11 + 2);
}

float TanqueCombustible::obtenerCantidadCombustible(const string& tipo) const {
    // Devolvemos la cantidad de combustible según el tipo solicitado
    if (tipo == "Regular") {
        return regular;
    } else if (tipo == "Premium") {
        return premium;
    } else if (tipo == "EcoExtra") {
        return ecoExtra;
    } else {
        cout << "Tipo de combustible no válido. " << endl;
        return 0.0;
    }
}
unsigned char TanqueCombustible::obtenerSurtidores() const {
    return surtidores;
}

void TanqueCombustible::ventaCombustible(const string& tipo, float cantidad) {
    // Reducimos la cantidad de combustible según la categoría solicitada
    if (tipo == "Regular") {
        regular -= cantidad;
    } else if (tipo == "Premium") {
        premium -= cantidad;
    } else if (tipo == "EcoExtra") {
        ecoExtra -= cantidad;
    } else {
        cout << "Tipo de combustible no válido. No se puede realizar la venta. " << endl;;
    }
}
void TanqueCombustible::modificarSurtidores() {
    char opcion;
    int cantidad;
    int condicionFinalizacion = 0;

    while (condicionFinalizacion != 1){
        int condicion = 0;
        cout << "Deseas modificar los surtidores? (S para si, N para no): ";
        cin >> opcion;

        if (opcion == 'S' || opcion == 's') {
            cout << "El numero actual de surtidores es: " << static_cast<int>(surtidores) << endl;

            while (condicion != 1){
                cout << "Deseas agregar (A) o quitar (Q) surtidores? ";
                cin >> opcion;

                if (opcion == 'A' || opcion == 'a') {
                    condicion = 1;
                    cout << "Cuantos surtidores deseas agregar? ";
                    cin >> cantidad;
                    surtidores += cantidad;
                    if (static_cast<int>(surtidores) > 12){
                        cout << "No se pueden tener mas de 12 surtidores, por lo tanto se actualizara al maximo posible. " << endl;
                        surtidores =12;
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(TanqueCombustible::obtenerNaves()) << endl;
                    }
                    else{
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(TanqueCombustible::obtenerNaves()) << endl;
                    }
                }
                else if (opcion == 'Q' || opcion == 'q') {
                    condicion = 1;
                    cout << "Cuantos surtidores deseas quitar? ";
                    cin >> cantidad;
                    surtidores -= cantidad;
                    if (surtidores < 2){
                        cout << "No se pueden tener menos de 2 surtidores, por lo tanto se actualizara al minimo posible. " << endl;
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(TanqueCombustible::obtenerNaves()) << endl;
                    }
                    else{
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(TanqueCombustible::obtenerNaves()) << endl;
                    }
                }
                else {
                    cout << "Opción no valida. Por favor elige A o Q." << endl;
                }
            }
        }
        else {
            cout << "No se realizara ninguna modificacion." << endl;
            condicionFinalizacion = 1;
        }
    }
}

unsigned char TanqueCombustible::obtenerNaves() {
    if (surtidores % 2 == 0){
        naves = surtidores/2;
    }
    else{
        naves = (surtidores + 1)/2;
    }
    return naves;
}
void TanqueCombustible::asignarModelosSurtidores() {
    // Definimos los modelos disponibles
    string modelos[3] = {"S", "PMD", "PHR"};

    // Creamos un array para almacenar el modelo de cada surtidor
    modeloSurtidor = new string[surtidores];
    for (int i = 0; i < surtidores; i++) {
        int modeloAleatorio = rand() % 3;
        modeloSurtidor[i] = modelos[modeloAleatorio];
    }

    cout << "Modelos asignados a cada surtidor:" << endl;
    for (int i = 0; i < surtidores; i++) {
        cout << "Surtidor " << (i + 1) << ": " << modeloSurtidor[i] << endl;
    }
}
