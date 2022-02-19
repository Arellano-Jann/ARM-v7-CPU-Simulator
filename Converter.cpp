#include "Converter.h"


Converter::Converter(std::string func, uint32_t hex1, uint32_t hex2)
	: func(func)
	, hex1(hex1)
	, hex2(hex2)
{
	int funcType = find(func);
	std::cout << funcType;
	switch(funcType){
		case 0:{ std::cout << "Function not found" << std::endl; break; }
		case 1:{ addFunction(); break; }
		case 2:{ andFunction(); break; }
		case 3:{ asrFunction(); break; }
		case 4:{ lsrFunction(); break; }
		case 5:{ lslFunction(); break; }
		case 6:{ notFunction(); break; }
		case 7:{ orrFunction(); break; }
		case 8:{ subFunction(); break; }
		case 9:{ xorFunction(); break; }
	}
}

int Converter::find(std::string func){
	for (int i = 0; i < 9; i++){
		if (func==(functionList[i])){
			return i+1;
		}
	}
	return 0;
}

/**
 * @brief Prints the base 16 (hex) form in "0x" format.
 * 
 * @param decimal The base 10 value to be printed in base 16 form
 */
void Converter::printOut(){
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << finalHex << std::endl;
}

/**
 * @brief Adds 2 uint32_t base 10 values together.
 * 
 * @param finalHex1 The first base 10 value to be added
 * @param finalHex2 The second base 10 value to be added
 * @return uint32_t The base 10 result of the addition of two base 10 values.
 */
void Converter::addFunction(){
	finalHex = hex1 + hex2;
	printOut();
}


void Converter::andFunction(){
	finalHex = hex1 & hex2;
	printOut();
}

void Converter::asrFunction(){
	finalHex = hex1/2; // hex1 >> 1
	printOut();
}

void Converter::lsrFunction(){
	finalHex = hex1/2; // hex1 >> 1
	printOut();
}

void Converter::lslFunction(){
	finalHex = hex1*2; // hex1 << 1
	printOut();
}

void Converter::notFunction(){
	finalHex = ~hex1;
	printOut();
}

void Converter::orrFunction(){
	finalHex = hex1 | hex2;
	printOut();
}

void Converter::subFunction(){
	finalHex = hex1 - hex2;
	printOut();
}

void Converter::xorFunction(){
	finalHex = hex1 ^ hex2;
	printOut();
}

