class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int tik0 = 0, tik1 = INT_MIN;
        int tik0_old = 0;
        
        for(int val:prices) {
            int temp = tik0;
            tik0 = max(tik0, tik1 + val);
            tik1 = max(tik1, tik0_old-val);
            tik0_old = temp;
        }
        return tik0;
    }
};
