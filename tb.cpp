#include "systemc.h"
#include "tb.h"

void testbench::clock_gen() {
	while(1) {
		clock.write(sc_logic('0'));
		wait(5, SC_NS);
		clock.write(sc_logic('1'));
		wait(5, SC_NS);
		cout<<"-------------- PERIODO DE CLOCK -------------"<<endl;
	}
}

void testbench::stimuli() {
	sc_trace_file *tf = sc_create_vcd_trace_file("trace_file");
}
