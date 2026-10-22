
class Solution {
public:
    double trimMean(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        double res = 0;
        int m = arr.size();
        int k = m / 20;

        for (int i = k; i < m - k; i++) {
            res += arr[i];
        }

        return res / (m - 2 * k);
    }
};
