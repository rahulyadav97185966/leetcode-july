//Reverse Bits
class Solution {
public:
      uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; ++i) {
            // swap bit i and bit 31 - i
            int tmp = ((1 << i) & n) >> i;
            tmp ^= ((1 << (31-i)) & n) >> (31-i);
            n ^= tmp << i;
            n ^= tmp << (31 - i);
        }
        return n;
    }
};
