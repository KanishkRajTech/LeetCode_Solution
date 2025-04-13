class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> st;
            int i = 0, n = traversal.size();
    
            while (i < n) {
                int depth = 0;
                // Count dashes to determine depth
                while (i < n && traversal[i] == '-') {
                    depth++;
                    i++;
                }
                
                // Extract node value
                int value = 0;
                while (i < n && isdigit(traversal[i])) {
                    value = value * 10 + (traversal[i] - '0');
                    i++;
                }
    
                TreeNode* node = new TreeNode(value);
    
                // Adjust stack to correct depth
                while (st.size() > depth) {
                    st.pop();
                }
    
                // Attach node to parent
                if (!st.empty()) {
                    if (!st.top()->left) st.top()->left = node;
                    else st.top()->right = node;
                }
    
                // Push node to stack
                st.push(node);
            }
    
            // Root is the first node added to the stack
            while (st.size() > 1) {
                st.pop();
            }
    
            return st.top();
        }
    };