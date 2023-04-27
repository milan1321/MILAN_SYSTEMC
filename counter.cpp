#include "counter.h"


void counter::up_count()
{
  if(clr)
    internal_count = 0 ;
  else
  {
    if(internal_count == 15)
      internal_count = 0;
    else
      internal_count++;

  }
  count = internal_count;
}

void counter::data()
{
  cout << sc_simulation_time()/1000 << "NS CLR: " << clr <<" CLK : " << clk <<" COUNT: "<< internal_count << "\n";
}
