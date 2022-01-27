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
 * @brief 
 * 
 * @param hex 
 * @return uint32_t 
 */
uint32_t convertHexToDecimal(uint32_t hex){
	std::stringstream ss;
	ss << std::hex << hex;
	ss >> hex;
	return hex;
}

/**
 * @brief 
 * 
 * @param decimal 
 */
void printDecimalToHex(uint32_t decimal){
	std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << decimal << std::endl;
}

/**
 * @brief 
 * 
 * @param decimal1 
 * @param decimal2 
 * @return uint32_t 
 */
uint32_t addDecimal(uint32_t decimal1, uint32_t decimal2){
	uint32_t hex3;
	hex3 = decimal1 + decimal2;
	return hex3;
}

/**
 * @brief 
 * 
 * @return int 
 */
int main(){

	//ignore the 0x
	//add the 2 hexes by using a dictionary formula
	//each digit corresponds to a number
	//make sure to remember that there's a carry and a sum
	//the remainder will be the carry?
	//the sum will be the not remainder?????

	//read the text input line by line. this comes from a file
	// create a function to take in 3 string values. add, hex, hex.
	// save the first word to a variable and match that first word to an operation
	// save the second word to variable top and truncate the first 2 digits
	// save the third word to variable bot and truncate the first 2 digits
	// add the top to the bot using hex math
		// this is done by converting each digit to a base 10 number and adding them together
	// save the remainder to variable remainder (need to figure this out)
	// add variable remainder to top and to bot. this might just be the regular process or something. needs more work.
	// convert to uint32_t and print out
	// print 2 captured numbers
	// print solution
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
    
