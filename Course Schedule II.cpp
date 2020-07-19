class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        if(numCourses == 0) return {};
        vector<int> output(numCourses);
        vector<int> order(numCourses,0);
        
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<pre.size();i++){
            int f=pre[i][0];
            int s=pre[i][1];
            adj[s].push_back(f);
            order[f]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(order[i]==0) q.push(i);
        }
        int i=0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            output[i++] = front;
            if(adj.find(front)!=adj.end()) {
                for(int i=0;i<adj[front].size();i++){
                    order[adj[front][i]]--;
                    if(order[adj[front][i]]==0) q.push(adj[front][i]);
                }
            }
            
        }
        if(i==numCourses)
        return output;
        else return {};
    }
};
