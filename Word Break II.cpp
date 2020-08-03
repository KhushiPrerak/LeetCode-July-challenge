class Solution {
public:
    unordered_map<string, vector<string>> dp;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        if(dp.find(s)!=dp.end()) return dp[s];
        
        vector<string> result;
        
        for(string word : wordDict ) {
            if(s.substr(0,word.length()) == word) {
                if(word.length() == s.length())
                    result.push_back(word);
                else {
                    vector<string> temp = wordBreak(s.substr(word.length()), wordDict);
                    for(string t : temp) {
                        result.push_back(word +" "+t);
                    }
                }
            }
        }
        dp[s] = result;
        return result;
    }
};
