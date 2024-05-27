#include <iostream>
#include <string>
#include "PersonaD.h"
#include "ProductoD.h"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"      
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace std;
void menuAdmin();
void MenuPrincipal(){
	int x;
	do{
		cout << GREEN << "Bienvenido a la tienda de abarrotes ...Que desea hacer? " << BLUE <<"\n1.-Comprar siendo cliente\n "<< MAGENTA << "2.-Administrar tienda	" << RED <<"\n0.-Salir del sistema\n" << RESET;cin >> x;
		switch(x){
			case 0:
				cout << "Saliendo del sistema...\n";
				exit(0);
				break;
			case 1:
				cout << "Comprando...\n";
				break;
			case 2:
				cout << "Entrando como administrador...\n";
				menuAdmin();
				break;
			default:
				cout << "Opcion invalida, Intenta de nuevo\n";
				break;
		}
	}while(x != 0);
}
void menuAdmin(){
	string usuario = "admin";
	string usuarioUser;
	int contrasena = 1234, contrasenaUser = 0, x = 0;
	do{
		cout << "Ingrese el usuario (x para cancelar):\n";cin >> usuarioUser;
		if(usuarioUser == "x"){
			MenuPrincipal();
		}
		cout << "Ingrese la contrasena: \n";cin >> contrasenaUser;
		if(contrasena != contrasenaUser){
			cout << "Contrasena incorrecta, Intentelo de nuevo...\n";
		}
	}while(contrasena != contrasenaUser);
	do{
		cout << "Bienvenido " << usuario << " ...Que desea hacer?:	\n1.-Anadir item a inventario\n2.-Eliminar item de inventario\n3.-Modificar item de inventario\n4.-Mostrar items del inventario\n0.-Cerrar sesion y volver al menu principal\n";cin >> x;	
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
			default:
				cout << "Opcion invalida, Intentelo de nuevo...\n";
		}
	}while(x == 0);
}

int main() {
	//Ingresar constructor de Tienda
	//Ingresar constructor de Cliente
	//El constructor de Empleado se da de alta en el sistema
	//El constructor de NoPerecederos y Perecederos se dan de alta en el sistema
	MenuPrincipal();
	return 0;
}
