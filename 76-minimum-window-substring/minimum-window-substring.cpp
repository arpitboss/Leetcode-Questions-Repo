class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size()>s.size()) {
            return "";
        }
        unordered_map<char,int> mp;
        for (int i=0;i<t.size();i++) {
            mp[t[i]]++;
        }
        int mini=INT_MAX;
        int reqCnt=t.size(); 
        int i=0, j=0;
        int st=0;

        while (j<s.size()) {
            if (mp[s[j]]>0) {
                reqCnt--;
            } 
            mp[s[j]]--;
           
            while (reqCnt==0) {
                if (j-i+1<mini) {
                    mini=j-i+1;
                    st=i;
                }
                mp[s[i]]++;
                if (mp[s[i]]>0) {
                    reqCnt++;
                }
                i++;
            }
            j++;
        }
        return mini==INT_MAX?"":s.substr(st,mini);
    }
};