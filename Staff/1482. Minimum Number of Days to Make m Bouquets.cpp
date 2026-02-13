class Solution {
public:
    bool makeBouquetDay(vector<int>& bloomDay, int mid, int m, int k){
        int bouquet =0;
        int flower =0;
        for(int i =0;i <= bloomDay.size()-1;i++){
            if(bloomDay[i] <= mid){
                flower ++;
                if(flower == k){
                    bouquet++;
                    flower =0;
                }
            }
            else
                flower =0;
        }
        return bouquet >=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
       
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if( (long long)m*k > n)  return -1;
        while (low<=high){
            int mid = (low+high)/2;

            if( makeBouquetDay(bloomDay, mid, m, k) )
                high = mid -1;
            else
                low = mid +1;

        }
        return low;
    }
};