class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int minEven = INT_MAX;
        int minOdd = INT_MAX;


        for(int x : nums1){
            if(x % 2 == 0){
                minEven = min(minEven, x);
            } else {
                minOdd = min(minOdd, x);

            }
        }

        // bool canMakeOdd = (minOdd < minEven);
        // bool canMakeEven = (oddCount >= 2);

        // return canMakeOdd || canMakeEven;
        if(minEven == INT_MAX) return true;
        if(minOdd == INT_MAX) return true;
        return minOdd < minEven;
    }
};