/*
  Archivo: Archivo.h
  Autor: Luis Yovany Romo
  Email: luis.romo@correounivalle.edu.co
  Fecha creación: 2018-02-09
  Fecha Última modificación: 2018-02-09
  Versión: 0.1
  Licencia: GPL
*/

// Clase: Archivo
// Responsabilidad: Realizar operaciones sobre una archivo
// ColaboraciÃ³n: ninguna

#ifndef HH_ARCHIVO
#define HH_ARCHIVO

#include <string>
using namespace std;

class Archivo{
    private:
        string nombre;
        string contenido;
        int cantidadLineas;
        void cantidadDeLineas();
        void extraerContenido();

        
        
    public:
        Archivo(string nombre);
        ~Archivo();
        int lineas();
        void setContenido(string contenido);
        string getContenido();
        void setCantidadLineas(int cantidad);
        int getCantidadLineas();
        int frecuenciaAbsoluta(string contenido, int numHijos);
        void setFrecuenciasAbsolutas(string contenido);
        void setFrecuenciasAcumuladas(string contenido);
        void setFrecuenciasRelativas(string contenido);
        void setFrecuenciasRelativasAcumuladas(string contenido);
        void setCantidadHijos();
        void generarTabla();
//        void frecuenciasAbsolutas2(string contenido);
        int frecuenciasAbsolutas[10];
        int frecuenciasAcumuladas[10];
        double frecuenciasRelativas[10];
        double frecuenciasRelativasAcumuladas[10];
        int cantidadHijos[10];
        int maximoHijos(string contenido, int maximoHijos);
        int masHijos(string contenido, int masHijos, int hastaHijos);
        double porcentajeFamilias(string contenido, int masHijos);

};

#endif
