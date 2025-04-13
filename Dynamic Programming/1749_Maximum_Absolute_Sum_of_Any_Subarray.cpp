class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int max_sum = 0, min_sum = 0; 
            int curr_max = 0, curr_min = 0;
    
            for (int num : nums) {
                curr_max = max(num, curr_max + num);
                curr_min = min(num, curr_min + num);
    
                max_sum = max(max_sum, curr_max);
                min_sum = min(min_sum, curr_min);
            }
            
            return max(max_sum, abs(min_sum));
        }
    };