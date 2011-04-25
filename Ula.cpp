#include "Ula.h"

void Ula::compute(){

	if(control == '0')
		sig_s.write(op_a.read() + op_b.read());
	else
		sig_s.write(op_a.read() - op_b.read());
	
	if(sig_s.read() == 0)
		flag_z.write(SC_LOGIC_0);
	else
		flag_z.write(SC_LOGIC_1);

	out_data.write(sig_s.read());
}
