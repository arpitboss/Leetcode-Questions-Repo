class Solution {
public:
    bool solve(vector<string> &wordDict, string &s, int i, set<string> &st, vector<int> &dp) {
        if (i==s.size()) {
            return dp[i]=true;
        }

        if (dp[i]!=-1) {
            return dp[i];
        }

        for (int k=i;k<s.size();k++) {
            string tmp=s.substr(i,k-i+1);
            if (st.find(tmp)!=st.end()) {
                if (solve(wordDict,s,k+1,st,dp)) {
                    return dp[i]=true;
                } 
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,-1); 
        int i=0;
        set<string> st;
        for (auto x:wordDict) {
            st.insert(x);
        }
        return solve(wordDict,s,i,st,dp);
    }
};