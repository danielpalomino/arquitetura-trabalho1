#include "systemc.h"
#include "Processor.h"



SC_MODULE(testbench) {
	sc_signal<sc_logic>   clock;    


	Processor *processador;


	void clock_gen();
	void stimuli();


	SC_CTOR(testbench)

	{

		sc_trace_file *tf;
		tf = sc_create_vcd_trace_file("main.trace");
		processador = new Processor("processador");

		sc_trace(tf,clock,"clk");


		SC_THREAD(clock_gen);
		sensitive << clock;

		SC_THREAD(stimuli);
		sensitive_pos << clock;
		//sc_close_vcd_trace_file(tf);


	}
};
