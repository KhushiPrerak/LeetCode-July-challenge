class Solution {
public:
    unordered_map<int,int> mapp;
    TreeNode* helper(vector<int>&inorder, int inS, int inE, vector<int>&postorder, int postS, int postE){
        if(postS>postE || inS>inE) return NULL;
        TreeNode* root = new TreeNode(postorder[postE]);
        int idx = mapp[postorder[postE]];
        int count = inE-idx;
        root->left = helper(inorder,inS , idx-1,postorder,postS , postE-count-1 );
        root->right = helper(inorder,idx+1 ,inE ,postorder, postE-count,postE-1 );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mapp[inorder[i]] = i;
        }
        return helper(inorder, 0, n-1, postorder, 0,n-1);
    }
};
