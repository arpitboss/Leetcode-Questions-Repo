class Solution {
public:
    // int dp[31][31];
    unordered_map<string,bool> mp;
    bool solve(string s1, string s2) {
        if (s1.compare(s2)==0) {
            return true;
        }

        if (s1.size()==1) {
            return false;
        }

        string key=s1+" "+s2;
        if (mp.find(key)!=mp.end()) {
            return mp[key];
        }

        bool flag=false;
        for (int i=1;i<=s1.size()-1;i++) {
            if ((solve(s1.substr(0,i), s2.substr(s2.size()-i,i)) && solve(s1.substr(i,s1.size()-i), s2.substr(0,s2.size()-i))) || (solve(s1.substr(0,i), s2.substr(0,i)) && solve(s1.substr(i,s1.size()-i), s2.substr(i,s2.size()-i)))) {
            flag=true;
            break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        if (s1.size()!=s2.size()) {
            return false;
        }
        // memset(dp,-1,sizeof(dp));
        return solve(s1,s2);
    }
};