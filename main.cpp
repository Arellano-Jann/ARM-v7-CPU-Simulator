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
#include "Converter.h"

// /**
//  * @brief Converts a uint32_t base 16 (hex) value to a base 10 value.
//  * 
//  * @param hex the hex to be converted
//  * @return uint32_t The converted base 10 value
//  */
// uint32_t convertHexToDecimal(uint32_t hex){
// 	std::stringstream ss;
// 	ss << std::hex << hex;
// 	ss >> hex;
// 	return hex;
// }

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
			Converter converter(hex1, hex2); // check if this gets destroyed. so no dupe values
			std::cout << "0x" << hex1 << func;
			std::cout << "0x" << hex2 << " : ";

			converter.addFunction();
			converter.printOut();

			// uint32_t decimal1 = convertHexToDecimal(hex1);
			// uint32_t decimal2 = convertHexToDecimal(hex2);
			// printDecimalToHex(addDecimal(hex1, hex2));
    	}
 	}
  	file.close();
  
  return 0;
}
    
