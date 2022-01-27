/**
 * @file main.cpp
 * @author Jann Arellano
 * @brief This program takes in a file and adds the 2 hexadecimal numbers on each line of the file.
 * @version 0.1
 * @date 2022-01-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @brief Converts a uint32_t base 16 (hex) value to a base 10 value.
 * 
 * @param hex the hex to be converted
 * @return uint32_t The converted base 10 value
 */
uint32_t convertHexToDecimal(uint32_t hex){
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> hex;
	return hex;
}

/**
 * @brief Prints the base 16 (hex) form in "0x" format from a uint32_t base 10 value.
 * 
 * @param decimal The base 10 value to be printed in base 16 form
 */
void printDecimalToHex(uint32_t decimal){
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << decimal << std::endl;
}

/**
 * @brief Adds 2 uint32_t base 10 values together.
 * 
 * @param decimal1 The first base 10 value to be added
 * @param decimal2 The second base 10 value to be added
 * @return uint32_t The base 10 result of the addition of two base 10 values.
 */
uint32_t addDecimal(uint32_t decimal1, uint32_t decimal2){
	uint32_t hex3;
	hex3 = decimal1 + decimal2;
	return hex3;
}

/**
 * @brief The main driver function that takes in a file and processes it.
 * 
 * @return int 
 */
int main(){
	std::string filename;
	std::cout << "What's the filename? ";
	std::cin >> filename;

	std::ifstream file(filename);

	if (file.is_open()){
		std::string func;
		uint32_t hex1, hex2;
		while (file >> func >> std::hex >> hex1 >> hex2){
			std::cout << func << " FUNCTION: ";
			std::cout << "0x" << hex1 << " + ";
			std::cout << "0x" << hex2 << " : ";
			uint32_t decimal1 = convertHexToDecimal(hex1);
			uint32_t decimal2 = convertHexToDecimal(hex2);
			printDecimalToHex(addDecimal(decimal1, decimal2));
    	}
 	}
  	file.close();
  
  return 0;
}
    
