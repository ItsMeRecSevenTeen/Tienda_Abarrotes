class Tienda{
	protected:
		char nombre[20], direccion[20];
	public:
		Tienda();
};
class Producto{
	protected:
		char nombre[20], fechadecad[20], cantidad[7];
		int codigo, unidades;
		float precio;
	public:
		Producto();
		friend class Sistema_tienda;
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
