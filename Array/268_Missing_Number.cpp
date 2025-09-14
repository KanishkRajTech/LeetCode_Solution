class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

       
        long long totalsum = n * (n + 1) / 2;  

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int missingnum = totalsum - sum;
        return missingnum; 
    }
};