class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        for (int i=0;i<grid[0].size();i++) {
            int c=0,l=0;
            for (int j=0;j<grid.size();j++) {
                if (grid[j][i]==0 && i==0) {
                    for (int k=0;k<grid[0].size();k++) {
                        if (grid[j][k]==0) 
                        grid[j][k]=1;
                        else 
                        grid[j][k]=0;
                    }
                }
                else {
                    if (grid[j][i]==0) {
                        c++;
                    }
                    else {
                        l++;
                    }
                } 
            }
            if (c>l) {
                for (int m=0;m<grid.size();m++) {
                    if (grid[m][i]==1)
                    grid[m][i]=0;
                    else
                    grid[m][i]=1;
                }
            }
        }

        // string s="";
        int sum=0;
        for (int i=0;i<grid.size();i++) {
            int k=0;
            for (int j=0;j<grid[i].size();j++) {
                sum+=(grid[i][j]*pow(2,grid[0].size()-1-k));
                k++;
                // s+=grid[i][j];
            }
        }
        return sum;
    }
};