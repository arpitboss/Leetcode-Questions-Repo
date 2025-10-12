class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int i=0, j=0;
        int res=0;
        while (j<s.size()) {
            while (mp[s[j]]>0) {
                mp[s[i]]--;
                i++;
            }
            mp[s[j]]++;
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};