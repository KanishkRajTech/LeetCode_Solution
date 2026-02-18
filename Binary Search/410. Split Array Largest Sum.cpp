class Solution {
public:
    int  countPartitions(vector<int>& nums, int time){
        int partitions = 1; 
        long subarraySum = 0; 

        for (int num : nums) {
            if (subarraySum + num <= time) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int low  = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0); 
        while(low <= high){
            int time = (low+high)/2;

            int partitions = countPartitions(nums, time);
            if(partitions > k)
                low = time+1;
            else
                high = time-1; 
        }
        return low;
    }
};