class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
            unordered_map<int, int> postIndex;
            int n = pre.size();
            
            // Store the indices of postorder values for quick lookup
            for (int i = 0; i < n; i++) {
                postIndex[post[i]] = i;
            }
    
            // Helper function for recursion
            function<TreeNode*(int, int, int, int)> build = [&](int preStart, int preEnd, int postStart, int postEnd) -> TreeNode* {
                if (preStart > preEnd) return nullptr;
                
                // Create root node
                TreeNode* root = new TreeNode(pre[preStart]);
                if (preStart == preEnd) return root; // Single node case
    
                // Find the left child in postorder
                int leftChild = pre[preStart + 1];
                int leftSize = postIndex[leftChild] - postStart + 1;
    
                // Build left and right subtrees
                root->left = build(preStart + 1, preStart + leftSize, postStart, postStart + leftSize - 1);
                root->right = build(preStart + leftSize + 1, preEnd, postStart + leftSize, postEnd - 1);
    
                return root;
            };
    
            return build(0, n - 1, 0, n - 1);
        }
    };