class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for (int i = low; i <= high; i++) {
            string num = to_string(i);
            int n = num.length();
            if (n % 2 != 0) continue;

            int firstSum = 0, lastSum = 0;
            for (int j = 0; j < n / 2; j++) {
                firstSum += num[j] - '0';
                lastSum += num[n - j - 1] - '0';
            }

            if (firstSum == lastSum) result++;
        }
        return result;
    }
};
