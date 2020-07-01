#include "../src/translator.h"
#include <gtest/gtest.h>

using namespace std;

TEST(translatorTest, test_translate_nop) {
  std::vector<uint8_t> codebuf = {0x00};
  pair<int,string> tout = Translator::translateOp(codebuf, 0);
  EXPECT_EQ(tout.first,1);
  EXPECT_EQ(tout.second,"0000 NOP\n");
}

TEST(translatorTest, test_translate_lxi_b) {
  std::vector<uint8_t> codebuf = {0x01, 0x02, 0x03};
  pair<int,string> tout = Translator::translateOp(codebuf, 0);
  EXPECT_EQ(tout.first,1);
  EXPECT_EQ(tout.second,"0000 LXI    B, #$0302\n");
}
