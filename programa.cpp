#include "Cliente.h" // Inclui mi archivo .h
#include "Etiqueta.h"
#include <iostream>
using namespace  std;
int main(int argc, char const*argv[])
{   
    int producto{};
    int i=1;
    cout << "Registro de Cliente" << endl;
    Cliente jose;
    jose.registrarse();
    cout << "Cuantos productos quieres comprar ";cin >> producto;
    jose.seleccionar(producto);
    jose.confirmar();
    jose.pagar();
    Etiqueta pol(jose.getDatos());
    pol.fehca_hoy();
    pol.crear();
    pol.guardar();
    cout << "Los datos de la etiqueta son \n" + pol.getFormato()<< endl;
    
    return 0;
}