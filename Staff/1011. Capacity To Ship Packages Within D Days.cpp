class Solution {
public:
    int checkWeihg(vector<int>& weights, int mid){
        int sum =0;
        int days =0;
        for(int i : weights){
            if((sum + i) <= mid)
                sum += i;
            else{
                days ++;
                sum =i;
            }
        }
        return days +1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeights = 0;
        for(int w:weights){
            totalWeights +=w;
        }
        int low = *max_element(weights.begin(), weights.end());
        int high = totalWeights;
        while(low <= high){
            int mid = (low+high)/2;

            int result = checkWeihg(weights, mid);

            if( result <= days )
                high = mid-1;
            else
                low = mid+1;
        }
        return low;
    }
};