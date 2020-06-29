#include <vector>
#include <string>
#include <cstdio>

using namespace std;

// disassembler for 8080 binaries
class Translator {
public:
  static pair<int,string> translateOp(const vector<uint8_t>& codebuffer, uint16_t pc) {
    uint8_t opcode = codebuffer[pc];
    int opbytes = 1;

    // using C-style string formats is annoying
    char buf[6];
    sprintf(buf, "%04x " ,pc);
    string ret(buf);

    switch (opcode) {
      case 0x00: ret.append("NOP"); break;
    }
    ret.append("\n");
    return pair<int,string>(opbytes,ret);
  }
};
