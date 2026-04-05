class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;

        for(char c : s) {
            freq[c]++;
        }

        int ans = 0;
        unordered_set<char> visited;
        for(auto &it : freq) {
            char c = it.first;


            if(visited.count(c)) continue;

            char mirror;

            if(c >= 'a' && c <= 'z') {
                mirror = 'z' - (c - 'a');
            } 
            else {
                mirror = '9' - (c - '0');
            }

            int freC = freq[c];
            int freM = freq.count(mirror) ? freq[mirror] : 0;


            ans += abs(freC - freM);


            visited.insert(c);
            visited.insert(mirror);
        }

        return ans;
    }
};