class Solution {
    #define ll long long
    #define pii pair<ll,ll>
    ll MOD = 1e9+7;

    void calculateScore(vector<int>& nums,vector<ll>& score){
        for(ll ele: nums){
            ll count=0;
            for(ll i=2;i*i<ele;++i){
                if(ele%i==0)
                    count++;
                while(ele%i==0)
                    ele/=i;
            }
            if(ele>1)   count++;
            score.push_back(count);
        }
    }
    void calculateSubarrayCountPerScore(vector<ll>& score,vector<ll>& subarray_count){
        //Calculate Previous Greater or Equal Element
        vector<ll> pge;
        stack<ll> st;
        ll n=score.size();
        for(ll i=0;i<n;++i){
            while(!st.empty() and score[st.top()]<score[i])
                st.pop();
            if(st.empty())  pge.push_back(-1);
            else            pge.push_back(st.top());
            st.push(i);
        }

        //Parsse from right (next greater element) and count subarrays
        st = stack<ll>();
        ll count;
        for(ll i=n-1;i>=0;--i){
            count=0;
            while(!st.empty() and score[st.top()]<=score[i])
                st.pop();
            if(st.empty())  count = (n-i)*(i-pge[i]);
            else            count = (st.top()-i)*(i-pge[i]);
            
            st.push(i);
            subarray_count[i]=count;
        }
    }
    ll binaryExponentiation(long long a,long long b){
        //Find pow(a,b) mod (10^9+7)
        ll res=1;
        while(b){
            if(b&1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res % MOD;
    }
public:
    int maximumScore(vector<int>& nums, ll k) {
        ll n=nums.size();
        vector<ll> score;
        calculateScore(nums,score);

        vector<ll> subarray_count(n);
        calculateSubarrayCountPerScore(score,subarray_count);
        
        //Push (score,subarray) pair in maxheap
        priority_queue<pii> maxheap;
        for(ll i=0;i<n;++i)
            maxheap.push(make_pair(nums[i],i));
        
        long long res=1;
        while(k>0){
            pii curr = maxheap.top();
            maxheap.pop();
            res = (res * binaryExponentiation(curr.first,min(k,subarray_count[curr.second]))) % MOD;
            k -= subarray_count[curr.second];
        }
        return res;
    }
};