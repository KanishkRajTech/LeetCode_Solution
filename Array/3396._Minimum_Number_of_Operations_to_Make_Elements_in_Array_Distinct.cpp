class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (seen.find(nums[i]) != seen.end()) {
                return (i + 1 + 2) / 3; // Equivalent to ceil((i + 1) / 3)
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};
