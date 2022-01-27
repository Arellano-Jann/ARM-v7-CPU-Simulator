#include.cpp

void addHex(std::string line){
  std::string function;
  std::string hex1;
  std::string hex2;
  //int i = 0;
  for (int i = 0 ; i < line.length(); i++){ // does this stop at the space or after the space???
    if (line[i] == ' '){ break; }
    function += line[i];
  }
  for (int i = function.length(); i < line.length(); i++){
    if (line[i] == ' '){ break; }
    hex1 += line[i];
  }
  for (int i = function.length() + hex1.length(); i < line.length(); i++){
    if (line[i] == ' '){ break; }
    hex2 += line[i];
  }
  hex1.erase(0, 2);
  hex2.erase(0, 2);

  uint32_t decimal1 = convertHexToDecimal(hex1); // ensure hex1 saves properly
  uint32_t decimal2 = convertHexToDecimal(hex2);
  return addHexHelper(decimal1, decimal2);
}
    
uint32_t convertHexToDecimal(std::string hex){ // maybe put a &
  // hex = std::stoul(hex, nullptr, 16);
  unsigned long hex1;
  hex1 = std::stoul(hex,nullptr,16);
  uint32_t decimal = hex1;
  return decimal;
  //convert to uint32_t
}

void addHexHelper(uint32_t hex1, uint32_t hex2){
  uint32_t hex3;
  hex3 = hex1 + hex2;
  //if (hex3 > UINT32_MAX){ hex3 - UINT32_MAX; }
  printDecimalToHex(hex3);
}

void printDecimalToHex(uint32_t decimal){
  std::cout << std::setfill('0') << std::setw(8) << std::hex << decimal;
}