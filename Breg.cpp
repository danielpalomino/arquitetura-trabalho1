#include "Breg.h"

void Breg::compute() {
	if(control.read() == SC_LOGIC_0) {
		out_data1 = reg[read_Adress1.read()];
		out_data2 = reg[read_Adress2.read()];
	}
	else {
		reg[write_Adress.read()] =  in_data;
	}
}			

