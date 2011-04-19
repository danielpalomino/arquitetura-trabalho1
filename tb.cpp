//// Testbench
#include <systemc.h>
#include "tb.h"




void testbench::clock_gen() 
  {
    while(1) 
    {
      clock.write(sc_logic('0'));
      wait(5, SC_NS);
      clock.write(sc_logic('1'));
      wait(5, SC_NS);
	cout<<"-------------- PERIODO DE CLOCK -------------"<<endl;
    }
   }

void testbench::stimuli() 
  {
    sc_trace_file *tf = sc_create_vcd_trace_file("trace_file");
    sc_trace(tf,a,"a");
    sc_trace(tf,a,"b");
  
    while(1) 
    {
      a.write(sc_logic('1'));
      b.write(sc_logic('0'));
      //wait(10, SC_NS);
      wait();

      cout<<"SAIDA S="<<s.read()<<"; C="<<c.read()<<endl;

      a.write(sc_logic('1'));
      b.write((sc_logic) 1);
      //wait(10, SC_NS);
      wait();
    
      cout<<"SAIDA S="<<s.read()<<"; C="<<c.read()<<endl;
    }
   }
