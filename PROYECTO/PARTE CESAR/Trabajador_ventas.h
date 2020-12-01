// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#ifndef TRABAJADOR_VENTAS_C
#define TRABAJADOR_VENTAS_C
#include <string>
#include <iostream>
using namespace std;

class Trabajador_ventas{
    private:
        string nombre="Manolo";
        string num_id="6913";
        string orden_f;
        int cobrado;
        int pagado;
    public:
        Trabajador_ventas(){nombre = "Fernando";num_id = "00730";orden_f = "";cobrado=0;pagado=0;}
        Trabajador_ventas(string pedido,int c,int p) : orden_f{pedido},cobrado{c},pagado{p}
        {
        }

        void confirmar_orden(){
            cout << "Favor de confirmar la siguiente orden"<< endl;
            cout << orden_f << endl;
        }

        void confirmar_pago(){
            if (pagado == cobrado){
                cout << "Gracias, pago correcto." << endl;
            }
            else if (pagado < cobrado){
                cout << "Con un limite de 12 hrs, favor de depositar la diferencia de: $" + to_string(cobrado-pagado) << endl;
            }
            else{
                cout << "Gracias por su donacion de: $" + to_string(pagado-cobrado) << endl;
            }
        }

        void estatus_orden(){
            cout << "Tu orden ha sido enviada a almacen." << endl;
        }
}; //Clase Trabajador_ventas

#endif