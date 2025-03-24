class Solution {
    #define pii pair<int,int>
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pii> time;
        for(auto& meeting: meetings){
            time.push_back(make_pair(meeting[0],1));
            time.push_back(make_pair(meeting[1]+1,0));
        }
        sort(time.begin(),time.end());
        
        //Apply Line-Sweep 1D
        int overlap = 0;
        int count = time[0].first - 1;//Count free time before start
        for(int i=0;i<time.size()-1;++i){
            if(time[i].second==0)   overlap--;
            else                    overlap++;

            if(overlap==0)
                count += time[i+1].first - time[i].first;
        }
        count += days - time.back().first + 1;//Count free time after end
        return count;
    }
};
