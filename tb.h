#include <systemc.h>
#include "Half_add.h"



SC_MODULE(testbench) {
	sc_signal<sc_logic>   a, b, s, c;      
	sc_signal<sc_logic>   clock;    


	Half_add* somador;


	void clock_gen();
	void stimuli();


	SC_CTOR(testbench)

	{

		sc_trace_file *tf;
		tf = sc_create_vcd_trace_file("main.trace");
		somador = new Half_add("somador");

		somador->a(a);
		somador->b(b);
		somador->c(c);
		somador->s(s);
		sc_trace(tf,clock,"clk");
		sc_trace(tf,somador->a,"a");
		sc_trace(tf,somador->c,"s");


		SC_THREAD(clock_gen);
		sensitive << clock;

		SC_THREAD(stimuli);
		sensitive_pos << clock;
		//sc_close_vcd_trace_file(tf);


	}
};
