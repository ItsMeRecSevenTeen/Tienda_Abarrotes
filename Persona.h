class Tienda;
class Persona{
	protected:
		char nombre[20];
		int ID;
	public:
		Persona();
};
class Empleado: public Persona{
	private:
		char puesto[20];
		double salario;
	public:
		Empleado();
};
class Cliente: public Persona{
	private:
		char direccion[20], numtel[10];
	public:
		Cliente();
		void adquirirArticulos();
		void verCarrito();
		void pagarCarrito(Cliente, Tienda);
};
