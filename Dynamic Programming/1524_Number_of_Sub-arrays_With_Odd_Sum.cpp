class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            int odd_count = 0, even_count = 1; 
            int prefix_sum = 0, result = 0;
    
            for (int num : arr) {
                prefix_sum += num;
    
                if (prefix_sum % 2 == 0) {
                    result = (result + odd_count) % MOD; 
                    even_count++; 
                } else {
                    result = (result + even_count) % MOD; 
                    odd_count++; 
                }
            }
    
            return result;
        }
    };
    