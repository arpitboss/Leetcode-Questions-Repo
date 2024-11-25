class Solution {
public:
    bool check(char ch, int i, int j, vector<vector<char>> &board) {
        for (int k=0;k<9;k++) {
            if (board[i][k]==ch) {
                return false;
            }
        }

        for (int k=0;k<9;k++) {
            if (board[k][j]==ch) {
                return false;
            }
        }

        int x=(i/3)*3;
        int y=(j/3)*3;
        for (int k=x;k<x+3;k++) {
            for (int m=y;m<y+3;m++) {
                if (board[k][m]==ch) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int i, int j, vector<vector<char>>& board) {
        if (i==9) {
            return true;
        }

        if (j==9) {
            return solve(i+1,0,board);
        }

        if (board[i][j]!='.') {
            return solve(i,j+1,board);
        }

        for (char ch='1';ch<='9';ch++) {
            if (check(ch,i,j,board)) {
                board[i][j]=ch;
                bool res=solve(i,j+1,board);
                if (res==true) {
                    return true;
                }
            }
        }
        board[i][j]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};