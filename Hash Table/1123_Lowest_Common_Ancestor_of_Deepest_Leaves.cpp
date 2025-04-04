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
    #define pni pair<TreeNode*,int>

    pni findLCA(TreeNode* curr){
        if(!curr)   return make_pair(nullptr,0);

        pni left = findLCA(curr->left);
        pni right = findLCA(curr->right);

        if(left.second==right.second)
            return make_pair(curr,1+left.second);
        else if(left.second>right.second)
            return make_pair(left.first,1+left.second);
        return make_pair(right.first,1+right.second);
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        pni res = findLCA(root);
        return res.first;
    }
};