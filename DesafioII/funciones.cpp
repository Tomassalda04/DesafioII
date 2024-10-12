#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>

void verificarCodigo(redEstaciones &red, string &cod) {
    while (true) {
        bool esNumero = true;
        if (cod.length() > 4) {
            esNumero = false;
        }
        for(unsigned int i=0;i<cod.length();i++){
            char temp= cod[i];
            if(temp < '0' || temp > '9') {
                esNumero = false;
                break;
            }
        }
        bool repetido = false;
        for (unsigned int i = 0; i < red.getCantEstaciones(); i++) {
            if (red.getRedEstaciones()[i]->obtenerCodigo() == cod) {
                repetido = true;
                break;
            }
        }
        if (!esNumero) {
            cout << "    *****ERROR*****" << endl;
            cout << "----------Entrada invalida----------" << endl;
            cout << "Ingrese un codigo de maximo 4 digitos numericos: "<<endl;
            cin>>cod;
        }
        else if (repetido) {
            cout << "    *****ERROR*****" << endl;
            cout << "----------CODIGO REPETIDO----------" << endl;
            cout << "Ingrese un nuevo codigo de maximo 4 digitos numericos: "<<endl;
            cin >> cod;
        }
        else {
            break;
        }
    }
}
void verificarRegion(string& reg){
    while (true){
        bool Valido=true;
        string temp;
        unsigned char c;
        for(unsigned int i=0;i<reg.length();i++){
            c=reg[i];
            temp+= toupper(c);
        }
        if(temp!="NORTE" && temp!="CENTRO" && temp!="SUR"){
            cout << "    *****ERROR*****" << endl;
            cout << "----------Entrada invalida----------" << endl;
            cout << "Ingrese la region: " << endl;
            cout <<"**NORTE CENTRO SUR**"<<endl;
            cout <<"____________________"<<endl;
            cin>>reg;
        }
        else{
            reg=temp;
            break;
        }
    }
}
void verificarGps(redEstaciones& red,string& coordenada1,string& coordenada2,string& coordenada3){
    while(true){
        bool numValido1=true,numValido2=true,numValido3=true;
        bool repetido=false;
        unsigned int posNegativo1=0,posNegativo2=0,posNegativo3=0;
        if(coordenada1[0]=='-'){
            posNegativo1=1;
        }
        if(coordenada2[0]=='-'){
            posNegativo2=1;
        }
        if(coordenada3[0]=='-'){
            posNegativo3=1;
        }
        for(unsigned int i=posNegativo1;i<coordenada1.length();i++){
            char temp= coordenada1[i];
            if(temp<'0' || temp>'9'){
                numValido1=false;
                break;
            }
        }
        for(unsigned int i=posNegativo2;i<coordenada2.length();i++){
            char temp= coordenada2[i];
            if(temp<'0' || temp>'9'){
                numValido2=false;
                break;
            }
        }
        for(unsigned int i=posNegativo3;i<coordenada3.length();i++){
            char temp= coordenada3[i];
            if(temp<'0' || temp>'9'){
                numValido3=false;
                break;
            }
        }
        string tempcoordenadas = coordenada1 + ", " + coordenada2 + ", " + coordenada3;
        for (unsigned int i = 0; i < red.getCantEstaciones(); i++) {
            if (red.getRedEstaciones()[i]->obtenerGps() == tempcoordenadas) {
                repetido = true;
                break;
            }
        }
        if (!numValido1 || !numValido2 || !numValido3 ) {
            cout<< "    *****ERROR*****" << endl;
            cout<< "----------Entrada invalida----------" << endl;
            cout<< "Ingrese un numero correcto para las coordenadas" << endl;
            cout << "Ingrese la coordenada 1:"<<endl;
            cin >> coordenada1;
            cout << "Ingrese la coordenada 2:"<<endl;
            cin >> coordenada2;
            cout << "Ingrese la coordenada 3:"<<endl;
            cin >> coordenada3;
            string tempcoordenadas = coordenada1 + ", " + coordenada2 + ", " + coordenada3;
            for (unsigned int i = 0; i < red.getCantEstaciones(); i++) {
                if (red.getRedEstaciones()[i]->obtenerGps() == tempcoordenadas) {
                    repetido = true;
                    break;
                }
            }
        }
        else if (repetido) {
            cout << "    *****ERROR*****" << endl;
            cout << "----------COORDENADA REPETIDA----------" << endl;
            cout << "Ingrese coordenadas diferentes:" << endl;
            cout << "Ingrese la coordenada 1:"<<endl;
            cin >> coordenada1;
            cout << "Ingrese la coordenada 2:"<<endl;
            cin >> coordenada2;
            cout << "Ingrese la coordenada 3:"<<endl;
            cin >> coordenada3;
            repetido=false;
        }
        else {
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
        if(opcion!='y'&& opcion!='Y'&&opcion!='n'&&opcion!='N'){
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
void mostrarCodigos(redEstaciones& red){
    cout<<"    ----------CODIGOS DISPONIBLES----------"<<endl;
    for(unsigned int i=0;i<red.getCantEstaciones();i++){
        string codigo= red.getRedEstaciones()[i]->obtenerCodigo();
        cout<<codigo<<" "<<endl;
    }
}
