class Solution {
    public:
        string getHappyString(int n, int k) {
            vector<string> result;
            string current = "";
            backtrack(n, current, result);
            
            if (k > result.size()) {
                return "";
            }
            
            return result[k - 1];
        }
        
        void backtrack(int n, string& current, vector<string>& result) {
            if (current.size() == n) {
                result.push_back(current);
                return;
            }
            
            for (char ch : {'a', 'b', 'c'}) {
                if (current.empty() || current.back() != ch) {
                    current.push_back(ch);
                    backtrack(n, current, result);
                    current.pop_back();
                }
            }
        }
    };