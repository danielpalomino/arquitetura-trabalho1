#include "Control.h"

void Control::compute() {

	switch (op.read().to_uint()) {
		case 0:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
		case 1:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
		case 2:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
		default:
			breg_in.write(SC_LOGIC_0);
			ula_in.write(SC_LOGIC_0);
			pc_in.write(SC_LOGIC_0);
			ula_func.write(SC_LOGIC_0);
			break;
	}
}
