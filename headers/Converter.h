#pragma once
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>

/**
 * @brief Determines the function and does an operation depending on the function found in functionList. It prints it out afterwards.
 * 
 */
class Converter{
	uint32_t Rn = 0; // first operand
	uint32_t Rm = 0; // second operand
	uint32_t Rd = 0; // destination
	std::string func = "";
	char functionList[10][4] = {"ADD" , "AND" , "ORR" , "SUB" , "XOR" , "ASR" , "LSR" , "LSL" , "NOT" , "MOV"};

	void printOut(); // Prints out final hex
	void addFunction(); // Add the operands
	void andFunction(); // Do a bitwise AND of the operands
	void asrFunction(); // Do a 1-bit arithmetic shift right for signed numbers
	void lsrFunction(); // Do a 1-bit logical shift right for unsigned numbers
	void lslFunction(); // Do a 1-bit logical shift left for unsigned numbers
	void notFunction(); // Do a bitwise NOT on the first operand
	void orrFunction(); // Do a bitwise OR of the operands
	void subFunction(); // Subtract the second operand from the first operand
	void xorFunction(); // Do a bitwise exclusive OR of the operands
	void movFunction(); // Move the second (immediate) operand to the first operand

public:
	Converter() = default;
	Converter(std::string func, uint32_t Rn, uint32_t Rm);
	Converter(std::string func, uint32_t Rn);
	int findInFunctionList(std::string func);
};
