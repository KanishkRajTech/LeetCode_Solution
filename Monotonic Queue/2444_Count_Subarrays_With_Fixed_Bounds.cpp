class Solution {
    #define ll long long
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll valid_subarrays = 0;
        int invalid_idx = -1;
        int minK_idx = -1;
        int maxK_idx = -1;

        for(int i=0;i<nums.size();++i){
            if(nums[i]<minK or nums[i]>maxK)    invalid_idx = i;
            
            if(nums[i]==minK)   minK_idx = i;
            if(nums[i]==maxK)   maxK_idx = i;

            int count = max((min(minK_idx,maxK_idx)-invalid_idx),0);
            valid_subarrays += count;
        }
        return valid_subarrays;
    }
};