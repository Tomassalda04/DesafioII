#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    unsigned char opcionMenuPrincipal;
    unsigned char condicionInicial = '0';
    redEstaciones red;
    string nombre = "TerMex1", codigo = "1", gerente = "Tom", region = "Sur";
    string gps[3] {"0", "0", "0"};
    int cont=0;
    EstacionServicio* estacion = new EstacionServicio(nombre, codigo, gerente, region, gps, cont);
    //estacion->modificarSurtidores();
    estacion->asignarModelosSurtidores();
    red.agregarEstacion(estacion);
    while(condicionInicial !=1){
        cout << " ELIJA LA OPCION DE SU PREFERENCIA" << endl;
        cout << "1. GESTION DE LA RED." << endl;
        cout << "2. GESTION DE ESTACIONES DE SERVICIO." << endl;
        cout << "3. SISTEMA NACIONAL DE VERIFICACION DE FUGAS." << endl;
        cout << "4. SIMULACION DE VENTAS" << endl;
        cout << "5. SALIR DEL PROGRAMA" << endl;
        cin>>opcionMenuPrincipal;
        switch (opcionMenuPrincipal){
        case '1':{
            unsigned char opcion;
            cout<<"*****GESTION DE LA RED*****"<<endl;
            cout << " ELIJA LA OPCION DE SU PREFERENCIA" << endl;
            cout << "1. AGREGAR ESTACION DE SERVICIO." << endl;
            cout << "2. ELIMINAR ESTACION DE SERVICIO." << endl;
            cout << "3. CALCULAR EL MONTO TOTAL DE VENTAS." << endl;
            cout <<"4. MOSTRAR ESTACIONES." << endl;
            cout << "5. SALIR AL MENU PRINCIPAL" << endl;
            cin>>opcion;
            verficarOpcion(opcion);
            switch(opcion){
            case '1':{
                srand(static_cast<unsigned int>(time(0)));
                cout << "***AGREGAR ESTACION DE SERVICIO.***" << endl;
                char confi='y';
                while (confi != 'n') {
                    // Obtener los datos de la estación
                    cout << "Ingrese el nombre: " << endl;
                    cin >> nombre;
                    cout << "Ingrese el codigo: " << endl;
                    cin >> codigo;
                    verficarCodigo(codigo);
                    cout << "Ingrese el gerente: " << endl;
                    cin >> gerente;
                    cout << "Ingrese la region: " << endl;
                    cin >> region;
                    verficarCodigo(codigo);
                    for (int i = 0; i < 3; i++) {
                        cout << "Ingrese la coordenada " << (i + 1) << ": ";
                        cin >> gps[i];
                        verificarGps(gps[i]);
                    }
                    EstacionServicio* estacion = new EstacionServicio(nombre, codigo, gerente, region, gps, cont);
                    cout << "Cantidad de combustible en el tanque:" << endl;
                    cout << "Regular: " << estacion->obtenerCantidadCombustible("Regular") << " litros" << endl;
                    cout << "Premium: " << estacion->obtenerCantidadCombustible("Premium") << " litros" << endl;
                    cout << "EcoExtra: " << estacion->obtenerCantidadCombustible("EcoExtra") << " litros" << endl;
                    cout << "Hay " << static_cast<int>(estacion->obtenerSurtidores()) << " surtidores distribuidos en " << static_cast<int>(estacion->obtenerNaves()) << " naves." << endl;

                    // Modificar los surtidores y asignar modelos a los surtidores
                    estacion->modificarSurtidores();
                    estacion->asignarModelosSurtidores();
                    // Agregar la nueva estación a la red
                    red.agregarEstacion(estacion);
                    // Preguntar si el usuario desea agregar otra estación
                    cout << "Desea agregar otra estacion? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                    cont++;
                }
                break;
            }
            case '2':{
                unsigned char volverPrincipal = '0';
                while(volverPrincipal != '1'){
                    cout << "EN ESTE MOMENTO USTED PUEDE MANIPULAR LA ESTACION DE SERVICIO." << endl;
                    cout << "--- Valores iniciales de la estacion de servicio ---" << endl;
                    cout << "Cantidad inicial de gasolina (Regular): " << estacion->obtenerCantidadCombustible("Regular") << " litros" << endl;
                    cout << "Cantidad inicial de gasolina (Premium): " << estacion->obtenerCantidadCombustible("Premium") << " litros" << endl;
                    cout << "Cantidad inicial de gasolina (EcoExtra): " << estacion->obtenerCantidadCombustible("EcoExtra") << " litros" << endl;
                    cout << "---------------------------------------------------------------"<< endl;
                    cout << "Numero inicial de surtidores: " << static_cast<int>(estacion->obtenerSurtidores()) << endl;
                    cout << "Numero inicial de naves: " << static_cast<int>(estacion->obtenerNaves()) << endl;
                    cout << "---------------------------------------------------------------"<< endl;
                    estacion->mostrarSurtidores();
                    cout << "---------------------------------------------------------------"<< endl;
                    cout << "SELECCIONE LA OPCION QUE PREFIERA." <<endl;
                    unsigned char opcionEstacionServicio;
                    cout << "1. AGREGAR/ELIMINAR UN SURTIDOR A UNA E/S." << endl;
                    cout << "2. ACTIVAR/DESACTIVAR UN SURTIDOR DE UNA E/S." <<endl;
                    cout << "3. SIMULACION DE VENTAS DEL DIA." << endl;
                    cout << "4. VOLVER AL MENU PRINCIPAL." << endl;
                    cin >> opcionEstacionServicio;
                    switch (opcionEstacionServicio) {
                    case '1':{
                        estacion->modificarSurtidores();
                        break;
                    }
                    case '2':{
                        string modelo;
                        char activarOpcion;
                        bool activar;

                        cout << "Ingrese el modelo del surtidor (S, PMD, PHR): ";
                        cin >> modelo;

                        cout << "Desea activar (A) o desactivar (D) los surtidores de este modelo? ";
                        cin >> activarOpcion;

                        if (activarOpcion == 'A' || activarOpcion == 'a') {
                            activar = true;
                        } else if (activarOpcion == 'D' || activarOpcion == 'd') {
                            activar = false;
                        } else {
                            cout << "OpciÃ³n no valida. Intente de nuevo." << endl;
                            continue;  // Regresa al inicio del bucle
                        }

                        // Cambiamos el estado de los surtidores por modelo
                        estacion->cambiarEstadoSurtidorPorModelo(modelo, activar);
                        break;
                    }
                    case '3':{
                        float cantidadMaximaVenta;
                        cout << "Ingrese la cantidad maxima de venta por transaccion (en litros): ";
                        cin >> cantidadMaximaVenta;
                        cout << "---------------------------------------------------------------------------" << endl;
                        estacion->simulacionVentas(cantidadMaximaVenta);
                        break;
                    }
                    case '4':{
                        cout << "VOLVIENDO AL MENU PRINCIPAL..." << endl;
                        volverPrincipal= '1';
                        break;
                    }
                    default:
                        cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
                    }
                    break;
                }
                break;
            }
            case '3':{
                break;

            }
            case '4':{
                cout<<"***MOSTRAR ESTACIONES.***"<<endl;
                red.getredEstaciones();
                break;
            }
            case '5':{
                break;

            }
            }
<<<<<<< Updated upstream
=======
            break;
        }
         case '2': {
            cout << "SELECCIONE LA OPCION QUE PREFIERA." << endl;
            unsigned char opcionEstacionServicio;
            cout << "1. AGREGAR/ELIMINAR UN SURTIDOR A UNA E/S." << endl;
            cout << "2. ACTIVAR/DESACTIVAR UN SURTIDOR DE UNA E/S." << endl;
            cout << "3. SIMULACION DE VENTAS DEL DIA." << endl;
            cout << "4. VOLVER AL MENU PRINCIPAL." << endl;
            cin >> opcionEstacionServicio;
            switch (opcionEstacionServicio) {
            case '1':{
                cout << " ***AGREGAR O ELIMINAR SURTIDORES.***" << endl;
                char confi='y';
                while(confi != 'n' && confi != 'N'){
                    string opcion;
                    mostrarCodigos(red);
                    cout<<"***ELIJA EL CODIGO DE LA ESTACION DE SERVICIO QUE DESEA MANIPULAR***: "<<endl;
                    cin>>opcion;
                    verificarCodigoExistente(red,opcion);
                    red.modificarSurtidoresRed(opcion);
                    cout << "DESEA AGREGAR O ELIMINAR SURTIDORES DE ESTACION? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                }
                break;
            }
            /*case '2':{
                cout << "***ACTIVAR/DESACTIVAR UN SURTIDOR DE UNA E/S***" << endl;
                char confi='y';
                while(confi != 'n' && confi != 'N'){
                    string opcion;
                    mostrarCodigos(red);
                    cout<<"***ELIJA EL CODIGO DE LA ESTACION DE SERVICIO QUE DESEA MANIPULAR***: "<<endl;
                    cin>>opcion;
                    verificarCodigoExistente(red,opcion);
                    red.modificarSurtidoresRed(opcion);
                    cout << "DESEA ACTIVAR O DESACTIVAR SURTIDORES DE ESTACION? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                }
                break;
            }*/
                break;
            default:
                break;
            }


            break;
        }
>>>>>>> Stashed changes
        }
    }
}
    return 0;
}
