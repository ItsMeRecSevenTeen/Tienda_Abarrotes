#include <iostream> //Para cout
#include <string> //Para cadenas
#include <fstream>  //Para ofstream e ifstream (Escritura y lectura de ficheros)
#include <vector> //Arreglo de datos
#include <sstream> //Para strings dinamicos
#include <cstring> //Para strcpy (Asignar una cadena a un char[])
#include <chrono> //Para obtener la fecha y hora del sistema
#include <iomanip> //Para dar formato a impresiones y texto
#include <windows.h> //Para consola de windows (Color de texto en consola)
#include "Persona.h" //Importacion de cabeceras
#include "Producto.h"

#define color SetConsoleTextAttribute

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//Constructores
Tienda::Tienda(){
    color(hConsole, 2);cout << "Ingrese el nombre de la tienda: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 2);cin >> nombreTienda;
    color(hConsole, 2);cout << "Ingrese la direccion de la tienda: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 2);cin >> direccion;
    color(hConsole, 2);cout << "A nombre de quien esta registrado?: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 2);cin >> nombreDueno;
}
Persona::Persona(){
    color(hConsole, 11);cout << "Ingrese su nombre: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 11);cin >> nombre;
}
Cliente::Cliente(){
    color(hConsole, 11);cout << "Ingrese su direccion: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres\n";color(hConsole, 11);cin >> direccion;
    color(hConsole, 11);cout << "Ingrese su numero de telefono:";color(hConsole, 6);cout << "\tNumerico, 10 digitos\n";color(hConsole, 11);cin >> numtel;
}
Empleado::Empleado(){
    color(hConsole, 13);cout << "Ingrese el puesto del nuevo empleado: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres EJ: Cajero, Almacenista\n";color(hConsole, 11);cin >> puesto;
    color(hConsole, 13);cout << "Ingrese el salario del empleado: ";color(hConsole, 6);cout << "\tNumerico, Pago con 2 decimas de centavo, EJ: 6000.50, 5500\n";color(hConsole, 11);cin >> salario;
}
Producto::Producto(){
    color(hConsole, 13);cout << "Ingrese el codigo del producto: ";color(hConsole, 6);cout << "\tNumerico, un codigo, EJ: 1, 17, 1500\n";color(hConsole, 208);cin >> codigo;
	color(hConsole, 13);cout << "Ingrese el nombre del producto: ";color(hConsole, 6);cout << "\tSin espacios, 20 caracteres maximos\n";color(hConsole, 208);cin >> nombre;
	color(hConsole, 13);cout << "Ingrese la fecha de caducidad: ";color(hConsole, 6);cout << "\tdd/mm/aaaa, EJ: 17/07/2025\n";color(hConsole, 208);cin >> fechadecad;
	color(hConsole, 13);cout << "Cuanto contenido neto tiene el producto?: ";color(hConsole, 6);cout << "\tgrs, kgs, mls, lts, gls, EJ: 500gr, 1Kg, 1Lt\n";color(hConsole, 208);cin >> cantidad;
	color(hConsole, 13);cout << "Ingrese la cantidad de productos: ";color(hConsole, 6);cout << "\tUn numero, cantidad de envases\n";color(hConsole, 208);cin >> unidades;
	color(hConsole, 13);cout << "Ingrese el precio unitario del producto?: ";color(hConsole, 6);cout << "\tPrecio con 2 decimas de centavo EJ: 25.50, 17\n";color(hConsole, 208);cin >> precio;
}
Perecederos::Perecederos(){
    int x;
    color(hConsole, 13);cout << "Cual es la temperatura de almacenamiento del producto perecedero?: ";color(hConsole, 6);cout << "\tUn numero, Grados Celsius(Sin simbolo)\n";color(hConsole, 208);cin >> temperaturaalmacencelcius;
    color(hConsole, 13);cout << "Tipo de almacenamiento que requiere el producto: ";color(hConsole, 6);cout << "Elija un numero: \t1.-Ambiente\t2.-Refrigeracion\t3.-Congelacion\n";color(hConsole, 208);cin >> x;
    do{
        switch(x){
            case 1:{
                strcpy(tipoconservacion, "Ambiente");
                break;
            }
            case 2:{
                strcpy(tipoconservacion, "Refrigeracion");
                break;
            }
            case 3:{
                strcpy(tipoconservacion, "Congelacion");
                break;
            }
            default:{
                color(hConsole, 64);
                cout << "Opcion invalida, Intentelo de nuevo...\n";
                color(hConsole, 2);
            }
        }
    }while(x < 0 || x > 4);
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
        do{
            color(hConsole, 11);
            cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
            for (int i = 0; i < inventario.size(); i++){ // Mostrando el vector con los datos del fichero (Mostrando los productos del inventario)
                vector<string> camposProducto;
                string campo;
                stringstream ss(inventario[i]);
                while (getline(ss, campo, ',')) {
                    camposProducto.push_back(campo);
                }
                color(hConsole, 176);cout << "Codigo:";color(hConsole, 11);cout << " " << camposProducto[0] << " \t";
                color(hConsole, 176);cout << "Producto:";color(hConsole, 11);cout << " " << camposProducto[1] << " \t";
                color(hConsole, 176);cout << "Contenido Neto: ";color(hConsole, 11);cout << " " << camposProducto[2] << " \t";
                color(hConsole, 176);cout << "Precio:";color(hConsole, 11);cout << " " << camposProducto[3] << "$" << " \t";
                color(hConsole, 176);cout << "Fecha de Caducidad:";color(hConsole, 11);cout << " " << camposProducto[4] << " \t";
                color(hConsole, 176);cout << "Unidades en stock:";color(hConsole, 11);cout << " " << camposProducto[5] << endl;
            }
            cout << endl;

            cout << "\nIngrese el codigo del producto que va a adquirir";color(hConsole, 6);cout << " (x para dejar de comprar):\n";
            color(hConsole, 11);
            cin >> codigoUsuario;
            if(codigoUsuario == "x"){
                break;
            }else if(stoi(codigoUsuario) <= 0 || stoi(codigoUsuario) > inventario.size()){
                color(hConsole, 64);
                cout << "No existe ese producto, Intentelo de nuevo...\n";
                color(hConsole, 11);
            }else{
                for(int i = 0 ; i < inventario.size(); i++){
                    vector<string> camposProducto;
                    string campo;
                    stringstream ss(inventario[i]);
                    while (getline(ss, campo, ',')) {
                    camposProducto.push_back(campo);
                    }
                    if(codigoUsuario == camposProducto[0]){
                        cout << "Cuantos " << camposProducto[1] << "(s) desea adquirir? ";color(hConsole, 6);cout << camposProducto[5] << " Unidades disponibles\n";color(hConsole, 11);
                        cin >> respuestaUsuario;
                        if(stoi(camposProducto[5]) >= stoi(respuestaUsuario)){
                            int cantidadProducto = stoi(camposProducto[5]);
                            cantidadProducto -= stoi(respuestaUsuario);
                            camposProducto[5] = to_string(cantidadProducto);
                            inventario[i] = camposProducto[0] + "," + camposProducto[1] + "," + camposProducto[2] + "," + camposProducto[3] + "," + camposProducto[4] + "," + camposProducto[5];
                            carrito.push_back(camposProducto[0] + "," + camposProducto[1] + "," + camposProducto[2] + "," + camposProducto[3] + "," + respuestaUsuario);
                            color(hConsole, 96);cout << "Adquirio " << respuestaUsuario << " " << camposProducto[1] << "(s)";
                            break;
                        }else{
                        color(hConsole, 64);
                        cout << "No puedes comprar más de la existencia, intentalo de nuevo";
                        color(hConsole, 11);
                        }
                    }else{
                    continue;
                    }
                }
            }

        }while(codigoUsuario != "x");

        // Este bloque de codigo, anade los artículos adquiridos al carrito
        if(!carrito.empty()){
            ofstream archivoEscritura("Carrito.txt");
            if (archivoEscritura.is_open()){
                for (const auto& lineaProducto : carrito){
                    archivoEscritura << lineaProducto << endl;
                }
                archivoEscritura.close();
            } else {
            cout << "Error al abrir el archivo para escritura\n";
        }
        //Aqui se Actualiza el inventario
        ofstream archivoActualizacion("Articulos.txt");
        if (archivoActualizacion.is_open()){
            for(const auto& lineaProducto : inventario){
                archivoActualizacion << lineaProducto << endl;
            }
            archivoActualizacion.close();
        }else{
            cout << "Error al escribir el archivo\n";
        }
        color(hConsole, 96);
        cout << "Productos anadidos al carrito correctamente\n";
        }else{
            color(hConsole, 64);cout << "No se anadio ningun articulo al carrito";
        }

    } else {
        color(hConsole, 96);cout << "No hay ningun articulo en el inventario, Dile al dueno que anada algun producto\n";
    }
}
void Cliente::verCarrito(){
    vector<string> carrito;
    string lineaProducto;

    ifstream archivoLectura("Carrito.txt");
    archivoLectura.seekg(0, ios::end);
    if (!archivoLectura.is_open() || archivoLectura.tellg() == 0){
        color(hConsole, 64);
        cout << "No has adquirido articulos, Intenta comprar algo para agregarlo a tu carrito de compras\n";
    }else{
        archivoLectura.seekg(0, ios::beg);
        while (getline(archivoLectura, lineaProducto)){
            carrito.push_back(lineaProducto);
        }
        archivoLectura.close();
        color(hConsole, 11);
        cout << "\n-_-_-_-_-_-_Articulos en carrito-_-_-_-_-_-_\n";
        for (int i = 0; i < carrito.size(); i++){ // Mostrando el vector con los datos del fichero (Mostrando los productos del inventario)
            vector<string> camposProducto;
            string campo;
            stringstream ss(carrito[i]);
            while (getline(ss, campo, ',')) {
                camposProducto.push_back(campo);
            }
            color(hConsole, 176);cout << "Codigo:";color(hConsole, 11);cout << " " << camposProducto[0] << " \t";
            color(hConsole, 176);cout << "Producto:";color(hConsole, 11);cout << " " << camposProducto[1] << " \t";
            color(hConsole, 176);cout << "Contenido Neto:";color(hConsole, 11);cout << " " << camposProducto[2] << " \t";
            color(hConsole, 176);cout << "Precio Unitario:";color(hConsole, 11);cout << " " << camposProducto[3] << "$" << " \t";
            color(hConsole, 176);cout << "Unidades:";color(hConsole, 11);cout << " " << camposProducto[4] << endl;
        }
        cout<< endl;
    }
}
void Cliente::pagarCarrito(Cliente miCliente, Tienda miTienda){
        ifstream archivoLectura("Carrito.txt");
        archivoLectura.seekg(0, ios::end);
        if (!archivoLectura.is_open() || archivoLectura.tellg() == 0){
            color(hConsole, 64);;cout << "No hay ningun articulo en el carrito por pagar, adquiere un producto...";
        }else{
            archivoLectura.seekg(0, ios::beg);
            float subtotal = 0, total;
            vector<string> lineas;
            string lineaProducto, respuestaUsuario;

            while (getline(archivoLectura, lineaProducto)){
                lineas.push_back(lineaProducto);
            }
            archivoLectura.close();
            cout << "-_-_-_-_-_-_Articulos en carrito por pagar-_-_-_-_-_-_\n";
            for (int i = 0; i < lineas.size(); i++){ // Mostrando el vector con los datos del fichero
                vector<string> camposProducto;
                string campo;
                stringstream ss(lineas[i]);
                while (getline(ss, campo, ',')) {
                    camposProducto.push_back(campo);
                }
                color(hConsole, 176);cout << "Codigo:";color(hConsole, 11);cout << " " << camposProducto[0] << " \t";
                color(hConsole, 176);cout << "Producto:";color(hConsole, 11);cout << " " << camposProducto[1] << " \t";
                color(hConsole, 176);cout << "Contenido Neto:";color(hConsole, 11);cout << " " << camposProducto[2] << " \t";
                color(hConsole, 176);cout << "Precio Unitario:";color(hConsole, 11);cout << " " << camposProducto[3] << "$" << " \t";
                color(hConsole, 176);cout << "Unidades:";color(hConsole, 11);cout << " " << camposProducto[4] << "\t";
                subtotal = stoi(camposProducto[3]) * stoi(camposProducto[4]);
                total += subtotal;
                color(hConsole, 176);cout << "Subtotal:";color(hConsole, 11);cout << " " << subtotal << endl;
            }
            color(hConsole, 176);cout << "\nUsted paga:";color(hConsole, 11);cout << " " << total << "$" << "\nGracias por su compra!";
            ofstream archivoEscritura("Ticket.txt");
            if(archivoEscritura.is_open()){
                    archivoEscritura << "_-_-_-_-_ " << miTienda.nombreTienda << " _-_-_-_-_" << endl;
                    auto ahora = chrono::system_clock::now();
                    time_t tiempoActual = chrono::system_clock::to_time_t(ahora);
                    archivoEscritura << "Fecha: " << put_time(localtime(&tiempoActual), "%Y-%m-%d %H:%M:%S") << endl;
                for(const auto& linea : lineas){
                    archivoEscritura << linea << endl;
                }
                archivoEscritura.close();
            }
            ofstream archivoBorrado("Carrito.txt", ofstream::trunc);
            archivoBorrado.close();
        }
}

void Tienda::anadirItemInventario(){
    int x;
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
            cout << "No hay ningun articulo para eliminar\n";
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
        cout << "No hay ningun articulo para modificar\n";
        color(hConsole, 2);
    }
}
void Tienda::mostrarItemInventario(){
    vector<string> inventario;
    string lineaProducto;

    ifstream archivoLectura("Articulos.txt");
    if (!archivoLectura.is_open()){
        color(hConsole, 64);
        cout << "No ha dado de alta nuevos articulos, Intente agregar algunos a su inventario\n";
        color(hConsole, 2);
    }else{
        while (getline(archivoLectura, lineaProducto)){
            inventario.push_back(lineaProducto);
        }
        archivoLectura.close();
        cout << "\n-_-_-_-_-_-_Articulos en inventario-_-_-_-_-_-_\n";
        for (int i = 0; i < inventario.size(); i++){ // Mostrando el vector con los datos del fichero
            vector<string> camposProducto;
            string campo;
            stringstream ss(inventario[i]);
            while (getline(ss, campo, ',')) {
                camposProducto.push_back(campo);
            }
            color(hConsole, 208);cout << "Codigo:";color(hConsole, 13);cout << " " << camposProducto[0] << " \t";
            color(hConsole, 208);cout << "Producto:";color(hConsole, 13);cout << " " <<camposProducto[1] << " \t";
            color(hConsole, 208);cout << "Contenido Neto: ";color(hConsole, 13);cout << " " << camposProducto[2] << " \t";
            color(hConsole, 208);cout << "Precio:";color(hConsole, 13);cout << " " << camposProducto[3] << "$" << " \t";
            color(hConsole, 208);cout << "Fecha de Caducidad:";color(hConsole, 13);cout << " " << camposProducto[4] << " \t";
            color(hConsole, 208);cout << "Unidades en stock:";color(hConsole, 13);cout << " " << camposProducto[5] << endl;
            }
            cout << endl;
    }
}
void Tienda::mostrarInformacionTienda(){
    color(hConsole, 208);cout << "Nombre de la tienda:";color(hConsole, 13);cout << " " << nombreTienda << endl;
    color(hConsole, 208);cout << "Direccion de la tienda:";color(hConsole, 13);cout << " " << direccion << endl;
    color(hConsole, 208);cout << "Registrado a nombre de:";color(hConsole, 13);cout << " " << nombreDueno << endl;
}
void Tienda::contratarEmpleado(){
    Empleado miEmpleado;
    color(hConsole, 96);cout << "Empleado anadido correctamente";
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
void menuPrincipal(Tienda miTienda);
void menuCliente(Tienda miTienda){
    Cliente miCliente;
    int x;
    do{
        color(hConsole, 11);cout << "\nQue desea realizar?\t";
        color(hConsole, 176);cout << "Cliente";
        color(hConsole, 11);cout << "\n1.-Adquirir articulos\n2.-Ver Carrito\n3.-Pagar Carrito\n4.-Regresar al menu principal\n0.-Salir del sistema\n";cin >> x;
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
            miCliente.pagarCarrito(miCliente, miTienda);
            break;
        case 4:
            menuPrincipal(miTienda);
            break;
        default:
            color(hConsole, 64);
			cout << "Opcion invalida, Intentelo de nuevo...\n";
            color(hConsole, 2);
        }
    }while(x != 0);
}
void menuPrincipal(Tienda miTienda){
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
			menuPrincipal(miTienda);
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
		color(hConsole, 13);cout << "\nBienvenido... Que desea hacer?\t";
		color(hConsole, 208);cout << "Administrador";
		color(hConsole, 13);cout << "\n1.-Anadir item a inventario\n2.-Eliminar item de inventario\n3.-Modificar item de inventario\n4.-Mostrar items del inventario\n5.-Contratar Empleado\n6.-Ver informacion de la tienda\n0.-Cerrar sesion y volver al menu principal\n";cin >> x;
		switch(x){
			case 0:
				menuPrincipal(miTienda);
				break;
			case 1:
                miTienda.anadirItemInventario();
			    break;
			case 2:
			    miTienda.eliminarItemInventario();
				break;
			case 3:
			    miTienda.modificarItemInventario();
				break;
            case 4:
                miTienda.mostrarItemInventario();
                break;
            case 5:
                miTienda.contratarEmpleado();
                break;
            case 6:
                miTienda.mostrarInformacionTienda();
                break;
			default:{
			    color(hConsole, 64);
				cout << "Opcion invalida, Intentelo de nuevo...\n";
				color(hConsole, 2);
				}
		}
    }while(x != 0);
}

int main() {
    Tienda miTienda;
	//El constructor de Empleado se da de alta en el sistema
	menuPrincipal(miTienda);
	return 0;
}
