class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string result = "";
            int n = nums.size();
            
            // Use diagonal approach to guarantee a unique string
            for (int i = 0; i < n; ++i) {
                // Flip the i-th character of the i-th string to ensure uniqueness
                result += (nums[i][i] == '0') ? '1' : '0';
            }
            
            return result;
        }
    };