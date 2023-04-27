#include "systemc.h"

SC_MODULE (ADDER)
{
	sc_in<bool> a;
	sc_in<bool> b;
	sc_in<bool> c;

	sc_out<bool> sum;
	sc_out<bool> carry;
	
	SC_CTOR (ADDER)
	{
		SC_METHOD(add);
		sensitive << a << b << c;
	}

	void add()
	{
		sc_logic aXORbXORc, aANDb, bANDc, cANDa;
		aXORbXORc = a.read() ^ b.read() ^ c.read();
		aANDb = a.read() & b.read();
		bANDc = b.read() & c.read();
		cANDa = c.read() & a.read();

		sum.write(aXORbXORc);
		carry.write(aANDb | bANDc | aANDa);
	}
};

//test_bench
//#include "systemc.h"
//#include "adder.cpp"
//#include "stimulus.cpp"

int sc_main(int argc, char* argv[])
{
ADDER adder("full_adder");//new instance of the module


//signal declaration
sc_signal<bool> a;
sc_signal<bool> b;
sc_signal<bool> c;
sc_signal<bool> sum;
sc_signal<bool> carry;

//connection of ports to a signal
adder.a(a);
adder.b(b);
adder.c(c);
adder.sum(sum);
adder.carry(carry);

//clock generation
sc_clock clk("clock", 10, SC_NS, 0.5)

//connection of dut to clock
adder.clk(clk);

//stimulus 
SC_CTOR(ADDERSTIMULUS){
SC_THREAD(stimulus);
sensitive << clk.pos();
}

//generation of all possible stimulus
void stimulus(){
a.write() = 0;
b.write() = 0;
c.write() = 0;
wait(5, SC_NS);

a.write() = 0;
b.write() = 0;
c.write() = 1;
wait(5, SC_NS);

a.write() = 0;
b.write() = 1;
c.write() = 0;
wait(5, SC_NS);

a.write() = 0;
b.write() = 1;
c.write() = 1;
wait(5, SC_NS);

a.write() = 1;
b.write() = 0;
c.write() = 0;
wait(5, SC_NS);


a.write() = 1;
b.write() = 0;
c.write() = 1;
wait(5, SC_NS);

a.write() = 1;
b.write() = 1;
c.write() = 0;
wait(5, SC_NS);

a.write() = 1;
b.write() = 1;
c.write() = 1;
wait(5, SC_NS);
}
//monitor process as clocked thread//output checker
SC_CTOR(ADDERSTIMULUS){
SC_CTHREAD(monitor, clk.pos());
}

void monitor() {
	while (true) {
		std::cout << "a = " << a.read();
		std::cout << "b = " << b.read();
		std::cout << "c = " << c.read();
		std::cout << "sum = " << sum.read();
		std::cout << "carry = " << carry.read() << " ";
		std::cout << sc_time_stamp() << std::endl;
		wait();
	}

};

//connection of the stimulus & output checker to DUT
/*sc_in<bool> clk;
sc_out<bool> a;
sc_out<bool> b;
sc_out<bool> c;
sc_in<bool> sum;
sc_in<bool> carry;*/

//creating a new instance of module
ADDERstimulus tb("ADDERTest");

//port to signal connection
tb.clk(clk);
tb.a(a);
tb.b(b);
tb.c(c);
tb.sum(sum);
tb.carry(carry);

//run the simulation
sc_start(50, SC_NS);
//stop the simulation
sc_stop(1000, SC_NS);


}











