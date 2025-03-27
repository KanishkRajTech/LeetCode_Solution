class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the dominant element using Boyer-Moore Voting Algorithm
        int candidate = -1, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Verify if the candidate is actually dominant
        int totalCount = 0;
        for (int num : nums) {
            if (num == candidate) totalCount++;
        }
        if (totalCount * 2 <= n) return -1; // No valid split exists

        // Step 3: Find the minimum valid split index
        int leftCount = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == candidate) leftCount++;

            int leftSize = i + 1;
            int rightSize = n - leftSize;
            int rightCount = totalCount - leftCount;

            // Check if the candidate is dominant in both halves
            if (leftCount * 2 > leftSize && rightCount * 2 > rightSize) {
                return i;
            }
        }

        return -1; // No valid split found
    }
};
