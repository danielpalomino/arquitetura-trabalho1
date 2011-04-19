#include "MemData.h"

MemData::compute() {
	if(control.read() == SC_LOGIC_0)
		out_data = mem[adress];
	else
		mem[adress] = in_data;
}
