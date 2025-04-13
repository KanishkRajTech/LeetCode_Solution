class Solution {
    public:
        string smallestNumber(string pattern) {
            string result = "";
            stack<int> st;
    
            for (int i = 0; i <= pattern.size(); ++i) {
                st.push(i + 1);
                if (i == pattern.size() || pattern[i] == 'I') {
                    while (!st.empty()) {
                        result += to_string(st.top());
                        st.pop();
                    }
                }
            }
    
            return result;
        }
    };