#include "counter.h"

SC_MODULE(counter_test)
{

  sc_signal<bool > clk;
  sc_signal<bool > clr;

  sc_signal<sc_uint<4> > count;


  sc_trace_file *pTracefile;


  counter uut;

  void stimulus();


  SC_CTOR(counter_test):
    clr("sig_clr"),
    clk("sig_clk"),
    count("sig_count"),
    uut("mod_uut")
  {
    uut.clr(clr);
    uut.clk(clk);
    uut.count(count);

    pTracefile = sc_create_vcd_trace_file("some_vcd_name");

    sc_trace(pTracefile, clr, "trace_clr");
    sc_trace(pTracefile, clk, "trace_clk");
    sc_trace(pTracefile, count, "trace_count");

    SC_THREAD(stimulus)
  }

  ~counter_test()
  {
    sc_close_vcd_trace_file(pTracefile);
  }

};
