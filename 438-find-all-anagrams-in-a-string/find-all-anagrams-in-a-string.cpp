class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        int n=s.size();
        int m=p.size();
        if (n<m) {
            return v;
        }
        int countT[256];
        int countP[256];
        for (int i=0;i<m;i++) {
            countT[s[i]]++;
            countP[p[i]]++;
        }

        for (int i=m;i<=n;i++) {
            bool flag=true;
            for (int j=0;j<256;j++) {
                if (countT[j]!=countP[j]) {
                    flag=false;
                }
            }
            if (flag) {
                v.push_back(i-m);
            }
            countT[s[i]]++;
            countT[s[i-m]]--;
        }
        return v;
    }
};