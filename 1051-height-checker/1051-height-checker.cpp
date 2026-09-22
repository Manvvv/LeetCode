class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int result = 0;
        vector<int>check;
        check = heights;
        int n = heights.size();
        

       sort(heights.begin(), heights.end());
      
        for(int i=0; i<n; i++){
            if(heights[i]!=check[i]){
                result++;
            }
        }
       return result;
    }
};