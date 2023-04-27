#include "systemc.h"

SC_MODULE(counter)//same name as file
{
  sc_in<bool> clk;
  sc_in<bool> clr;
  sc_out<sc_uint<4> > count; //> >//spacing is important

  int internal_count;

  void up_count();

  void data();

  SC_CTOR(counter)
  {
    internal_count = 0;

    SC_METHOD(up_count);
      sensitive_pos << clk;
      sensitive_pos << clr;
    
    SC_METHOD(data);
      sensitive_pos << clk;
      sensitive << clr;
  }
};
