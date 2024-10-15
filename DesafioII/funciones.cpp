#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>

class redEstaciones;
class EstacionServicio;

void verficarCodigo(string& cod){
    while(true){
        unsigned char aux=0;
        for(int i=0;i<cod.length();i++){
            char temp= cod[i];
            if(temp<'0' || temp>'9'){
                aux=1;
            }
        }
        if(aux==1){
            cout<<"    *****ERROR*****"<<endl<<"----------Entrada invalida----------"<<endl<< "Ingrese un numero correcto para el codigo:"<<endl;
            cin>>cod;
        }
        else if(cod.length()>4){
            cout<<"    *****ERROR*****"<<endl<<"-------MAXIMO 4 DIGITOS CODIGO-------"<<endl<< "Ingrese un numero correcto para el codigo:"<<endl;
            cin>>cod;
        }
        else{
            break;
        }
    }
}
void verificarGps(string& coordenada){
    while(true){
        unsigned char aux=0;
        unsigned int posNegativo=0;
        if(coordenada[0]=='-'){
            posNegativo=1;
        }
        for(int i=posNegativo;i<coordenada.length();i++){
            char temp= coordenada[i];
            if(temp<'0' || temp>'9'){
                aux=1;
            }
        }
        if(aux==1){
            cout<<"    *****ERROR*****"<<endl<<"----------Entrada invalida----------"<<endl<< "Ingrese un numero correcto para el codigo:"<<endl;
            cin>>coordenada;
        }
        else{
            break;
        }
    }
}
void verificarPrecioCombustible(string& precio){
    while(true){
        unsigned char aux=0;
        for(int i=0;i<precio.length();i++){
            char temp= precio[i];
            if(temp<'0' || temp>'9'){
                aux=1;
            }
        }
        if(aux==1){
            cout<<"    *****ERROR*****"<<endl<<"----------Entrada invalida----------"<<endl<< "Ingrese un numero correcto para el codigo:"<<endl;
            cin>>precio;
        }
        else{
            break;
        }
    }
}
void verficarYoN(char &opcion){
    while(true){
        if(opcion!='y'&& opcion!='Y'&&opcion!='N'&&opcion!='N'){
            cout<<"     *ERRROR*"<<endl<<"----------Entrada invalida----------"<<endl<<"Desea agregar otra estacion? (y/n): "<<endl;
            cin>>opcion;
        }
        else{
            break;
        }
    }
}
void verficarOpcion(unsigned char& opc){
    while(true){
        if(opc<'1'||opc>'4'){
            cout<<"        *ERRROR*"<<endl<<"----------Entrada invalida----------"<<endl;
            cout<<"*****GESTION DE LA RED*****"<<endl;
            cout << " ELIJA LA OPCION DE SU PREFERENCIA" << endl;
            cout << "1. AGREGAR ESTACION DE SERVICIO." << endl;
            cout << "2. ELIMINAR ESTACION DE SERVICIO." << endl;
            cout << "3. CALCULAR EL MONTO TOTAL DE VENTAS." << endl;
            cout << "4. SALIR DEL PROGRAMA" << endl;
            cin>>opc;
        }
        else{
            break;
        }
    }
}
<<<<<<< Updated upstream
=======
void mostrarCodigos(redEstaciones& red){
    cout<<"    ----------CODIGOS DISPONIBLES----------"<<endl;
    for(unsigned int i=0;i<red.getCantEstaciones();i++){
        string codigo= red.getRedEstaciones()[i]->obtenerCodigo();
        cout<<i+1<<". "<<codigo<<endl;
    }
}

void verificarCodigoExistente(redEstaciones& red, string& opc){
    while(true){
        bool existe=false;
        for(unsigned int i=0;i<red.getCantEstaciones();i++){
            if(opc==red.getRedEstaciones()[i]->obtenerCodigo()){
                existe=true;
                break;
            }
        }
        if(!existe){
            cout << "              *****ERROR*****" << endl;
            cout<<"          ----CODIGO NO EXISTENTE----"<<endl;
            mostrarCodigos(red);
            cout<<"Elija el codigo que desee: "<<endl;
            cin>>opc;
        }
        else{
            break;
        }
    }
}
bool verificarSurtidoresDesactivados(redEstaciones& red, string&cod){
    for(unsigned int i=0;i<red.getCantEstaciones();i++){
        if (red.getRedEstaciones()[i]->obtenerCodigo() == cod) {
            if(red.getRedEstaciones()[i]->surtidoresActivos()){
                return true;
            }
            else{
                return false;
            }
        }
    }
}
bool verificarCodigoSurtidores(redEstaciones& red, string& opc){
    char YoN;
    while(true){
        bool permitidoEliminar=verificarSurtidoresDesactivados(red,opc);
        if(permitidoEliminar){
            cout << "              *****ERROR*****" << endl;
            cout<<"      ----CODIGO CON SURTIDORES ACTIVOS----"<<endl;
            cout<<"Desea intentar con otra estacion (y/n): "<<endl;
            cin>>YoN;
            verficarYoN(YoN);
            if(YoN == 'y' || YoN == 'Y'){
                mostrarCodigos(red);
                cout<<"Elija el codigo que desee eliminar: "<<endl;
                cin>>opc;
                verificarCodigoExistente(red,opc);
            }
            else {
                return false;
            }
        }
        else{
            return true;
        }
    }
}
void opcionesPorModificar(redEstaciones& red,string& opc){
    cout<<"OPCIONES PARA MODIFICAR"<<endl;
    for(unsigned int i=0;i<red.getCantEstaciones();i++){
        if(red.getRedEstaciones()[i]->obtenerCodigo()==opc){
            cout<<"1. NOMBRE : "<<red.getRedEstaciones()[i]->obtenerNombre()<<endl;
            cout<<"2. CODIGO : "<<red.getRedEstaciones()[i]->obtenerCodigo()<<endl;
            cout<<"3. GERENTE : "<<red.getRedEstaciones()[i]->obtenerGerente()<<endl;
        }
    }
    cout<<"Elija una opcion: "<<endl;
}
void verficarOpcionModificar(redEstaciones& red, string& opc, char& opcion){
    while(true){
        if(opcion!='1' && opcion!='2' && opcion!='3'){
            cout << "              *****ERROR*****" << endl;
            cout<<"           ----OPCION INCORRECTA----"<<endl;
            opcionesPorModificar(red,opc);
            cin>>opcion;
        }
        else{
            break;
        }
    }
}










>>>>>>> Stashed changes
