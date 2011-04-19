#include "Control.h"

void Control::compute() {

	switch (op.read().to_uint()) {
		//add
		case 0:
			
			break;
		//LOAD WORD
		case 1:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
		//STORE WORD
		case 2:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
		//BRANCH EQUAL
		default:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
	}
}
