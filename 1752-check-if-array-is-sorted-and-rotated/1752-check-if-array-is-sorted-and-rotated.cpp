class Solution {
public:
    bool check(vector<int>& nums) {
        
        vector<int>nums1 = nums;
        nums1.insert(nums1.end(),nums.begin(),nums.end());
        int count = 1;
        int n = nums.size();
        for(int i=1;i<nums1.size();i++){
            if(count == n){
                return true;
            }
            if(nums1[i]>=nums1[i-1]){
                count++;
            }
            else{
                count=1;
            }
        }
         return false;
    }
};