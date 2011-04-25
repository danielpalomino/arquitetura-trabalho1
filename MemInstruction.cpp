#include "MemInstruction.h"

void MemInstruction::compute() {
	instruction = mem[pc.read()];
}
