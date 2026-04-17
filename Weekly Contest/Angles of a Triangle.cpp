class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        double a = sides[0], b = sides[1], c = sides[2];

        if (a + b <= c) return {};

        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));

        double pi = acos(-1);
        A = A * 180 / pi;
        B = B * 180 / pi;
        C = C * 180 / pi;
        
        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};