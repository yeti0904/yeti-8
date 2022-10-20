#ifndef YETI8_VM_HH
#define YETI8_VM_HH

#include "_components.hh"
#include "constants.hh"

class VM;

VM& VMInstance();

struct VMRegisters {
	uint8_t ac;
	uint16_t sp;
	uint16_t pc;
	uint16_t hl;
	uint8_t r1;
	uint8_t r2;
	uint8_t r3;
	uint8_t r4;
	uint8_t r5;
	uint8_t r6;
	uint8_t r7;
	uint8_t r8;
	uint8_t r9;
};

class VM {
	public:
		std::array <uint8_t, YETI8_MEMORY_SIZE> memory;
		VMRegisters                             registers;

		VM(); 
		~VM();
		void     LoadProgram(const std::vector <uint8_t>& bytes);
		uint16_t Read16Bit(uint16_t addr);
		void     Write16Bit(uint16_t addr, uint16_t value);
		uint16_t ReadReg(uint8_t reg);
		void     WriteReg(uint8_t reg, uint16_t value);
		size_t   RegSize(uint8_t reg);
		void     RunInstruction(bool& run);
};

#endif