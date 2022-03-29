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
#include <map>
#include "../headers/Converter.h"

// struct GlobalRegister{
	
// 	uint32_t r0 = 0x0;
// 	uint32_t r1 = 0x0;
// 	uint32_t r2 = 0x0;
// 	uint32_t r3 = 0x0;
// 	uint32_t r4 = 0x0;
// 	uint32_t r5 = 0x0;
// 	uint32_t r6 = 0x0;
// 	uint32_t r7 = 0x0;
// 	// uint32_t r8 = 0x0;
// 	// uint32_t r9 = 0x0;
// 	// uint32_t r10 = 0x0;
// 	// uint32_t r11 = 0x0;
// 	// uint32_t r12 = 0x0;
// 	// uint32_t r13 = 0x0;
// 	// uint32_t r14 = 0x0;
// 	// uint32_t r15 = 0x0;
// };

/**
 * @brief The main driver function that takes in a file of assembly code and processes it.
 * 
 * @return int 
 */
int main(){
	std::map<std::string, uint32_t> registers;
	registers.insert(std::pair<std::string, uint32_t>("r1",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r2",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r3",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r4",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r5",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r6",0x0));
	registers.insert(std::pair<std::string, uint32_t>("r7",0x0));


	std::string filename = "";
	std::cout << "What's the filename? ";
	std::cin >> filename;

	std::ifstream file(filename);

	if (file.is_open()){
		std::string func;
		uint32_t Rd, Rn, Rm;

		while (file >> func){
			Converter functionFinder;
			if (functionFinder.findInFunctionList(func) > 5){
				// single input
				file >> std::hex >> Rd >> Rn;
				std::cout << "0x" << std::hex << Rn << " " << func << " : ";

				Converter converter(func, Rn);
				// Converter registerFinder;
				// int reg = registerFinder.findRegister(Rd);
				registers[Rd, converter.getRd()];
			}
			else{
				// double input
				file >> std::hex >> Rd >> Rn >> Rm;
				std::cout << "0x" << std::hex << Rn << " " << func << " ";
				std::cout << "0x" << std::hex << Rm << " : ";
				Converter converter(func, Rd, Rn, Rm);
				Rd = converter.getRd();

			}
		}
 	}
  	file.close();
  
  return 0;
}
    
