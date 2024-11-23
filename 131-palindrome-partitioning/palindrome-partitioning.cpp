class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        if (i>=j) {
            return true;
        }
        while (i<j) {
            if (s[i]==s[j]) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
    void solve(vector<vector<string>>& v, vector<string> &u, string &s, int i, int j) {
        if (i>j) {
            v.push_back(u);
            return;
        }

        for (int k=i;k<=j;k++) {
            if (isPalindrome(s,i,k)) {
                string tmp=s.substr(i,k-i+1);
                u.push_back(tmp);
                solve(v,u,s,k+1,j);
                u.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> u;
        int i=0;
        int j=s.size()-1;
        solve(v,u,s,i,j);
        return v;
    }
};