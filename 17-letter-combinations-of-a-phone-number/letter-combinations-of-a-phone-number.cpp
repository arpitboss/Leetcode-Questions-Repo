class Solution {
public:
    void solve(int i, string &s, map<char,string> &mp, vector<string> &ans, string &tmp) {
        if (i==s.size()) {
            ans.push_back(tmp);
            return;
        }

        char ch=s[i];
        for (auto k:mp[ch]) {
            tmp+=k;
            solve(i+1,s,mp,ans,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size()==0) {
            return ans;
        }
        map<char,string> mp; 
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        string tmp;
        solve(0,digits,mp,ans,tmp);
        return ans;
    }
};