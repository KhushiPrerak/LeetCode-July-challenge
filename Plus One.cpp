class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int c=1;
        for(int i=0;i<digits.size();i++){
            digits[i]+=c;
            c=digits[i]/10;
            digits[i]=digits[i]%10;
        }
        if(c!=0)
            digits.push_back(c);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
