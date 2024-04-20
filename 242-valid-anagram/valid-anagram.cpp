class Solution {
public:
    bool isAnagram(string s, string t) {
       map<char,int> mp;
       map<char,int> mp1;

       for (int i=0;i<s.size();i++) {
            mp[s[i]]++;
       }

       for (int i=0;i<t.size();i++) {
            mp1[t[i]]++;
       }

       if (mp.size()==mp1.size()) {
            bool flag=true;
            for (int i=0;i<mp.size();i++) {
                if (mp[i]!=mp1[i]) {
                    flag=false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
            else {
                return false;
            }
       }
       else {
            return false;
       }
    }
};