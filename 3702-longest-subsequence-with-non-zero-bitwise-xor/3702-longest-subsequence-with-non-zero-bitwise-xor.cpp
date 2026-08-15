class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int i = 0;
        int ans = 0;
        
        while(i < nums.size()) {
            ans ^= nums[i];
            i++;
        }

        if(ans != 0) {
            return nums.size();
        }
        else {
            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != 0) {
                    return nums.size() - 1;
                }
            }
        }

        return 0;
    }
};