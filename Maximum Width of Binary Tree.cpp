class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        long width = 0;
        while(!q.empty()) {
            long left = q.front().second;
            long right = left;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                right = q.front().second;
                q.pop();
                if(curr->left) q.push({curr->left, 2 * right});
                if(curr->right) q.push({curr->right, 2 * right + 1});
            }
            width = max(width, right - left + 1);
        }
        return width;
    }
};
