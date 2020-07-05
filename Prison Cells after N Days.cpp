class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        if(cells.size() == 0 ||  N == 0) return cells;
        N = N%14==0 ? 14 : N%14; // idk why. saw this from the discussion forum. Will update code as soon as I figure this out.
        for(int i=0;i<N;i++) {
            vector<int> ans(cells.size());
            ans[0] = ans[cells.size()-1]=0;
            for(int j=1;j<cells.size()-1;j++){
                if(cells[j-1]==cells[j+1]){
                    ans[j] = 1;
                } else {
                    ans[j] = 0;
                }
            }
            cells = ans;
        }
        return cells;
    }
};
