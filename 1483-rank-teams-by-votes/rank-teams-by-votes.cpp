class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n = votes.size();
        if (n==1) {
            return votes[0];
        }
        int m = votes[0].size();
        map<char, vector<int>> mp;
        for(char c: votes[0])
        {
            mp[c] = vector<int>(m+1 , 0);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                mp[votes[i][j]][j+1]++;
            }
        }
        vector<pair<char, vector<int>>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [&](pair<char, vector<int>> &a , pair<char, vector<int>> &b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.second>b.second;
        });
        string res="";
        for(auto i: v)
        {
            res += i.first;
        }
        return res;
    }
};