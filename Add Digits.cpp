// O(1) Runtime solution 
class Solution {
public:

    int addDigits(int num) {
        
        if(num == 0) return 0;
        
        if(num%9 == 0) return 9; // as digits of multiples of 9 always adds up to 9
        else return num%9; 
        // digit_sum(10*n) = digit_sum(n)
        // digit_sum(n + 9*n) = digit_sum(n)
        
    }
};
