class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k=0;
        for (int i=0;i<t.size() && k<s.size();i++) {
            if (t[i]==s[k]) {
                k++;
            }
        }
        if (k==s.size()) {
            return true;
        }
        else {
            return false;
        }
    }
};