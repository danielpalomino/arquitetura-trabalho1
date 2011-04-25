#include "systemc.h"
#include "Processor.h"

//SC_MODULE(topo)
int sc_main(int argc, char* argv[])
{

	sc_signal<sc_logic> clock;
	Processor processor;
	void clock_gen();

	sc_time time(500, SC_NS);

	sc_trace_file *tf;
	tf = sc_create_vcd_file("main.trace");
	
	processor.clock(clock);

	sc_trace(tf,processor.clock,"clk");
	sc_trace(tf,processor.instruction,"instruction");

	sc_start(time);
	
	return 0;
};


void clock_gen() {
	while(1) {
		clock.write(sc_logic('0'));
		wait(5, SC_NS);
		clock.write(sc_logic('1'));
		wait(5, SC_NS);
		cout<<"-------------- PERIODO DE CLOCK -------------"<<endl;
	}
}
