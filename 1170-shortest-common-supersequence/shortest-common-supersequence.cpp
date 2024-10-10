class Solution {
public:
    string lcs(string x, string y, int n, int m) {
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int i,j;
        for (i=1;i<=n;i++) {
            for (j=1;j<=m;j++) {
                if (x[i-1]==y[j-1]) {
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
            if (x[i-1]==y[j-1]) {
                ans.push_back(x[i-1]);
                i--;
                j--;
            }
            else if (dp[i-1][j]>dp[i][j-1]) {
                    ans.push_back(x[i-1]);
                    i--;
            }
            else {
                    ans.push_back(y[j-1]);
                    j--;
            }
        }

        while (i>0) {
            ans.push_back(x[i-1]);
            i--;
        }
        while (j>0) {
            ans.push_back(y[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        return lcs(str1, str2, n, m);
    }
};