#include "CPU6502.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <sstream>
#include "Globals.h"

CPU6502::CPU6502()
{
}


CPU6502::~CPU6502()
{
}

bool CPU6502::Start()
{
	std::cout << "Starting CPU6502 module." << std::endl;
	CreateInstructionArray();	
	//LoadRom("Super_mario_brothers2.nes");	
	//LoadRom("Super Mario Bros. (World).nes");	
	LoadRom("Castlevania (USA) (Rev A).nes");

	return true;
}

void CPU6502::CreateInstructionArray() {

	instructions[0x61] = Instruction(0x61, 2, 6, "ADC	 ($@,X)	");
	instructions[0x65] = Instruction(0x65, 2, 3, "ADC	 $@		");
	instructions[0x69] = Instruction(0x69, 2, 2, "ADC	 #$@	");
	instructions[0x6D] = Instruction(0x6D, 3, 4, "ADC	 $@¡	");
	instructions[0x71] = Instruction(0x71, 2, 5, "ADC	 ($@),Y	");
	instructions[0x75] = Instruction(0x75, 2, 4, "ADC	 $@,X	");
	instructions[0x79] = Instruction(0x79, 3, 4, "ADC	 $@¡,Y	");
	instructions[0x7D] = Instruction(0x7D, 3, 4, "ADC	 $@¡,X	");
	instructions[0x4B] = Instruction(0x4B, 2, 2, "ALR*	 #$@	");
	instructions[0x0B] = Instruction(0x0B, 2, 2, "ANC*	 #$@	");
	instructions[0x2B] = Instruction(0x2B, 2, 2, "ANC*	 #$@	");
	instructions[0x21] = Instruction(0x21, 2, 6, "AND	 ($@,X)	");
	instructions[0x25] = Instruction(0x25, 2, 3, "AND	 $@		");
	instructions[0x29] = Instruction(0x29, 2, 2, "AND	 #$@	");
	instructions[0x2D] = Instruction(0x2D, 3, 4, "AND	 $@¡	");
	instructions[0x31] = Instruction(0x31, 2, 5, "AND	 ($@),Y	");
	instructions[0x35] = Instruction(0x35, 2, 4, "AND	 $@,X	");
	instructions[0x39] = Instruction(0x39, 3, 4, "AND	 $@¡,Y	");
	instructions[0x3D] = Instruction(0x3D, 3, 4, "AND	 $@¡,X	");
	instructions[0x8B] = Instruction(0x8B, 2, 2, "ANE*	 #$@	");
	instructions[0xAB] = Instruction(0xAB, 2, 2, "ANX*	 #$@	");
	instructions[0x6B] = Instruction(0xAB, 2, 2, "ARR*	 #$@	");
	instructions[0x06] = Instruction(0x06, 2, 5, "ASL	 $@		");
	instructions[0x0A] = Instruction(0x0A, 1, 2, "ASL	 A		");
	instructions[0x0E] = Instruction(0x0E, 3, 6, "ASL	 $@¡	");
	instructions[0x16] = Instruction(0x16, 2, 6, "ASL	 $@,X	");
	instructions[0x1E] = Instruction(0x1E, 3, 7, "ASL	 $@¡,X	");
	instructions[0x03] = Instruction(0x03, 2, 8, "ASO*	 ($@,X)	");
	instructions[0x07] = Instruction(0x07, 2, 5, "ASO*	 $@		");
	instructions[0x0F] = Instruction(0x0F, 3, 6, "ASO*	 $@¡	");
	instructions[0x13] = Instruction(0x13, 2, 8, "ASO*	 ($@),Y	");
	instructions[0x17] = Instruction(0x17, 2, 6, "ASO*	 $@,X	");
	instructions[0x1B] = Instruction(0x1B, 3, 7, "ASO*	 $@¡,Y	");
	instructions[0x1F] = Instruction(0x1F, 3, 7, "ASO*	 $@¡,X	");
	instructions[0x43] = Instruction(0x43, 1, 2, "ASR	 A		");
	instructions[0x44] = Instruction(0x44, 2, 4, "ASR	 $@		");
	instructions[0x54] = Instruction(0x54, 2, 4, "ASR	 $@,X	");
	instructions[0x90] = Instruction(0x90, 2, 2, "BCC	 @		"); //@ = PC + VALUE
	instructions[0xB0] = Instruction(0xB0, 2, 2, "BCS	 @		"); //@ = PC + VALUE
	instructions[0xF0] = Instruction(0xF0, 2, 2, "BEQ	 @		"); //@ = PC + VALUE
	instructions[0x24] = Instruction(0x24, 2, 3, "BIT	 $@		");
	instructions[0x2C] = Instruction(0x2C, 3, 4, "BIT	 $@¡	");
	instructions[0x30] = Instruction(0x30, 2, 2, "BMI	 @		"); //@ = PC + VALUE
	instructions[0xD0] = Instruction(0xD0, 2, 2, "BNE	 @		"); //@ = PC + VALUE
	instructions[0x10] = Instruction(0x10, 2, 2, "BPL	 @		"); //@ = PC + VALUE
	instructions[0x80] = Instruction(0x80, 2, 2, "BRA	 @		"); //@ = PC + VALUE
	instructions[0x00] = Instruction(0x00, 2, 2, "BRk	 #$@	");
	instructions[0x50] = Instruction(0x50, 2, 2, "BVC	 @		"); //@ = PC + VALUE
	instructions[0x70] = Instruction(0x70, 2, 2, "BVS	 @		"); //@ = PC + VALUE
	instructions[0x18] = Instruction(0x18, 1, 2, "CLC			");
	instructions[0xD8] = Instruction(0xD8, 1, 2, "CLD			");
	instructions[0x58] = Instruction(0x58, 1, 2, "CLI			");
	instructions[0xB8] = Instruction(0xB8, 1, 2, "CLV			");
	instructions[0xC1] = Instruction(0xC1, 2, 6, "CMP	 ($@,X)	");
	instructions[0xC5] = Instruction(0xC5, 2, 3, "CMP	 $@		");
	instructions[0xC9] = Instruction(0xC9, 2, 2, "CMP	 #$@	");
	instructions[0xCD] = Instruction(0xCD, 3, 4, "CMP	 $@¡	");
	instructions[0xD1] = Instruction(0xD1, 2, 5, "CMP	 ($@),Y	");
	instructions[0xD5] = Instruction(0xD5, 2, 4, "CMP	 $@,X	");
	instructions[0xD9] = Instruction(0xD9, 3, 4, "CMP	 $@¡,Y	");
	instructions[0xDD] = Instruction(0xDD, 3, 4, "CMP	 $@¡,X	");
	instructions[0xE0] = Instruction(0xE0, 2, 2, "CPX	 #$@	");
	instructions[0xE4] = Instruction(0xE4, 2, 3, "CPX	 $@		");
	instructions[0xEC] = Instruction(0xEC, 3, 4, "CPX	 $@¡	");
	instructions[0xC0] = Instruction(0xC0, 2, 2, "CPY	 #$@	");
	instructions[0xC4] = Instruction(0xC4, 2, 3, "CPY	 $@		");
	instructions[0xCC] = Instruction(0xCC, 3, 4, "CPY	 $@¡	");
	instructions[0xC3] = Instruction(0xC3, 2, 8, "DCM*	 ($@,X)	");
	instructions[0xC7] = Instruction(0xC7, 2, 5, "DCM*	 $@		");
	instructions[0xCF] = Instruction(0xCF, 3, 6, "DCM*	 $@¡	");
	instructions[0xD3] = Instruction(0xD3, 2, 8, "DCM*	 ($@),Y	");
	instructions[0xD7] = Instruction(0xD7, 2, 6, "DCM*	 $@,X	");
	instructions[0xDB] = Instruction(0xDB, 3, 7, "DCM*	 $@¡,Y	");
	instructions[0xDF] = Instruction(0xDF, 3, 7, "DCM*	 $@¡,X	");
	instructions[0xC6] = Instruction(0xC6, 2, 5, "DEC	 $@     ");
	instructions[0xCE] = Instruction(0xCE, 3, 6, "DEC	 $@¡    ");
	instructions[0xD6] = Instruction(0xD6, 2, 6, "DEC	 $@,X   ");
	instructions[0xDE] = Instruction(0xDE, 3, 7, "DEC	 $@¡,X  ");
	instructions[0xCA] = Instruction(0xCA, 1, 2, "DEX	        ");
	instructions[0x88] = Instruction(0x88, 1, 2, "DEY	        ");
	instructions[0x41] = Instruction(0x41, 2, 6, "EOR	 ($@,X) ");
	instructions[0x45] = Instruction(0x45, 2, 3, "EOR	 $@     ");
	instructions[0x49] = Instruction(0x49, 2, 2, "EOR	 #$@    ");
	instructions[0x4D] = Instruction(0x4D, 3, 4, "EOR	 $@¡    ");
	instructions[0x51] = Instruction(0x51, 2, 5, "EOR	 ($@),Y ");
	instructions[0x55] = Instruction(0x55, 2, 4, "EOR	 $@,X   ");
	instructions[0x59] = Instruction(0x59, 3, 4, "EOR	 $@¡,Y  ");
	instructions[0x5D] = Instruction(0x5D, 3, 4, "EOR	 $@¡,X  ");
	instructions[0x02] = Instruction(0x02, 1, 2, "HLT*	        ");
	instructions[0x12] = Instruction(0x12, 1, 2, "HLT*	        ");
	instructions[0x22] = Instruction(0x22, 1, 2, "HLT*	        ");
	instructions[0x32] = Instruction(0x32, 1, 2, "HLT*	        ");
	instructions[0x42] = Instruction(0x42, 1, 2, "HLT*	        ");
	instructions[0x52] = Instruction(0x52, 1, 2, "HLT*	        ");
	instructions[0x62] = Instruction(0x62, 1, 2, "HLT*	        ");
	instructions[0x72] = Instruction(0x72, 1, 2, "HLT*	        ");
	instructions[0x92] = Instruction(0x92, 1, 2, "HLT*	        ");
	instructions[0xB2] = Instruction(0xB2, 1, 2, "HLT*	        ");
	instructions[0xD2] = Instruction(0xD2, 1, 2, "HLT*	        ");
	instructions[0xF2] = Instruction(0xF2, 1, 2, "HLT*	        ");
	instructions[0xE6] = Instruction(0xE6, 2, 5, "INC	 $@     ");
	instructions[0xEE] = Instruction(0xEE, 3, 6, "INC	 $@¡    ");
	instructions[0xF6] = Instruction(0xF6, 2, 6, "INC	 $@,X   ");
	instructions[0xFE] = Instruction(0xFE, 3, 7, "INC	 $@¡,X  ");
	instructions[0xE3] = Instruction(0xE3, 2, 8, "INS*	 ($@,X) ");
	instructions[0xE7] = Instruction(0xE7, 2, 5, "INS*	 $@     ");
	instructions[0xEF] = Instruction(0xEF, 3, 6, "INS*	 $@¡    ");
	instructions[0xF3] = Instruction(0xF3, 2, 8, "INS*	 ($@),Y ");
	instructions[0xF7] = Instruction(0xF7, 2, 6, "INS*	 $@,X   ");
	instructions[0xFB] = Instruction(0xFB, 3, 7, "INS*	 $@¡,Y  ");
	instructions[0xFF] = Instruction(0xFF, 3, 7, "INS*	 $@¡,X  ");
	instructions[0xE8] = Instruction(0xE8, 1, 2, "INX	        ");
	instructions[0xC8] = Instruction(0xC8, 1, 2, "INY	        ");
	instructions[0x4C] = Instruction(0x4C, 3, 3, "JMP	 $@¡    ");
	instructions[0x6C] = Instruction(0x6C, 3, 5, "JMP	 ($@¡)  ");
	instructions[0x20] = Instruction(0x20, 3, 6, "JSR	 $@¡    ");
	instructions[0xBB] = Instruction(0xBB, 3, 4, "LAS*	 $@¡,Y  ");
	instructions[0xA3] = Instruction(0xA3, 2, 6, "LAX*	 ($@,X) ");
	instructions[0xA7] = Instruction(0xA7, 2, 3, "LAX*	 $@     ");
	instructions[0xAF] = Instruction(0xAF, 3, 4, "LAX*	 $@¡    ");
	instructions[0xB3] = Instruction(0xB3, 2, 5, "LAX*	 ($@),Y ");
	instructions[0xB7] = Instruction(0xB7, 2, 4, "LAX*	 $@,Y   ");
	instructions[0xBF] = Instruction(0xBF, 3, 4, "LAX*	 $@¡,Y  ");
	instructions[0xA1] = Instruction(0xA1, 2, 6, "LDA	 ($@,X) ");
	instructions[0xA5] = Instruction(0xA5, 2, 3, "LDA	 $@     ");
	instructions[0xA9] = Instruction(0xA9, 2, 2, "LDA	 #$@    ");
	instructions[0xAD] = Instruction(0xAD, 3, 4, "LDA	 $@¡    ");
	instructions[0xB1] = Instruction(0xB1, 2, 5, "LDA	 ($@),Y ");
	instructions[0xB5] = Instruction(0xB5, 2, 4, "LDA	 $@,X   ");
	instructions[0xB9] = Instruction(0xB9, 3, 4, "LDA	 $@¡,Y  ");
	instructions[0xBD] = Instruction(0xBD, 3, 4, "LDA	 $@¡,X  ");
	instructions[0xA2] = Instruction(0xA2, 2, 2, "LDX	 #$@    ");
	instructions[0xA6] = Instruction(0xA6, 2, 3, "LDX	 $@     ");
	instructions[0xAE] = Instruction(0xAE, 3, 4, "LDX	 $@¡    ");
	instructions[0xB6] = Instruction(0xB6, 2, 4, "LDX	 $@,Y   ");
	instructions[0xBE] = Instruction(0xBE, 3, 4, "LDX	 $@¡,Y  ");
	instructions[0xA0] = Instruction(0xA0, 2, 2, "LDY	 #$@    ");
	instructions[0xA4] = Instruction(0xA4, 2, 3, "LDY	 $@     ");
	instructions[0xAC] = Instruction(0xAC, 3, 4, "LDY	 $@¡    ");
	instructions[0xB4] = Instruction(0xB4, 2, 4, "LDY	 $@,X   ");
	instructions[0xBC] = Instruction(0xBC, 3, 4, "LDY	 $@¡,X  ");
	instructions[0x43] = Instruction(0x43, 2, 8, "LSE*	 ($@,X) ");
	instructions[0x47] = Instruction(0x47, 2, 5, "LSE*	 $@     ");
	instructions[0x4F] = Instruction(0x4F, 3, 6, "LSE*	 $@¡    ");
	instructions[0x53] = Instruction(0x53, 2, 8, "LSE*	 ($@),Y ");
	instructions[0x57] = Instruction(0x57, 2, 6, "LSE*	 $@,X   ");
	instructions[0x5B] = Instruction(0x5B, 3, 7, "LSE*	 $@¡,Y  ");
	instructions[0x5F] = Instruction(0x5F, 3, 7, "LSE*	 $@¡,X  ");
	instructions[0x46] = Instruction(0x46, 2, 5, "LSR	 $@     ");
	instructions[0x4A] = Instruction(0x4A, 1, 2, "LSR	 A      ");
	instructions[0x4E] = Instruction(0x4E, 3, 6, "LSR	 $@¡    ");
	instructions[0x56] = Instruction(0x56, 2, 6, "LSR	 $@,X   ");
	instructions[0x5E] = Instruction(0x5E, 3, 7, "LSR	 $@¡,X  ");
	instructions[0xEA] = Instruction(0xEA, 0, 1, "NOP	        ");
	instructions[0x1A] = Instruction(0x1A, 1, 2, "NOP*	        ");
	instructions[0x3A] = Instruction(0x3A, 1, 2, "NOP*	        ");
	instructions[0x5A] = Instruction(0x5A, 1, 2, "NOP*	        ");
	instructions[0x7A] = Instruction(0x7A, 1, 2, "NOP*	        ");
	instructions[0xDA] = Instruction(0xDA, 1, 2, "NOP*	        ");
	instructions[0xFA] = Instruction(0xFA, 1, 2, "NOP*	        ");
	instructions[0x01] = Instruction(0x01, 2, 6, "ORA	 ($@,X) ");
	instructions[0x05] = Instruction(0x05, 2, 3, "ORA	 $@     ");
	instructions[0x09] = Instruction(0x09, 2, 2, "ORA	 #$@    ");
	instructions[0x0D] = Instruction(0x0D, 3, 4, "ORA	 $@¡    ");
	instructions[0x11] = Instruction(0x11, 2, 5, "ORA	 ($@),Y ");
	instructions[0x15] = Instruction(0x15, 2, 4, "ORA	 $@,X   ");
	instructions[0x19] = Instruction(0x19, 3, 4, "ORA	 $@¡,Y  ");
	instructions[0x1D] = Instruction(0x1D, 3, 4, "ORA	 $@¡,X  ");
	instructions[0x48] = Instruction(0x48, 1, 3, "PHA	        ");
	instructions[0x08] = Instruction(0x08, 1, 3, "PHP	        ");
	instructions[0x68] = Instruction(0x68, 1, 4, "PLA	        ");
	instructions[0x28] = Instruction(0x28, 1, 4, "PLP	        ");
	instructions[0x23] = Instruction(0x23, 2, 8, "RLA*	 ($@,X) ");
	instructions[0x27] = Instruction(0x27, 2, 5, "RLA*	 $@     ");
	instructions[0x2F] = Instruction(0x2F, 3, 6, "RLA*	 $@¡    ");
	instructions[0x33] = Instruction(0x33, 2, 8, "RLA*	 ($@),Y ");
	instructions[0x37] = Instruction(0x37, 2, 6, "RLA*	 $@,X   ");
	instructions[0x3B] = Instruction(0x3B, 3, 7, "RLA*	 $@¡,Y  ");
	instructions[0x3F] = Instruction(0x3F, 3, 7, "RLA*	 $@¡,X  ");
	instructions[0x26] = Instruction(0x26, 2, 5, "ROL	 $@     ");
	instructions[0x2A] = Instruction(0x2A, 1, 2, "ROL	 A      ");
	instructions[0x2E] = Instruction(0x2E, 3, 6, "ROL	 $@¡    ");
	instructions[0x36] = Instruction(0x36, 2, 6, "ROL	 $@,X   ");
	instructions[0x3E] = Instruction(0x3E, 3, 7, "ROL	 $@¡,X  ");
	instructions[0x66] = Instruction(0x66, 2, 5, "ROR	 $@     ");
	instructions[0x6A] = Instruction(0x6A, 1, 2, "ROR	 A      ");
	instructions[0x6E] = Instruction(0x6E, 3, 6, "ROR	 $@¡    ");
	instructions[0x76] = Instruction(0x76, 2, 6, "ROR	 $@,X   ");
	instructions[0x7E] = Instruction(0x7E, 3, 7, "ROR	 $@¡,X  ");
	instructions[0x63] = Instruction(0x63, 2, 8, "RRA*	 ($@,X) ");
	instructions[0x67] = Instruction(0x67, 2, 5, "RRA*	 $@     ");
	instructions[0x6F] = Instruction(0x6F, 3, 6, "RRA*	 $@¡    ");
	instructions[0x73] = Instruction(0x73, 2, 8, "RRA*	 ($@),Y ");
	instructions[0x77] = Instruction(0x77, 2, 6, "RRA*	 $@,X   ");
	instructions[0x7B] = Instruction(0x7B, 3, 7, "RRA*	 $@¡,Y  ");
	instructions[0x7F] = Instruction(0x7F, 3, 7, "RRA*	 $@¡,X  ");
	instructions[0x40] = Instruction(0x40, 1, 6, "RTI	        ");
	instructions[0x60] = Instruction(0x60, 1, 6, "RTS	        ");
	instructions[0x83] = Instruction(0x83, 2, 6, "SAX*	 ($@,X) ");
	instructions[0x87] = Instruction(0x87, 2, 3, "SAX*	 $@     ");
	instructions[0x8F] = Instruction(0x8F, 3, 4, "SAX*	 $@¡    ");
	instructions[0x97] = Instruction(0x97, 2, 4, "SAX*	 $@,Y   ");
	instructions[0xE1] = Instruction(0xE1, 2, 6, "SBC	 ($@,X) ");
	instructions[0xE5] = Instruction(0xE5, 2, 3, "SBC	 $@     ");
	instructions[0xE9] = Instruction(0xE9, 2, 2, "SBC	 #$@    ");
	instructions[0xEB] = Instruction(0xEB, 2, 2, "SBC*	 #$@    ");
	instructions[0xED] = Instruction(0xED, 3, 4, "SBC	 $@¡    ");
	instructions[0xF1] = Instruction(0xF1, 2, 5, "SBC	 ($@),Y ");
	instructions[0xF5] = Instruction(0xF5, 2, 4, "SBC	 $@,X   ");
	instructions[0xF9] = Instruction(0xF9, 3, 4, "SBC	 $@¡,Y  ");
	instructions[0xFD] = Instruction(0xFD, 3, 4, "SBC	 $@¡,X  ");
	instructions[0xCB] = Instruction(0xCB, 2, 2, "SBX*	 #$@    ");
	instructions[0x38] = Instruction(0x38, 1, 2, "SEC	        ");
	instructions[0xF8] = Instruction(0xF8, 1, 2, "SED	        ");
	instructions[0x78] = Instruction(0x78, 1, 2, "SEI	        ");
	instructions[0x93] = Instruction(0x93, 2, 6, "SHA*	 ($@),Y ");
	instructions[0x9F] = Instruction(0x9F, 3, 5, "SHA*	 $@¡,Y  ");
	instructions[0x9E] = Instruction(0x9E, 3, 5, "SHX*	 $@¡,Y  ");
	instructions[0x9C] = Instruction(0x9C, 3, 5, "SHY*	 $@¡,X  ");
	instructions[0x04] = Instruction(0x04, 2, 3, "SKB*	 $@     ");
	instructions[0x14] = Instruction(0x14, 2, 4, "SKB*	 $@,X   ");
	instructions[0x34] = Instruction(0x34, 2, 4, "SKB*	 $@,X   ");
	instructions[0x44] = Instruction(0x44, 2, 3, "SKB*	 $@     ");
	instructions[0x54] = Instruction(0x54, 2, 4, "SKB*	 $@,X   ");
	instructions[0x64] = Instruction(0x64, 2, 3, "SKB*	 $@     ");
	instructions[0x74] = Instruction(0x74, 2, 4, "SKB*	 $@,X   ");
	instructions[0x80] = Instruction(0x80, 2, 2, "SKB*	 #$@    ");
	instructions[0x82] = Instruction(0x82, 2, 2, "SKB*	 #$@    ");
	instructions[0x89] = Instruction(0x89, 2, 2, "SKB*	 #$@    ");
	instructions[0xC2] = Instruction(0xC2, 2, 2, "SKB*	 #$@    ");
	instructions[0xD4] = Instruction(0xD4, 2, 4, "SKB*	 $@,X   ");
	instructions[0xE2] = Instruction(0xE2, 2, 2, "SKB*	 #$@    ");
	instructions[0xF4] = Instruction(0xF4, 2, 4, "SKB*	 $@,X   ");
	instructions[0x0C] = Instruction(0x0C, 3, 4, "SKW*	 $@¡    ");
	instructions[0x1C] = Instruction(0x1C, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0x3C] = Instruction(0x3C, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0x5C] = Instruction(0x5C, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0x7C] = Instruction(0x7C, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0xDC] = Instruction(0xDC, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0xFC] = Instruction(0xFC, 3, 4, "SKW*	 $@¡,X  ");
	instructions[0x81] = Instruction(0x81, 2, 6, "STA	 ($@,X) ");
	instructions[0x85] = Instruction(0x85, 2, 3, "STA	 $@     ");
	instructions[0x8D] = Instruction(0x8D, 3, 4, "STA	 $@¡    ");
	instructions[0x91] = Instruction(0x91, 2, 6, "STA	 ($@),Y ");
	instructions[0x95] = Instruction(0x95, 2, 4, "STA	 $@,X   ");
	instructions[0x99] = Instruction(0x99, 3, 5, "STA	 $@¡,Y  ");
	instructions[0x9D] = Instruction(0x9D, 3, 5, "STA	 $@¡,X  ");
	instructions[0x86] = Instruction(0x86, 2, 3, "STX	 $@     ");
	instructions[0x8E] = Instruction(0x8E, 3, 4, "STX	 $@¡    ");
	instructions[0x96] = Instruction(0x96, 2, 4, "STX	 $@,Y   ");
	instructions[0x84] = Instruction(0x84, 2, 3, "STY	 $@     ");
	instructions[0x8C] = Instruction(0x8C, 3, 4, "STY	 $@¡    ");
	instructions[0x94] = Instruction(0x94, 2, 4, "STY	 $@,X   ");
	instructions[0xAA] = Instruction(0xAA, 1, 2, "TAX	        ");
	instructions[0xA8] = Instruction(0xA8, 1, 2, "TAY	        ");
	instructions[0xBA] = Instruction(0xBA, 1, 2, "TSX	        ");
	instructions[0x8A] = Instruction(0x8A, 1, 2, "TXA	        ");
	instructions[0x9A] = Instruction(0x9A, 1, 2, "TXS	        ");
	instructions[0x98] = Instruction(0x98, 1, 2, "TYA	        ");
}

bool CPU6502::LoadRom(const std::string& name)
{
	std::cout << "Loading ROM " << name << "." << std::endl;
	uchar opcode;	
	std::ifstream source(name.c_str(), std::ios_base::binary);
	std::stringstream ss;

	////////////////////////////////////////////////////////////////////////////////////////////////
	//Header
	char header[16];
	source.read(header, sizeof(char) * 16);
	ss << header[0] << header[1] << header[2];	
	if (ss.str() != "NES") {
		std::cout << "Bad header. Aborting." << std::endl;
	}
	assert(source);
	
	PRG_ROM_size = header[4] * 16;
	CHR_ROM_size = header[5] * 8;

	std::cout << "PRG_ROM size " + std::to_string(PRG_ROM_size) + "Kb." << std::endl;
	std::cout << "CHR_ROM size " + std::to_string(CHR_ROM_size) + "Kb." << std::endl;

	//Flags		
	F6 = { (uchar)header[6] };
	std::cout << std::endl << "Flag6" << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << "Mapper: " << std::to_string(F6 >> 4) << std::endl;
	std::cout << "Ignore mirroring: " << std::to_string(GET_BIT(3,F6)) << std::endl;
	std::cout << "Trainer: " << std::to_string(GET_BIT(2, F6)) << std::endl;
	std::cout << "Battery-packed PRG RAM: " << std::to_string(GET_BIT(1, F6)) << std::endl;
	std::cout << "Mirroring: " << std::to_string(GET_BIT(0, F6)) << std::endl;
	
	F7 = { (uchar)header[7] };
	
	std::cout << std::endl << "Flag7" << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << "Mapper: " << std::to_string(F7 >> 4) << std::endl;
	if (GET_2BIT(2, F7) == 2)
		std::cout << "Format: NES 2.0" << std::endl;
	else
		std::cout << "Format: iNES" << std::endl;

	std::cout << "PlayChoice-10: " << std::to_string(GET_BIT(1, F7)) << std::endl;
	std::cout << "VS Unisystem: " << std::to_string(GET_BIT(0, F7)) << std::endl;

	F8 = { (uchar)header[8] };

	std::cout << std::endl << "Flag8" << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << "PRG RAM size: " << std::to_string(F8) << std::endl;
	
	F9 = { (uchar)header[9] };

	F10 = { (uchar)header[10] };

	std::cout << std::endl << "Flag9" << std::endl;
	std::cout << "-----" << std::endl;
	if (GET_2BIT(0, F10) == 0)
		std::cout << "TV system: NTSC"<< std::endl;
	else if (F10 << 6 >> 6 == 2)
		std::cout << "TV system: PAL"<< std::endl;
	else
		std::cout << "TV system: Dual compatible"<< std::endl;
			
	mapper = (F7 >> 4) * 4 + (F6 >> 4);

	std::cout << std::endl << "Mapper #" << std::to_string(mapper) << std::endl;
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	PRG_ROM.resize(PRG_ROM_size * 1024);

	source.read(reinterpret_cast<char*>(&PRG_ROM[0]), sizeof(char) * PRG_ROM_size * 1024);
	return false;
}
