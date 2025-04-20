class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        unordered_map<int,int> group_freq;
        int count = 0;
        
        //Insert all elements and count full_group_elements
        for(int ele: answers){
            if(ele==0)
                count += 1;
            else{
                group_freq[ele]++;
                if(group_freq[ele]==ele+1){
                    count += ele+1;
                    group_freq[ele]=0;
                }
            }
        }
        //Add leftover
        for(auto [group,freq]: group_freq)
            if(freq>0)
                count += group+1;
        
        return count;
    }
};
