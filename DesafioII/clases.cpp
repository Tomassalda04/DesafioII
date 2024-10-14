#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
using namespace std;

#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

EstacionServicio::EstacionServicio(const string& nombre, const string& codigo, const string& gerente, const string& region, string gps[3], int &cont) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->gerente = gerente;
    this->region = region;
    this->gps[0] = gps[0];
    this->gps[1] = gps[1];
    this->gps[2] = gps[2];

    // Inicializar cantidades de combustible con un valor aleatorio entre 100 y 200
    regular = rand() % 101 + 100; // entre 100 y 200
    premium = rand() % 101 + 100; // entre 100 y 200
    ecoExtra = rand() % 101 + 100; // entre 100 y 200

    // Inicializar el número de surtidores con un valor entre 2 y 12
    surtidores = rand() % 11 + 2; // entre 2 y 12
    naves = 1; // Inicializa a 1 o al número deseado

    // Inicializa los arrays dinámicos para modelos y estados de surtidores
    modeloSurtidor = new string[surtidores]; // Crear el arreglo dinámico
    estadoSurtidor = new bool[surtidores];   // Crear el arreglo dinámico

    // Asignar modelos y estados iniciales
    for (unsigned char i = 0; i < surtidores; ++i) {
        modeloSurtidor[i] = "Modelo " + to_string(i + 1); // Asignar un modelo
        estadoSurtidor[i] = true; // Inicializa todos los surtidores como activos
    }

    // Inicializar precios
    precioRegularN = 0.0f; // Asigna un precio inicial
    precioPremiumN = 0.0f; // Asigna un precio inicial
    precioEcoExtraN = 0.0f; // Asigna un precio inicial
    precioRegularC = 0.0f; // Asigna un precio inicial
    precioPremiumC= 0.0f; // Asigna un precio inicial
    precioEcoExtraC = 0.0f; // Asigna un precio inicial
    precioRegularS = 0.0f; // Asigna un precio inicial
    precioPremiumS = 0.0f; // Asigna un precio inicial
    precioEcoExtraS = 0.0f; // Asigna un precio inicial
}

float EstacionServicio::obtenerCantidadCombustible(const string& tipo) const {
    if (tipo == "Regular") {
        return regular; // Asegúrate de que 'regular' esté inicializado adecuadamente
    } else if (tipo == "Premium") {
        return premium; // Asegúrate de que 'premium' esté inicializado adecuadamente
    } else if (tipo == "EcoExtra") {
        return ecoExtra; // Asegúrate de que 'ecoExtra' esté inicializado adecuadamente
    } else {
        cout << "Tipo de combustible no válido." << endl;
        return -1; // Indica un error
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
void EstacionServicio::asignarEstadoSurtidores() {
    estadoSurtidor = new bool[surtidores];
    for (int i = 0; i < surtidores; i++) {
        estadoSurtidor[i] = true;
    }

    cout << "Estado inicial asignado a cada surtidor (todos activados):" << endl;
    for (int i = 0; i < surtidores; i++) {
        cout << "Surtidor " << (i + 1) << " esta activado." << endl;
    }
}

void EstacionServicio::cambiarEstadoSurtidorPorModelo(const string& modelo, bool activar) {
    int contadorModelo = 0;

    // Contamos cuántos surtidores hay del modelo especificado
    for (int i = 0; i < surtidores; i++) {
        if (modeloSurtidor[i] == modelo) {
            contadorModelo++;
        }
    }

    // Si no hay surtidores de ese modelo, informamos al usuario y salimos
    if (contadorModelo == 0) {
        cout << "No se encontraron surtidores con el modelo " << modelo << "." << endl;
        return;
    }

    // Informamos al usuario cuántos surtidores hay del modelo especificado
    cout << "Hay " << contadorModelo << " surtidores del modelo " << modelo << "." << endl;

    // Pedimos al usuario cuántos surtidores quiere activar/desactivar
    int cantidad;
    cout << "¿Cuántos surtidores deseas " << (activar ? "activar" : "desactivar") << "? (máximo " << contadorModelo << "): ";
    cin >> cantidad;

    // Validamos la cantidad ingresada
    if (cantidad < 1 || cantidad > contadorModelo) {
        cout << "Cantidad no válida. Debe ser entre 1 y " << contadorModelo << "." << endl;
        return;
    }

    // Activamos o desactivamos la cantidad especificada de surtidores
    int surtidoresModificados = 0;
    for (int i = 0; i < surtidores && surtidoresModificados < cantidad; i++) {
        if (modeloSurtidor[i] == modelo) {
            estadoSurtidor[i] = activar;  // Cambiamos el estado según el valor de `activar`
            surtidoresModificados++;
            cout << "Surtidor " << (i + 1) << " con modelo " << modelo << " ha sido " << (activar ? "activado." : "desactivado.") << endl;
        }
    }
}

void EstacionServicio::mostrarSurtidores() {
    cout << "Modelos de Surtidores y su Estado:" << endl;
    for (unsigned char i = 0; i < surtidores; i++) {
        cout << "Modelo: " << modeloSurtidor[i] << " - Estado: " << (estadoSurtidor[i] ? "Activo" : "Inactivo") << endl;
    }
}

int EstacionServicio::contarSurtidoresActivos() {
    int contador = 0;
    for (int i = 0; i < surtidores; i++) {
        if (estadoSurtidor[i]) {  // Verifica si el surtidor está activado
            contador++;
        }
    }
    return contador;
}
bool EstacionServicio::surtidoresActivos(){
    if(surtidores>0){
        return true;
    }
    else if(surtidores<=0){
        return false;
    }
}
void EstacionServicio::simulacionVentas(float cantidadMaximaVenta) {
    // Usamos el número de surtidores activos para determinar el número de ventas
    int numeroSurtidoresActivos = contarSurtidoresActivos();
    int numeroVentas = rand() % numeroSurtidoresActivos + (numeroSurtidoresActivos * 2);  // Ajusta la lógica

    float cantidadVenta;
    string tipoCombustible;

    // Acumuladores para las ventas totales de cada tipo de gasolina
    float totalRegularVendido = 0;
    float totalPremiumVendido = 0;
    float totalEcoExtraVendido = 0;

    cout << "Simulacion de ventas del dia:" << endl;

    for (int i = 0; i < numeroVentas; i++) {
        // Elegimos aleatoriamente el tipo de combustible
        int tipoAleatorio = rand() % 3;

        // Elegimos aleatoriamente la cantidad de venta (máximo hasta `cantidadMaximaVenta`)
        cantidadVenta = static_cast<float>(rand() % static_cast<int>(cantidadMaximaVenta) + 1);

        if (tipoAleatorio == 0) {
            tipoCombustible = "Regular";
        } else if (tipoAleatorio == 1) {
            tipoCombustible = "Premium";
        } else {
            tipoCombustible = "EcoExtra";
        }

        // Verificamos si hay suficiente gasolina del tipo seleccionado
        if (obtenerCantidadCombustible(tipoCombustible) >= cantidadVenta) {
            ventaCombustible(tipoCombustible, cantidadVenta);
            cout << "Venta de " << cantidadVenta << " litros de " << tipoCombustible << ". Quedan "
                 << obtenerCantidadCombustible(tipoCombustible) << " litros." << endl;

            // Acumulamos las ventas de acuerdo al tipo de combustible
            if (tipoCombustible == "Regular") {
                totalRegularVendido += cantidadVenta;
            } else if (tipoCombustible == "Premium") {
                totalPremiumVendido += cantidadVenta;
            } else {
                totalEcoExtraVendido += cantidadVenta;
            }
        } else if (obtenerCantidadCombustible(tipoCombustible) > 0) {
            // Si no hay suficiente para la venta completa, se vende lo que queda
            float cantidadRestante = obtenerCantidadCombustible(tipoCombustible);
            ventaCombustible(tipoCombustible, cantidadRestante);
            cout << "Se intentó vender " << cantidadVenta << " litros de " << tipoCombustible
                 << ", pero solo quedan " << cantidadRestante << " litros. Vendiendo el resto." << endl;
            cout << tipoCombustible << " se ha agotado." << endl;

            // Acumulamos lo que quedó por vender
            if (tipoCombustible == "Regular") {
                totalRegularVendido += cantidadRestante;
            } else if (tipoCombustible == "Premium") {
                totalPremiumVendido += cantidadRestante;
            } else {
                totalEcoExtraVendido += cantidadRestante;
            }
        } else {
            cout << tipoCombustible << " se ha agotado. No se puede realizar la venta." << endl;
        }
    }

    // Mostramos el resumen final de las ventas
    cout << "\n--- Resumen final de ventas ---" << endl;
    cout << "Total vendido de Regular: " << totalRegularVendido << " litros." << endl;
    cout << "Total vendido de Premium: " << totalPremiumVendido << " litros." << endl;
    cout << "Total vendido de EcoExtra: " << totalEcoExtraVendido << " litros." << endl;

    cout << "Fin de la simulacion del dia." << endl;
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
int EstacionServicio::getPrecioPremiumN(){
    cout<<"Premium: "<<precioPremiumN;
    return precioPremiumN;
}
int EstacionServicio::getPrecioPremiumC(){
    cout<<"Premium: "<<precioPremiumC;
    return precioPremiumC;
}
int EstacionServicio::getPrecioPremiumS(){
    cout<<"Premium: "<<precioPremiumS;
    return precioPremiumS;
}
int EstacionServicio::getPrecioRegularN(){
    cout<<" Regular: "<<precioRegularN;
    return precioRegularN;
}
int EstacionServicio::getPrecioRegularC(){
    cout<<" Regular: "<<precioRegularC;
    return precioRegularC;
}
int EstacionServicio::getPrecioRegularS(){
    cout<<" Regular: "<<precioRegularS;
    return precioRegularS;
}
int EstacionServicio::getPrecioEcoExtraN(){
    cout<<" EcoExtra: "<<precioEcoExtraN;
    return precioEcoExtraN;
}
int EstacionServicio::getPrecioEcoExtraC(){
    cout<<" EcoExtra: "<<precioEcoExtraC;
    return precioEcoExtraC;
}
int EstacionServicio::getPrecioEcoExtraS(){
    cout<<" EcoExtra: "<<precioEcoExtraS;
    return precioEcoExtraS;
}
void EstacionServicio::setPrecioPremiumN(int precio){
    precioPremiumN = precio;
}
void EstacionServicio::setPrecioPremiumC(int precio){
    precioPremiumC = precio;
}
void EstacionServicio::setPrecioPremiumS(int precio){
    precioPremiumS = precio;
}
void EstacionServicio::setPrecioRegularN(int precio){
    precioRegularN = precio;
}
void EstacionServicio::setPrecioRegularC(int precio){
    precioRegularC = precio;
}
void EstacionServicio::setPrecioRegularS(int precio){
    precioRegularS = precio;
}
void EstacionServicio::setPrecioEcoExtraN(int precio){
    precioEcoExtraN = precio;
}
void EstacionServicio::setPrecioEcoExtraC(int precio){
    precioEcoExtraC = precio;
}
void EstacionServicio::setPrecioEcoExtraS(int precio){
    precioEcoExtraS = precio;
}
void EstacionServicio::setNombre(string _nombre){
    nombre=_nombre;
}
void EstacionServicio::setCodigo(string _codigo){
    codigo=_codigo;
}
void EstacionServicio::setGerente(string _gerente){
    gerente=_gerente;
}

redEstaciones::redEstaciones() {
    cantEstaciones=0;
    estaciones = nullptr;
}

void redEstaciones::agregarEstacion(EstacionServicio* nuevaEstacion){
    EstacionServicio** tempEstacion = new EstacionServicio*[cantEstaciones + 1];
    for (unsigned int i = 0; i < cantEstaciones  ; i++) {
        tempEstacion[i] = this->estaciones[i];
    }
    tempEstacion[cantEstaciones] = nuevaEstacion;
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
            cout << "               ***REGION NORTE***" << endl << "               ------------------" << endl;
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
        else if(i == 1) {
            cout << "               ***REGION CENTRO***" << endl << "               -------------------" << endl;
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
        else if(i == 2){
            cout << "                ***REGION SUR***" << endl << "                ----------------" << endl;
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
void redEstaciones::precios(){
    for(unsigned int i=0;i<cantEstaciones;i++){
        string nombre=estaciones[i]->obtenerNombre(),region=estaciones[i]->obtenerRegion();
        cout<<"NOMBRE : "<<nombre<<endl;
        cout<<"REGION : "<<region<<endl;
        if(region=="NORTE"){
            estaciones[i]->setPrecioPremiumN(stoi(fijarPrecio[0][0]));
            estaciones[i]->setPrecioRegularN(stoi(fijarPrecio[0][1]));
            estaciones[i]->setPrecioEcoExtraN(stoi(fijarPrecio[0][2]));
        }
        else if(region=="CENTRO"){
            estaciones[i]->setPrecioPremiumC(stoi(fijarPrecio[1][0]));
            estaciones[i]->setPrecioRegularC(stoi(fijarPrecio[1][1]));
            estaciones[i]->setPrecioEcoExtraC(stoi(fijarPrecio[1][2]));
        }
        else if(region=="SUR"){
            estaciones[i]->setPrecioPremiumS(stoi(fijarPrecio[2][0]));
            estaciones[i]->setPrecioRegularS(stoi(fijarPrecio[2][1]));
            estaciones[i]->setPrecioEcoExtraS(stoi(fijarPrecio[2][2]));
        }
    }
}
void redEstaciones::obtenerPrecios(string region, string codigo){
    cout<<"Precio Combustible: "<<endl;
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(estaciones[i]->obtenerCodigo()==codigo){
            if(estaciones[i]->obtenerRegion()=="NORTE"){
                estaciones[i]->getPrecioPremiumN();
                estaciones[i]->getPrecioRegularN();
                estaciones[i]->getPrecioEcoExtraN();
            }
            else if(estaciones[i]->obtenerRegion()=="CENTRO"){
                estaciones[i]->getPrecioPremiumC();
                estaciones[i]->getPrecioRegularC();
                estaciones[i]->getPrecioEcoExtraC();
            }
            else if(estaciones[i]->obtenerRegion()=="SUR"){
                estaciones[i]->getPrecioPremiumS();
                estaciones[i]->getPrecioRegularS();
                estaciones[i]->getPrecioEcoExtraS();
            }
        }
    }
}

EstacionServicio** redEstaciones::getRedEstaciones() {
    return estaciones;
}
void redEstaciones::mostrarRedEstaciones(){
    cout<<"-----------------------------------------------"<<endl;
    cout<<"|              COMPANIA TERMEX                |"<<endl;
    cout<<"-----------------------------------------------"<<endl;
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
        obtenerPrecios(estaciones[i]->obtenerRegion(),estaciones[i]->obtenerCodigo());
        cout<<endl;
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
int redEstaciones::getCantEstaciones(){
    return cantEstaciones;
}
void redEstaciones::setNombreEstacion(string codigo,string _nombre){
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(codigo==estaciones[i]->obtenerCodigo()){
            estaciones[i]->setNombre(_nombre);
        }
    }
}
void redEstaciones::setCodigoEstacion(string codigo,string _codigo){
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(codigo==estaciones[i]->obtenerCodigo()){
            estaciones[i]->setCodigo(_codigo);
        }
    }
}
void redEstaciones::setGerenteEstacion(string codigo,string _gerente){
    for(unsigned int i=0;i<cantEstaciones;i++){
        if(codigo==estaciones[i]->obtenerCodigo()){
            estaciones[i]->setGerente(_gerente);
        }
    }
}
