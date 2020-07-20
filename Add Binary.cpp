class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans ="";
        int len1 = a.size()-1;
        int len2= b.size()-1;
        int carry =0, sum=0;
        while(len1>=0 || len2>=0) {
            int num1 = len1>=0 ? a[len1] - '0' : 0;
            int num2 = len2>=0 ? b[len2] - '0' : 0;
            sum = num1 + num2 + carry; 
            if(sum == 0) {
                sum =0;
                carry=0;
                ans += "0";
            } else if(sum==1) {
                sum = 0;
                carry = 0;
                ans += "1";
            } else if(sum == 2){
                sum = 0;
                carry = 1;
                ans += "0";
            } else if(sum ==3){
                sum =0;
                carry = 1;
                ans+="1";
            }
            len1--;
            len2--;
        }
        

        if(carry) {
            ans+="1";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
