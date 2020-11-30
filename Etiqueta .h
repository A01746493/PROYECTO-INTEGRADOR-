#ifndef ETIQUETA_C
#define ETIQUETA_C
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace  std;

class Etiqueta{
    private:
        string datos,fecha,formato;
        int No_paquete;
        vector<string> base_de_datos{};
    public:
    Etiqueta(string ficha): datos{ficha}
    {
    }
    void fehca_hoy(){
         time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        fecha = asctime(timeinfo);
        
    }
    void crear(){
        formato+=datos;
        formato+= "Fecha de envio: "+fecha;
        srand(time(NULL));
        RAND_MAX;
        No_paquete =  (rand() % 2000)+1;
        formato+= "Numero de pedido: " + to_string(No_paquete) + "\n";
    }//Metodo crear
    string getFormato(){return formato;};
    void guardar(){
        base_de_datos.push_back(formato);
    }//Guardar datos
};//Clase cleinte

#endif