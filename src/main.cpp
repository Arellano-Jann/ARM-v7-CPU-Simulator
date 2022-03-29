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

enum GlobalRegister : uint32_t{
	
	r0 = 0x0 , 
	r1 = 0x0 , 
	r2 = 0x0 , 
	r3 = 0x0 , 
	r4 = 0x0 , 
	r5 = 0x0 , 
	r6 = 0x0 , 
	r7 = 0x0 , 
	// r8 = 0x0;
	// r9 = 0x0;
	// r10 = 0x0;
	// r11 = 0x0;
	// r12 = 0x0;
	// r13 = 0x0;
	// r14 = 0x0;
	// r15 = 0x0;
};

/**
 * @brief The main driver function that takes in a file of assembly code and processes it.
 * 
 * @return int 
 */
int main(){

	std::string filename = "";
	std::cout << "What's the filename? ";
	std::cin >> filename;

	std::ifstream file(filename);

	if (file.is_open()){
		std::string func;
		uint32_t Rn, Rm;

		while (file >> func){
			Converter functionFinder;
			if (functionFinder.findInFunctionList(func) > 5){
				// single input hex
				file >> std::hex >> Rn;
				std::cout << "0x" << std::hex << Rn << " " << func << " : ";
				Converter converter(func, Rn);
			}
			else{
				// double input hex
				file >> std::hex >> Rn >> Rm;
				std::cout << "0x" << std::hex << Rn << " " << func << " ";
					std::cout << "0x" << std::hex << Rm << " : ";
						Converter converter(func, Rn, Rm); 
			}
		}
 	}
  	file.close();
  
  return 0;
}
    
