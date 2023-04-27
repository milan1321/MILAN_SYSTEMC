#include "systemc.h"

SC_MODULE (SUB)
{
	sc_in<logic> a;
	sc_in<logic> b;
	sc_in<logic> c;

	sc_out<logic> diff;
	sc_out<logic> borr;
	
	SC_CTOR (SUB)
	{
		SC_METHOD(sub);
		sensitive << a << b << c;
	}

	void sub()
	{
		sc_logic aXORbXORc, ~aAND~bANDc, ~aANDbANDc, ~aANDbANDc, aANDbANDc;
		aXORbXORc = a.read() ^ b.read() ^ c.read();
		~aAND~bANDc = ~a.read() & ~b.read() & c.read();
		~aANDbANDc = ~a.read() & b.read() & c.read();
		~aANDbANDc = ~a.read() & b.read() & c.read();
		aANDbANDc = a.read() & b.read() & c.read();

		diff = aXORbXORc;
		borr = ~aAND~bANDc | ~aANDbANDc | ~aANDbANDc | aANDbANDc ;
	}
};
























