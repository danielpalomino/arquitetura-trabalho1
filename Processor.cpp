#include "Processor.h"

void Processor::computeInstruction() {

	//amarrar sinais de controle
	control.clk(clock);
	control.aluSrc(aluSrc);
	control.MemtoReg(MemtoReg);
	control.MemReadWrite(MemReadWrite);
	control.ControlAlu(ControlAlu);
	control.Regwrite(Regwrite);
	control.RegDst(RegDst);
	control.branch_signal(branch_signal);
	//amarrar o pc a entrada da memoria de intruções
	op.write(instruction.read().range(31,26));
	memInstruction.pc(pc);
	//amarrar o op da intrução ao controle
	control.op(op);
	//amarrar a instrução de controle ao breg, ext sinal, memoria e ula
	rs.write(instruction.read().range(25,21));
	rt.write(instruction.read().range(20,16));
	if(RegDst.read() == SC_LOGIC_0)
		rd.write(instruction.read().range(20,16));
	else
		rd.write(instruction.read().range(15,11));

	breg.control(Regwrite);
	breg.read_Adress1(rs);
	breg.read_Adress2(rt);
	breg.write_Adress(rd);
	breg.out_data1(outBreg1);
	breg.out_data2(outBreg2);
	//amarrar os dados de saída dos regs a ula
	SignExtended.write(instruction.read().range(15,0));

	completeAdress.write(SignExtended.read().to_int());

	ula.control(ControlAlu);
	ula.op_a(outBreg1);
	if(aluSrc.read() == SC_LOGIC_0)
		ula.op_b(outBreg2);
	else
		ula.op_b(completeAdress);
	ula.out_data(outUla);
	ula.flag_z(ulaFlagZ);
	//amarrar a saida da ula a memoria de dados e ao breg
	memData.control(MemReadWrite);
	memData.out_data(outMemData);
	memData.adress(outUla);
	memData.in_data(outBreg2);

	if(MemtoReg.read() == SC_LOGIC_0)
		breg.in_data(outMemData);
	else
		breg.in_data(outUla);
	//incrementar o pc
	regular_pc.write(pc.read()+4);
	if(ulaFlagZ.read().to_bool() & branch_signal.read().to_bool())
		pc.write(regular_pc.read()+SignExtended.read());
	else
		pc.write(regular_pc.read());
}

