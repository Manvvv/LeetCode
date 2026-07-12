class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        vector<int> SortedArr = arr;
        int duplicate = 0;

        sort(SortedArr.begin(), SortedArr.end());

        unordered_map<int, int> rank;
        for(int i=0; i<SortedArr.size(); i++){
        rank[SortedArr[i]]=i+1;
        
        if( i>0 && SortedArr[i]==SortedArr[i-1]){
            duplicate++;
        }
        rank[SortedArr[i]]-=duplicate;
        }
        for(int i=0; i<arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};