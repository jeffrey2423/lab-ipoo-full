/*
  Archivo: Main.cpp
  Autor: Luis Yovany Romo Portilla
  Email: luis.romo@correounivalle.edu.co
  Fecha creaciC3n: 2017-08-11
  Fecha C:ltima modificaciC3n: 2017-08-31
  VersiC3n: 0.1 
  Licencia: GPL
*/

//Utilidad: Controlar las operaciones a realizar en encuesta

#include <iostream>
#include <string>
#include <math.h>
#include "archivo.h"

 
using namespace std;

 
int main () {
    
  
    string nombre = "encuesta.txt";
    Archivo archivo(nombre);
    string linea;
    int cantidad = archivo.lineas();
    string contenido = archivo.getContenido();
    
    int hijos[cantidad];
    /*
    for (int i = 0 ; i < cantidad ;i++){
        hijos[i] = (int)contenido[i]  - 48;  
        cout << contenido[i];
    }*/
  

archivo.setFrecuenciasAbsolutas(contenido);
archivo.setFrecuenciasAcumuladas(contenido);
archivo.setFrecuenciasRelativas(contenido);
archivo.setFrecuenciasRelativasAcumuladas(contenido);
archivo.setCantidadHijos();
/*
cout << endl << archivo.frecuenciaAbsoluta(contenido,2) << endl;
cout << archivo.frecuenciasAbsolutas[2] << endl;
cout << archivo.frecuenciasAcumuladas[2] << endl;

//cout << contenido.length() << endl;

cout << archivo.frecuenciasRelativas[8] << endl;
cout << archivo.frecuenciasRelativasAcumuladas[8] << endl;

cout << archivo.frecuenciasRelativas[9] << endl;
cout << archivo.frecuenciasRelativasAcumuladas[9] << endl;
cout << archivo.cantidadHijos[5] << endl;*/


	
    int a = 0;
  while (a != 5)
    {



      cout <<endl<<endl<<
	"::::::::::::::::::::::::::::::::::::::::::::::::::::::MENU::::::::::::::::::::::::::::::::::::::::::::::::::::::::: : "
	<< endl;
  cout << "1: TABLA DE DISTRIBUCION"<< endl;
  cout <<"2: CUANTAS FAMILIAS TIENEN UN NUMERO DETERMINADO DE HIJOS (de cero hasta el numero que acaba de digitar)"<< endl;
  
  cout <<"3: CUANTAS FAMILIAS TIENEN UN NUMERO DETERNIMADO DE HIJOS EN UN RANGO ESPECIFICO (mas del primer valor hasta el segundo valor)"<< endl;
	
  cout <<"4: PORCENTAJE DE FAMILIAS QUE TIENEN MAS DE UN NUMERO DETERMINADO DE HIJOS"<< endl;
  cout <<"5: salir"<< endl;
  cout << " su opcion:  ";



      cin >> a;
      switch (a)
	{

	case 1:


    cout<< ":::::::::::::::TABLA DE DISTRIBUCION::::::::::::::::::::::::::"<<endl;
    
    archivo.generarTabla();

	  break;

	case 2:
    int maximoHijos;
    cout<< "digite el valor maximo de hijos" <<endl;
    cin>>maximoHijos;
    cout<<"la cantidad de familias que su cantidad de hijos esta entre 0 y "<< maximoHijos << "es: "<<archivo.maximoHijos(contenido, maximoHijos);

	  break;

	case 3:


      int masHijos;
    int hastaHijos;
    cout<< "digite el valor minimo de hijos" <<endl;
    cin>>masHijos;
    cout<< "digite el valor maximo de hijos" <<endl;
    cin>>hastaHijos;
    cout<<"la cantidad de familias que tienen mas de  "<<masHijos<< " y menos o igual a "<< hastaHijos<< " hijos son : "<<archivo.masHijos(contenido, masHijos, hastaHijos)<<endl;


	  break;

	case 4:

          int masHijosp;
   
    cout<< "digite el valor minimo de hijos(no toma este valor)" <<endl;
    cin>>masHijosp;

    cout<<"la cantidad de familias que tienen mas de  "<<masHijosp<< " hijos corresponde al: "<<archivo.porcentajeFamilias(contenido, masHijosp)<<" %"<<endl;
    
	  break;


	}


  }


    
    return 0;
}
