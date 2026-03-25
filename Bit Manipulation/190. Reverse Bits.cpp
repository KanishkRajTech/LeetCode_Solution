class Solution {
public:
    int reverseBits(int n) {
        string res = "";
        
        while(n > 0){
            if(n % 2 == 1) res += '1';
            else res += '0';
            n = n / 2;
        }

       
        while(res.length() < 32){
            res += '0';
        }

        int num = 0;
         long long p = 1;
        for(int i = 31; i >= 0; i--){
            if(res[i] == '1') num += p;
            p *= 2;
        }

        return num;
    }
};