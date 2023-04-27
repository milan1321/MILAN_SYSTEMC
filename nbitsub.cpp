#include <systemc.h>

C_MODULE(subtractornbit){
	sc_in<sc_logic<n>> a;
 
	sc_in<sc_logic<n>> b;

	sc_in<sc_logic<n>> diff;
	sc_in<sc_logic<n>> borr;

	SC_CTOR(subtractornbit){
		SC_METHOD(sub);
		sensitive << a << b;
	}

	void sub(){
		out.write(a.read() - b.read());
	}
};
		




