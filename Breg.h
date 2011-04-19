#include "system.h"

SC_MODULE(Breg){
	sc_in<sc_logic> control;
	sc_in<sc_int<32 > in_data;
	sc_in<sc_uint<5> > read_Adress1, read_Adress2, write_Adress;
	sc_out<sc_int<32> > out_data1, out_data2;
	
	//memoria
	sc_signal<sc_int<32> > reg[32];

	void compute();

	SC_CTOR(Breg){
		SC_METHOD(compute);
		sensitive << read_Adress1 << read_Adress2 << clk;
	}
};
