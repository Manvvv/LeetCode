class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int left = 0; 
        int right = nums.size() - 1;
        int idx = -1;
                    
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                idx = mid;
                
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        res[0] = idx;


            
        left = 0; 
        right = nums.size() - 1;
        idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                idx = mid;
                
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        res[1] = idx;

        return res;
    }
};