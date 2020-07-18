class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> freq;
        int n= nums.size();
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
        }
        
        vector<vector<int>> temp(n+1,vector<int>());
        
        for(auto it=freq.begin();it!=freq.end();it++){
            temp[it->second].push_back(it->first);
        }
        vector<int> ans;
        
        int count = 0;
        while(count<k) {
            for(int i=n;i>=1;i--) {
                if(temp[i].size()!=0) {
                    if(temp[i].size()<=(k-count)){
                        ans.insert(ans.end(), temp[i].begin(),temp[i].end());
                        count = count + temp[i].size();
                    } else  {
                        for(int j = 0; j<(k-count);j++){
                            ans.push_back(temp[i][j]);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
