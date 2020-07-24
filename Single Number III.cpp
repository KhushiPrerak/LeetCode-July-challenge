class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mapp;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        
        vector<int> output;
        for(auto it=mapp.begin();it!=mapp.end();it++){
            if(it->second==1){
                output.push_back(it->first);
            }
        }
        
        return output;
    }
};
