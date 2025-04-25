class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> freq;
            freq[0] = 1; // for subarrays starting at index 0
    
            long long ans = 0;
            int count = 0;
    
            for (int num : nums) {
                if (num % modulo == k) count++;
    
                int currMod = count % modulo;
                int requiredMod = (currMod - k + modulo) % modulo;
    
                if (freq.count(requiredMod)) {
                    ans += freq[requiredMod];
                }
    
                freq[currMod]++;
            }
    
            return ans;
        }
    };
    