// Recursive Solution 
class Solution {
public:
    void fill(TreeNode* root, vector<vector<int>>& out, int level){
        if(root==NULL) return;
        if(root->left) fill(root->left,out,level+1);
        if(root->right) fill(root->right,out,level+1);
        out[out.size()-1-level].push_back(root->val);
    }
    int levels(TreeNode* root){
        if(root==NULL)return 0;
        int left = levels(root->left);
        int right=levels(root->right);
        return 1+max(left,right);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        int l = levels(root);
        vector<vector<int>> out(l,vector<int>());
        fill(root,out,0);
        return out;
    }
};

// Iterative Solution 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> output;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front!=NULL){
                level.push_back(front->val);
                if(front->left) q.push(front->left);
                if(front->right)q.push(front->right);
            } else {
                output.push_back(level);
                level.clear();
                if(!q.empty())
                    q.push(NULL);
            }
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
