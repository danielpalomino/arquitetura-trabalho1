#include "systemc.h"

SC_MODULE(Control) {

	sc_in <sc_logic> clk;
	sc_in <sc_uint<6> > op;

	//SAIDAS MUXS
	sc_out<sc_logic> aluSrc, MemtoReg, MemReadWrite, ControlAlu, Regwrite, RegDst, branch_signal;

	void compute();

	SC_CTOR(Control){
		SC_METHOD(compute);
		sensitive << clk;
	}
};

