class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        output.push_back({});
        for(int num : nums){
            vector<vector<int>> sub;
            for(auto cur : output) {
                vector<int> temp = cur;
                temp.push_back(num);
                sub.push_back(temp);
            }
            for(auto cur : sub) {
                output.push_back(cur);
            }
        }
        return output;
    }
};
