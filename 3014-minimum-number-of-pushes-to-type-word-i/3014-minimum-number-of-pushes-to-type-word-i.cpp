class Solution {
public:
    int minimumPushes(string word) {
     int n = word.length();
     int pushcnt= 0;

     for(int i = 0; i< n; i++){
        pushcnt+= i/8 +1;
     }   
     return pushcnt;
    }
};