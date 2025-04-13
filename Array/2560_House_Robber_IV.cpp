class Solution {
    int canAssign(int& max_val,vector<int>& nums,int& k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=max_val){
                count++;
                i++;
            }
        }
        return count>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int mid;

        int ans;
        while(low<=high){
            mid = low+(high-low)/2;
            if(canAssign(mid,nums,k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};