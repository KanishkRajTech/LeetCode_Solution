class Solution {
public:
    
    void reverseArr(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverseArr(nums, 0, n - 1);

        reverseArr(nums, 0, k - 1);

        reverseArr(nums, k, n - 1);
    }
};
