#include "systemc.h"
#include "Control.h"
#include "MemAdress.h"
#include "Breg.h"
#include "Ula.h"
#include "MemData.h"

SC_MODULE(Processor){
	sc_in<sc_logic> clock;

	Control *control;
	MemInstruction *memIntruction;
	Breg *breg;
	Ula *ula;
	MemData *memData;

	sc_signal<sc_int> pc;

	void computeInstruction();

	SC_CTOR(Processor){
		pc = 0;
		control = new Control();
		memInstruction = new MemInstruction();
		breg = new Breg();
		ula = new Ula();
		memData = new MemData();
		SC_METHOD(computeInstruction);
		sensitive << clock;
	}
};
