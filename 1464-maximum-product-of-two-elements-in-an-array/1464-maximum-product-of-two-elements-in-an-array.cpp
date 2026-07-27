class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;

        int i=nums.size()-1;
        int j=nums.size()-2;

         res = (nums[i]-1)*(nums[j]-1);

         return res;
    }
};