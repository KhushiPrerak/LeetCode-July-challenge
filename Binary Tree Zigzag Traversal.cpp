class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> output;
        if(root==NULL) return output;
        queue<TreeNode*> pending;
        pending.push(root);
        while(!pending.empty()){
            int size = pending.size();
            vector<int> temp;
            while(size--) {
                auto front = pending.front();
                temp.push_back(front->val);
                pending.pop();
                if(front->left) pending.push(front->left);
                if(front->right) pending.push(front->right);
            }
            output.push_back(temp);
        }
        
        for(int i=1;i<output.size();i=i+2) {
            reverse(output[i].begin(),output[i].end());
        }
        return output;
        
    }
};
