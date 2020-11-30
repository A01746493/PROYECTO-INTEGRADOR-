// José Luis Madrigal Sánchez A01745419
// César Emiliano Palome Luna A01746493
#ifndef CLIENTE_C
#define CLIENTE_C
#include <string>
#include <iostream>
#include "Paquete.h"
#include "Etiqueta.h"
using namespace std;

class Cliente{
    private:
        string nombre, correo, direccion, datos, telefono;
        float pago, cobro;
        int productos;
        string orden{};
        Paquete paquete{};
        Etiqueta etiqueta{};
    public:
        Cliente(){nombre = "";direccion = "";correo = "";telefono = "";paquete = Paquete {};pago = 0;cobro = 0;productos = 0;orden = "";etiqueta = Etiqueta{};}
        void registrarse (){
            cout << "\nDame tu nombre: "; getline(cin,nombre);
            cout << "\nDame tu direccion: "; getline(cin,direccion);
            cout << "\nDame tu correo: "; cin >> correo;
            cout << "\nDame tu telefono: ";cin >>telefono; 
            datos+= "Nombre: " + nombre +"\n";
            datos+= "Correo: " + correo + "\n";
            datos+= "Direccion: " + direccion + "\n";
            datos+="Telefono: " + telefono + "\n";
        }//registro
        string getDatos(){return datos;};
        string getCorreo(){return correo;};
        void seleccionar(int producto){
            int opcion,modelo,sudadera{0},gorra{0},pantalon{0};
            productos=producto;
            string tipo[]={"Sudaderas","Gorras","Pantalon"};
            for (int i=1; i < productos+1; i++){
                cout << "\nSelecciona la opcion que deseas buscar: \n" << endl;
                for (int j = 0; j < 3; j++){
                    cout << to_string(j+1)+ ".-" + tipo[j] << endl; 
                    }//Menu1
                cin >> opcion;
                switch (opcion){
                case 1:
                    cout << "\n1.- Sudadera de Nike $1,500\n"<<"2.- Sudadera Jolo $3,800\n"<<"3.- Sudadera Pol $6,500"<<endl;
                    cin >> modelo;
                    if (modelo == 1){
                        cobro=cobro+1500;
                        sudadera+=1;}
                    else if (modelo == 2){
                        cobro=cobro+3800;
                        sudadera+=1;}
                    else{
                        cobro=cobro+6500;
                        sudadera+=1;}
                break;
                case 2:
                    cout << "\n1.- Gorra de Nike $650\n"<<"2.- Gorra Jolo $350\n"<<"3.- Gorra Pol $250"<<endl;
                    cin >> modelo;
                        if (modelo == 1){
                            cobro=cobro+650;
                            gorra+=1;}
                        else if (modelo == 2){
                            cobro=cobro+350;
                            gorra+=1;}
                        else{
                            cobro=cobro+250;
                            gorra+=1;}
                break;
                default:
                    cout << "\n1.- Pantalon de Puma $950\n"<<"2.- Pantalon Reebok $1,200\n"<<"3.- Pantalon Onorable $3,945" <<endl;
                    cin >> modelo;
                        if (modelo == 1){
                            cobro=cobro+950;
                            pantalon+=1;}
                        else if (modelo == 2){
                            cobro=cobro+1200;
                            pantalon+=1;}
                        else{
                            cobro=cobro+3945;
                            pantalon+=1;}   
            }//Switch
            }//For para contar los productos 
            orden+="Sudaderas: " +to_string(sudadera)+"\n";
            orden+="Gorras: " +to_string(gorra)+"\n";
            orden+="Pantalones: " +to_string(pantalon)+"\n";
        }//Seleccionar funcion   
        string getCantidad(){return orden;};
        float getCobro(){return cobro;};
        void confirmar(){
            string respuesta;
            cout << "\nConfirmar orden de productos comprados "<<endl;
            cout << orden << endl;
            cout << "Por pagar "<<endl;
            cout << "$" +to_string(cobro);
        }
        void pagar(){
            string respuesta2;
            cout << "\nRealiza el pago" << endl;
            cout << "Ingresa la cantidad a pagar: $"; cin >> pago;
            cout << "\nEs correcta la cantidad de $" + to_string(pago) + "?(si/no)\n";
        }
        
        void crear_etiqueta(){
            Etiqueta etiqueta(datos);
            etiqueta.crear();
            etiqueta.guardar();
            this->etiqueta = etiqueta;
        }

        void crear_paquete(){
            Paquete paquete(orden);
            paquete.crear();
            paquete.pegar(etiqueta);
            cout << paquete.cerrar() << endl;
            cout << paquete.getEnvio() << endl;
        }
        string getOrden(){return paquete.getEnvio();}
        double getPagar(){return pago;}
        double getCobrar(){return cobro;}
};
#endif