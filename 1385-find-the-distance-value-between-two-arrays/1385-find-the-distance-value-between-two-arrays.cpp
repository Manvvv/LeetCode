class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       
        int n =arr1.size();
        int count =0;
         sort(arr2.begin(),arr2.end());
         

        for(int i=0; i<n; i++){

             int start =0;
             int end =arr2.size();
             int found = 0;

            while(start < end){

               
                int mid = start + (end-start)/2;

                if(abs(arr1[i]-arr2[mid]) <= d){
                    found=1;
                    break;
                }

                if (arr1[i] - arr2[mid] > d) {
                    start = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            if(found==0)
                count++;
            
        }
        return count;
    }
};