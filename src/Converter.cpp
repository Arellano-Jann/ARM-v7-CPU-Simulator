#include "../headers/Converter.h"

/**
 * @brief Constructs a new Converter object that takes in three parameters for 2 input assembly instructions
 * 
 * @param func 
 * @param Rn 
 * @param Rm 
 */
Converter::Converter(std::string func, uint32_t Rn, uint32_t Rm)
	: func(func)
	, Rn(Rn)
	, Rm(Rm)
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
 * @param Rn 
 */
Converter::Converter(std::string func, uint32_t Rn)
	: func(func)
	, Rn(Rn)
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
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << Rd << std::endl;
}

/**
 * @brief Adds Rn and Rm together.
 * 
 */
void Converter::addFunction(){
	Rd = Rn + Rm;
	printOut();
}

/**
 * @brief Ands Rn and Rm together.
 * 
 */
void Converter::andFunction(){
	Rd = Rn & Rm;
	printOut();
}

/**
 * @brief Shifts Rn and Rm arithmetically right 1 place.
 * 
 */
void Converter::asrFunction(){
	Rd = Rn/2; // Rn >> 1
	printOut();
}

/**
 * @brief Shifts Rn and Rm logically right 1 place.
 * 
 */
void Converter::lsrFunction(){
	Rd = Rn/2; // Rn >> 1
	printOut();
}

/**
 * @brief Shifts Rn and Rm logically left 1 place.
 * 
 */
void Converter::lslFunction(){
	Rd = Rn*2; // Rn << 1
	printOut();
}

/**
 * @brief Nots Rn and Rm together.
 * 
 */
void Converter::notFunction(){
	Rd = ~Rn;
	printOut();
}

/**
 * @brief Ors Rn and Rm together.
 * 
 */
void Converter::orrFunction(){
	Rd = Rn | Rm;
	printOut();
}

/**
 * @brief Subtracts Rn and Rm together.
 * 
 */
void Converter::subFunction(){
	Rd = Rn - Rm;
	printOut();
}

/**
 * @brief Exclusive Ors Rn and Rm together.
 * 
 */
void Converter::xorFunction(){
	Rd = Rn ^ Rm;
	printOut();
}

void Converter::movFunction(){
	Rd = Rn;
	printOut();
}