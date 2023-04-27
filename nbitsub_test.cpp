#include"systemc.h"
#include"nbit_sub.cpp"

SC_MODULE(testbench) {
	sc_out<sc_unit<n>> a;

	sc_out<sc_unit<n>> b;
	sc_out<sc_unit<n>> diff;
	sc_out<sc_unit<n>> borr;

	void test() {
		a.write(5);
		b.write(4);
		wait(5, SC_NS);
		assert(diff.read() == 0;

	sc_stop();
	}
SC_CTOR(testbench){
SC_THREAD(test);
sensitive << diff;
}
};
int sc_main(int argc, char *argv[]) {
sub.a(a);
sub.b(b);
sub.diff(diff);
testbench tb("tb");
tb.a(a);
tb.b(b);
tb.diff(diff);

sc_start();
return 0;
}
