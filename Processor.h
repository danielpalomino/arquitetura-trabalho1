#include "systemc.h"
#include "Control.h"
#include "MemInstruction.h"
#include "Breg.h"
#include "Ula.h"
#include "MemData.h"

SC_MODULE(Processor){
	sc_in<sc_logic> clock;

	Control control;
	MemInstruction memInstruction;
	Breg breg;
	Ula ula;
	MemData memData;
	//Control *control;
	//MemInstruction *memInstruction;
	//Breg *breg;
	//Ula *ula;
	//MemData *memData;

	//sinais de controle
	sc_signal<sc_uint<6> > op;
	sc_signal<sc_logic> aluSrc, MemtoReg, MemReadWrite, ControlAlu, Regwrite, RegDst;
	//sinais do pc
	sc_signal<sc_uint<32> > pc, regular_pc;
	sc_signal<sc_logic> branch_signal;
	//saída da memoria de intrução
	sc_signal<sc_uint<32> > instruction;
	//entradas e saídas do banco de registradores
	sc_signal<sc_uint<5> > rs, rt, rd;
	sc_signal<sc_int<32> > outBreg1, outBreg2;
	//endereço extendido
	sc_signal<sc_uint<32> > SignExtended;
	sc_signal<sc_int<32> > completeAdress;
	//sinais da ula
	sc_signal<sc_int<32> > outUla;
	sc_signal<sc_logic> ulaFlagZ;
	//sinais memoria de dados
	sc_signal<sc_int<32> > outMemData;

	void computeInstruction();
	//control = new Control();
	//memInstruction = new MemInstruction();
	//breg = new Breg();
	//ula = new Ula();
	//memData = new MemData();

	SC_CTOR(Processor) : control("controle"), memInstruction("memIns"), breg("bancoReg"), ula ("regs"), memData("memData")
   {
		pc = 0;
		SC_METHOD(computeInstruction);
		sensitive << clock;
	}
};
