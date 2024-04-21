class Solution {
public:
    const int CHAR = 256;
    int firstUniqChar(string s) {
       int fIndex[CHAR];
       int res=INT_MAX;
       fill(fIndex,fIndex+CHAR,-1);

       for (int i=0;i<s.size();i++) {
        if (fIndex[s[i]]==-1) {
            fIndex[s[i]]=i;
        }
        else {
            fIndex[s[i]]=-2;
        }
       }

       for (int i=0;i<CHAR;i++) {
        if (fIndex[i]>=0) {
            res=min(res,fIndex[i]);
        }
       }
       return (res==INT_MAX) ? -1 : res;
    }
};