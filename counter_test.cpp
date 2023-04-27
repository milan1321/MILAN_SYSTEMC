#include "counter_test.h"

void counter_test::stimulus()
{
  int i;

  clr.write(1);

  for(i=0; i<=5; i++)
  {
    clk.write(1);
    wait(10, SC_NS);
    clk.write(0);
    wait(10, SC_NS);
  }

  clr.write(0);

  for(i=0; i<=18; i++)
  {
    clk.write(1);
    wait(10, SC_NS);
    clk.write(0);
    wait(10, SC_NS);
  }

  clr.write(1);

  for(i=0; i<=3; i++)
  {
    clk.write(1);
    wait(10, SC_NS);
    clk.write(0);
    wait(10, SC_NS);
  }

  clr.write(0);

  for(i=0; i<=18; i++)
  {
    clk.write(1);
    wait(10, SC_NS);
    clk.write(0);
    wait(10, SC_NS);
  }

  sc_stop();  //$finish
}

int sc_main (int, char *[]) {
   counter_test top1("Top1");
   sc_start();
   return 0;
}

//SC_MODULE_EXPORT(counter_test)

