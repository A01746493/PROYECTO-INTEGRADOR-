// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#ifndef TRABAJADOR_ALMACEN_C
#define TRABAJADOR_ALMACEN_C
#include <iostream>
#include <cstdlib>
#include <ctime>
#include  <string>
using namespace std;

class Trabajador_almacen{
    private:
        string nombre="Isidro";
        string num_id="1459";
        string paquete;
        int entrega;
    public:
        Trabajador_almacen(){nombre="Cesar";num_id="0149";paquete="";entrega=0;}
        Trabajador_almacen(string p) : paquete{p}
        {
        }
        void recibir_pedido(){
            cout << paquete << endl;
            cout << "\nPedido recibido." << endl;
        }
        void fecha_entrega(){
            srand(time(NULL));
            RAND_MAX;
            entrega =  (rand() % 15)+1;
            cout << "La fecha de entrega es en " + to_string(entrega) + " dias." << endl;
        }
        void enviar_paquete(){
            cout << "Tu paquete ha sido enviado con exito, gracias por comprar en J&P Store.\n" << endl;
        }

};

#endif