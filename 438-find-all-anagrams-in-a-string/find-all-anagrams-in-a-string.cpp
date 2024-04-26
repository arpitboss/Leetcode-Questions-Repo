class Solution {
public:

    bool isAnagram(string &t, string &p, int i) {
        int count[256]={0};
        for (int j=0;j<p.size();j++) {
            count[p[j]]++;
            count[t[i+j]]--;
        }
        for (int j=0;j<256;j++) {
            if (count[j]!=0) {
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if (s.size()<p.size()) {
            return v;
        }
        
        for (int i=0;i<=s.size()-p.size();i++) {
            if (isAnagram(s,p,i)) {
                v.push_back(i);
            }
        }
        return v;
    }
};