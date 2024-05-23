class Tienda{
	protected:
		char nombre[20], direccion[20];
	public:
		Tienda();
};
class Producto{
	private:
		char nombre[20], fechadecad[20];
		int cantidad, codigo, unidades;
		float precio;
	public:
		Producto();
};
class NoPerecederos: public Producto{
	private:
		char paisdeorigen[20], fechaorigen[20];
	public:
		NoPerecederos();
};
class Perecederos: public Producto{
	private:
		int temperaturaalmacencelcius;
		char tipoconservacion[20];
	public:
		Perecederos();
};
