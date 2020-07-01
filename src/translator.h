#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <vector>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

template <typename T>
inline string hexStr(T i) {
  char buf[2*sizeof(T)+1];
  stringstream fstream;
  fstream << "%0" << 2*sizeof(T) << "x" ;
  string format = fstream.str();
  sprintf(buf,format.c_str(),i);
  return string(buf);
}

// disassembler for 8080 binaries
class Translator {
public:
  static pair<int,string> translateOp(const vector<uint8_t>& codebuffer, uint16_t pc) {
    uint8_t opcode = codebuffer[pc];
    int opbytes = 1;

    // using C-style string formats is annoying
    string ret = hexStr<uint16_t>(pc);
    ret.append(" ");

    switch (opcode) {
      case 0x00: ret.append("NOP"); break;
      case 0x01:
      if (codebuffer.size() < pc+3) {
        ret = "invalid opcode";
        break;
      }
      ret.append("LXI    B, #$");
      ret.append(hexStr<uint8_t>(codebuffer[pc+2]));
      ret.append(hexStr<uint8_t>(codebuffer[pc+1]));
      break;
    }
    ret.append("\n");
    return pair<int,string>(opbytes,ret);
  }
};

#endif
