class Solution {
public:
    void solve(vector<string> &wordDict, string &s, int i, set<string> &st, vector<string> &ans, string res) {
        if (i==s.size()) {
            res.pop_back();
            ans.push_back(res);
        }

        for (int k=i;k<s.size();k++) {
            string tmp=s.substr(i,k-i+1);
            res.push_back(s[k]);
            if (st.find(tmp)!=st.end()) {
                solve(wordDict,s,k+1,st,ans,res+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<string> ans;
        int i=0;
        set<string> st;
        for (auto x:wordDict) {
            st.insert(x);
        }
        solve(wordDict,s,i,st,ans,"");
        return ans;
    }
};