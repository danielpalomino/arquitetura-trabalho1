#include "systemc.h"

SC_MODULE(Ula){
	sc_in<sc_logic> control;
	sc_in<sc_int<32> > op_a, op_b;
	sc_out<sc_int<32> > out_ula;
	sc_out<sc_logic> flag_z;

	sc_signal<sc_int<32> > sig_s;

	void compute();

	SC_CTOR(Ula) {
		SC_METHOD(compute);
		sensitive << op_a << op_b << control;
	}
};

