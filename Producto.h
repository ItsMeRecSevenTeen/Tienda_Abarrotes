class Tienda{
	protected:
		char nombreTienda[20], direccion[20], nombreDueno[20];
	public:
		Tienda();
		void anadirItemInventario();
		void eliminarItemInventario();
		void modificarItemInventario();
		void mostrarItemInventario();
		void mostrarInformacionTienda();
        void contratarEmpleado();
		friend void Cliente::pagarCarrito(Cliente, Tienda);
};
class Producto{
	protected:
		char nombre[20], fechadecad[20], cantidad[7];
		int codigo, unidades;
		float precio;
	public:
		Producto();
		friend class Tienda;
};
class NoPerecederos: public Producto{
	private:
		char paisdeorigen[20], fechaorigen[20];
	public:
		NoPerecederos();
		void DarAlta(NoPerecederos);
};
class Perecederos: public Producto{
	private:
		int temperaturaalmacencelcius;
		char tipoconservacion[20];
	public:
		Perecederos();
		void DarAlta(Perecederos);
};
