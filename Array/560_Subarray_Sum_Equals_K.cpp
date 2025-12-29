class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int count =0;
        int n = nums.size();   
        map<int,int>mpp;
        mpp[0] =1;
        int preSum =0;
        for ( int i =0;i<n;i++){
            preSum +=  nums[i];
            int remove = preSum-k;
            count +=mpp[remove];
            mpp[preSum] += 1;
        }

        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int sum =0;
        //         for(int k = i; k < j; k++)
        //             sum = sum + nums[j];
        //         if (sum==k)
        //             count++;
        //     }
        // }
        return count;
    }
};