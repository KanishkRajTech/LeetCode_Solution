class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        int m = grid.size(), n = grid[0].size();

        // Flatten the grid into a 1D array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Check if transformation is possible
        for (int num : nums) {
            if ((num - nums[0]) % x != 0) {
                return -1;
            }
        }

        // Find the median
        int median = nums[nums.size() / 2];
        int operations = 0;

        // Calculate operations needed to make all elements equal to median
        for (int num : nums) {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};
