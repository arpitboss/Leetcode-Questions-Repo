class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len=0;
        vector<int> count(256,-1);
        int first=0;
        int second=0;

        while (second<s.size()) {
            first=max(first,count[s[second]]+1);
            len=max(len,second-first+1);
            count[s[second]]=second;
            second++;
        }
        return len;
    }
};