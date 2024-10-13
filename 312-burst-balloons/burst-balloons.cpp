class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &arr, int i, int j) {
        if (i>=j) {
            return 0;
        }
        
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        int ans=INT_MIN;
        for (int k=i;k<=j-1;k++) {
            int tmp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            if (tmp>ans) {
                ans=tmp;
            }
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
         int N=nums.size();
         memset(dp,-1,sizeof(dp));
         vector<int> arr(N+2);
         int n=arr.size();
         arr[0]=1;
         arr[n-1]=1;
        for(int i = 1;i<=nums.size();i++){
            arr[i]=nums[i-1];   
        }
        return solve(arr,1,n-1);
    }
};