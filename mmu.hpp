#pragma once

#include <string>


class Mmu
{
 public:
  unsigned char readByte(unsigned short addr);
  unsigned short readWord(unsigned short addr);
  void writeByte(unsigned short addr, unsigned char value);
  void writeWord(unsigned short addr, unsigned short value);
  
  void reset();

  void loadFile(const std::string& filename);



 private:
  static const unsigned char _bios;
  

};

