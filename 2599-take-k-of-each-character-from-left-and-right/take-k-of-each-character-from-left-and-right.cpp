class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char,int> mp;
        for (int i=0;i<n;i++) {
            mp[s[i]]++;
        }

        if (mp['a']<k || mp['b']<k || mp['c']<k) {
            return -1;
        }

        unordered_map<char,int> mp2;
        mp2['a']=0;
        mp2['b']=0;
        mp2['c']=0;
        
        int res = 0;
        int left = 0;
        int right=0;

        while (right<n) {
            mp2[s[right]]++;
            while (mp['a']-mp2['a']<k || mp['b']-mp2['b']<k || mp['c']-mp2['c']<k) {
                mp2[s[left]]--;
                left++;
            }
            res=max(res,right-left+1);
            right++;
        }
        return n-res;
    }
};
