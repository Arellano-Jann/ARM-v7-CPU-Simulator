#include "Converter.h"

/**
 * @brief Prints the base 16 (hex) form in "0x" format from a uint32_t base 10 value.
 * 
 * @param decimal The base 10 value to be printed in base 16 form
 */
void Converter::printOut(){
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << decimal << std::endl;
}

/**
 * @brief Adds 2 uint32_t base 10 values together.
 * 
 * @param decimal1 The first base 10 value to be added
 * @param decimal2 The second base 10 value to be added
 * @return uint32_t The base 10 result of the addition of two base 10 values.
 */
void Converter::addFunction(){
	decimal = hex1 + hex2;
}


void Converter::andFunction(){
	decimal = hex1 and hex2;
}

void Converter::asrFunction(){
	
}

void Converter::lsrFunction(){
	
}

void Converter::lslFunction(){
	
}

void Converter::notFunction(){
	decimal = not hex1;
}

void Converter::orrFunction(){
	decimal = hex1 or hex2;
}

void Converter::subFunction(){
	decimal = hex1 - hex2;
}

void Converter::xorFunction(){
	decimal = hex1 xor hex2;
}

