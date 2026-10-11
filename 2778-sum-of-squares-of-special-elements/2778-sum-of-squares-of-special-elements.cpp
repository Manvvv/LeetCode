class Solution {
public:
    int sumOfSquares(vector<int>& nums) {

     int ans;
     int res=0;
        int n = nums.size();

       for(int i=1 ;i<=n; i++){
          if(n%i==0){
            ans=nums[i-1];
          }
          ans*=ans;
          res+=ans;
          ans=0;
       }
       return res;
    }
};