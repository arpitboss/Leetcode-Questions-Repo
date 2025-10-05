class Solution {
public:
    bool isPalindrome(string s) {
        int st=0, en=s.size()-1;
        while (st<=en) {
            if (!isalnum(s[st])) {
                st++;
                continue;
            }
            else if (!isalnum(s[en])) {
                en--;
                continue;
            }
            else if (tolower(s[st])!=tolower(s[en])) {
                return false;
            }
            st++;
            en--;
        }
        return true;
    }
};