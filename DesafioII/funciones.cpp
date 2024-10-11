#include "clases.h"
#include "funciones.h"
#include <iostream>
#include <string>

class redEstaciones;
class EstacionServicio;

void verficarCodigo(string& cod){
    while(true){
        int aux=0;
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
        char aux=0;
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
        int aux=0;
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
