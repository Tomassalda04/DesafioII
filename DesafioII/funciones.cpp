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
            cout<<"    *****ERROR*****"<<endl<<"----------Entrada invalida----------"<<endl<< "Ingrese un numero correcto para el precio:"<<endl;
            cin>>precio;
        }
        else{
            break;
        }
    }
}
void verificarLitros(string& litros){
    while(true){
        unsigned char aux=0;
        for(int i=0;i<litros.length();i++){
            char temp= litros[i];
            if(temp<'0' || temp>'9'){
                aux=1;
            }
        }
        if(aux==1){
            cout<<"    *****ERROR*****"<<endl<<"----------Entrada invalida----------"<<endl<< "Ingrese un numero correcto para el precio:"<<endl;
            cin>>litros;
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
        if(opc<'1'||opc>'9'){
            cout<<"           *ERRROR*"<<endl<<"----------Entrada invalida----------"<<endl;
            cout<<"*****GESTION DE LA RED*****"<<endl;
            cout <<" ELIJA LA OPCION DE SU PREFERENCIA" << endl;
            cout <<"1. AGREGAR ESTACION DE SERVICIO." << endl;
            cout <<"2. ELIMINAR ESTACION DE SERVICIO." << endl;
            cout <<"3. SIMULAR VENTAS RED." << endl;
            cout <<"4. CALCULAR EL MONTO TOTAL DE VENTAS." << endl;
            cout <<"5. FIJAR PRECIOS COMBUSTBLE." << endl;
            cout <<"6. MODIFICAR ESTACIONES." << endl;
            cout <<"7. MOSTRAR ESTACIONES" << endl;
            cout <<"8. SALIR AL MENU PRINCIPAL" <<endl;
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
void mostrarEstacion(redEstaciones& red,string& opc){
    for(unsigned int i= 0; i<red.getCantEstaciones(); i++){
        if(red.getRedEstaciones()[i]->obtenerCodigo()==opc){
            red.getRedEstaciones()[i]->mostrarSurtidores();
        }
    }
}

int obtenerOpcionMenu(unsigned char numeroDeOpciones) {
    unsigned char opcion;

    while (true) {
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        if (opcion >='1' && opcion <= numeroDeOpciones) {
            return opcion;
        }
        else {
            cout <<"              *****ERROR*****" << endl;
            cout << "Entrada invalida. Por favor, ingrese un numero entre 1 y " << numeroDeOpciones
                 << "." << endl;
        }
    }
}
