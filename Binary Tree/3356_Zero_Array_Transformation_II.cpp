class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            vector<int> diff(n+1,0);
            int sum=0;
            int pos=0;
            for(int i=0;i<n;++i){
                while(sum + diff[i] < nums[i]){
                    if(pos==queries.size())
                        return -1;
                    
                    int start = queries[pos][0];
                    int end = queries[pos][1];
                    int val = queries[pos][2];
                    pos++;
                    
                    if(end < i) continue; 
    
                   
                    diff[max(start,i)]+=val;
                    diff[end+1]-=val;
                }
                sum += diff[i];
            }
            return pos;
        }
    };
    