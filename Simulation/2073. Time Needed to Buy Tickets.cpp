class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        for(int i = 0; i < tickets.size(); i++) {
            q.push(i);
        }
        int time = 0;
        while(true) {
            int i =q.front();
            q.pop();
            tickets[i]--;
            time++;
            if(tickets[i]== 0&& i== k) {
                return time;
            }
            if(tickets[i] >0) {
                q.push(i);
            }
        }
        return time;
    }
};