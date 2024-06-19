#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>  // Para ofstream
#include <iostream> // Para cout
#include <vector>
#include <sstream>
#include "Persona.h"
#include "Producto.h"

#define color SetConsoleTextAttribute

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//Constructores
Tienda::Tienda(){
    color(hConsole, 2);cout << "Ingrese el nombre de la tienda: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 2);cin>>nombre;
    color(hConsole, 2);cout << "Ingrese la direccion de la tienda: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 2);cin>>direccion;
}
Persona::Persona(){
    color(hConsole, 1);cout << "Ingrese su nombre: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 1);cin>>nombre;
}
Cliente::Cliente(){
    color(hConsole, 1);cout << "Ingrese su direccion: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 1);cin>>direccion;
    color(hConsole, 1);cout << "Ingrese su numero de telefono:";color(hConsole, 6);cout << "\tNumerico, 10 digitos\n";color(hConsole, 1);cin>>numtel;
}
Producto::Producto(){
    color(hConsole, 13);cout << "Ingrese el codigo del producto: ";color(hConsole, 6);cout << "\tNumerico\n";color(hConsole, 208);cin>>codigo;
	color(hConsole, 13);cout << "Ingrese el nombre del producto: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 208);cin>>nombre;
	color(hConsole, 13);cout << "Ingrese la fecha de caducidad: ";color(hConsole, 6);cout << "\t'dd/mm/aaaa'\n";color(hConsole, 208);cin>>fechadecad;
	color(hConsole, 13);cout << "Cuanto contenido neto tiene el producto?: ";color(hConsole, 6);cout << "\t(grs, kgs, mls, lts, gls)\n";color(hConsole, 208);cin>>cantidad;
	color(hConsole, 13);cout << "Ingrese la cantidad de productos?: ";color(hConsole, 6);cout << "\tUn numero\n";color(hConsole, 208);cin>>unidades;
	color(hConsole, 13);cout << "Ingrese el precio unitario del producto?: ";color(hConsole, 6);cout << "\tPrecio con 2 decimas de centavo\n";color(hConsole, 208);cin>>precio;
}
Perecederos::Perecederos(){
    color(hConsole, 13);cout << "Cual es la temperatura de almacenamiento del producto perecedero?: ";color(hConsole, 6);cout << "\tUn numero, Grados Celsius\n";color(hConsole, 208);cin >> temperaturaalmacencelcius;
    color(hConsole, 13);cout << "Tipo de almacenamiento que requiere el producto?: ";color(hConsole, 6);cout << "\t(Ambiente, Refrigeracion, Congelacion)\n";color(hConsole, 208);cin>> tipoconservacion;
}
NoPerecederos::NoPerecederos(){
    color(hConsole, 13);cout << "De que pais proviene el producto NO perecedero?: ";color(hConsole, 6);cout << "\tUn pais, Sin espacios, 20 caracteres\n";color(hConsole, 208);cin >> paisdeorigen;
    color(hConsole, 13);cout << "En que fecha fue producido el producto?: ";color(hConsole, 6);cout << "\t'dd/mm/aaaa'\n";color(hConsole, 208);cin >> fechaorigen;
}
//Fin de constructores
void Cliente::adquirirArticulos(){
    vector<string> inventario, carrito;
    string lineaProducto, codigoUsuario, respuestaUsuario;

    ifstream archivoLectura("Articulos.txt");
    if (archivoLectura.is_open()){
        while (getline(archivoLectura, lineaProducto)){
            inventario.push_back(lineaProducto);
        }
        archivoLectura.close();
            vector<string> camposProducto;
            string campo;
        do{
            cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
            for (int i = 0 ;i < inventario.size(); i++){//Mostrando el vector con los datos del fichero
                stringstream ss(inventario[i]);
                while (getline(ss, campo, ',')) {
                    camposProducto.push_back(campo);
                }
                cout << "Codigo: " << camposProducto[0] << " \tProducto: " << camposProducto[1] << " \tCantidad: " << camposProducto[2] << " \tUnidades en stock: " << camposProducto[3] << " \tFecha de Caducidad: " << camposProducto[4] << " \tPrecio unitario: " << camposProducto[5] << endl;
                camposProducto.clear();
            }
            cout << endl;
        cout << "\nIngrese el codigo del producto que va a adquirir (x para cancelar):\n";cin >> codigoUsuario;
        if(codigoUsuario == "x"){
            break;
        }else{
            stringstream ss(inventario[stoi(codigoUsuario) - 1]);
            while (getline(ss, campo, ',')) {
                    camposProducto.push_back(campo);
                }
                cout << "Cuantos " << camposProducto[1] << "(s) desea adquirir?" << camposProducto[3] << "Unidades disponibles";cin >> respuestaUsuario;
                if(stoi(camposProducto[3]) >= stoi(respuestaUsuario)){
                    int cantidadProducto = stoi(camposProducto[3]);
                    cantidadProducto -= stoi(respuestaUsuario);
                    camposProducto[3] = to_string(cantidadProducto);
                    carrito.push_back(camposProducto[0] + "," + camposProducto[1] + "," + camposProducto[2] + "," + respuestaUsuario);
                    cout << "Adquirio " << respuestaUsuario << camposProducto[1] << "(s)";
                }else{
                cout << "No puedes comprar mas de la existencia";
                }
        }
        }while(codigoUsuario != "x");

        // anadiendo los articulos adquiridos al carrito
        ofstream archivoEscritura("Carrito.txt");
        if (archivoEscritura.is_open()){
            for (const auto& lineaProducto : carrito){
                archivoEscritura << lineaProducto << endl;
            }
            archivoEscritura.close();
        }
        else{
            color(hConsole, 64);
            cout << "Error al abrir el archivo para escritura\n";
            color(hConsole, 2);
        }
        color(hConsole, 96);cout << "Productos anadidos al carrito correctamente\n";
    }
    else{
        color(hConsole, 64);
        cout << "Error al abrir el archivo para lectura\n";
        color(hConsole, 2);
    }
}
void Cliente::verCarrito(){
    ifstream archivoLectura("Carrito.txt");
    archivoLectura.seekg(0, ios::end);
    if (!archivoLectura.is_open() || archivoLectura.tellg() == 0){
        color(hConsole, 64);
        cout << "No has adquirido articulos, Intenta comprar algo para agregarlo a tu carrito de compras\n";
        archivoLectura.close();
    }
}
void Cliente::pagarCarrito(){

}

void Tienda::anadirItemInventario(int x){
    cout << "Que tipo de articulo anadira al inventario?\n1.-Perecedero\n2.-No Perecedero\n";cin >> x;
			    switch(x){
                    case 1:{
                        Perecederos miPerecedero;
                        miPerecedero.DarAlta(miPerecedero);
                        color(hConsole, 96);cout << "Producto anadido al inventario\n";
                        break;
                    }
                    case 2:{
                        NoPerecederos miNoPerecedero;
                        miNoPerecedero.DarAlta(miNoPerecedero);
                        color(hConsole, 96);cout << "Producto anadido al inventario\n";
                        break;
                    }
                    default:{
                        color(hConsole, 64);
                    cout << "Opcion invalida, Intentelo de nuevo...\n";
                    color(hConsole, 2);
                    break;
                    }
			    }
}
void Tienda::eliminarItemInventario(){
    vector<string> lineas;
    string linea;

    // Se lee el fichero y se guardan las líneas en el vector
    ifstream archivoLectura("Articulos.txt");
    if (archivoLectura.is_open()){
        while (getline(archivoLectura, linea)){
            lineas.push_back(linea);
        }
        archivoLectura.close();
        cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
        for (auto x : lineas){//Mostrando el vector con los datos del fichero
            cout << x << endl;
        }
        cout << endl;
        int lineaParaEliminar;
        color(hConsole, 13);
        cout << "Ingrese el codigo del producto a eliminar\n";
        cin >> lineaParaEliminar;
        //Eliminando una línea específica del vector
        if (lineaParaEliminar - 1 < lineas.size()){
            lineas[lineaParaEliminar - 1] = "";
        }
        else{
            cout << "El indice de la linea para eliminar esta fuera de rango." << endl;
        }

        // Escribiendo el contenido modificado de vuelta al fichero
        ofstream archivoEscritura("Articulos.txt");
        if (archivoEscritura.is_open()){
            for (const auto& linea : lineas){
                archivoEscritura << linea << endl;
            }
            archivoEscritura.close();
        }
        else{
            color(hConsole, 64);
            cout << "Error al abrir el archivo para escritura\n";
            color(hConsole, 2);
        }
        color(hConsole, 96);cout << "El producto ha sido eliminado correctamente" << endl;
    }
    else{
        color(hConsole, 64);
        cout << "Error al abrir el archivo para lectura\n";
        color(hConsole, 2);
    }
}

void Tienda::modificarItemInventario(){
    vector<string> lineas;
    string linea;
    ostringstream cadena;
    int x;

    // Se lee el fichero y se guardan las líneas en el vector
    ifstream archivoLectura("Articulos.txt");
    if (archivoLectura.is_open()){
        while (getline(archivoLectura, linea)){
            lineas.push_back(linea);
        }
        archivoLectura.close();
        cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
        for (auto x : lineas){//Mostrando el vector con los datos del fichero
            cout << x << endl;
        }
        cout << endl;
        int lineaParaModificar;
        color(hConsole, 13);
        cout << "Ingrese el codigo del producto a modificar\n";cin >> lineaParaModificar;
        cout << "Que tipo de articulo anadira al inventario?\n1.-Perecedero\n2.-No Perecedero\n";cin >> x;
        switch(x){
            case 1:{
                Perecederos miPerecedero;
                // Modificando una línea específica del vector
                if (lineaParaModificar - 1 < lineas.size()){
                    cadena << miPerecedero.codigo << "," << miPerecedero.nombre << "," << miPerecedero.cantidad << "," << miPerecedero.precio << "," << miPerecedero.fechadecad << "," << miPerecedero.unidades;
                    lineas[lineaParaModificar - 1] = cadena.str();
                }else{
                    cout << "El indice de la linea para modificar está fuera de rango." << endl;
                }
                break;
            }
            case 2:{
                NoPerecederos miNoPerecedero;
                // Modificando una línea específica del vector
                if (lineaParaModificar - 1 < lineas.size()){
                    cadena << miNoPerecedero.codigo << "," << miNoPerecedero.nombre << "," << miNoPerecedero.cantidad << "," << miNoPerecedero.precio << "," << miNoPerecedero.fechadecad << "," << miNoPerecedero.unidades;
                    lineas[lineaParaModificar - 1] = cadena.str();
                }else{
                    cout << "El indice de la linea para modificar está fuera de rango." << endl;
                }
                break;
            }
            default:
                color(hConsole, 64);
                cout << "Opcion invalida, Intentelo de nuevo...\n";
                color(hConsole, 2);
        }
        // Escribiendo el contenido modificado de vuelta al fichero
        ofstream archivoEscritura("Articulos.txt");
        if (archivoEscritura.is_open()){
            for (const auto& linea : lineas){
                archivoEscritura << linea << endl;
            }
            archivoEscritura.close();
        }
        else{
            color(hConsole, 64);
            cout << "Error al abrir el archivo para escritura\n";
            color(hConsole, 2);
        }
        color(hConsole, 96);cout << "Producto modificado del inventario correctamente\n";
    }
    else{
        color(hConsole, 64);
        cout << "Error al abrir el archivo para lectura\n";
        color(hConsole, 2);
    }
}

void Tienda::mostrarItemInventario(){
    ifstream fich("Articulos.txt");
    if (!fich.is_open()){
        color(hConsole, 64);
        cout << "No ha dado de alta nuevos articulos, Intente agregar algunos a su inventario\n";
        color(hConsole, 2);
    }else{
        string valor;
        vector<string> datos;
        while (fich >> valor){
            datos.push_back(valor);
        }
        cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
        for (auto x : datos){
            cout << x << endl;
        }
        cout << endl;
    }
}

void Perecederos::DarAlta(Perecederos miPerecedero){
    vector<string> lineas;
    ostringstream cadena;
    string linea;
    ifstream archivoLectura("Articulos.txt");
    if (archivoLectura.is_open()){
        while (getline(archivoLectura, linea)){
            lineas.push_back(linea);
        }
        archivoLectura.close();
    }
    cadena << miPerecedero.codigo << "," << miPerecedero.nombre << "," << miPerecedero.cantidad << "," << miPerecedero.precio << "," << miPerecedero.fechadecad << "," << miPerecedero.unidades;
    lineas.push_back(cadena.str());
    ofstream fich("Articulos.txt");
        if (!fich){
  		    color(hConsole, 64);cout << "Error al abrir Articulos.txt\n";
    		/*exit(EXIT_FAILURE);*/
        }
		if (fich.is_open()){
                fich << "";
            for (const auto& linea : lineas){
                fich << linea << endl;
            }
            fich.close();
        }
}
void NoPerecederos::DarAlta(NoPerecederos miNoPerecedero){
    vector<string> lineas;
    ostringstream cadena;
    string linea;
    ifstream archivoLectura("Articulos.txt");
    if (archivoLectura.is_open()){
        while (getline(archivoLectura, linea)){
            lineas.push_back(linea);
        }
        archivoLectura.close();
    }
    cadena << miNoPerecedero.codigo << "," <<miNoPerecedero.nombre << "," << miNoPerecedero.cantidad << "," << miNoPerecedero.precio << "," << miNoPerecedero.fechadecad << "," << miNoPerecedero.unidades;
    lineas.push_back(cadena.str());
    ofstream fich("Articulos.txt");
        if (!fich){
  		    color(hConsole, 64);cout << "Error al abrir Articulos.txt\n";
    		/*exit(EXIT_FAILURE);*/
        }
		if (fich.is_open()){
                fich << "";
            for (const auto& linea : lineas){
                fich << linea << endl;
            }
            fich.close();
        }
}

void menuAdmin(Tienda miTienda);
void MenuPrincipal(Tienda miTienda);
void menuCliente(Tienda miTienda){
    Cliente miCliente;
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
            miCliente.adquirirArticulos();
			break;
        case 2:
            miCliente.verCarrito();
            break;
        case 3:
            miCliente.pagarCarrito();
            break;
        case 4:
            MenuPrincipal(miTienda);
            break;
        default:
            color(hConsole, 64);
			cout << "Opcion invalida, Intentelo de nuevo...\n";
            color(hConsole, 2);
        }
    }while(x != 0);
}
void MenuPrincipal(Tienda miTienda){
	int x;
	do{
 		color(hConsole, 2);cout << "Bienvenido a la tienda de abarrotes... Que desea hacer? \t";
 		color(hConsole, 32);cout << "Usuario";
 		color(hConsole, 2);cout << "\n1.-Comprar siendo cliente\n"<< "2.-Administrar tienda	" << "\n0.-Salir del sistema\n";cin >> x;
		switch(x){
			case 0:
			    color(hConsole, 6);cout << "Saliendo del sistema...\n";color(hConsole, 15);
				exit(0);
				break;
			case 1:{
				menuCliente(miTienda);
				break;
			}
			case 2:
				menuAdmin(miTienda);
				break;
			default:
			    color(hConsole, 64);
				cout << "Opcion invalida, Intenta de nuevo\n";
				color(hConsole, 2);
				break;
		}
	}while(x != 0);
}
void menuAdmin(Tienda miTienda){
	string usuario = "admin", contrasena = "1234", contrasenaUser = "0";
	string usuarioUser;
	int x = 0;
	do{
		color(hConsole, 13);cout << "Ingrese el usuario (x para cancelar):\n";cin >> usuarioUser;
		if(usuarioUser == "x"){
			MenuPrincipal(miTienda);
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
	cout << "Entrando como administrador...\n";
	do{
		color(hConsole, 13);cout << "Bienvenido... Que desea hacer?\t";
		color(hConsole, 208);cout << "Administrador";
		color(hConsole, 13);cout << "\n1.-Anadir item a inventario\n2.-Eliminar item de inventario\n3.-Modificar item de inventario\n4.-Mostrar items del inventario\n0.-Cerrar sesion y volver al menu principal\n";cin >> x;
		switch(x){
			case 0:
				MenuPrincipal(miTienda);
				break;
			case 1:
                miTienda.anadirItemInventario(x);
			    break;
			case 2:
			    miTienda.eliminarItemInventario();
				break;
			case 3:
			    miTienda.modificarItemInventario();
				break;
            case 4:{
                miTienda.mostrarItemInventario();
                break;
            }
            case 5:{
                //cout << "Nombre de la tienda: " << miTienda.nombre << "\nDireccion de la tienda: " << miTienda.direccion << endl;
                break;
            }
			default:{
			    color(hConsole, 64);
				cout << "Opcion invalida, Intentelo de nuevo...\n";
				color(hConsole, 2);}
		}
    }while(x != 0);
}

int main() {
    Tienda miTienda;
	//El constructor de Empleado se da de alta en el sistema
	MenuPrincipal(miTienda);
	return 0;
}
