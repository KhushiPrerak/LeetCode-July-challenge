class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> char_freq(26,0);
        for(int i=0;i<tasks.size();i++){
            char_freq[tasks[i]-'A']++;
        }
        
        sort(char_freq.begin(),char_freq.end());
        
        int max_val = char_freq[25] - 1;
        int idle_slots = max_val*n;
        
        for(int i=24;i>=0;i--){
            idle_slots -= min(char_freq[i],max_val);
        }
        return (idle_slots>0)?idle_slots+tasks.size() : tasks.size();
    }
};
