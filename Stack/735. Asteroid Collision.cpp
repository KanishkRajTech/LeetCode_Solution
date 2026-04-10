
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for(int i = 0; i < n; i++){
            int num = asteroids[i];

            if(num >= 0){
                st.push(num);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(num)){
                    st.pop();
                } 

                if(!st.empty() && st.top() == abs(num)) {
                    st.pop(); 
                }
                else if(st.empty() || st.top() < 0) {
                    st.push(num);
                }
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};