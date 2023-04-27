#include "systemc.h"

SC_MODULE (MUL)
{
	sc_in<bool<4>> a;
	sc_in<bool<4>> b;
	sc_out<bool<9>> product;

	SC_CTOR (MUL)
	{
		SC_METHOD(mul);
		sensitive << a << b;
	}
	void mul(){
		product.write((sc_unit<8>)(a.read().to_unit()*b.read().unit()));
	}
	};

//testbench
int sc_main(int argc, char* argv[]) {
	sc_signal<bool<4>> a;
	sc_signal<bool<4>> b;
	sc_signal<bool<9>> product;

	MUL mult("mult");
	mult.a(a);
	mult.b(b);
	mult.product(product);

	a = "1100";
	b = "1001";

	sc_start(50, SC_NS);
	
	cout << "a = " << a.read() << endl;
	cout << "b = " << b.read() << endl;
	cout << "product = " << product.read() << endl;
	return 0;

}

