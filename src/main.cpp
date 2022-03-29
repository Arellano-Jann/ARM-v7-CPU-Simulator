/**
 * @file main.cpp
 * @author Jann Arellano
 * @brief This program takes in a file and processes the hexadecimal numbers on each line of the file.
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
#include "../headers/Converter.h"

/**
 * @brief The main driver function that takes in a file of assembly code and processes it.
 * 
 * @return int 
 */
int main(){
	uint32_t r0 = 0x0;
	uint32_t r1 = 0x0;
	uint32_t r2 = 0x0;
	uint32_t r3 = 0x0;
	uint32_t r4 = 0x0;
	uint32_t r5 = 0x0;
	uint32_t r6 = 0x0;
	uint32_t r7 = 0x0;
	// uint32_t r8 = 0x0;
	// uint32_t r9 = 0x0;
	// uint32_t r10 = 0x0;
	// uint32_t r11 = 0x0;
	// uint32_t r12 = 0x0;
	// uint32_t r13 = 0x0;
	// uint32_t r14 = 0x0;
	// uint32_t r15 = 0x0;

	std::string filename = "";
	std::cout << "What's the filename? ";
	std::cin >> filename;

	std::ifstream file(filename);

	if (file.is_open()){
		std::string func;
		uint32_t hex1, hex2;

		while (file >> func){
			Converter functionFinder;
			if (functionFinder.findInFunctionList(func) > 5){
				// single input hex
				file >> std::hex >> hex1;
				std::cout << "0x" << std::hex << hex1 << " " << func << " : ";
				Converter converter(func, hex1);
			}
			else{
				// double input hex
				file >> std::hex >> hex1 >> hex2;
				std::cout << "0x" << std::hex << hex1 << " " << func << " ";
					std::cout << "0x" << std::hex << hex2 << " : ";
						Converter converter(func, hex1, hex2); 
			}
		}
 	}
  	file.close();
  
  return 0;
}
    
