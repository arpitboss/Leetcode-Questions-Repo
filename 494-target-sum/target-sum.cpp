class Solution {
public:
    int MOD=1000000007;
    int subsetSum(vector<int>& arr, int n, int sum) {
        vector<vector<int>> dp(n+1, vector<int>(sum+1));
        
        for (int j=0;j<=sum;j++) {
            dp[0][j]=0;
        }
        for (int i=0;i<=n;i++) {
            dp[i][0]=1;
        }
        
        
        for (int i=1;i<=n;i++) {
            for (int j=0;j<=sum;j++) {
                if (arr[i-1]<=j) {
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%MOD;
                }
                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int tSum=0;
        for (auto i:arr) {
            tSum+=i;
        }
        if ((tSum+target)%2!=0 || (tSum+target)<0) {
            return 0;
        }
        int sum=(tSum+target)/2;
        return subsetSum(arr,n,sum);
        
    }
};