// XOR two numbers and count the number of set bits. 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp  = x^y;
        int setBits = 0;
        while(temp!=0) {
            temp = temp & (temp-1);
            setBits++;
        }
        return setBits;
    }
};
