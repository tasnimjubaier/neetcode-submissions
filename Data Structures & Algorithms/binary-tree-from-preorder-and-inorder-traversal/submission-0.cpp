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
    TreeNode* buildTree(vector<int>& p, vector<int>& q) {
        if(p.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(p[0]);

        int idx;
        for(int i = 0; i < q.size(); i++) if(q[i] == p[0]) {idx = i; break;}


        vector<int> x, y;
        int sz1 = idx, sz2 = q.size() - 1 - idx; 
        for(int i = 1; i < 1 + sz1; i++) x.push_back(p[i]);
        for(int i = 0; i < sz1; i++) y.push_back(q[i]);

        root->left = buildTree(x, y);

        x.clear(), y.clear();

        for(int i = sz1+1; i < p.size(); i++) x.push_back(p[i]);
        for(int i = sz1+1; i < q.size(); i++) y.push_back(q[i]);

        root->right = buildTree(x, y);
        return root; 
    }
};
