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
void verificarLitros(string& litros);
void verficarYoN(char &opcion);
void verficarOpcion(unsigned char& opc);
void mostrarCodigos(redEstaciones& red);
bool verificarSurtidoresDesactivados(redEstaciones& red, const string&cod);
void verificarCodigoExistente(redEstaciones& red,string& opc);
bool verificarCodigoSurtidores(redEstaciones& red,string& opc);
void opcionesPorModificar(redEstaciones& red,string& opc);
void verficarOpcionModificar(redEstaciones& red, string& opc, char& opcion);
void mostrarEstacion(redEstaciones& red,string& opc);
#endif // FUNCIONES_H
