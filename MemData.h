#include "systemc.h"

SC_MODULE(MemData){
	sc_in<sc_logic> control;
	sc_in<sc_int<32> > adress;
	sc_in<sc_int<32> > in_data;
	sc_out<sc_int<32> > out_data;

	//memoria
	sc_signal<sc_int<32> > mem[1024];

	void compute();

	SC_CTOR(MemData){
		SC_METHOD(compute);
		sensitive << adress << in_data << out_data << control;
	}
};
