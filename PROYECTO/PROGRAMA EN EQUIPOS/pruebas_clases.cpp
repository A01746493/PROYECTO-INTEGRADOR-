#include "Cliente.h" 
#include <iostream>
#include "Trabajador_ventas.h"
#include "Trabajador_almacen.h"
using namespace std;

int main(int argc, char const*argv[])
{ 
 Cliente jose;
    jose.registrarse();
    jose.seleccionar(1);
    cout << jose.getDatos() << endl;
    cout << jose.getCorreo() << endl;
    cout << jose.getCantidad() << endl;
    cout << jose.getCobrar() << endl;
    jose.confirmar();
    jose.crear_etiqueta();
    jose.pagar();
    jose.crear_paquete();
    cout << jose.getOrden() << endl;
 Trabajador_ventas paulo(jose.getOrden(), jose.getCobrar(), jose.getPagar());  
    paulo.confirmar_orden();
    paulo.confirmar_pago();
    paulo.estatus_orden();
Trabajador_almacen cesar(jose.getOrden());
    cesar.recibir_pedido();
    cesar.fecha_entrega();
    cesar.enviar_paquete();

return 0;
}