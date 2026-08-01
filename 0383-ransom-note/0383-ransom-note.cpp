class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0;
        int j = 0;
        string ans = "";

        while (i < ransomNote.length()) {
            j = 0;
            while (j < magazine.length()) {
                if (ransomNote[i] == magazine[j]) {
                    ans.push_back(ransomNote[i]);
                    magazine[j] = '#';   // mark as used
                    break;
                }
                j++;
            }
            i++;
        }

        if (ransomNote == ans) {
            return true;
        }
        return false;
    }
};