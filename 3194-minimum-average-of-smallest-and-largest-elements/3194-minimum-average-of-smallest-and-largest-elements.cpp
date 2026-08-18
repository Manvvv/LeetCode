class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        
        vector<double>ans;
        
        double avg=0;

        while(!nums.empty()){

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        avg = (mn+mx)/2.0;

        ans.push_back(avg);

         nums.erase(find(nums.begin(), nums.end(), mn));
            nums.erase(find(nums.begin(), nums.end(), mx));




        }
        return *min_element(ans.begin(), ans.end());
    }
};