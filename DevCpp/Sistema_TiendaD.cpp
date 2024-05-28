#include <iostream>
#include <string>
#include <windows.h>
#include "PersonaD.h"
#include "ProductoD.h"

#define color SetConsoleTextAttribute

using namespace std;

void MenuPrincipal();
void menuCliente(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
        case 1:
            break;
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
		/*color(hConsole, 5);*/cout << "Bienvenido... Que desea hacer?\t";
		color(hConsole, 208);cout << "Administrador";
		color(hConsole, 13);cout << "\n1.-Anadir item a inventario\n2.-Eliminar item de inventario\n3.-Modificar item de inventario\n4.-Mostrar items del inventario\n0.-Cerrar sesion y volver al menu principal\n";cin >> x;
		switch(x){
			case 0:
				MenuPrincipal();
				break;
			case 1:
				break;
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
