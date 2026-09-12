class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int smallest = 1;
        unordered_set<int> multipleOfK;

        for (int num : nums) {
            if (num % k == 0)
                multipleOfK.insert(num / k);

            if (num / k == smallest) {
                while (multipleOfK.count(smallest)) {
                    smallest++;
                }
            }
        }

        return smallest * k;
    }
};