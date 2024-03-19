class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int left=0,right=n-1,top=0,bottom=n-1;
        int x=1;
        while (x<=n*n) {
        for (int i=left;i<=right;i++) {
            v[top][i]=x;
            x++;
        }
        top++;
        for (int i=top;i<=bottom;i++) {
            v[i][right]=x;
            x++;
        }
        right--;
        for (int i=right;i>=left;i--) {
            v[bottom][i]=x;
            x++;
        }
        bottom--;
        for (int i=bottom;i>=top;i--) {
            v[i][left]=x;
            x++;
        }
        left++;
        }
        return v;
    }
};