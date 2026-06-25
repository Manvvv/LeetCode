class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();
        
       for(int i=0; i<n; i++){
        if(nums[i]==target){
            nums[i] = 1;
        }
        else{
            nums[i] = -1;
        }
       }
        

      int ans=0;

         for(int start = 0; start<n; start++){
              int sum = 0;
            for(int end = start; end<n; end++){
               sum +=nums[end];

               if(sum >0){
                ans++;
               }
            }
         }
         return ans;
    }
};