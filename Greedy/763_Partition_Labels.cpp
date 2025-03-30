class Solution {
    public:
        vector<int> partitionLabels(string s) {
            vector<int> lastIndex(26, 0);
            vector<int> partitions;
    
            // Step 1: Store last occurrence of each character
            for (int i = 0; i < s.size(); i++) {
                lastIndex[s[i] - 'a'] = i;
            }
    
            // Step 2: Iterate through the string and form partitions
            int maxLast = 0, partitionStart = 0;
            for (int i = 0; i < s.size(); i++) {
                maxLast = max(maxLast, lastIndex[s[i] - 'a']);
                if (i == maxLast) { // End of partition
                    partitions.push_back(i - partitionStart + 1);
                    partitionStart = i + 1;
                }
            }
    
            return partitions;
        }
    };
    