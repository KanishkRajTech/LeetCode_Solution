class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>map;
        for(char ch :s){
            map[ch]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(map[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};