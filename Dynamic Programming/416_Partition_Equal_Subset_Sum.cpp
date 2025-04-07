class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is odd, we can't split it equally
        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case: sum 0 is always possible

        for (int num : nums) {
            // go backwards to avoid using the same element more than once
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
