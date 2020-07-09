class Solution {
public:
    int a[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int count=4;
                    for(int k=0;k<4;k++){
                        int ni = i + a[k][0];
                        int nj = j + a[k][1];
                        if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1){
                            count--;
                        }
                    }
                    freq[count]++;
                }
            }
        }
        int ans=0;
        for(auto it=freq.begin();it!=freq.end();it++){
            ans = ans + it->first*it->second;
        }
        return ans;
    }
};
