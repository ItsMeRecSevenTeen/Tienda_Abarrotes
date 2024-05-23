#include <iostream>
#include "Persona.h"
#include "Producto.h"
using namespace std;

void MenuPrincipal(){
	int x;
	do{
		cout << "Bienvenido a la tienda de abarrotes ¿Que desea hacer? 1.-Comprar siendo cliente	2.-Administrar tienda	0.-Salir del sistema\n";cin >> x;
		switch(x){
			case 0:
				cout << "Saliendo del sistema...\n";
				break;
			case 1:
				cout << "Comprando...\n";
				break;
			case 2:
				cout << "Entrando como administrador...\n";
				break;
			default:
				cout << "Opcion invalida, Intenta de nuevo\n";
				break;
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
