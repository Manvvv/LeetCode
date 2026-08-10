class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int start = 0;
        int end = arr.size();
        sort(arr.begin(),arr.end());

        while(start < end){
            
            int mid = start + (end-start) / 2;

            if(arr[mid] <= target){
                start = mid+1;
            }
           
            else{
                end = mid;
            }
        }
      
        return arr[start % arr.size()];
    }
};