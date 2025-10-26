class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<int> tmp(26,0);
        for (char ch:p) {
            tmp[ch-'a']++;
        }

        vector<int> res;
        int i=0, j=0;
        while (i<n) {
            tmp[s[i]-'a']--;

            if (i-j+1==m) {
                if (tmp==vector<int>(26,0)) {
                    res.push_back(j);
                }
                tmp[s[j]-'a']++;
                j++;
            }
            i++;
        }

        return res;
    }
};