#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>  // Para ofstream
#include <iostream> // Para cout
#include "Persona.h"
#include "Producto.h"

#define color SetConsoleTextAttribute

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
Producto::Producto(){
	cout << "Ingrese el nombre del producto: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 208);cin>>nombre;
	color(hConsole, 13);cout << "Ingrese la fecha de caducidad: ";color(hConsole, 6);cout << "\t'dd/mm/aaaa'\n";color(hConsole, 208);cin>>fechadecad;
	color(hConsole, 13);cout << "Cuanto contenido neto tiene el producto?: ";color(hConsole, 6);cout << "\t(grs, kgs, mls, lts, gls)\n";color(hConsole, 208);cin>>cantidad;
	color(hConsole, 13);cout << "Ingrese la cantidad de productos?: ";color(hConsole, 6);cout << "\tUn numero\n";color(hConsole, 208);cin>>unidades;
	color(hConsole, 13);cout << "Ingrese el precio unitario del producto?: ";color(hConsole, 6);cout << "\tPrecio con 2 decimas de centavo\n";color(hConsole, 208);cin>>precio;
}
Perecederos::Perecederos(){
    color(hConsole, 13);cout << "Cual es la temperatura de almacenamiento del producto perecedero?: ";color(hConsole, 6);cout << "\tUn numero, °C\n";cin >> temperaturaalmacencelcius;
    color(hConsole, 13);cout << "Tipo de almacenamiento que requiere el producto?: ";color(hConsole, 6);cout << "\t(Ambiente,Refrigeracion, Congelacion)\n";cin>> tipoconservacion;
}
void Perecederos::DarAlta(Perecederos miPerecedero){
    ofstream fich("Articulos.txt");
  				if (!fich){
				    cout << "Error al abrir Articulos.txt\n";
    				exit(EXIT_FAILURE);
				}
				fich << miPerecedero.codigo << "," << miPerecedero.nombre << "," << miPerecedero.cantidad << "," << miPerecedero.precio << "," << miPerecedero.fechadecad << "," << miPerecedero.unidades << "\n";
}

void MenuPrincipal();
void menuCliente(){
    int x;
    do{
        color(hConsole, 1);cout << "Que desea realizar?\t";
        color(hConsole, 16);cout << "Cliente";
        color(hConsole, 1);cout << "\n1.-Adquirir articulos\n2.-Ver Carrito\n3.-Pagar Carrito\n4.-Regresar al menu principal\n0.-Salir del sistema\n";cin >> x;
        switch(x){
        case 0:
            color(hConsole, 6);
            cout << "Saliendo del sistema";
            exit(0);
            break;
        case 1:{
			break;
		}
        case 2:
            break;
        case 3:
            break;
        case 4:
            MenuPrincipal();
            break;
        default:
            color(hConsole, 64);
			cout << "Opcion invalida, Intentelo de nuevo...\n";
            color(hConsole, 2);
        }
    }while(x != 0);
}
void menuAdmin();
void MenuPrincipal(){
	int x;
	do{
 		color(hConsole, 2);cout << "Bienvenido a la tienda de abarrotes... Que desea hacer? \t";
 		color(hConsole, 32);cout << "Usuario";
 		color(hConsole, 2);cout << "\n1.-Comprar siendo cliente\n"<< "2.-Administrar tienda	" << "\n0.-Salir del sistema\n";cin >> x;
		switch(x){
			case 0:
			    color(hConsole, 6);cout << "Saliendo del sistema...\n";
				exit(0);
				break;
			case 1:{
				menuCliente();
				break;
			}
			case 2:
				menuAdmin();
				break;
			default:
			    color(hConsole, 64);
				cout << "Opcion invalida, Intenta de nuevo\n";
				color(hConsole, 2);
				break;
		}
	}while(x != 0);
}
void menuAdmin(){
 	color(hConsole, 13);cout << "Entrando como administrador...\n";

	string usuario = "admin", contrasena = "1234", contrasenaUser = "0";
	string usuarioUser;
	int x = 0;
	do{
		cout << "Ingrese el usuario (x para cancelar):\n";cin >> usuarioUser;
		if(usuarioUser == "x"){
			MenuPrincipal();
		}
		else if(usuarioUser != usuario){
            color(hConsole, 64);cout << "Usuario incorrecto...Intentelo de nuevo\n";
            color(hConsole, 13);
		}
		else{
			cout << "Ingrese la contrasena: \n";cin >> contrasenaUser;
			if(contrasena != contrasenaUser){
                color(hConsole, 64);cout << "Contrasena incorrecta, Intentelo de nuevo\n";
                color(hConsole, 13);
			}
		}
	}while(contrasena != contrasenaUser);
	do{
		color(hConsole, 13);cout << "Bienvenido... Que desea hacer?\t";
		color(hConsole, 208);cout << "Administrador";
		color(hConsole, 13);cout << "\n1.-Anadir item a inventario\n2.-Eliminar item de inventario\n3.-Modificar item de inventario\n4.-Mostrar items del inventario\n0.-Cerrar sesion y volver al menu principal\n";cin >> x;
		switch(x){
			case 0:
				MenuPrincipal();
				break;
			case 1:
                cout << "Que tipo de articulo anadira al inventario?\n1.-Perecedero\n2.-No Perecedero\n";cin >> x;
			    switch(x){
                    case 1:{
                        Perecederos miPerecedero;
                        miPerecedero.DarAlta(miPerecedero);
                        color(hConsole, 6);cout << "Producto anadido al inventario\n";
                        break;
                    }
                    case 2:{
                    }
                    default:
                    color(hConsole, 64);
                    cout << "Opcion invalida, Intentelo de nuevo...\n";
                    color(hConsole, 2);
			    }
			case 2:
				break;
			case 3:
				break;
            case 4:
                break;
			default:
			    color(hConsole, 64);
				cout << "Opcion invalida, Intentelo de nuevo...\n";
				color(hConsole, 2);
		}
	}while(x != 0);
}

int main() {
	//Ingresar constructor de Tienda
	//Ingresar constructor de Cliente
	//El constructor de Empleado se da de alta en el sistema
	//El constructor de NoPerecederos y Perecederos se dan de alta en el sistema
	MenuPrincipal();
	return 0;
}
