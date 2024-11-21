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

        int res = n;
        int left = 0;
        int right = 0;

        while (right<n) {
            mp[s[right]]--;
            while (mp['a']<k || mp['b']<k || mp['c']<k) {
                mp[s[left]]++;
                left++;
            }
            res=min(res,n-(right-left+1));
            right++;
        }
        return res;
    }
};
