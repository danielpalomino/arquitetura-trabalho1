#include "systemc.h"

SC_MODULE(Control) {

	sc_clock clk;
	sc_in <sc_lv<6> > op;

	//SAIDAS MUXS
	sc_out<sc_logic> breg_in, ula_in, pc_in, ula_func;

	void compute();

	SC_CTOR(Control){
		SC_METHOD(compute);
		sensitive << clk;
	}
};

