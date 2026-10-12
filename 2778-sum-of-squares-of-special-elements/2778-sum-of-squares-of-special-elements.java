class Solution {
    public int sumOfSquares(int[] nums) {
        int sum = 0;
        int res=0;
        int n = nums.length;
        for (int i = 1;i<=n;i++){
            if(n%i== 0){
                res = nums[i-1];

                res*=res;
                sum+=res;
                res=0;
            }

        }
        return sum;
        
    }
}