#include "systemc.h"

Processor::computeInstruction() {
	//amarrar o pc a entrada da memoria de intruções
	memIntruction->pc(pc);
	//amarrar o op da intrução ao controle
	control->op(
	//usar os sinais de controle para os muxs
	//amarrar a instrução de controle ao breg, ext sinal, memoria e ula
	//amarrar os dados de saída dos regs a ula
	//amarrar a saida da ula a memoria de dados e ao breg
	//incrementar o pc
}
