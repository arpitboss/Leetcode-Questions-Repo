class Solution {
public:
    string lcs(string s, string t, int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        int i,j;
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                if (s[i-1]==t[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        i=n;
        j=m;
        string ans="";
        while (i>0 && j>0) {
            if (s[i-1]==t[j-1]) {
                ans.push_back(s[i-1]);
                i--;
                j--;
            }
            else {
                if (dp[i-1][j]>dp[i][j-1]) {
                    i--;
                }
                else {
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        return s==lcs(s,t,n,m);
    }
};