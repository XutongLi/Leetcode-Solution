class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0; //0xFFFFFFFF
        while (num & mask)
            mask <<= 1;
        return num ^ ~mask;
    }
};
//num = 00000000...101
//mask = 11111...  000
//num ^ ~mask = 010