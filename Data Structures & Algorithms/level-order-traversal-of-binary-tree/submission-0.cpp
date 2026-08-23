/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root, int lev = 0) {
        if(root == nullptr) return ans;
        if(ans.size() < lev+1) ans.push_back(vector<int>{});
        ans[lev].push_back(root->val);
        levelOrder(root->left, lev + 1);
        levelOrder(root->right, lev + 1);
        return ans;
    }
};
