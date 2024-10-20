class Solution {
public:
    int dp[10001][101];
    int solve(int f, int e) {
        if (f==0 || f==1) {
            return f;
        }

        if (e==1) {
            return f;
        }

        if (dp[f][e]!=-1) {
            return dp[f][e];
        }

        int mini=INT_MAX;
        int st=1,en=f;
        while(st<=en) {
            int k=(st+en)/2;
            int itBreaks,notBreaks;
            if (dp[k-1][e-1]!=-1) {
                itBreaks=dp[k-1][e-1];
            }
            else {
                dp[k-1][e-1]=solve(k-1,e-1);
                itBreaks=dp[k-1][e-1];
            }

            if (dp[f-k][e]!=-1) {
                notBreaks=dp[f-k][e];
            }
            else {
                dp[f-k][e]=solve(f-k,e);
                notBreaks=dp[f-k][e];
            }
            int temp=1+max(itBreaks,notBreaks);
            mini=min(mini,temp);
            if (itBreaks<notBreaks) {
                st=k+1;
            }
            else {
                en=k-1;
            }
        }
        return dp[f][e]=mini;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};