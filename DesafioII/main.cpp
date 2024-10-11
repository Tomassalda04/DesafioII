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
            }
            case '2':{

            }
            case '3':{

            }
            case '4':{
                cout<<"***MOSTRAR ESTACIONES.***"<<endl;
                red.getredEstaciones();
            }
            case '5':{

            }
            }
        }
    }
}
    return 0;
}
