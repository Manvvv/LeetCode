class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long long int res = 0;

        while(i < n && s[i]==' '){
            i++;
        }
        if(i < n && s[i]=='+' || s[i]=='-'){
            if(s[i]=='+'){
                sign = 1;
            }
            if(s[i]=='-'){
                sign = -1;
            }
            i++;

        }
          while(i < n && isdigit(s[i])){
            res = res*10 + (s[i] - '0');
            if(sign * res >= INT_MAX) return INT_MAX;
            if(sign * res <= INT_MIN) return INT_MIN;
            i++;
          }
     return sign * res;
    }
};