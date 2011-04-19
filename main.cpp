#include "tb.h"
#include "systemc.h"

//SC_MODULE(topo)
int sc_main(int argc, char* argv[])
{
   
    
    testbench* test;
    sc_time time(500, SC_NS);
    
    test = new testbench("TESTE");
    
    sc_start(time);
    
};
