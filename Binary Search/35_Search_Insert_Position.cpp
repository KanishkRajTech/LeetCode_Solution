class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low =0;
        int n = nums.size();
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid +1;
        }

        return ans;
    }
};