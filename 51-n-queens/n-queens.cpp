class Solution {
public:
    bool check(int i, int j, int n, vector<string> &board) {
        for (int k=0;k<n;k++) {
            if (board[k][j]=='Q') {
                return false;
            }
        }
        
        int r=i-1,c=j-1;
        while (r>=0 && c>=0) {
            if (board[r][c]=='Q') {
                return false;
            }
            r--;
            c--;
        }
        
        r=i-1,c=j+1;
        while (r>=0 && c<n) {
            if (board[r][c]=='Q') {
                return false;
            }
            r--;
            c++;
        }
        return true;
    }
    void solve(int i, vector<vector<string>> &ans, vector<string> &v, int n) {
        if (i==n) {
            ans.push_back(v);
            return;
        }

        for (int k=0;k<n;k++) {
            if (check(i,k,n,v)) {
                v[i][k]='Q';
                solve(i+1,ans,v,n);
                v[i][k]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));
        solve(0,ans,v,n);
        return ans;
    }
};