#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
using namespace std;
/*Constructor para la clase redEstacion
 *Este arreglo va ir conectado a los objetos que se crean apartir de la clase EstacionServicio
 *Dicho lo anterior si se crea un onjeto en la otra clase se tiene que llamar esta clase para agregarla
*/

//Inicializacion miembro a miembro
EstacionServicio::EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region,string gps[3], int &cont)
    : nombre(nombre), codigo(codigo), gerente(gerente), region(region){
    for (unsigned int i = 0; i < 3; i++) {
        this->gps[i] = gps[i];
    }
    regular = rand() % 101 + 100;
    premium = rand() % 101 + 100;
    ecoExtra = rand() % 101 + 100;
    surtidores = static_cast<unsigned char>(rand() % 11 + 2);
}

float EstacionServicio::obtenerCantidadCombustible(const string& tipo) const {
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
unsigned char EstacionServicio::obtenerSurtidores() const {
    return surtidores;
}

void EstacionServicio::ventaCombustible(const string& tipo, float cantidad) {
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
void EstacionServicio::modificarSurtidores() {
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
                        cout << "Numero actualizado de naves: " << static_cast<int>(EstacionServicio::obtenerNaves()) << endl;
                    }
                    else{
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(EstacionServicio::obtenerNaves()) << endl;
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
                        cout << "Numero actualizado de naves: " << static_cast<int>(EstacionServicio::obtenerNaves()) << endl;
                    }
                    else{
                        cout << "Numero actualizado de surtidores: " << static_cast<int>(surtidores) << endl;
                        cout << "Numero actualizado de naves: " << static_cast<int>(EstacionServicio::obtenerNaves()) << endl;
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

unsigned char EstacionServicio::obtenerNaves() {
    if (surtidores % 2 == 0){
        naves = surtidores/2;
    }
    else{
        naves = (surtidores + 1)/2;
    }
    return naves;
}
void EstacionServicio::asignarModelosSurtidores() {
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

string* EstacionServicio::obtenerModelosSurtidores() {
    return modeloSurtidor;
}

string EstacionServicio::obtenerNombre(){
    return nombre;
}

string EstacionServicio::obtenerGerente(){
    return gerente;
}

string EstacionServicio::obtenerRegion(){
    return region;
}

string EstacionServicio::obtenerCodigo(){
    return codigo;
}

string EstacionServicio::obtenerGps(){
    return gps[0] + ", " + gps[1] + ", " + gps[2];
}

redEstaciones::redEstaciones() {
    cantEstaciones=0;
    estaciones = nullptr;
}

void redEstaciones::agregarEstacion(EstacionServicio* newEstacion){
    EstacionServicio** tempEstacion = new EstacionServicio*[cantEstaciones + 1];
    for (unsigned int i = 0; i < cantEstaciones  ; i++) {
        tempEstacion[i] = this->estaciones[i];
    }
    tempEstacion[cantEstaciones] = newEstacion;
    delete[] this->estaciones;
    this->estaciones = tempEstacion;
    cantEstaciones++;
}

void redEstaciones::eliminarEstacion(string &cod){
    int codEliminar=-1;
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(estaciones[i]->obtenerCodigo()==cod){
            codEliminar=i;
            break;
        }
    }
    EstacionServicio** tempEstaciones = new EstacionServicio*[cantEstaciones - 1];
    unsigned int control = 0;
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(codEliminar!= i){
            tempEstaciones[control] = this->estaciones[i];
            control++;
        }
    }
    delete estaciones[codEliminar];
    delete[] this->estaciones;
    this->estaciones = tempEstaciones;
    cantEstaciones--;
}

void redEstaciones::fijarPrecioCombustible(){
    for(unsigned int i = 0; i < 3; i++) {
        if(i == 0) {
            cout << "***REGION NORTE***" << endl << "--------------" << endl;
            for(unsigned int j = 0; j < 3; j++) {
                if(j == 0) {
                    cout << "--PREMIUM--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else if(j == 1) {
                    cout << "--REGULAR--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else {
                    cout << "--ECOEXTRA--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                }
            }
        } else if(i == 1) {
            cout << "***REGION CENTRO***" << endl << "--------------" << endl;
            for(unsigned int j = 0; j < 3; j++) {
                if(j == 0) {
                    cout << "--PREMIUM--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else if(j == 1) {
                    cout << "--REGULAR--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else {
                    cout << "--ECOEXTRA--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                }
            }
        } else {
            cout << "***REGION SUR***" << endl << "--------------" << endl;
            for(unsigned int j = 0; j < 3; j++) {
                if(j == 0) {
                    cout << "--PREMIUM--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else if(j == 1) {
                    cout << "--REGULAR--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                } else {
                    cout << "--ECOEXTRA--" << endl;
                    cin >> fijarPrecio[i][j];
                    verificarPrecioCombustible(fijarPrecio[i][j]);
                }
            }
        }
    }
}

void redEstaciones::getredEstaciones(){
    if (cantEstaciones == 0) {
        cout << "No hay estaciones en la red." << endl;
        return;
    }
    for (int i = 0; i < cantEstaciones; i++) {
        cout << "Estacion " << (i + 1) << ":" << endl;
        cout << "Nombre: " << estaciones[i]->obtenerNombre() << endl;
        cout << "Codigo: " << estaciones[i]->obtenerCodigo()<< endl;
        cout << "Gerente: " << estaciones[i]->obtenerGerente() << endl;
        cout << "Region: " << estaciones[i]->obtenerRegion() << endl;
        cout << "Coordenadas GPS: ";
        cout << "Coordenadas GPS: " << estaciones[i]->obtenerGps() << endl;
        cout << "Combustible Regular: " << estaciones[i]->obtenerCantidadCombustible("Regular") << " litros" << endl;
        cout << "Combustible Premium: " << estaciones[i]->obtenerCantidadCombustible("Premium") << " litros" << endl;
        cout << "Combustible EcoExtra: " << estaciones[i]->obtenerCantidadCombustible("EcoExtra") << " litros" << endl;
        cout << "Numero de surtidores: " << static_cast<int>(estaciones[i]->obtenerSurtidores()) << endl;
        cout << "Numero de naves: " << static_cast<int>(estaciones[i]->obtenerNaves()) << endl;
        string* modelos = estaciones[i]->obtenerModelosSurtidores();
        cout << "Modelos de surtidores: ";
        for (unsigned char j = 0; j < estaciones[i]->obtenerSurtidores(); j++) {
            cout << modelos[j] << (j < estaciones[i]->obtenerSurtidores() - 1 ? ", " : "");
        }
        cout << endl;
        cout << "--------------------------------------" << endl;
    }
}
