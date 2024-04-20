class Solution {
public:
    const int CHAR = 256;
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) 
            return false;

        vector<int>v(CHAR, 0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]]++;
            v[t[i]]--;
        }

        for(int i=0;i<CHAR;i++)
        {
            if(v[i]!=0)
                return false;
        }
        return true;
    }
};