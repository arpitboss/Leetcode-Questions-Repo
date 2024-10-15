class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &str, int i, int j) {
        while (i<j) {
            if (str[i]!=str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string &str, int i, int j) {
        if (i>=j) {
            return 0;
        }
        
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        
        if (isPalindrome(str,i,j)) {
            return 0;
        }
        
        int mini=INT_MAX;
        for (int k = i; k<=j-1; k++){
            if (isPalindrome(str, i, k)){
                mini = min(mini, 1 + solve(str, k + 1, j));
            }
        }
        return dp[i][j]=mini;
    }
    int minCut(string str) {
        int i=0;
        int j=str.size()-1;
        memset(dp,-1,sizeof(dp));
        return solve(str,i,j); 
    }
};