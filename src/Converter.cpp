#include "../headers/Converter.h"

/**
 * @brief Constructs a new Converter object that takes in three parameters for 2 input assembly instructions
 * 
 * @param func 
 * @param hex1 
 * @param hex2 
 */
Converter::Converter(std::string func, uint32_t hex1, uint32_t hex2)
	: func(func)
	, hex1(hex1)
	, hex2(hex2)
{
	int funcType = findInFunctionList(func);
	switch(funcType){
		case 1:{ addFunction(); break; }
		case 2:{ andFunction(); break; }
		case 6:{ asrFunction(); break; }
		case 7:{ lsrFunction(); break; }
		case 8:{ lslFunction(); break; }
		case 9:{ notFunction(); break; }
		case 3:{ orrFunction(); break; }
		case 4:{ subFunction(); break; }
		case 5:{ xorFunction(); break; }
    	default:{ std::cout << "Function not found" << std::endl; break; }
	}
}

/**
 * @brief Constructs a new Converter object that takes in two parameters for 1 input assembly instructions
 * 
 * @param func 
 * @param hex1 
 */
Converter::Converter(std::string func, uint32_t hex1)
	: func(func)
	, hex1(hex1)
{
	int funcType = findInFunctionList(func);
	switch(funcType){
		case 1:{ addFunction(); break; }
		case 2:{ andFunction(); break; }
		case 6:{ asrFunction(); break; }
		case 7:{ lsrFunction(); break; }
		case 8:{ lslFunction(); break; }
		case 9:{ notFunction(); break; }
		case 3:{ orrFunction(); break; }
		case 4:{ subFunction(); break; }
		case 5:{ xorFunction(); break; }
    	default:{ std::cout << "Function not found" << std::endl; break; }
	}
}

/**
 * @brief Takes in a string function from the file and compares it to an array and returns the position of the string in the array.
 * 
 * @param func 
 * @return int 
 */
int Converter::findInFunctionList(std::string func){
	for (int i = 0; i < 9; i++){
		if (func==(functionList[i])){
			return i+1;
		}
	}
	return -1;
}

/**
 * @brief Prints the base 16 (hex) form in "0x" format.
 * 
 */
void Converter::printOut(){
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << finalHex << std::endl;
}

/**
 * @brief Adds hex1 and hex2 together.
 * 
 */
void Converter::addFunction(){
	finalHex = hex1 + hex2;
	printOut();
}

/**
 * @brief Ands hex1 and hex2 together.
 * 
 */
void Converter::andFunction(){
	finalHex = hex1 & hex2;
	printOut();
}

/**
 * @brief Shifts hex1 and hex2 arithmetically right 1 place.
 * 
 */
void Converter::asrFunction(){
	finalHex = hex1/2; // hex1 >> 1
	printOut();
}

/**
 * @brief Shifts hex1 and hex2 logically right 1 place.
 * 
 */
void Converter::lsrFunction(){
	finalHex = hex1/2; // hex1 >> 1
	printOut();
}

/**
 * @brief Shifts hex1 and hex2 logically left 1 place.
 * 
 */
void Converter::lslFunction(){
	finalHex = hex1*2; // hex1 << 1
	printOut();
}

/**
 * @brief Nots hex1 and hex2 together.
 * 
 */
void Converter::notFunction(){
	finalHex = ~hex1;
	printOut();
}

/**
 * @brief Ors hex1 and hex2 together.
 * 
 */
void Converter::orrFunction(){
	finalHex = hex1 | hex2;
	printOut();
}

/**
 * @brief Subtracts hex1 and hex2 together.
 * 
 */
void Converter::subFunction(){
	finalHex = hex1 - hex2;
	printOut();
}

/**
 * @brief Exclusive Ors hex1 and hex2 together.
 * 
 */
void Converter::xorFunction(){
	finalHex = hex1 ^ hex2;
	printOut();
}