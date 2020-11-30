// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#ifndef PAQUETE_C
#define PAQUETE_C
#include <iostream>
#include "Etiqueta.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Paquete{
    private:
        double peso, tamano;
        string orden, datos, paquete;
    public:
        Paquete(){peso = 0;tamano = 0;orden = "";paquete = "";}
        Paquete(string pedido) : orden{pedido}
        {
        }
        void crear(){ 
            paquete+= "El paquete contiene lo siguiente: \n" + orden;
            srand(time(NULL));
            RAND_MAX;
            peso = (rand() % 3)+0.5;
            tamano = (rand() % 20)+0.5;
            paquete+="Tu paquete pesa (kg): " + to_string(peso);
            paquete+="\nTu paquete tiene un volumen de(m^3): " + to_string(tamano);
        }
        void pegar(Etiqueta etiqueta){
          paquete+=etiqueta.getFormato();
        }
        string cerrar(){
            return "Tu paquete esta esperando a ser enviado";
        }
        string getEnvio(){return paquete;}
}; //Clase Paquete

#endif