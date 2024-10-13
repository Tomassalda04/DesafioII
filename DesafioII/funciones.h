#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "clases.h"
#include <iostream>
#include <string>
using namespace std;

void verificarCodigo(redEstaciones& red, string&cod);
void verificarRegion(string& reg);
void verificarGps(redEstaciones& red,string& coordenada1,string& coordenada2,string& coordenada3);
void verificarPrecioCombustible(string& precio);
void verficarYoN(char &opcion);
void verficarOpcion(unsigned char& opc);
void mostrarCodigos(redEstaciones& red);
bool verificarSurtidoresDesactivados(redEstaciones& red, const string&cod);
void verificarCodigoEliminar(redEstaciones& red,string& opc);
bool verificarCodigoSurtidores(redEstaciones& red,string& opc);
#endif // FUNCIONES_H
