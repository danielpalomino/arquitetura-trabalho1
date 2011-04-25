#include "Control.h"

void Control::compute() {

	switch (op.read().to_uint()) {
		//ADD
		case 0:
			aluSrc.write(SC_LOGIC_0);
			MemtoReg.write(SC_LOGIC_1);
			MemReadWrite.write(SC_LOGIC_0);
			ControlAlu.write(SC_LOGIC_0);
			Regwrite.write(SC_LOGIC_1);
			RegDst.write(SC_LOGIC_1);
			branch_signal.write(SC_LOGIC_0);
			break;
		//LOAD WORD
		case 1:
			aluSrc.write(SC_LOGIC_1);
			MemtoReg.write(SC_LOGIC_0);
			MemReadWrite.write(SC_LOGIC_0);
			ControlAlu.write(SC_LOGIC_0);
			Regwrite.write(SC_LOGIC_1);
			RegDst.write(SC_LOGIC_0);
			branch_signal.write(SC_LOGIC_0);
			break;
		//STORE WORD
		case 2:
			aluSrc.write(SC_LOGIC_1);
			MemtoReg.write(SC_LOGIC_0);
			MemReadWrite.write(SC_LOGIC_1);
			ControlAlu.write(SC_LOGIC_0);
			Regwrite.write(SC_LOGIC_0);
			RegDst.write(SC_LOGIC_0);
			branch_signal.write(SC_LOGIC_0);
			break;
		//BRANCH EQUAL
		default:
			aluSrc.write(SC_LOGIC_1);
			MemtoReg.write(SC_LOGIC_0);
			MemReadWrite.write(SC_LOGIC_0);
			ControlAlu.write(SC_LOGIC_1);
			Regwrite.write(SC_LOGIC_0);
			RegDst.write(SC_LOGIC_0);
			branch_signal.write(SC_LOGIC_1);
			break;
	}
}
