#pragma once
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>

class Converter{
	uint32_t hex1;
	uint32_t hex2;
	uint32_t decimal;
public:
	Converter(uint32_t hex1, uint32_t hex2);
	void printOut();
	void addFunction();
	void andFunction();
	void asrFunction();
	void lsrFunction();
	void lslFunction();
	void notFunction();
	void orrFunction();
	void subFunction();
	void xorFunction();	
};

Converter::Converter(uint32_t hex1, uint32_t hex2)
	: hex1(hex1)
	, hex2(hex2)
{}
