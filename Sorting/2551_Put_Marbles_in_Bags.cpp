class Solution {
public:
    long long putMarbles(std::vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // Only one partition, difference is 0

        std::vector<int> pairSums;
        
        // Compute adjacent pair sums
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }

        std::sort(pairSums.begin(), pairSums.end());

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSums[i];                     
            maxSum += pairSums[n - 2 - i];             
        }

        return maxSum - minSum;
    }
};
