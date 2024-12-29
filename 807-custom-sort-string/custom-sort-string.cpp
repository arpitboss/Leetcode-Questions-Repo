class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for (int i=0;i<s.size();i++) {
            mp[s[i]]++;
        }

        string ans="";
        for (int i=order.size()-1;i>=0;i--) {
            if (mp.find(order[i])!=mp.end()) {
                while (mp[order[i]]>0) {
                    ans=order[i]+ans;
                    mp[order[i]]--;
                }   
            }
        }

        for (int i=0;i<s.size();i++) {
            if (mp[s[i]]) {
                ans+=s[i];
            }
        }
        return ans;
    }
};