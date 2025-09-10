class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        for(int j=0;j<n;j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }   
        return i+1;
    }
};