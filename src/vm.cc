#include "vm.hh"

VM& VMInstance() {
	static VM instance;
	return instance;
}

VM::VM() {
	registers.ac = 0;
	registers.sp = 0;
	registers.pc = 0;
	registers.hl = 0;
	registers.r1 = 0;
	registers.r2 = 0;
	registers.r3 = 0;
	registers.r4 = 0;
	registers.r5 = 0;
	registers.r6 = 0;
	registers.r7 = 0;
	registers.r8 = 0;
	registers.r9 = 0;
}

VM::~VM() {
	
}

void VM::LoadProgram(const std::vector <uint8_t>& bytes) {
	uint16_t addr = 0;
	for (auto& byte : bytes) {
		memory[addr] = byte;
		++ addr;
	}
	registers.sp = addr;
}

uint16_t VM::Read16Bit(uint16_t addr) {
	return (memory[addr] << 010) | (memory[addr + 1]);
}

void VM::Write16Bit(uint16_t addr, uint16_t value) {
	memory[addr]     = (value & 0xFF00) >> 010;
	memory[addr + 1] = value & 0x00FF;
}

uint16_t VM::ReadReg(uint8_t reg) {
	switch (reg) {
		case YETI8_REGISTER_AC: {
			return registers.ac;
		}
		case YETI8_REGISTER_SP: {
			return registers.sp;
		}
		case YETI8_REGISTER_PC: {
			return registers.pc;
		}
		case YETI8_REGISTER_HL: {
			return registers.hl;
		}
		case YETI8_REGISTER_R1: {
			return registers.r1;
		}
		case YETI8_REGISTER_R2: {
			return registers.r2;
		}
		case YETI8_REGISTER_R3: {
			return registers.r3;
		}
		case YETI8_REGISTER_R4: {
			return registers.r5;
		}
		case YETI8_REGISTER_R5: {
			return registers.r5;
		}
		case YETI8_REGISTER_R6: {
			return registers.r6;
		}
		case YETI8_REGISTER_R7: {
			return registers.r7;
		}
		case YETI8_REGISTER_R8: {
			return registers.r8;
		}
		case YETI8_REGISTER_R9: {
			return registers.r9;
		}
	}
	fprintf(stderr, "[ERROR] unknown register: %i\n", reg);
	exit(EXIT_FAILURE);
	return 0;
}

void VM::WriteReg(uint8_t reg, uint16_t value) {
	switch (reg) {
		case YETI8_REGISTER_AC: {
			registers.ac = value;
			break;
		}
		case YETI8_REGISTER_SP: {
			registers.sp = value;
			break;
		}
		case YETI8_REGISTER_PC: {
			registers.pc = value;
			break;
		}
		case YETI8_REGISTER_HL: {
			registers.hl = value;
			break;
		}
		case YETI8_REGISTER_R1: {
			registers.r1 = value;
			break;
		}
		case YETI8_REGISTER_R2: {
			registers.r2 = value;
			break;
		}
		case YETI8_REGISTER_R3: {
			registers.r3 = value;
			break;
		}
		case YETI8_REGISTER_R4: {
			registers.r5 = value;
			break;
		}
		case YETI8_REGISTER_R5: {
			registers.r5 = value;
			break;
		}
		case YETI8_REGISTER_R6: {
			registers.r6 = value;
			break;
		}
		case YETI8_REGISTER_R7: {
			registers.r7 = value;
			break;
		}
		case YETI8_REGISTER_R8: {
			registers.r8 = value;
			break;
		}
		case YETI8_REGISTER_R9: {
			registers.r9 = value;
			break;
		}
		default: {
			fprintf(stderr, "[ERROR] unknown register: %i\n", reg);
			exit(EXIT_FAILURE);	
		}
	}
}

size_t VM::RegSize(uint8_t reg) {
	switch (reg) {
		case YETI8_REGISTER_SP:
		case YETI8_REGISTER_PC:
		case YETI8_REGISTER_HL: {
			return 2;
		}
		default: return 1;
	}
}

void VM::DumpRegisters() {
	printf(
		"REGISTER DUMP\n"
		"=============\n"
		"ac: 0x%X\n"
		"sp: 0x%X\n"
		"pc: 0x%X\n"
		"hl: 0x%X\n"
		"r1: 0x%X\n"
		"r2: 0x%X\n"
		"r3: 0x%X\n"
		"r4: 0x%X\n"
		"r5: 0x%X\n"
		"r6: 0x%X\n"
		"r7: 0x%X\n"
		"r8: 0x%X\n"
		"r9: 0x%X\n",
		registers.ac,
		registers.sp,
		registers.pc,
		registers.hl,
		registers.r1,
		registers.r2,
		registers.r3,
		registers.r4,
		registers.r5,
		registers.r6,
		registers.r7,
		registers.r8,
		registers.r9
	);
}

void VM::RunInstruction(bool& run) {
	uint8_t instruction = memory[registers.pc];
	++ registers.pc;
	switch (instruction) {
		case YETI8_INSTRUCTION_NOP: {
			break;
		}
		case YETI8_INSTRUCTION_STO: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;
			uint16_t addr = Read16Bit(registers.pc);
			registers.pc += 2;
			if (RegSize(reg) == 2) {
				Write16Bit(addr, ReadReg(reg));
			}
			else {
				memory[addr] = (uint8_t) ReadReg(reg);
			}
			break;
		}
		case YETI8_INSTRUCTION_LD: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;
			uint16_t addr = Read16Bit(registers.pc);
			registers.pc += 2;

			if (RegSize(reg) == 2) {
				WriteReg(reg, Read16Bit(addr));
			}
			else {
				WriteReg(reg, memory[addr]);
			}
			break;
		}
		case YETI8_INSTRUCTION_RCP: {
			uint8_t regd = memory[registers.pc];
			++ registers.pc;
			uint8_t regs = memory[registers.pc];
			++ registers.pc;

			WriteReg(regd, ReadReg(regs));
			break;
		}
		case YETI8_INSTRUCTION_MOV: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;
			
			if (RegSize(reg) == 2) {
				WriteReg(reg, Read16Bit(registers.pc));
				registers.pc += 2;
			}
			else {
				WriteReg(reg, memory[registers.pc]);
				++ registers.pc;
			}
			
			break;
		}
		case YETI8_INSTRUCTION_MVI: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;
			
			if (RegSize(reg) == 2) {
				if (registers.ac != 0) {
					WriteReg(reg, Read16Bit(registers.pc));
				}
				registers.pc += 2;
			}
			else {
				if (registers.ac != 0) {
					WriteReg(reg, memory[registers.pc]);
				}
				++ registers.pc;
			}
			break;
		}
		case YETI8_INSTRUCTION_CMP: {
			uint8_t reg1 = memory[registers.pc];
			++ registers.pc;
			uint8_t reg2 = memory[registers.pc];
			++ registers.pc;

			registers.ac = ReadReg(reg1) == ReadReg(reg2)? 255 : 0;
			break;
		}
		case YETI8_INSTRUCTION_ADD: {
			uint8_t reg1 = memory[registers.pc];
			++ registers.pc;
			uint8_t reg2 = memory[registers.pc];
			++ registers.pc;

			registers.ac = ReadReg(reg1) + ReadReg(reg2);
			break;
		}
		case YETI8_INSTRUCTION_SUB: {
			uint8_t reg1 = memory[registers.pc];
			++ registers.pc;
			uint8_t reg2 = memory[registers.pc];
			++ registers.pc;

			registers.ac = ReadReg(reg1) - ReadReg(reg2);
			break;
		}
		case YETI8_INSTRUCTION_MUL: {
			uint8_t reg1 = memory[registers.pc];
			++ registers.pc;
			uint8_t reg2 = memory[registers.pc];
			++ registers.pc;

			registers.ac = ReadReg(reg1) * ReadReg(reg2);
			break;
		}
		case YETI8_INSTRUCTION_DIV: {
			uint8_t reg1 = memory[registers.pc];
			++ registers.pc;
			uint8_t reg2 = memory[registers.pc];
			++ registers.pc;

			registers.ac = ReadReg(reg1) / ReadReg(reg2);
			break;
		}
		case YETI8_INSTRUCTION_NOT: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;

			registers.ac = ~ReadReg(reg);
			break;
		}
		case YETI8_INSTRUCTION_PUSH: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;

			if (RegSize(reg) == 2) {
				++ registers.sp;
				Write16Bit(registers.sp, ReadReg(reg));
				++ registers.sp;
			}
			else {
				++ registers.sp;
				memory[registers.sp] = ReadReg(reg);
			}

			break;
		}
		case YETI8_INSTRUCTION_POP: {
			uint8_t reg = memory[registers.pc];
			++ registers.pc;

			if (RegSize(reg) == 2) {
				-- registers.sp;
				WriteReg(reg, Read16Bit(registers.sp));
				-- registers.sp;
			}
			else {
				WriteReg(reg, memory[registers.sp]);
				-- registers.sp;
			}
			break;
		}
		case YETI8_INSTRUCTION_HLT: {
			run = false;
			return;
		}
		default: {
			fprintf(stderr, "[ERROR] unrecognised instruction %i\n", instruction);
			exit(EXIT_FAILURE);
		}
	}
}