class Solution {
public:
    int  FindSmallestDivisor(vector<int>& nums,int divisor){
        int  n = nums.size()-1;
        int total =0;
       for (int x : nums) {
            total += (x + divisor - 1) / divisor; 
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1;
        int high = *max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid = (low+high)/2;

            int result = FindSmallestDivisor(nums, mid);
          
            if (result <= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};