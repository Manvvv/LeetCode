class Solution {
public:
    int countCommas(int n) {
    
    int comma=0;

    if(n<=999){
        return 0;
    }

        while(n>999){
         comma++;
         n--;
        }
        
        return comma;
    }
};