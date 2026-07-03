class Solution {
public:
    string removeOuterParentheses(string s) {
      
      string ans;
      int balance =0;

      for(int i=0; i<s.size(); i++){
        if(s[i]=='(' ){
             balance++;
             if(balance >1){
            ans+=s[i];
            }
        }
        else {
            balance--;
            if(balance > 0){
                ans+=s[i];
            }
        }
      }  
      return ans;
    }
};