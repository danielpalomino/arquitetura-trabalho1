#include "MemData.h"

void MemData::compute() {
	if(control.read() == SC_LOGIC_0)
		out_data = mem[adress.read()];//LEITURA
	else
		mem[adress.read()] = in_data;//ESCRITA
}
