class Solution {
public:
    string reverseWords(string s) {
        
        string ans = "", temp ="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                temp+=s[i];
            } else {
                if(temp!="") {
                    if(ans==""){
                        ans = temp;
                    } else {
                        ans = temp + " " +ans;
                    }
                    temp ="";
                }
            }
        }
        if(temp!="") {
            if(ans==""){
                ans = temp;
            } else {
                ans = temp + " " +ans;
            }
            temp ="";
        }
        return ans;
    }
};
