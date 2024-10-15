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
    string nombre = "TerMex1", codigo = "1", gerente = "Tomas", region = "NORTE",nombre2 = "TerMex2", codigo2 = "2", gerente2 = "Cristo", region2 = "CENTRO",nombre3 = "TerMex3", codigo3 = "3", gerente3 = "Santiago", region3 = "SUR";
    string gps[3] {"0", "0", "0"},gps2[3] {"1", "1", "1"},gps3[3] {"3", "3", "3"};
    int cont=0,cont2=0,cont3=0;
    EstacionServicio* estacion = new EstacionServicio(nombre, codigo, gerente, region, gps, cont);
    EstacionServicio* estacion2 = new EstacionServicio(nombre2, codigo2, gerente2, region2, gps2, cont2);
    EstacionServicio* estacion3 = new EstacionServicio(nombre3, codigo3, gerente3, region3, gps3, cont3);
    //estacion->modificarSurtidores();
    estacion->asignarModelosSurtidores();
    estacion2->asignarModelosSurtidores();
    estacion3->asignarModelosSurtidores();
    red.agregarEstacion(estacion);
    red.agregarEstacion(estacion2);
    red.agregarEstacion(estacion3);
    system("cls");
    cout<<"-----------------------------------------------"<<endl;
    cout<<"|              COMPANIA TERMEX                |"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"        **********BIENVENIDO**********"<<endl;
    cout<<""<<endl;
    cout<<"     *****FIJAR PRECIOS COMBUSTIBLES*****"<<endl;
    red.fijarPrecioCombustible();
    red.precios();
    while(condicionInicial !=1){
        cout<<endl<<endl<<endl;
        cout<<"*****MENU PRINCIPAL*****"<<endl;
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
            cout <<" ELIJA LA OPCION DE SU PREFERENCIA" << endl;
            cout <<"1. AGREGAR ESTACION DE SERVICIO." << endl;
            cout <<"2. ELIMINAR ESTACION DE SERVICIO." << endl;
            cout <<"3. CALCULAR EL MONTO TOTAL DE VENTAS." << endl;
            cout <<"4. MODIFICAR ESTACIONES." << endl;
            cout <<"5. MOSTRAR ESTACIONES" << endl;
            cout <<"6. SALIR AL MENU PRINCIPAL" <<endl;
            cin>>opcion;
            verficarOpcion(opcion);
            switch(opcion){
            case '1':{
                srand(static_cast<unsigned int>(time(0)));
                cout << "   ***AGREGAR ESTACION DE SERVICIO.***" << endl;
                char confi='y';
                while (confi != 'n') {
                    // Obtener los datos de la estación
                    cout << "Ingrese el nombre: " << endl;
                    cin >> nombre;
                    cout << "Ingrese el codigo: " << endl;
                    cin >> codigo;
                    verificarCodigo(red,codigo);
                    cout << "Ingrese el gerente: " << endl;
                    cin >> gerente;
                    cout << "Ingrese la region: " << endl;
                    cout<<"**NORTE CENTRO SUR**"<<endl;
                    cout<<"____________________"<<endl;
                    cin >> region;
                    verificarRegion(region);
                    for (int i = 0; i < 3; i++) {
                        cout << "Ingrese la coordenada " << (i + 1) << ": ";
                        cin >> gps[i];
                    }
                    verificarGps(red,gps[0],gps[1],gps[2]);
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
                    red.precios();
                    // Preguntar si el usuario desea agregar otra estación
                    cout << "Desea agregar otra estacion? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                    cont++;
                }
                break;
            }
            case '2':{
                cout << "   ***ELIMINAR ESTACION DE SERVICIO.***" << endl;
                char confi='y';
                while(confi != 'n' && confi != 'N'){
                    bool continuar;
                    string opcion;
                    mostrarCodigos(red);
                    cout<<"Elija el codigo que desee eliminar: "<<endl;
                    cin>>opcion;
                    verificarCodigoExistente(red,opcion);
                    continuar=verificarCodigoSurtidores(red,opcion);
                    if(!continuar){
                        cout<<"Saliendo al Menu Principal..."<<endl;
                        break;
                    }
                    red.eliminarEstacion(opcion);
                    cout << "Desea eliminar otra estacion? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                }
                break;
            }
            case '3':{
                cout << "***CALCULAR MONTO TOTAL DE LAS VENTAS DE UNA ESTACION DE SERVICIO.***" << endl;
                char confi='y';
                while(confi != 'n' && confi != 'N'){
                    string opcion;
                    mostrarCodigos(red);
                    cout<<"Elija el codigo que desee: "<<endl;
                    cin>>opcion;
                    verificarCodigoExistente(red,opcion);

                    cout << "Desea eliminar otra estacion? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                }
                break;

            }
            case '4':{
                cout << "    ***MODIFICAR ESTACION DE SERVICIO.***" << endl;
                char confi='y';
                while(confi != 'n' && confi != 'N'){
                    char opcion;
                    string opc;
                    mostrarCodigos(red);
                    cout<<"Elija el codigo que desee: "<<endl;
                    cin>>opc;
                    verificarCodigoExistente(red,opc);
                    opcionesPorModificar(red,opc);
                    cin>>opcion;
                    verficarOpcionModificar(red,opc,opcion);
                    if(opcion=='1'){
                        string _nombre;
                        cout << "***MODIFICAR NOMBRE ESTACION DE SERVICIO.***" << endl;
                        cin>>_nombre;
                        red.setNombreEstacion(opc,_nombre);
                    }
                    else if(opcion=='2'){
                        string _codigo;
                        cout << "***MODIFICAR CODIGO ESTACION DE SERVICIO.***" << endl;
                        cin>>_codigo;
                        verificarCodigoExistente(red,opc);
                        red.setCodigoEstacion(codigo,_codigo);
                    }
                    else{
                        string _gerente;
                        cout << "***MODIFICAR GERENTE ESTACION DE SERVICIO.***" << endl;
                        cin>>_gerente;
                        red.setGerenteEstacion(codigo,_gerente);
                    }
                    cout << "Desea modificar otra estacion? (y/n): " << endl;
                    cin >> confi;
                    verficarYoN(confi);
                }
                break;
            }
            case '5':{

                red.mostrarRedEstaciones();
                break;
            }
            }
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

        }
    }
    return 0;
}

