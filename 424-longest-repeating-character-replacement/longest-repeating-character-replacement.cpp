class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int> tmp(26,0);
        int i=0,j=0;
        int res=0,maxi=0;

        while (i<n) {
            tmp[s[i]-'A']++;
            maxi=max(tmp[s[i]-'A'],maxi);
            while (i-j+1-maxi>k) {
                tmp[s[j]-'A']--;
                j++;
            }
            res=max(res,i-j+1);
            i++;
        }
        return res;
    }
};