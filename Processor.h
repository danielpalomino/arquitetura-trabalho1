#include "systemc.h"
#include "Control.h"
#include "MemAdress.h"
#include "Breg.h"
#include "Ula.h"
#include "MemData.h"

SC_MODULE(Processor){
	sc_in<sc_logic> clock;

	Control *control;
	MemAdress *memAdress;
	Breg *breg;
	Ula *ula;
	MemData *memData;

	sc_signal<sc_int> pc;

	void computeOneInstruction();

	SC_CTOR(Processor){
		pc = 0;

		control = new Control();
		
		SC_METHOD(computeOneInstruction);
		sensitive << clock;
	}
};
