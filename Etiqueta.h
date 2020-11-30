// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#ifndef ETIQUETA_C
#define ETIQUETA_C
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
using namespace std;

class Etiqueta{
    private:
        string datos,fecha,formato;
        int num_paquete;
        vector<string> base_de_datos{};
    public:
    Etiqueta(){datos ="";fecha = "";formato = "";num_paquete = 0;base_de_datos = {};}
    Etiqueta(string info): datos{info}
    {
    }
    void crear(){
        time_t now = time(0);
        tm* localtm = localtime(&now);
        fecha = asctime(localtm);
        formato += "\n***Etiqueta***\n";
        formato+=datos;
        formato+= "Fecha de pedido: "+ fecha;
        srand(time(NULL));
        RAND_MAX;
        num_paquete =  (rand() % 2000)+1;
        formato+= "Numero de pedido: " + to_string(num_paquete) + "\n";
    }//Metodo crear
    string getFormato(){return formato;}
    void guardar(){
        base_de_datos.push_back(formato);
    }//Guardar datos
};//Clase Etiqueta

#endif