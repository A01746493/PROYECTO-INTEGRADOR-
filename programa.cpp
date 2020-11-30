// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#include "Cliente.h" 
#include <iostream>
#include "Trabajador_ventas.h"
#include "Trabajador_almacen.h"
using namespace std;
int main(int argc, char const*argv[])
{   
    int producto{};
    int i=1;
    string confi_orden;
    string respuesta;
    string respuesta2;
    cout << "\nJ&P Store (Jolo Y Palome)\n";
    cout << "Registro de Cliente" << endl;
    Cliente jose;
    jose.registrarse();
    cout << "\nCuantos productos quieres comprar? ";cin >> producto;
    jose.seleccionar(producto);
    jose.confirmar();
    cout << "\nEsta bien tu pedido?(si/no)\n";cin >> respuesta;
    if (respuesta =="si"){
        cout <<"\nTu pedido sera enviado a ventas\n";
        jose.pagar();
        cin >> respuesta2;
        if (respuesta2 =="si"){
            cout <<"\nTu pago fue realizado y mandado a ventas\n";
            jose.crear_etiqueta();
            jose.crear_paquete();
            Trabajador_ventas manolo(jose.getOrden(), jose.getCobrar(), jose.getPagar());
            manolo.confirmar_orden();
            cout << "(si/no): " ; cin >> confi_orden;
            if (confi_orden=="no"){
                cout << "Error de nuestro sistema, intente mas tarde. " << endl;
            }
            else{
                manolo.confirmar_pago();
                manolo.estatus_orden();
                Trabajador_almacen pol(jose.getOrden());
                pol.recibir_pedido();
                pol.fecha_entrega();
                pol.enviar_paquete();
            }
        }
        else{
            cout<< "Error de nuestro sistema, intente mas tarde. " << endl;
        }
    }
    else{
        cout << "Error de nuestro sistema, intente mas tarde. " << endl;
    }
}