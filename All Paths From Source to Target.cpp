class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> output;
        vector<int> path;
        dfs(graph,path,output,0);
        return output;   
    }
    void dfs(vector<vector<int>>& graph, vector<int>&path, vector<vector<int>>& output,int sv){
        
        path.push_back(sv);
        if(sv==graph.size()-1)
            output.push_back(path);
        for(int i=0;i<graph[sv].size();i++){
            dfs(graph,path, output, graph[sv][i]);
        }
        path.pop_back();
    }
};
