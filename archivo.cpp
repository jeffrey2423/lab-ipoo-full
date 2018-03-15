/*
  Archivo: Archivo.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2017-08-31
  Fecha última modificación: 2017-08-31
  Versión: 0.1
  Licencia: GPL
*/

#include <iostream>
#include <fstream>
#include "archivo.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

Archivo::Archivo(string nombre){
    this->nombre = nombre;
    this->cantidadLineas = 0;
    this->contenido = "";
    cantidadDeLineas();
    extraerContenido();
    }


Archivo::~Archivo(){
    
}


void Archivo::setCantidadLineas(int cantidad){
    this -> cantidadLineas = cantidad;
}

string Archivo::getContenido(){
    return contenido;
}

void Archivo::setContenido(string contenido){
    this -> contenido = contenido;
}

int Archivo::getCantidadLineas(){
    return cantidadLineas;
}

int Archivo::lineas(){
    fstream archivo;  //Define un objeto de la clas fstream, manejo de arvhico para lectura y escritura
    string linea;
    int cantidad;
    archivo.open ( nombre , ios::in);  // Abre el archivo con el nombre especificado con derechos de lectura
    if (archivo.is_open()) { //Evalua si el archivo está abierto
        cantidad = 0;
        archivo.seekg (0, archivo.end);
        int cantidad = archivo.tellg();
        archivo.seekg (0, archivo.beg);

        archivo.close(); //Cierra el archivo
        return cantidad ;
    }
    else{
      cout << "Archivo inexistente o faltan permisos para abrirlo" << endl;    
    } 

}

//Retrona la cantidad de lineas que contiene el archvio
void Archivo::cantidadDeLineas(){
    fstream archivo;  //Define un objeto de la clas fstream, manejo de arvhico para lectura y escritura
    string linea;
    int cantidad;
    archivo.open ( nombre , ios::in);  // Abre el archivo con el nombre especificado con derechos de lectura
    if (archivo.is_open()) { //Evalua si el archivo está abierto
        cantidad = 0;
        while (! archivo.eof() ) { //Evalua si ha llegado al final del Archivo
            getline (archivo,linea); //Extrae el contenido de la fila actual del archivo a la variable linea
            cantidad++;
        }

        archivo.close(); //Cierra el archivo
        setCantidadLineas(cantidad) ;
    }
    else{
      cout << "Archivo inexistente o faltan permisos para abrirlo" << endl;    
    } 

}

void Archivo::extraerContenido(){
    fstream archivo;
    string linea;
    string contenido;
    int cantidad;
    archivo.open ( nombre , ios::in);
    if (archivo.is_open()) {
        cantidad = 0;
        while (! archivo.eof() ) {
            getline (archivo,linea);
            contenido = contenido + linea;
            cout << linea << " - ";
        }

        archivo.close();
        setContenido(contenido) ;
    }
    else{
      cout << "Archivo inexistente o faltan permisos para abrirlo" << endl;    
    }  
}

int Archivo::frecuenciaAbsoluta(string contenido, int numHijos)
{
  int contador=0;
  for(int i=0; i<contenido.length(); i++)
  {
    if (((int)contenido[i] - 48) == numHijos)
    {
      contador++;
    }
//    cout << contenido[i] << "-";
  
  }
  return contador;
}

/*
string Archivo::frecuenciasAbsolutas(string contenido)
{
  string frecuenciasAbsolutas;
  for(int i=0; i<10; i++)
  {
    frecuenciasAbsolutas = frecuenciasAbsolutas + to_string(frecuenciaAbsoluta(contenido, i));
//   cout << frecuenciasAbsolutas[i] << "-";
  }
return frecuenciasAbsolutas;
}
*/

void Archivo::setFrecuenciasAbsolutas(string contenido)
{
  int frecuenciasAbsolutas[10];
  for(int i=0; i<10; i++)
  {
    this -> frecuenciasAbsolutas[i] = frecuenciaAbsoluta(contenido, i);
  }
}

void Archivo::setFrecuenciasAcumuladas(string contenido)
{
  int temporal = 0;
  for(int i=0; i<10; i++)
  {
    this -> frecuenciasAcumuladas[i] = (frecuenciaAbsoluta(contenido, i)  + temporal);
    temporal = temporal + frecuenciaAbsoluta(contenido, i);
  }
}

void Archivo::setFrecuenciasRelativas(string contenido)
{
  for(int i=0; i<10; i++)
  {
    this -> frecuenciasRelativas[i] = (double)frecuenciasAbsolutas[i] / contenido.length();
  }
}

void Archivo::setFrecuenciasRelativasAcumuladas(string contenido)
{
  double temporal = 0;
  for(int i=0; i<10; i++)
  {
    this -> frecuenciasRelativasAcumuladas[i] = this -> frecuenciasRelativas[i] + temporal;
    temporal = temporal + frecuenciasRelativas[i];

  }
}

void Archivo::setCantidadHijos(){
  int cantidadHijos[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int filas = sizeof this->cantidadHijos / sizeof *this->cantidadHijos;
  for(int i = 0; i< filas; i++){
    this->cantidadHijos[i] = cantidadHijos[i];
  }
}

void Archivo::generarTabla()
{
  int filas = 10;
  int columnas = 4;
  
  cout << "Hijos" << setw(5) << "f" << setw(8) << "F" << setw(10) << "h" << setw(12) << "H" << endl;
  cout << "=====================================================" << endl;
  for (int i = 0 ; i < filas; i++){
    int contador=1;
    cout << setw(3) << cantidadHijos[i] << setw(9);
    for (int j = 0; j < columnas; j++){
      
      if(contador == 1)
      {
      cout << this -> frecuenciasAbsolutas[i] << setw(8);
      }
      if(contador == 2)
      {
      cout << this -> frecuenciasAcumuladas[i] << setw(12);
      }
      if(contador == 3)
      {
      cout << this -> frecuenciasRelativas[i] << setw(12);
      }
      if(contador == 4)
      {
      cout << this -> frecuenciasRelativasAcumuladas[i] << setw(12);
      }
      contador++;
      }
      
    cout << endl;
  }
  
}

int Archivo::maximoHijos(string contenido, int maximoHijos)
{
    
  int cont=0;
  for(int i=0; i<contenido.length(); i++)
  {
    if (((int)contenido[i] - 48) >= 0 && ((int)contenido[i] - 48) <= maximoHijos)
    {
      cont++;
    }

  
  }
  return cont;
  
}

int Archivo::masHijos(string contenido, int masHijos, int maximoHijos)
{
    
  int conta=0;
  for(int i=0; i<contenido.length(); i++)
  {
    if (((int)contenido[i] - 48) > masHijos && ((int)contenido[i] - 48) <= maximoHijos)
    {
      conta++;
    }

  
  }
  return conta;
  
}

double Archivo::porcentajeFamilias(string contenido, int masHijosp){
  
    int conta=0;
    double porcent;
  for(int i=0; i<contenido.length(); i++)
  {
    if (((int)contenido[i] - 48) > masHijosp)
    {
      conta++;
    }

  
  }
  porcent = (double)conta / contenido.length()*100;
  return porcent;
  
}

